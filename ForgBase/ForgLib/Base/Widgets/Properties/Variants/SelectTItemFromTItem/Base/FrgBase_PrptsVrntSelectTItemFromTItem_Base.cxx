#include <FrgBase_PrptsVrntSelectTItemFromTItem_Base.hxx>
#include <FrgBase_TreeItem.hxx>

ForgBaseLib::FrgBase_PrptsVrntSelectTItemFromTItem_Base::FrgBase_PrptsVrntSelectTItemFromTItem_Base
(
	const QString& displayName /*= ""*/,
	FrgBase_TreeItem* tItem /*= nullptr*/,
	const QString& prefix /*= ""*/,
	const QString& suffix /*= "" */
)
	: FrgBase_PrptsVrntOneValue(displayName, tItem, prefix, suffix)
{

}

std::vector<ForgBaseLib::FrgBase_TreeItem*> ForgBaseLib::FrgBase_PrptsVrntSelectTItemFromTItem_Base::GetParentTItems() const
{
	std::vector<FrgBase_TreeItem*> result;

	if (theParentTItemsFunction_)
	{
		result = theParentTItemsFunction_();
	}

	return std::move(result);
}

void ForgBaseLib::FrgBase_PrptsVrntSelectTItemFromTItem_Base::DisplayNameChanged()
{
	emit DisplayNameChangedSignal(GetDisplayName());
}

void ForgBaseLib::FrgBase_PrptsVrntSelectTItemFromTItem_Base::ValueChanged()
{
	emit ValueChangedSignal(GetValue());
}

void ForgBaseLib::FrgBase_PrptsVrntSelectTItemFromTItem_Base::PrefixChanged()
{
	emit PrefixChangedSignal(GetPrefix());
}

void ForgBaseLib::FrgBase_PrptsVrntSelectTItemFromTItem_Base::SuffixChanged()
{
	emit SuffixChangedSignal(GetSuffix());
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_PrptsVrntSelectTItemFromTItem_Base)
{
	ar& boost::serialization::base_object<FrgBase_PrptsVrntOneValue<FrgBase_TreeItem*, false>>(*this);
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_PrptsVrntSelectTItemFromTItem_Base)
{
	ar& boost::serialization::base_object<FrgBase_PrptsVrntOneValue<FrgBase_TreeItem*, false>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_PrptsVrntSelectTItemFromTItem_Base)