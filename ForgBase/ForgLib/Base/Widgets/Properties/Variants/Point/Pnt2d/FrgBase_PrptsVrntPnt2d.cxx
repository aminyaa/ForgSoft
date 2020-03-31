#include <FrgBase_PrptsVrntPnt2d.hxx>

ForgBaseLib::FrgBase_PrptsVrntPnt2d::FrgBase_PrptsVrntPnt2d
(
	const char* displayName,
	ForgBaseLib::Pnt2d_Data* value,
	const char* prefix,
	const char* suffix
)
	: FrgBase_PrptsVrntOneValue<Pnt2d_Data*, false>(displayName, value, prefix, suffix)
{

}

void ForgBaseLib::FrgBase_PrptsVrntPnt2d::SetXValue(double x)
{
	GetValue()->theX_ = x;
	ValueChanged();
}

void ForgBaseLib::FrgBase_PrptsVrntPnt2d::SetYValue(double y)
{
	GetValue()->theY_ = y;
	ValueChanged();
}

void ForgBaseLib::FrgBase_PrptsVrntPnt2d::DisplayNameChanged()
{
	emit DisplayNameChangedSignal(GetDisplayName());
}

void ForgBaseLib::FrgBase_PrptsVrntPnt2d::ValueChanged()
{
	emit ValueChangedSignal(GetValue());
}

void ForgBaseLib::FrgBase_PrptsVrntPnt2d::PrefixChanged()
{
	emit PrefixChangedSignal(GetPrefix());
}

void ForgBaseLib::FrgBase_PrptsVrntPnt2d::SuffixChanged()
{
	emit SuffixChangedSignal(GetSuffix());
}