#include <FrgBase_SymbolTable.hxx>
#include <FrgBase_SymbolTableRegistry.hxx>
#include <FrgBase_ScalarField.hxx>
#include <FrgBase_VectorField.hxx>
#include <FrgBase_FieldParser.hxx>

#include <exprtk.hpp>

ForgBaseLib::FrgBase_SymbolTable::FrgBase_SymbolTable()
	: FrgBase_Object()
{
	theSymbolTable_ = new exprtk::symbol_table<double>();
}

ForgBaseLib::FrgBase_SymbolTable::~FrgBase_SymbolTable()
{
	FreePointer(theSymbolTable_);

	for (const auto& f : theFields_)
		delete f;
}

std::string ForgBaseLib::FrgBase_SymbolTable::GetFullPresentationName(const std::string& delimiter) const
{
	if (theParentSymbolTable_)
		return theParentSymbolTable_->GetFullPresentationName(delimiter) + delimiter + thePresentationName_;

	return thePresentationName_;
}

void ForgBaseLib::FrgBase_SymbolTable::AddExternalSymbolTable(FrgBase_SymbolTable* est)
{
	if (!est)
		return;

	for (const auto& t : theExternalSymbolTables_)
	{
		if (t == est)
			return;
	}

	theExternalSymbolTables_.push_back(est);
}

void ForgBaseLib::FrgBase_SymbolTable::RemoveExternalSymbolTable(FrgBase_SymbolTable* est)
{
	if (!est)
		return;

	std::vector<FrgBase_SymbolTable*> result;

	for (const auto& t : theExternalSymbolTables_)
	{
		if (t == est)
			continue;

		result.push_back(t);
	}

	theExternalSymbolTables_ = result;
}

std::string ForgBaseLib::FrgBase_SymbolTable::GetFullName(const std::string& delimiter) const
{
	if (theParentSymbolTable_)
		return theParentSymbolTable_->GetFullName(delimiter) + delimiter + theName_;

	return theRegistry_->GetName() + delimiter + theName_;
}

ForgBaseLib::FrgBase_ScalarField* ForgBaseLib::FrgBase_SymbolTable::AddVariable(const std::string& presentationName)
{
	if (theSymbolTable_)
	{
		std::string variableName = "Value" + std::to_string(theVariableIndex_);
		std::string variableFullName = GetFullName() + "_" + variableName;

		auto field = new FrgBase_ScalarField();
		field->SetSymbolTable(this);
		field->SetName(variableName);
		field->SetPresentationName(presentationName);
		field->SetExpression("0.0");

		bool added = theSymbolTable_->add_variable(variableFullName, field->GetValueRef());

		if (added)
		{
			theFields_.push_back(field);

			theVariableIndex_++;

			return field;
		}

		FreePointer(field);
	}

	return nullptr;
}

//bool ForgBaseLib::FrgBase_SymbolTable::AddVector(const std::string& vectorName)
//{
//	/*if (theSymbolTable_)
//		return theSymbolTable_->add_vector(vectorName, valuesRef);*/
//
//	return false;
//}

bool ForgBaseLib::FrgBase_SymbolTable::DeleteField(FrgBase_Field_Entity* field)
{
	if (!field)
		return false;

	if (!ContainsField(field))
		return false;

	if (!field->IsDeletable())
	{
		auto uFields = FrgBase_FieldParser::RetrieveFieldsUsingThisField(field, theRegistry_->GetTables());
		std::vector<std::string> uFieldsString;
		for (const auto& x : uFields)
			uFieldsString.push_back(x->GetPresentationName());

		std::exception ex(("Cannot delete the field due to dependency.\n Variables: " + FrgBase_FieldParser::CombineString(uFieldsString)).c_str());
		throw ex;
	}

	std::vector<FrgBase_Field_Entity*> finalFields;
	for (const auto& f : theFields_)
	{
		if (f != field)
			finalFields.push_back(f);
	}

	theFields_ = finalFields;

	delete field;

	return true;
}

bool ForgBaseLib::FrgBase_SymbolTable::ContainsField(FrgBase_Field_Entity* field) const
{
	for (const auto& f : theFields_)
	{
		if (f == field)
			return f;
	}

	return nullptr;
}

ForgBaseLib::FrgBase_Field_Entity* ForgBaseLib::FrgBase_SymbolTable::ContainsField(const std::string& fieldFullName) const
{
	for (const auto& f : theFields_)
	{
		if (f->GetFullName() == fieldFullName)
			return f;
	}

	return nullptr;
}

#define PRINT_ONELINE_CHAR(myString, margin, ss, myChar) \
for (int i = 0; i < myString.size() + margin; i++) \
ss << myChar; \
ss << std::endl;

void ForgBaseLib::FrgBase_SymbolTable::PrintField(std::ostringstream& ss, FrgBase_Field_Entity* field)
{
	if (!field)
		return;

	if (field->IsScalar())
	{
		auto scalarField = dynamic_cast<FrgBase_ScalarField*>(field);
		auto value = scalarField->GetValue();

		auto valueString = FrgBase_FieldParser::CombineValues({ "Value" }, { value });
		ss << FrgBase_FieldParser::CombineString({ scalarField->GetPresentationName(), valueString }) << std::endl;
	}
	else if (field->IsVector())
	{
		auto vectorField = dynamic_cast<FrgBase_VectorField_Entity*>(field);
		auto value = vectorField->GetValue();

		if (value.empty())
			return;

		std::vector<std::string> headerString;
		for (const auto& v : value)
			headerString.push_back(std::to_string(v));

		auto valueString = FrgBase_FieldParser::CombineValues(headerString, value);

		ss << FrgBase_FieldParser::CombineString({vectorField->GetPresentationName(), "[" + valueString + "]"}) << std::endl;
	}
}

std::string ForgBaseLib::FrgBase_SymbolTable::PrintField(FrgBase_Field_Entity* field)
{
	std::ostringstream ss;
	PrintField(ss, field);

	return ss.str();
}

void ForgBaseLib::FrgBase_SymbolTable::PrintField(std::ostream& out, FrgBase_Field_Entity* field)
{
	auto str = PrintField(field);

	out << str;
}

void ForgBaseLib::FrgBase_SymbolTable::Print(std::ostringstream& ss, bool calcValue)
{
	if (theFields_.empty())
	{
		ss << "Table is empty.";
		return;
	}

	int margin = 2;

	auto pName = GetPresentationName();

	ss << std::endl;
	PRINT_ONELINE_CHAR(pName, margin + 2, ss, "=");
	ss <<  pName << std::endl;
	PRINT_ONELINE_CHAR(pName, margin + 2, ss, "=");

	std::vector<std::string> headers = { "Variable", "Value" };
	auto headersInLine = FrgBase_FieldParser::CombineString(headers);
	ss << headersInLine << std::endl;
	PRINT_ONELINE_CHAR(headersInLine, margin, ss, "-");

	if(calcValue)
		CalcValue(FrgBase_FieldParser::InitCalculated());

	for (const auto& field : theFields_)
		PrintField(ss, field);
}

std::string ForgBaseLib::FrgBase_SymbolTable::Print(bool calcValue)
{
	std::ostringstream ss;
	Print(ss, calcValue);

	return ss.str();
}

void ForgBaseLib::FrgBase_SymbolTable::Print(std::ostream& out, bool calcValue)
{
	auto str = Print(calcValue);

	out << str;
}

void ForgBaseLib::FrgBase_SymbolTable::CalcValue(const std::shared_ptr<FrgBase_FieldParser::Calculated>& calculated)
{
	std::shared_ptr<FrgBase_FieldParser::Calculated> myCalculated;
	if (!calculated)
		myCalculated = FrgBase_FieldParser::InitCalculated();
	else
		myCalculated = calculated;

	for (const auto& field : theFields_)
		field->CalcValue(myCalculated);
}

bool ForgBaseLib::FrgBase_SymbolTable::AddVectorToSymbolTable
(
	exprtk::symbol_table<double>* table,
	const std::string& variableFullName,
	std::vector<double>& value
)
{
	if(table)
		return table->add_vector(variableFullName, value);

	return false;
}