#include <FrgBase_Field.hxx>
#include <FrgBase_ScalarField.hxx>

ForgBaseLib::FrgBase_Field_Entity::FrgBase_Field_Entity()
{

}

void ForgBaseLib::FrgBase_Field_Entity::CalcValue(const std::shared_ptr<FrgBase_FieldParser::Calculated>& calculated)
{
	if (theIsCalculating_)
	{
		theIsCalculating_ = false;

		std::exception ex("Cannot calculate the value. Recursive Loop!");
		throw ex;
	}

	theIsCalculating_ = true;

	//std::cout << "Calculating " << GetFullPresentationName() << std::endl;

	if (IsScalar())
	{
		const auto& scalarField = dynamic_cast<FrgBase_ScalarField*>(this);
		auto value = FrgBase_FieldParser::CalcValue(scalarField, calculated);
		scalarField->GetValueRef() = value;
	}
	else if (IsVector())
	{

	}

	//std::cout << GetFullPresentationName() << " Calculated." << std::endl;

	theIsCalculating_ = false;
}

std::string ForgBaseLib::FrgBase_Field_Entity::GetFullPresentationName(const std::string& delimiter) const
{
	if (theSymbolTable_)
		return theSymbolTable_->GetFullPresentationName(delimiter) + delimiter + thePresentationName_;

	return thePresentationName_;
}

std::string ForgBaseLib::FrgBase_Field_Entity::GetFullName(const std::string& delimiter) const
{
	if (theSymbolTable_)
		return theSymbolTable_->GetFullName(delimiter) + delimiter + theName_;

	return theName_;
}

std::vector<ForgBaseLib::FrgBase_SymbolTable*> ForgBaseLib::FrgBase_Field_Entity::RetrieveSymbolTables() const
{
	std::vector<FrgBase_SymbolTable*> tables;

	FrgBase_SymbolTable* base = theSymbolTable_;
	while (base)
	{
		tables.push_back(theSymbolTable_);

		base = theSymbolTable_->GetParentSymbolTable();
	}

	return tables;
}

std::vector<ForgBaseLib::FrgBase_SymbolTable*> ForgBaseLib::FrgBase_Field_Entity::RetrieveExternalSymbolTables() const
{
	std::vector<FrgBase_SymbolTable*> result;
	std::vector<std::vector<FrgBase_SymbolTable*>> resultIn;

	auto tables = theSymbolTable_->GetExternalSymbolTables();
	FrgBase_SymbolTable* base = theSymbolTable_;

	while (!tables.empty())
	{
		resultIn.push_back(tables);

		base = base->GetParentSymbolTable();
		if (base)
			tables = base->GetExternalSymbolTables();
		else
			break;
	}

	for (const auto x : resultIn)
		for (const auto& y : x)
			result.push_back(y);

	return result;
}

std::vector<ForgBaseLib::FrgBase_SymbolTable*> ForgBaseLib::FrgBase_Field_Entity::RetrieveSymbolTablesIncludingExternals() const
{
	std::vector<FrgBase_SymbolTable*> result;

	auto tables = RetrieveSymbolTables();
	auto tablesEx = RetrieveExternalSymbolTables();

	for (const auto x : tables)
		result.push_back(x);
	for (const auto x : tablesEx)
		result.push_back(x);

	return result;
}