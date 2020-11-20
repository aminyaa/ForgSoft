#include <FrgBase_PrptsVrntDouble.hxx>
#include <FrgBase_SerialSpec_QString.hxx>

ForgBaseLib::FrgBase_PrptsVrntDouble::FrgBase_PrptsVrntDouble
(
	const QString& displayName,
	double value,
	double min,
	double max,
	double step,
	const QString& prefix,
	const QString& suffix
)
	: FrgBase_PrptsVrntOneValue<double>(displayName, value, min, max, step, prefix, suffix)
{

}

void ForgBaseLib::FrgBase_PrptsVrntDouble::DisplayNameChanged()
{
	emit DisplayNameChangedSignal(GetDisplayName());
}

void ForgBaseLib::FrgBase_PrptsVrntDouble::ValueChanged()
{
	emit ValueChangedSignal(GetValue());
}

void ForgBaseLib::FrgBase_PrptsVrntDouble::MinimumValueChanged()
{
	emit MinimumValueChangedSignal(GetMinimumValue());
}

void ForgBaseLib::FrgBase_PrptsVrntDouble::MaximumValueChanged()
{
	emit MaximumValueChangedSignal(GetMaximumValue());
}

void ForgBaseLib::FrgBase_PrptsVrntDouble::StepValueChanged()
{
	emit StepValueChangedSignal(GetStepValue());
}

void ForgBaseLib::FrgBase_PrptsVrntDouble::PrefixChanged()
{
	emit PrefixChangedSignal(GetPrefix());
}

void ForgBaseLib::FrgBase_PrptsVrntDouble::SuffixChanged()
{
	emit SuffixChangedSignal(GetSuffix());
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_PrptsVrntDouble)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_PrptsVrntOneValue<double>>(*this);
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_PrptsVrntDouble)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_PrptsVrntOneValue<double>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_PrptsVrntDouble)