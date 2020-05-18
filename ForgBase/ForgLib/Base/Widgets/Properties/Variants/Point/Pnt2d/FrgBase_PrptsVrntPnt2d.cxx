#include <FrgBase_PrptsVrntPnt2d.hxx>
#include <FrgBase_Pnt2d.hxx>

ForgBaseLib::FrgBase_PrptsVrntPnt2d::FrgBase_PrptsVrntPnt2d
(
	const char* displayName,
	ForgBaseLib::FrgBase_Pnt2d* value,
	const char* prefix,
	const char* suffix
)
	: FrgBase_PrptsVrntOneValue<FrgBase_Pnt2d*, false>(displayName, value, prefix, suffix)
{

}

void ForgBaseLib::FrgBase_PrptsVrntPnt2d::SetXValue(double x)
{
	GetValue()->X() = x;
	ValueChanged();
}

void ForgBaseLib::FrgBase_PrptsVrntPnt2d::SetYValue(double y)
{
	GetValue()->Y() = y;
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