#include <FrgBase_PrptsVrntInt.hxx>

ForgBaseLib::FrgBase_PrptsVrntInt::FrgBase_PrptsVrntInt
(
	const QString& displayName,
	int value,
	int min, int max,
	int step,
	const QString& prefix,
	const QString& suffix
)
	: FrgBase_PrptsVrntOneValue<int>(displayName, value, min, max, step, prefix, suffix)
{

}

void ForgBaseLib::FrgBase_PrptsVrntInt::DisplayNameChanged()
{
	emit DisplayNameChangedSignal(GetDisplayName());
}

void ForgBaseLib::FrgBase_PrptsVrntInt::ValueChanged()
{
	emit ValueChangedSignal(GetValue());
}

void ForgBaseLib::FrgBase_PrptsVrntInt::MinimumValueChanged()
{
	emit MinimumValueChangedSignal(GetMinimumValue());
}

void ForgBaseLib::FrgBase_PrptsVrntInt::MaximumValueChanged()
{
	emit MaximumValueChangedSignal(GetMaximumValue());
}

void ForgBaseLib::FrgBase_PrptsVrntInt::StepValueChanged()
{
	emit StepValueChangedSignal(GetStepValue());
}

void ForgBaseLib::FrgBase_PrptsVrntInt::PrefixChanged()
{
	emit PrefixChangedSignal(GetPrefix());
}

void ForgBaseLib::FrgBase_PrptsVrntInt::SuffixChanged()
{
	emit SuffixChangedSignal(GetSuffix());
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_PrptsVrntInt)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_PrptsVrntOneValue<int>>(*this);
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_PrptsVrntInt)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_PrptsVrntOneValue<int>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_PrptsVrntInt)