#include <FrgBase_PrptsVrntInt.hxx>

ForgBaseLib::FrgBase_PrptsVrntInt::FrgBase_PrptsVrntInt
(
	const char* displayName,
	int value,
	int min, int max,
	int step,
	const char* prefix,
	const char* suffix
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