#include <FrgBase_SymbolTable.hxx>
#include <FrgBase_ScalarField.hxx>

#include <exprtk.hpp>

ForgBaseLib::FrgBase_SymbolTable::FrgBase_SymbolTable()
	: FrgBase_Object()
{
	theSymbolTable_ = new exprtk::symbol_table<double>();
}

ForgBaseLib::FrgBase_SymbolTable::~FrgBase_SymbolTable()
{
	FreePointer(theSymbolTable_);
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

	return theName_;
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