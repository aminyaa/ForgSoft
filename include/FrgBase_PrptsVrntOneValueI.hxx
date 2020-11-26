#pragma once

template<typename Type, bool IsBounded>
inline ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::FrgBase_PrptsVrntOneValue()
{

}

template <typename Type, bool IsBounded>
template <typename>
inline ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::FrgBase_PrptsVrntOneValue
(
	const QString& displayName,
	Type value,
	Type min,
	Type max,
	Type step,
	const QString& prefix,
	const QString& suffix
)
	: theDisplayName_(displayName)
	, theValue_(value)
	, theMinValue_(min)
	, theMaxValue_(max)
	, theStepValue_(step)
	, thePrefix_(prefix)
	, theSuffix_(suffix)
{

}

template<typename Type, bool IsBounded>
template<typename>
inline ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::FrgBase_PrptsVrntOneValue
(
	const QString& displayName,
	Type value,
	const QString& prefix,
	const QString& suffix
)
	: theDisplayName_(displayName)
	, theValue_(value)
	, thePrefix_(prefix)
	, theSuffix_(suffix)
{

}

template<typename Type, bool IsBounded>
inline const QString& ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::GetDisplayName() const
{
	return theDisplayName_;
}

template<typename Type, bool IsBounded>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::SetDisplayName(const QString& name)
{
	theDisplayName_ = name;
	DisplayNameChanged();
}

template<typename Type, bool IsBounded>
inline const Type& ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::GetValue() const
{
	return theValue_;
}

template<typename Type, bool IsBounded>
inline Type& ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::GetValueRef()
{
	return theValue_;
}

template<typename Type, bool IsBounded>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::GetValue(Type& output)
{
	output = theValue_;
}

template<typename Type, bool IsBounded>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::SetValue(const Type & value)
{
	theValue_ = value;
	ValueChanged();
}

template<typename Type, bool IsBounded>
template<typename>
inline const Type & ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::GetMinimumValue() const
{
	return theMinValue_;
}

template<typename Type, bool IsBounded>
template<typename>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::SetMinimumValue(const Type & minValue)
{
	theMinValue_ = minValue;
	MinimumValueChanged();
}

template<typename Type, bool IsBounded>
template<typename>
inline const Type & ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::GetMaximumValue() const
{
	return theMaxValue_;
}

template<typename Type, bool IsBounded>
template<typename>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::SetMaximumValue(const Type & maxValue)
{
	theMaxValue_ = maxValue;
	MaximumValueChanged();
}

template<typename Type, bool IsBounded>
template<typename>
inline const Type & ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::GetStepValue() const
{
	return theStepValue_;
}

template<typename Type, bool IsBounded>
template<typename>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::SetStepValue(const Type & stepValue)
{
	theStepValue_ = stepValue;
	StepValueChanged();
}

template<typename Type, bool IsBounded>
inline const QString& ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::GetPrefix() const
{
	return thePrefix_;
}

template<typename Type, bool IsBounded>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::SetPrefix(const QString& prefix)
{
	thePrefix_ = prefix;
	PrefixChanged();
}

template<typename Type, bool IsBounded>
inline const QString& ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::GetSuffix() const
{
	return theSuffix_;
}

template<typename Type, bool IsBounded>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::SetSuffix(const QString& suffix)
{
	theSuffix_ = suffix;
	SuffixChanged();
}

template<typename Type, bool IsBounded>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::SetVariant(const FrgBase_PrptsVrntOneValue & variant)
{
	theDisplayName_ = variant.GetDisplayName();
	theValue_ = variant.GetValue();

	//if constexpr (is_number<Type>::value)
	if constexpr (IsBounded)
	{
		theMinValue_ = variant.GetMinimumValue();
		theMaxValue_ = variant.GetMaximumValue();
		theStepValue_ = variant.GetStepValue();
	}

	thePrefix_ = variant.GetPrefix();
	theSuffix_ = variant.GetSuffix();
}