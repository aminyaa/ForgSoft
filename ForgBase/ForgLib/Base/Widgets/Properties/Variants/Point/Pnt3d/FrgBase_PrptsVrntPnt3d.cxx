#include <FrgBase_PrptsVrntPnt3d.hxx>

ForgBaseLib::FrgBase_PrptsVrntPnt3d::FrgBase_PrptsVrntPnt3d
(
	const char* displayName,
	ForgBaseLib::Pnt3d_Data* value,
	const char* prefix,
	const char* suffix
)
	: FrgBase_PrptsVrntOneValue<Pnt3d_Data*, false>(displayName, value, prefix, suffix)
{

}

void ForgBaseLib::FrgBase_PrptsVrntPnt3d::SetXValue(double x)
{
	GetValue()->theX_ = x;
	ValueChanged();
}

void ForgBaseLib::FrgBase_PrptsVrntPnt3d::SetYValue(double y)
{
	GetValue()->theY_ = y;
	ValueChanged();
}

void ForgBaseLib::FrgBase_PrptsVrntPnt3d::SetZValue(double z)
{
	GetValue()->theZ_ = z;
	ValueChanged();
}

void ForgBaseLib::FrgBase_PrptsVrntPnt3d::DisplayNameChanged()
{
	emit DisplayNameChangedSignal(GetDisplayName());
}

void ForgBaseLib::FrgBase_PrptsVrntPnt3d::ValueChanged()
{
	emit ValueChangedSignal(GetValue());
}

void ForgBaseLib::FrgBase_PrptsVrntPnt3d::PrefixChanged()
{
	emit PrefixChangedSignal(GetPrefix());
}

void ForgBaseLib::FrgBase_PrptsVrntPnt3d::SuffixChanged()
{
	emit SuffixChangedSignal(GetSuffix());
}