#include "FrgBase_SymbolTableRegistries.hxx"
#include <FrgBase_SymbolTableRegistry.hxx>

ForgBaseLib::FrgBase_SymbolTableRegistries::FrgBase_SymbolTableRegistries()
	: ForgBaseLib::FrgBase_Object()
{

}

std::shared_ptr<ForgBaseLib::FrgBase_SymbolTableRegistry>
ForgBaseLib::FrgBase_SymbolTableRegistries::CreateRegistry()
{
	auto registry =
		std::make_shared<FrgBase_SymbolTableRegistry>();

	AddRegistry(registry);

	return registry;
}

void ForgBaseLib::FrgBase_SymbolTableRegistries::AddRegistry
(
	const std::shared_ptr<FrgBase_SymbolTableRegistry>& registry
)
{
	if (!registry)
		return;

	if (ContainsRegistry(registry))
		return;

	const int index = theRegistries_.size();

	std::string tableName = "Registry" + std::to_string(index);

	registry->SetParentRegistries(this->shared_from_this());
	registry->SetName(tableName);
	registry->SetIndex(index);

	theRegistries_.push_back(registry);
}

void ForgBaseLib::FrgBase_SymbolTableRegistries::RemoveRegistry
(
	const std::shared_ptr<FrgBase_SymbolTableRegistry>& registry
)
{
	if (!registry)
		return;

	std::vector<std::shared_ptr<FrgBase_SymbolTableRegistry>> finalRegistries;
	for (const auto& r : theRegistries_)
	{
		if (r != registry)
			finalRegistries.push_back(r);
	}

	theRegistries_ = finalRegistries;
}

bool ForgBaseLib::FrgBase_SymbolTableRegistries::ContainsRegistry
(
	const std::shared_ptr<FrgBase_SymbolTableRegistry>& registry
)
{
	if (!registry)
		return false;

	for (const auto& r : theRegistries_)
	{
		if (r == registry)
			return true;
	}

	return false;
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_SymbolTableRegistries)
{
	ar& boost::serialization::base_object<FrgBase_Object>(*this);

	ar& theRegistries_;
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_SymbolTableRegistries)
{
	ar& boost::serialization::base_object<FrgBase_Object>(*this);

	ar& theRegistries_;
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_SymbolTableRegistries)