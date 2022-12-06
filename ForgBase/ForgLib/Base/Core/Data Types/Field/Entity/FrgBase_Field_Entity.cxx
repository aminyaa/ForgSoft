#include <FrgBase_Field_Entity.hxx>
#include <FrgBase_ScalarField.hxx>
#include <FrgBase_VectorField.hxx>
#include <FrgBase_SymbolTableRegistry.hxx>
#include <FrgBase_SymbolTable.hxx>
#include <FrgBase_FieldTools.hxx>

#include <exprtk.hpp>

ForgBaseLib::FrgBase_Field_Entity::FrgBase_Field_Entity()
{

}

ForgBaseLib::FrgBase_Field_Entity::~FrgBase_Field_Entity()
{
	if(IsScalar())
		theSymbolTable_->GetSymbolTable()->remove_variable(GetFullName());
	else if(IsVector())
		theSymbolTable_->GetSymbolTable()->remove_vector(GetFullName());
}

void ForgBaseLib::FrgBase_Field_Entity::CalcValue
(
	const std::shared_ptr<FrgBase_FieldParser::Calculated>& calculated
)
{
	if (theIsCalculating_)
	{
		theIsCalculating_ = false;

		std::string message =
			"Cannot calculate the value. Recursive Loop in calculating \"" +
			this->GetFullPresentationName(".", true) + "\"";

		std::exception ex(message.c_str());
		throw ex;
	}

	if (FrgBase_FieldParser::ContainFieldInCalculated(calculated, this->shared_from_this()))
		return;
}

std::string ForgBaseLib::FrgBase_Field_Entity::GetFullPresentationName
(
	const std::string& delimiter,
	const bool pure
) const
{
	std::string name = (pure ? thePresentationName_ : theName_);

	if (theSymbolTable_)
		return theSymbolTable_->GetFullPresentationName(delimiter) + delimiter + name;

	return name;
}

std::string ForgBaseLib::FrgBase_Field_Entity::GetFullName
(
	const std::string& delimiter
) const
{
	if (theSymbolTable_)
		return theSymbolTable_->GetFullName(delimiter) + delimiter + theName_;

	return theName_;
}

void ForgBaseLib::FrgBase_Field_Entity::SetExpression
(
	const std::string& expression
)
{
	// This will check recursive loop.Throws exception if there was a problem.
	FrgBase_FieldParser::CheckRecursiveLoop
	(
		this->shared_from_this(),
		expression
	);

	theExpression_ = expression;
}

std::vector<std::shared_ptr<ForgBaseLib::FrgBase_SymbolTable>>
ForgBaseLib::FrgBase_Field_Entity::RetrieveSymbolTables() const
{
	std::vector<std::shared_ptr<FrgBase_SymbolTable>> tables;

	auto base = theSymbolTable_;
	while (base)
	{
		tables.push_back(base);

		base = base->GetParentSymbolTable();
	}

	return tables;
}

std::vector<std::shared_ptr<ForgBaseLib::FrgBase_SymbolTable>>
ForgBaseLib::FrgBase_Field_Entity::RetrieveExternalSymbolTables() const
{
	std::vector<std::shared_ptr<FrgBase_SymbolTable>> result;
	std::vector<std::vector<std::shared_ptr<FrgBase_SymbolTable>>> resultIn;

	auto tables = theSymbolTable_->GetExternalSymbolTables();
	auto base = theSymbolTable_;

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

std::vector<std::shared_ptr<ForgBaseLib::FrgBase_SymbolTable>>
ForgBaseLib::FrgBase_Field_Entity::RetrieveSymbolTablesIncludingExternals() const
{
	std::vector<std::shared_ptr<FrgBase_SymbolTable>> result;

	auto tables = RetrieveSymbolTables();
	auto tablesEx = RetrieveExternalSymbolTables();

	for (const auto x : tables)
		result.push_back(x);
	for (const auto x : tablesEx)
		result.push_back(x);

	return result;
}

bool ForgBaseLib::FrgBase_Field_Entity::IsDeletable() const
{
	auto pointer =
		std::const_pointer_cast<FrgBase_Field_Entity>(this->shared_from_this());

	auto fields =
		FrgBase_FieldParser::RetrieveFieldsUsingThisField
		(
			pointer,
			theSymbolTable_->GetRegistry()->GetTables()
		);

	return fields.empty();
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_Field_Entity)
{
	ar& boost::serialization::base_object<FrgBase_Object>(*this);

	ar& thePresentationName_;
	ar& theExpression_;
	ar& thePresentationExpression_;

	ar& theSymbolTable_;
	ar& theRegistry_;
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_Field_Entity)
{
	ar& boost::serialization::base_object<FrgBase_Object>(*this);

	ar& thePresentationName_;
	ar& theExpression_;
	ar& thePresentationExpression_;

	ar& theSymbolTable_;
	ar& theRegistry_;
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_Field_Entity)