#include <FrgBase_PrptsVrntDouble.hxx>

ForgBaseLib::FrgBase_PrptsVrntDouble::FrgBase_PrptsVrntDouble
(
	const char* displayName,
	double value,
	double min,
	double max,
	double step,
	const char * prefix,
	const char * suffix
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