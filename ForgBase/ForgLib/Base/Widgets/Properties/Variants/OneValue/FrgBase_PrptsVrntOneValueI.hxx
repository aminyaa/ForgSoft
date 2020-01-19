#pragma once

template<typename T>
template <typename>
inline ForgBaseLib::FrgBase_PrptsVrntOneValue<T>::FrgBase_PrptsVrntOneValue
(
	T value,
	T min,
	T max,
	T step,
	const char * prefix,
	const char * suffix
)
	: theValue_(value)
	, theMinValue_(min)
	, theMaxValue_(max)
	, theStepValue_(step)
	, thePrefix_(prefix)
	, theSuffix_(suffix)
{

}

template<typename T>
template<typename>
inline ForgBaseLib::FrgBase_PrptsVrntOneValue<T>::FrgBase_PrptsVrntOneValue(T value, const char * prefix, const char * suffix)
	: theValue_(value)
	, thePrefix_(prefix)
	, theSuffix_(suffix)
{
}

template<typename T>
inline const T& ForgBaseLib::FrgBase_PrptsVrntOneValue<T>::GetValue() const
{
	return theValue_;
}

template<typename T>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<T>::SetValue(const T & value)
{
	theValue_ = value;
}

template<typename T>
template<typename>
inline const T & ForgBaseLib::FrgBase_PrptsVrntOneValue<T>::GetMinimumValue() const
{
	return theMinValue_;
}

template<typename T>
template<typename>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<T>::SetMinimumValue(const T & minValue)
{
	theMinValue_ = minValue;
}

template<typename T>
template<typename>
inline const T & ForgBaseLib::FrgBase_PrptsVrntOneValue<T>::GetMaximumValue() const
{
	return theMaxValue_;
}

template<typename T>
template<typename>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<T>::SetMaximumValue(const T & maxValue)
{
	theMaxValue_ = maxValue;
}

template<typename T>
template<typename>
inline const T & ForgBaseLib::FrgBase_PrptsVrntOneValue<T>::GetStepValue() const
{
	return theStepValue_;
}

template<typename T>
template<typename>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<T>::SetStepValue(const T & stepValue)
{
	theStepValue_ = stepValue;
}

template<typename T>
inline const char * ForgBaseLib::FrgBase_PrptsVrntOneValue<T>::GetPrefix() const
{
	return thePrefix_;
}

template<typename T>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<T>::SetPrefix(const char * prefix)
{
	thePrefix_ = prefix;
}

template<typename T>
inline const char * ForgBaseLib::FrgBase_PrptsVrntOneValue<T>::GetSuffix() const
{
	return theSuffix_;
}

template<typename T>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<T>::SetSuffix(const char * suffix)
{
	theSuffix_ = suffix;
}

template<typename T>
inline void ForgBaseLib::FrgBase_PrptsVrntOneValue<T>::SetVariant(const FrgBase_PrptsVrntOneValue & variant)
{
	theValue_ = variant.GetValue();

	if constexpr (is_number<T>::value)
	{
		theMinValue_ = variant.GetMinimumValue();
		theMaxValue_ = variant.GetMaximumValue();
		theStepValue_ = variant.GetStepValue();
	}

	thePrefix_ = variant.GetPrefix();
	theSuffix_ = variant.GetSuffix();
}