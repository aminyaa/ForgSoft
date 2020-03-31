#include <FrgBase_PrptsVrntColor.hxx>

ForgBaseLib::FrgBase_PrptsVrntColor::FrgBase_PrptsVrntColor
(
	const char* displayName,
	QColor value,
	const char* prefix,
	const char* suffix
)
	: FrgBase_PrptsVrntOneValue(displayName, value, prefix, suffix)
{

}

void ForgBaseLib::FrgBase_PrptsVrntColor::DisplayNameChanged()
{
	emit DisplayNameChangedSignal(GetDisplayName());
}

void ForgBaseLib::FrgBase_PrptsVrntColor::ValueChanged()
{
	emit ValueChangedSignal(GetValue());
}

void ForgBaseLib::FrgBase_PrptsVrntColor::PrefixChanged()
{
	emit PrefixChangedSignal(GetPrefix());
}

void ForgBaseLib::FrgBase_PrptsVrntColor::SuffixChanged()
{
	emit SuffixChangedSignal(GetSuffix());
}