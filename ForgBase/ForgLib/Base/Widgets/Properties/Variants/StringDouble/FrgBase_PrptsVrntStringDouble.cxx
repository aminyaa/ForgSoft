#include <FrgBase_PrptsVrntStringDouble.hxx>

ForgBaseLib::FrgBase_PrptsVrntStringDouble::FrgBase_PrptsVrntStringDouble
(
	const QString& displayName,
	double value,
	const QString& prefix,
	const QString& suffix
)
	: FrgBase_PrptsVrntOneValue<double, false>(displayName, value, prefix, suffix)
	, theIsStepped_(false)
	, theStepValue_(0.01L)
	, theIsLimited_(false)
	, theMinimumValue_(0.0L)
	, theMaximumValue_(0.0L)
{

}

void ForgBaseLib::FrgBase_PrptsVrntStringDouble::DisplayNameChanged()
{
	emit DisplayNameChangedSignal(GetDisplayName());
}

void ForgBaseLib::FrgBase_PrptsVrntStringDouble::ValueChanged()
{
	emit ValueChangedSignal(GetValue());
}

void ForgBaseLib::FrgBase_PrptsVrntStringDouble::PrefixChanged()
{
	emit PrefixChangedSignal(GetPrefix());
}

void ForgBaseLib::FrgBase_PrptsVrntStringDouble::SuffixChanged()
{
	emit SuffixChangedSignal(GetSuffix());
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_PrptsVrntStringDouble)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_PrptsVrntOneValue<double, false>>(*this);

	ar& theIsStepped_;
	ar& theStepValue_;

	ar& theIsLimited_;
	ar& theMinimumValue_;
	ar& theMaximumValue_;
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_PrptsVrntStringDouble)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_PrptsVrntOneValue<double, false>>(*this);

	ar& theIsStepped_;
	ar& theStepValue_;

	ar& theIsLimited_;
	ar& theMinimumValue_;
	ar& theMaximumValue_;
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_PrptsVrntStringDouble)