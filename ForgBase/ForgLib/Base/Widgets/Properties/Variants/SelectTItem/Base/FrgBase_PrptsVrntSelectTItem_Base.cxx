#include <FrgBase_PrptsVrntSelectTItem_Base.hxx>

ForgBaseLib::FrgBase_PrptsVrntSelectTItem_Base::FrgBase_PrptsVrntSelectTItem_Base
(
	const char* displayName,
	FrgBase_TreeItem* tItem,
	const char* prefix,
	const char* suffix
)
	: FrgBase_PrptsVrntOneValue(displayName, tItem, prefix, suffix)
{

}

void ForgBaseLib::FrgBase_PrptsVrntSelectTItem_Base::DisplayNameChanged()
{
	emit DisplayNameChangedSignal(GetDisplayName());
}

void ForgBaseLib::FrgBase_PrptsVrntSelectTItem_Base::ValueChanged()
{
	emit ValueChangedSignal(GetValue());
}

void ForgBaseLib::FrgBase_PrptsVrntSelectTItem_Base::PrefixChanged()
{
	emit PrefixChangedSignal(GetPrefix());
}

void ForgBaseLib::FrgBase_PrptsVrntSelectTItem_Base::SuffixChanged()
{
	emit SuffixChangedSignal(GetSuffix());
}