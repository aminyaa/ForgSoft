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