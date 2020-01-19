#pragma once
#ifndef _FrgBase_PrptsVrntOneValue_Header
#define _FrgBase_PrptsVrntOneValue_Header

#include <FrgBase_Global.hxx>

class QString;

BeginForgBaseLib

template <typename T>
class FrgBase_PrptsVrntOneValue
{

public:

	/*==============================================================================================================================*/
	/* using enable_if template for different types*/
	template <typename T1>
	using is_number = std::integral_constant<bool, std::is_same_v<int, T1> || std::is_same_v<double, T1> || std::is_same_v<float, T1>>;

	template <typename T1>
	using resolveNumberType = std::enable_if_t<std::is_same_v<int, T1> || std::is_same_v<double, T1> || std::is_same_v<float, T1>>;

	template <typename T1>
	using resolveIntType = std::enable_if_t<std::is_same_v<int, T1>>;

	template <typename T1>
	using resolveDoubleType = std::enable_if_t<std::is_same_v<double, T1>>;

	template <typename T1>
	using resolveStringType = std::enable_if_t<std::is_same_v<QString, T1>>;
	/*==============================================================================================================================*/
	/* Constructors*/
	template <typename = resolveNumberType<T>>
	FrgBase_PrptsVrntOneValue(T value, T min, T max, T step, const char* prefix, const char* suffix);

	template <typename = resolveStringType<T>>
	FrgBase_PrptsVrntOneValue(T value, const char* prefix, const char* suffix);
	/*==============================================================================================================================*/

	virtual ~FrgBase_PrptsVrntOneValue() {}

	const T& GetValue() const;
	void SetValue(const T& value);

	template <typename = resolveNumberType<T>>
	const T& GetMinimumValue() const;

	template <typename = resolveNumberType<T>>
	void SetMinimumValue(const T& minValue);

	template <typename = resolveNumberType<T>>
	const T& GetMaximumValue() const;

	template <typename = resolveNumberType<T>>
	void SetMaximumValue(const T& maxValue);

	template <typename = resolveNumberType<T>>
	const T& GetStepValue() const;

	template <typename = resolveNumberType<T>>
	void SetStepValue(const T& stepValue);

	const char* GetPrefix() const;
	void SetPrefix(const char* prefix);
	const char* GetSuffix() const;
	void SetSuffix(const char* suffix);

	void SetVariant(const FrgBase_PrptsVrntOneValue<T>& variant);

private:

	T theValue_;

	T theMinValue_;
	T theMaxValue_;
	T theStepValue_;

	const char* thePrefix_ = "";
	const char* theSuffix_ = "";
};

EndForgBaseLib

#include <FrgBase_PrptsVrntOneValueI.hxx>

#endif // !_FrgBase_PrptsVrntOneValue_Header
