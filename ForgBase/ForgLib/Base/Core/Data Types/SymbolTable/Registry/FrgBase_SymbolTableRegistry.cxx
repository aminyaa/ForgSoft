#include <FrgBase_SymbolTableRegistry.hxx>
#include <FrgBase_SymbolTable.hxx>

#include <sstream>

unsigned int ForgBaseLib::FrgBase_SymbolTableRegistry::theRegistryIndex_ = 0;

ForgBaseLib::FrgBase_SymbolTableRegistry::FrgBase_SymbolTableRegistry()
{
	this->SetName("Registry" + std::to_string(theRegistryIndex_));
	theRegistryIndex_++;
}

ForgBaseLib::FrgBase_SymbolTableRegistry::~FrgBase_SymbolTableRegistry()
{
	theTables_.clear();

	/*for (const auto& t : theTables_)
		delete t;*/
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

	std::string tableName = "Table" + std::to_string(theTableIndex_);

	table->SetRegistry(this->shared_from_this());
	table->SetName(tableName);
	table->SetPresentationName(table->GetPresentationName());

	theTableIndex_++;

	theTables_.push_back(table);
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

	for (auto t : theTables_)
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