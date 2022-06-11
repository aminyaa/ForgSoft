#include <FrgBase_FieldParser.hxx>
#include <FrgBase_SymbolTable.hxx>
#include <FrgBase_ScalarField.hxx>

#include <exprtk.hpp>

#define GetM(str) (std::max(15, (int)str.size() + 2))

std::shared_ptr<exprtk::expression<double>> ForgBaseLib::FrgBase_FieldParser::CompileExpression
(
	const std::string& expression,
	const std::vector<FrgBase_SymbolTable*>& symbolTables
)
{
	auto myExpression = std::make_shared<exprtk::expression<double>>();
	for (const auto& table : symbolTables)
		myExpression->register_symbol_table(*table->GetSymbolTable());

	auto myParser = std::make_shared<exprtk::parser<double>>();

	auto isCompiled = myParser->compile(expression, *myExpression.get());
	if (!isCompiled)
	{
		std::exception ex(myParser->error().c_str());
		throw ex;
	}

	return myExpression;
}

std::shared_ptr<exprtk::expression<double>> ForgBaseLib::FrgBase_FieldParser::CalcValueEntity
(
	FrgBase_Field_Entity* field,
	const std::shared_ptr<Calculated>& calculated
)
{
	auto tables = field->RetrieveSymbolTablesIncludingExternals();

	auto myExpression = CompileExpression
	(
		field->IsScalar() ?
		field->GetExpression() :
		"return " + field->GetExpression(),
		tables
	);

	//auto myExpression = CompileExpression(field->GetExpression(), tables);

	std::shared_ptr<FrgBase_FieldParser::Calculated> myCalculated;
	if (!calculated)
		myCalculated = InitCalculated();
	else
		myCalculated = calculated;

	std::vector<std::string> collectedVariables;
	exprtk::collect_variables(field->GetExpression(), collectedVariables);

	auto dependentFields = RetrieveFieldsUsingFullName(collectedVariables, tables);
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

std::vector<double> ForgBaseLib::FrgBase_FieldParser::RetrieveValuesFromExpression
(
	const size_t size,
	std::shared_ptr<exprtk::expression<double>> expression
)
{
	std::vector<double> result;

	auto value = expression->value();

	const auto& results = expression->results();
	if (results.count() == 0 || results.count() != size)
	{
		std::string message = "Cannot calculate the value. The size should be equal to " + std::to_string(size);
		std::exception ex(message.c_str());
		throw ex;
	}

	typedef exprtk::results_context<double> results_context_t;
	typedef typename results_context_t::type_store_t type_t;
	typedef typename type_t::scalar_view scalar_t;
	typedef typename type_t::vector_view vector_t;
	typedef typename type_t::string_view string_t;

	//const auto& results = expression->results();

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

double ForgBaseLib::FrgBase_FieldParser::CalcValueScalar
(
	FrgBase_ScalarField* field,
	const std::shared_ptr<Calculated>& calculated
)
{
	auto myExpression = CalcValueEntity(field, calculated);

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
	FrgBase_VectorField_Entity* field,
	const std::shared_ptr<Calculated>& calculated
)
{
	auto myExpression = CalcValueEntity(field, calculated);

	return RetrieveValuesFromExpression(field->GetSize(), myExpression);
}

//std::vector<double> ForgBaseLib::FrgBase_FieldParser::CalcValues
//(
//	const std::string& expression,
//	std::vector<FrgBase_SymbolTable*> symbolTables
//)
//{
//	return std::vector<double>();
//}

std::shared_ptr<ForgBaseLib::FrgBase_FieldParser::Calculated> ForgBaseLib::FrgBase_FieldParser::InitCalculated()
{
	auto calculated = std::make_shared<Calculated>();

	return calculated;
}

//void ForgBaseLib::FrgBase_FieldParser::ClearCalculated(const std::shared_ptr<Calculated>& calculated)
//{
//	if (calculated)
//	{
//		calculated->theFields_.clear();
//	}
//}

bool ForgBaseLib::FrgBase_FieldParser::ContainFieldInCalculated(const std::shared_ptr<Calculated>& calculated, FrgBase_Field_Entity* field)
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

std::string ForgBaseLib::FrgBase_FieldParser::CombineString(const std::vector<std::string>& strs)
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
		value << std::setw(GetM(headers[i])) << std::scientific << std::setprecision(6) << values[i];
	}

	return value.str();
}

ForgBaseLib::FrgBase_Field_Entity* ForgBaseLib::FrgBase_FieldParser::RetrieveFieldUsingFullName
(
	const std::string& variableFullName,
	const std::vector<FrgBase_SymbolTable*>& symbolTables
)
{
	for (const auto& table : symbolTables)
	{
		auto field = table->ContainsField(variableFullName);
		if (field)
			return field;
	}

	return nullptr;
}

std::vector<ForgBaseLib::FrgBase_Field_Entity*> ForgBaseLib::FrgBase_FieldParser::RetrieveFieldsUsingFullName
(
	const std::vector<std::string>& variablesFullName,
	const std::vector<FrgBase_SymbolTable*>& symbolTables
)
{
	std::vector<FrgBase_Field_Entity*> fields;

	for (const auto& variableFullName : variablesFullName)
	{
		auto field = RetrieveFieldUsingFullName(variableFullName, symbolTables);
		if (field)
			fields.push_back(field);
	}

	return fields;
}

std::vector<ForgBaseLib::FrgBase_Field_Entity*> ForgBaseLib::FrgBase_FieldParser::RetrieveDependentFields
(
	const FrgBase_Field_Entity* const field,
	const std::vector<FrgBase_SymbolTable*>& symbolTables
)
{
	std::vector<std::string> collectedVariables;
	exprtk::collect_variables(field->GetExpression(), collectedVariables);

	auto dependentFields = RetrieveFieldsUsingFullName(collectedVariables, symbolTables);

	return dependentFields;
}

std::vector<ForgBaseLib::FrgBase_Field_Entity*> ForgBaseLib::FrgBase_FieldParser::RetrieveFieldsUsingThisField
(
	const FrgBase_Field_Entity* const field,
	const std::vector<FrgBase_SymbolTable*>& symbolTables
)
{
	std::vector<FrgBase_Field_Entity*> result;

	for (const auto& t : symbolTables)
	{
		for (const auto& f : t->GetFields())
		{
			for (const auto& df : RetrieveDependentFields(f, symbolTables))
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

//std::vector<ForgBaseLib::FrgBase_Field_Entity*> ForgBaseLib::FrgBase_FieldParser::RetrieveDependentFields
//(
//	FrgBase_Field_Entity* field
//)
//{
//	std::vector<FrgBase_Field_Entity*> fields;
//
//	if (!field)
//		return fields;
//
//	for (const auto& table : field->RetrieveSymbolTables())
//	{
//		if (table->ContainsField(field))
//			fields.push_back(field);
//	}
//
//	return fields;
//}
//
//std::vector<ForgBaseLib::FrgBase_Field_Entity*> ForgBaseLib::FrgBase_FieldParser::RetrieveDependentFields
//(
//	const std::string& fieldFullName,
//	const std::vector<FrgBase_SymbolTable*>& symbolTables
//)
//{
//	std::vector<FrgBase_Field_Entity*> fields;
//
//	if (fieldFullName.empty())
//		return fields;
//
//	for (const auto& table : symbolTables)
//	{
//		int i = 0;
//
//		auto field = table->ContainsField(fieldFullName);
//		if (field)
//			fields.push_back(field);
//	}
//
//	return fields;
//}