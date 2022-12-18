#include <FrgBase_SymbolTableRegistry.hxx>
#include <FrgBase_SymbolTable.hxx>
#include <FrgBase_SymbolTableRegistries.hxx>

#include <sstream>

ForgBaseLib::FrgBase_SymbolTableRegistry::FrgBase_SymbolTableRegistry()
{
	
}

ForgBaseLib::FrgBase_SymbolTableRegistry::~FrgBase_SymbolTableRegistry()
{
	theTables_.clear();
}

std::shared_ptr<ForgBaseLib::FrgBase_SymbolTable>
ForgBaseLib::FrgBase_SymbolTableRegistry::CreateTable
(
	const std::string& presentationName
)
{
	auto table = std::make_shared<FrgBase_SymbolTable>();
	table->SetPresentationName(presentationName);

	AddTable(table);

	return table;
}

void ForgBaseLib::FrgBase_SymbolTableRegistry::AddTable
(
	const std::shared_ptr<FrgBase_SymbolTable>& table
)
{
	if (!table)
		return;

	if (ContainsTable(table))
		return;

	const int index = theTables_.size();

	std::string tableName = "Table" + std::to_string(index);

	table->SetRegistry(this->shared_from_this());
	table->SetName(tableName);
	table->SetIndex(index);
	table->SetPresentationName(table->GetPresentationName());

	theTables_.push_back(table);
}

void ForgBaseLib::FrgBase_SymbolTableRegistry::ClearTables()
{
	theTables_.clear();
}

void ForgBaseLib::FrgBase_SymbolTableRegistry::RemoveTable
(
	const std::shared_ptr<FrgBase_SymbolTable>& table
)
{
	if (!table)
		return;

	std::vector<std::shared_ptr<FrgBase_SymbolTable>> finalTables;
	for (const auto& t : theTables_)
	{
		if (t != table)
			finalTables.push_back(t);
	}

	theTables_ = finalTables;
}

bool ForgBaseLib::FrgBase_SymbolTableRegistry::ContainsTable
(
	const std::shared_ptr<FrgBase_SymbolTable>& table
)
{
	if (!table)
		return false;

	for (const auto& t : theTables_)
	{
		if (t == table)
			return true;
	}

	return false;
}

void ForgBaseLib::FrgBase_SymbolTableRegistry::Print
(
	std::ostringstream& ss,
	bool calcValue
)
{
	auto calculated = FrgBase_FieldParser::InitCalculated();

	for (const auto& table : theTables_)
	{
		if (calcValue)
			table->CalcValue(calculated);

		table->Print(ss, false);
	}
}

std::string ForgBaseLib::FrgBase_SymbolTableRegistry::Print(bool calcValue)
{
	std::ostringstream ss;
	Print(ss, calcValue);

	return ss.str();
}

void ForgBaseLib::FrgBase_SymbolTableRegistry::Print
(
	std::ostream& out,
	bool calcValue
)
{
	auto str = Print(calcValue);

	out << str;
}

std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Field_Entity>>
ForgBaseLib::FrgBase_SymbolTableRegistry::GetAllFields() const
{
	std::vector<std::shared_ptr<FrgBase_Field_Entity>> result;
	for (const auto& table : theTables_)
	{
		const auto& fields = table->GetFields();
		for (const auto& field : fields)
			result.push_back(field);
	}

	return result;
}

std::vector<std::shared_ptr<ForgBaseLib::FrgBase_ScalarField>>
ForgBaseLib::FrgBase_SymbolTableRegistry::GetAllScalarFields() const
{
	std::vector<std::shared_ptr<FrgBase_ScalarField>> result;
	for (const auto& table : theTables_)
	{
		auto fields = table->GetScalarFields();
		for (const auto& field : fields)
			result.push_back(field);
	}

	return result;
}

std::vector<std::shared_ptr<ForgBaseLib::FrgBase_VectorField>>
ForgBaseLib::FrgBase_SymbolTableRegistry::GetAllVectorFields() const
{
	std::vector<std::shared_ptr<FrgBase_VectorField>> result;
	for (const auto& table : theTables_)
	{
		auto fields = table->GetVectorFields();
		for (const auto& field : fields)
			result.push_back(field);
	}

	return result;
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_SymbolTableRegistry)
{
	ar& boost::serialization::base_object<FrgBase_Object>(*this);

	ar& theTables_;
	ar& theParentRegistries_;
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_SymbolTableRegistry)
{
	ar& boost::serialization::base_object<FrgBase_Object>(*this);

	ar& theTables_;
	ar& theParentRegistries_;
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_SymbolTableRegistry)