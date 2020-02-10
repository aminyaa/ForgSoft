#include <FrgBase_PrptsVrntBool.hxx>

ForgBaseLib::FrgBase_PrptsVrntBool::FrgBase_PrptsVrntBool
(
	const char * displayName,
	bool value,
	const char * prefix,
	const char * suffix
)
	: FrgBase_PrptsVrntOneValue<bool, false>(displayName, value, prefix, suffix)
{

}

void ForgBaseLib::FrgBase_PrptsVrntBool::DisplayNameChanged()
{
	emit DisplayNameChangedSignal(GetDisplayName());
}

void ForgBaseLib::FrgBase_PrptsVrntBool::ValueChanged()
{
	emit ValueChangedSignal(GetValue());
}

void ForgBaseLib::FrgBase_PrptsVrntBool::PrefixChanged()
{
	emit PrefixChangedSignal(GetPrefix());
}

void ForgBaseLib::FrgBase_PrptsVrntBool::SuffixChanged()
{
	emit SuffixChangedSignal(GetSuffix());
}