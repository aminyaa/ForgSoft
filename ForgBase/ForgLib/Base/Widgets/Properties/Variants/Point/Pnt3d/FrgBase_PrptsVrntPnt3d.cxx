#include <FrgBase_PrptsVrntPnt3d.hxx>
#include <FrgBase_Pnt3d.hxx>

ForgBaseLib::FrgBase_PrptsVrntPnt3d::FrgBase_PrptsVrntPnt3d
(
	const QString& displayName,
	ForgBaseLib::FrgBase_Pnt3d* value,
	const QString& prefix,
	const QString& suffix
)
	: FrgBase_PrptsVrntOneValue<FrgBase_Pnt3d*, false>(displayName, value, prefix, suffix)
{

}

void ForgBaseLib::FrgBase_PrptsVrntPnt3d::SetXValue(double x)
{
	GetValue()->X() = x;
	ValueChanged();
}

void ForgBaseLib::FrgBase_PrptsVrntPnt3d::SetYValue(double y)
{
	GetValue()->Y() = y;
	ValueChanged();
}

void ForgBaseLib::FrgBase_PrptsVrntPnt3d::SetZValue(double z)
{
	GetValue()->Z() = z;
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

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_PrptsVrntPnt3d)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_PrptsVrntOneValue<FrgBase_Pnt3d*, false>>(*this);

	ar& theXPrefixLabel_;
	ar& theYPrefixLabel_;
	ar& theZPrefixLabel_;

	ar& theXSuffixLabel_;
	ar& theYSuffixLabel_;
	ar& theZSuffixLabel_;
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_PrptsVrntPnt3d)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_PrptsVrntOneValue<FrgBase_Pnt3d*, false>>(*this);

	ar& theXPrefixLabel_;
	ar& theYPrefixLabel_;
	ar& theZPrefixLabel_;

	ar& theXSuffixLabel_;
	ar& theYSuffixLabel_;
	ar& theZSuffixLabel_;
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_PrptsVrntPnt3d)