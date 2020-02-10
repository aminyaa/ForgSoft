#include <FrgBase_PrptsVrntString.hxx>

ForgBaseLib::FrgBase_PrptsVrntString::FrgBase_PrptsVrntString
(
	const char* displayName,
	const QString & value,
	const char * prefix,
	const char * suffix
)
	: FrgBase_PrptsVrntOneValue<QString, false>(displayName, value, prefix, suffix)
{
	
}

void ForgBaseLib::FrgBase_PrptsVrntString::DisplayNameChanged()
{
	emit DisplayNameChangedSignal(GetDisplayName());
}

void ForgBaseLib::FrgBase_PrptsVrntString::ValueChanged()
{
	emit ValueChangedSignal(GetValue());
}

void ForgBaseLib::FrgBase_PrptsVrntString::PrefixChanged()
{
	emit PrefixChangedSignal(GetPrefix());
}

void ForgBaseLib::FrgBase_PrptsVrntString::SuffixChanged()
{
	emit SuffixChangedSignal(GetSuffix());
}