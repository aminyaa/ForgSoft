#include <FrgBase_FieldParser.hxx>
#include <FrgBase_SymbolTable.hxx>
#include <FrgBase_ScalarField.hxx>

#include <exprtk.hpp>

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

double ForgBaseLib::FrgBase_FieldParser::CalcValue
(
	FrgBase_ScalarField* field,
	const std::shared_ptr<Calculated>& calculated
)
{
	auto tables = field->RetrieveSymbolTablesIncludingExternals();

	auto myExpression = CompileExpression(field->GetExpression(), tables);

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

	auto value = myExpression->value();

	auto results = myExpression->results();
	if (results.count() > 0)
	{
		std::exception ex("Cannot calculate the value. The size is bigger than 1.");
		throw ex;
	}

	return value;
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
	for (const auto& f : calculated->theFields_)
	{
		if (f == field)
			return true;
	}

	return false;
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