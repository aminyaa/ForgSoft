#include <FrgBase_FieldParser.hxx>
#include <FrgBase_SymbolTable.hxx>
#include <FrgBase_ScalarField.hxx>
#include <FrgBase_VectorField.hxx>
#include <FrgBase_FieldTools.hxx>

#include <exprtk.hpp>

#define GetM(str) (std::max(15, (int)str.size() + 2))

std::shared_ptr<exprtk::expression<double>> ForgBaseLib::FrgBase_FieldParser::CompileExpression
(
	const std::shared_ptr<FrgBase_Field_Entity>& field
)
{
	if (!field)
		throw std::exception("Field is null in " __FUNCSIG__);

	auto e = field->GetExpression();

	if (e.empty())
		throw std::exception("Empty Expression.");

	const auto& tables =
		field->RetrieveSymbolTablesIncludingExternals();

	return CompileExpression
	(
		CreateFieldExpressionReadyToCompile(field),
		tables
	);
}

std::shared_ptr<exprtk::expression<double>> ForgBaseLib::FrgBase_FieldParser::CompileExpression
(
	const std::string& expression,
	const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& symbolTables
)
{
	auto myExpression =
		std::make_shared<exprtk::expression<double>>();

	for (const auto& table : symbolTables)
		myExpression->register_symbol_table(*table->GetSymbolTable());

	auto myParser =
		std::make_shared<exprtk::parser<double>>();

	auto isCompiled =
		myParser->compile(expression, *myExpression.get());

	if (!isCompiled)
	{
		std::string message =
			myParser->error().c_str();

		auto messageDecorized =
			FrgBase_FieldTools::DecorizeExpressionUsingString
		(
			message,
			symbolTables
		);

		std::exception ex(messageDecorized.c_str());
		throw ex;
	}

	return myExpression;
}

std::shared_ptr<exprtk::expression<double>>
ForgBaseLib::FrgBase_FieldParser::CalcValueEntity
(
	const std::shared_ptr<FrgBase_Field_Entity>& field,
	const std::shared_ptr<Calculated>& calculated
)
{
	auto tables =
		field->RetrieveSymbolTablesIncludingExternals();

	auto expressionString =
		CreateFieldExpressionReadyToCompile(field);

	auto myExpression =
		CompileExpression
	(
		expressionString,
		tables
	);

	//auto myExpression = CompileExpression(field->GetExpression(), tables);

	std::shared_ptr<FrgBase_FieldParser::Calculated> myCalculated;
	if (!calculated)
		myCalculated = InitCalculated();
	else
		myCalculated = calculated;

	auto collectedVariables =
		CollectVariablesFullName(field);

	auto dependentFields =
		RetrieveFieldsUsingFullName
		(
			collectedVariables,
			tables
		);

	for (const auto& myField : dependentFields)
	{
		if (!ContainFieldInCalculated(myCalculated, myField))
		{
			myField->CalcValue(myCalculated);
			myCalculated->theFields_.push_back(myField);
		}
	}

	if (!ContainFieldInCalculated(myCalculated, field))
		myCalculated->theFields_.push_back(field);

	return myExpression;
}

std::vector<double>
ForgBaseLib::FrgBase_FieldParser::RetrieveValuesFromExpression
(
	const size_t size,
	const std::shared_ptr<exprtk::expression<double>>& expression
)
{
	std::vector<double> result;

	auto value = expression->value();

	const auto& results = expression->results();
	if (results.count() == 0 || results.count() != size)
	{
		std::string message =
			"Cannot calculate the value. The size should be equal to " +
			std::to_string(size);

		std::exception ex(message.c_str());
		throw ex;
	}

	typedef exprtk::results_context<double> results_context_t;
	typedef typename results_context_t::type_store_t type_t;
	typedef typename type_t::scalar_view scalar_t;
	typedef typename type_t::vector_view vector_t;
	typedef typename type_t::string_view string_t;

	bool areValuesAcceptable = true;
	for (std::size_t i = 0; i < results.count(); ++i)
	{
		auto t = results[i];

		if (t.type == type_t::e_scalar)
		{
			auto value = scalar_t(t);

			if (std::isinf(value()))
				areValuesAcceptable = false;
			else if (std::isnan(value()))
				areValuesAcceptable = false;

			result.push_back(value());
		}
		else if (t.type == type_t::e_vector)
		{
			auto value = vector_t(t);
			for (std::size_t iter = 0; iter < value.size(); iter++)
			{
				if (std::isinf(value[iter]))
					areValuesAcceptable = false;
				else if (std::isnan(value[iter]))
					areValuesAcceptable = false;

				result.push_back(value[iter]);
			}
		}
	}

	if (!areValuesAcceptable)
	{
		std::exception ex("Value is not acceptable.");
		throw ex;
	}

	return result;
}

void ForgBaseLib::FrgBase_FieldParser::CheckRecursiveLoop
(
	const std::shared_ptr<FrgBase_Field_Entity>& field,
	const std::string& expression
)
{
	if (!field)
		throw std::exception("Field is null in " __FUNCSIG__);

	std::vector<std::string> varsNames;
	exprtk::collect_variables
	(
		CreateFieldExpressionReadyToCompile(expression, field->IsVector()),
		varsNames
	);

	const auto& myTables =
		field->RetrieveSymbolTablesIncludingExternals();

	auto fields =
		FrgBase_FieldParser::RetrieveFieldsUsingFullName
		(
			varsNames,
			myTables
		);

	std::string message =
		"Cannot compile the expression. It points to " + FrgBase_FieldTools::AddDecoratorAndBracket(field) +
		".\nIt will cause recursive definition.";

	for (const auto& f : fields)
	{
		if (f == field)
			throw std::exception(message.c_str());
	}

	const auto b = ContainsThisInFields
	(
		field,
		fields
	);

	if (b)
		throw std::exception(message.c_str());
}

double ForgBaseLib::FrgBase_FieldParser::CalcValueScalar
(
	const std::shared_ptr<FrgBase_ScalarField>& field,
	const std::shared_ptr<Calculated>& calculated
)
{
	auto myExpression =
		CalcValueEntity(field, calculated);

	auto value = myExpression->value();

	auto results = myExpression->results();
	if (results.count() > 0)
	{
		std::exception ex("Cannot calculate the value. The size is bigger than 1.");
		throw ex;
	}

	return value;
}

std::vector<double> ForgBaseLib::FrgBase_FieldParser::CalcValueVector
(
	const std::shared_ptr<FrgBase_VectorField_Entity>& field,
	const std::shared_ptr<Calculated>& calculated
)
{
	auto myExpression =
		CalcValueEntity(field, calculated);

	auto values =
		RetrieveValuesFromExpression
		(
			field->GetSize(),
			myExpression
		);

	return values;
}

std::shared_ptr<ForgBaseLib::FrgBase_FieldParser::Calculated>
ForgBaseLib::FrgBase_FieldParser::InitCalculated()
{
	auto calculated =
		std::make_shared<Calculated>();

	return calculated;
}

bool ForgBaseLib::FrgBase_FieldParser::ContainFieldInCalculated
(
	const std::shared_ptr<Calculated>& calculated,
	const std::shared_ptr<FrgBase_Field_Entity>& field
)
{
	if (calculated)
	{
		for (const auto& f : calculated->theFields_)
		{
			if (f == field)
				return true;
		}
	}

	return false;
}

std::string ForgBaseLib::FrgBase_FieldParser::CreateFieldExpressionReadyToCompile
(
	const std::string& expression,
	const bool isVector
)
{
	if (expression.empty())
		throw std::exception("Expression cannot be empty.");

	std::string result;
	if (isVector && expression[0] == '[')
		result = "return " + expression;
	else
		result = expression;

	return result;
}

std::string ForgBaseLib::FrgBase_FieldParser::CreateFieldExpressionReadyToCompile
(
	const std::shared_ptr<FrgBase_Field_Entity>& field
)
{
	if (!field)
		throw std::exception("Field is null in " __FUNCSIG__);

	return CreateFieldExpressionReadyToCompile
	(
		field->GetExpression(),
		field->IsVector()
	);
}

std::vector<std::string> ForgBaseLib::FrgBase_FieldParser::CollectVariablesFullName
(
	const std::shared_ptr<FrgBase_Field_Entity>& field
)
{
	if (!field)
		throw std::exception("Field is null in " __FUNCSIG__);

	std::vector<std::string> variables;

	exprtk::collect_variables
	(
		CreateFieldExpressionReadyToCompile(field),
		variables
	);

	return variables;
}

std::string ForgBaseLib::FrgBase_FieldParser::CombineString
(
	const std::vector<std::string>& strs
)
{
	std::ostringstream header;

	for (const auto& h : strs)
	{
		header << std::setw(GetM(h)) << h;
	}

	return header.str();
}

std::string ForgBaseLib::FrgBase_FieldParser::CombineValues
(
	const std::vector<std::string>& headers,
	const std::vector<double>& values
)
{
	std::ostringstream value;

	for (int i = 0; i < headers.size(); i++)
	{
		value << std::setw(GetM(headers[i])) <<
			std::scientific << std::setprecision(6) <<
			values[i];
	}

	return value.str();
}

std::shared_ptr<ForgBaseLib::FrgBase_Field_Entity>
ForgBaseLib::FrgBase_FieldParser::ContainsThisInFields
(
	const std::shared_ptr<FrgBase_Field_Entity>& field,
	const std::vector<std::shared_ptr<FrgBase_Field_Entity>>& fields
)
{
	if (!field || fields.empty())
		return nullptr;

	for (const auto& f : fields)
	{
		if (f == field)
			return f;

		auto t = RetrieveDependentFields
		(
			f,
			f->RetrieveSymbolTablesIncludingExternals()
		);

		const auto b = ContainsThisInFields
		(
			field,
			RetrieveDependentFields
			(
				f,
				f->RetrieveSymbolTablesIncludingExternals()
			)
		);

		if (b)
			return b;
	}

	return nullptr;
}

std::shared_ptr<ForgBaseLib::FrgBase_Field_Entity>
ForgBaseLib::FrgBase_FieldParser::RetrieveFieldUsingFullName
(
	const std::string& variableFullName,
	const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& symbolTables
)
{
	for (const auto& table : symbolTables)
	{
		auto field =
			table->ContainsField
			(
				variableFullName
			);

		if (field)
			return field;
	}

	return nullptr;
}

std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Field_Entity>>
ForgBaseLib::FrgBase_FieldParser::RetrieveFieldsUsingFullName
(
	const std::vector<std::string>& variablesFullName,
	const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& symbolTables
)
{
	std::vector<std::shared_ptr<FrgBase_Field_Entity>> fields;

	for (const auto& variableFullName : variablesFullName)
	{
		auto field =
			RetrieveFieldUsingFullName
			(
				variableFullName,
				symbolTables
			);

		if (field)
			fields.push_back(field);
	}

	return fields;
}

std::shared_ptr<ForgBaseLib::FrgBase_Field_Entity>
ForgBaseLib::FrgBase_FieldParser::RetrieveFieldUsingFullPresentationName
(
	const std::string& variableFullPresentationName,
	const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& symbolTables
)
{
	for (const auto& table : symbolTables)
	{
		auto field =
			table->ContainsFieldFullPresentationName
			(
				variableFullPresentationName
			);

		if (field)
			return field;
	}

	return nullptr;
}

std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Field_Entity>>
ForgBaseLib::FrgBase_FieldParser::RetrieveFieldsUsingFullPresentationName
(
	const std::vector<std::string>& variablesFullPresentationName,
	const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& symbolTables
)
{
	std::vector<std::shared_ptr<FrgBase_Field_Entity>> fields;

	for (const auto& variableFullPresentationName : variablesFullPresentationName)
	{
		auto field =
			RetrieveFieldUsingFullPresentationName
			(
				variableFullPresentationName,
				symbolTables
			);

		if (field)
			fields.push_back(field);
	}

	return fields;
}

std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Field_Entity>>
ForgBaseLib::FrgBase_FieldParser::RetrieveDependentFields
(
	const std::shared_ptr<FrgBase_Field_Entity>& field,
	const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& symbolTables,
	const bool recursively
)
{
	std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Field_Entity>> result;

	auto collectedVariables =
		CollectVariablesFullName(field);

	auto dependentFields =
		RetrieveFieldsUsingFullName
		(
			collectedVariables,
			symbolTables
		);

	result = dependentFields;

	if (recursively)
	{
		for (auto f : dependentFields)
		{
			auto fs = RetrieveDependentFields(f, symbolTables);
			for (auto fin : fs)
				result.push_back(fin);
		}
	}

	return result;
}

std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Field_Entity>>
ForgBaseLib::FrgBase_FieldParser::RetrieveFieldsUsingThisField
(
	const std::shared_ptr<FrgBase_Field_Entity>& field,
	const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& symbolTables,
	const bool recursively
)
{
	std::vector<std::shared_ptr<FrgBase_Field_Entity>> result;

	for (const auto& t : symbolTables)
	{
		for (const auto& f : t->GetFields())
		{
			for (const auto& df : RetrieveDependentFields(f, symbolTables, recursively))
			{
				if (df == field)
				{
					result.push_back(f);
					break;
				}
			}
		}
	}

	return result;
}