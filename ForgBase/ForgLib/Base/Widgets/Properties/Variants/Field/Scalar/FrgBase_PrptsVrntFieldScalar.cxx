#include <FrgBase_PrptsVrntFieldScalar.hxx>

ForgBaseLib::FrgBase_PrptsVrntFieldScalar::FrgBase_PrptsVrntFieldScalar
(
	const QString& displayName,
	double value,
	const QString& prefix,
	const QString& suffix
)
	: FrgBase_PrptsVrntOneValue<double, false>(displayName, value, prefix, suffix)
{
	theShowNonParentalParameters_ = true;
}

void ForgBaseLib::FrgBase_PrptsVrntFieldScalar::DisplayNameChanged()
{
	emit DisplayNameChangedSignal(GetDisplayName());
}

void ForgBaseLib::FrgBase_PrptsVrntFieldScalar::ValueChanged()
{
	emit ValueChangedSignal(GetValue());
}

void ForgBaseLib::FrgBase_PrptsVrntFieldScalar::PrefixChanged()
{
	emit PrefixChangedSignal(GetPrefix());
}

void ForgBaseLib::FrgBase_PrptsVrntFieldScalar::SuffixChanged()
{
	emit SuffixChangedSignal(GetSuffix());
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_PrptsVrntFieldScalar)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_PrptsVrntOneValue<double, false>>(*this);
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_PrptsVrntFieldScalar)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_PrptsVrntOneValue<double, false>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_PrptsVrntFieldScalar)