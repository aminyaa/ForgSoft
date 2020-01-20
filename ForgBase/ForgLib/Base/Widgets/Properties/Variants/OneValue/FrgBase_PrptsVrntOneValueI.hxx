#pragma once

template <typename Type, bool IsBounded>
template <typename>
inline ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::FrgBase_PrptsVrntOneValue
(
	const char* displayName,
	Type value,
	Type min,
	Type max,
	Type step,
	const char * prefix,
	const char * suffix
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
	const char* displayName,
	Type value,
	const char * prefix,
	const char * suffix
)
	: theDisplayName_(displayName)
	, theValue_(value)
	, thePrefix_(prefix)
	, theSuffix_(suffix)
{

}

template<typename Type, bool IsBounded>
inline const char * ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::GetDisplayName() const
{
	return theDisplayName_;
}

template<typename Type, bool IsBounded>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::SetDisplayName(const char * name)
{
	theDisplayName_ = name;
}

template<typename Type, bool IsBounded>
inline const Type& ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::GetValue() const
{
	return theValue_;
}

template<typename Type, bool IsBounded>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::SetValue(const Type & value)
{
	theValue_ = value;
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
}

template<typename Type, bool IsBounded>
inline const char * ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::GetPrefix() const
{
	return thePrefix_;
}

template<typename Type, bool IsBounded>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::SetPrefix(const char * prefix)
{
	thePrefix_ = prefix;
}

template<typename Type, bool IsBounded>
inline const char * ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::GetSuffix() const
{
	return theSuffix_;
}

template<typename Type, bool IsBounded>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::SetSuffix(const char * suffix)
{
	theSuffix_ = suffix;
}

template<typename Type, bool IsBounded>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>::SetVariant(const FrgBase_PrptsVrntOneValue & variant)
{
	theDisplayName_ = variant.GetDisplayName();
	theValue_ = variant.GetValue();

	if constexpr (is_number<Type>::value)
	{
		theMinValue_ = variant.GetMinimumValue();
		theMaxValue_ = variant.GetMaximumValue();
		theStepValue_ = variant.GetStepValue();
	}

	thePrefix_ = variant.GetPrefix();
	theSuffix_ = variant.GetSuffix();
}