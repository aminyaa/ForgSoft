#pragma once
#ifndef _FrgBase_PrptsVrntOneValue_Header
#define _FrgBase_PrptsVrntOneValue_Header

#include <FrgBase_Global.hxx>

BeginForgBaseLib

template <typename Type, bool IsBounded = true>
class FrgBase_PrptsVrntOneValue
{

public:

	typedef int IntType;
	typedef double DoubleType;
	typedef float FloatType;
	typedef bool  BoolType;

	/*==============================================================================================================================*/
	/* using enable_if template for different types*/
	template <typename T1>
	using is_number = std::integral_constant<bool, std::is_same_v<IntType, T1> || std::is_same_v<DoubleType, T1> || std::is_same_v<FloatType, T1>>;

	template <typename T1>
	using resolveNumberType = std::enable_if_t<std::is_same_v<IntType, T1> || std::is_same_v<DoubleType, T1> || std::is_same_v<FloatType, T1>>;
	/*==============================================================================================================================*/
	/* Constructors*/
	template <typename  = typename std::enable_if_t<IsBounded>>
	FrgBase_PrptsVrntOneValue(const char* displayName, Type value, Type min, Type max, Type step, const char* prefix, const char* suffix);

	template <typename = typename std::enable_if_t<!IsBounded>>
	FrgBase_PrptsVrntOneValue(const char* displayName, Type value, const char* prefix, const char* suffix);
	/*==============================================================================================================================*/

	virtual ~FrgBase_PrptsVrntOneValue() {}

	const char* GetDisplayName() const;
	void SetDisplayName(const char* name);

	const Type& GetValue() const;
	void SetValue(const Type& value);

	template <typename = typename std::enable_if_t<IsBounded>>
	const Type& GetMinimumValue() const;

	template <typename = typename std::enable_if_t<IsBounded>>
	void SetMinimumValue(const Type& minValue);

	template <typename = typename std::enable_if_t<IsBounded>>
	const Type& GetMaximumValue() const;

	template <typename = typename std::enable_if_t<IsBounded>>
	void SetMaximumValue(const Type& maxValue);

	template <typename = typename std::enable_if_t<IsBounded>>
	const Type& GetStepValue() const;

	template <typename = typename std::enable_if_t<IsBounded>>
	void SetStepValue(const Type& stepValue);

	const char* GetPrefix() const;
	void SetPrefix(const char* prefix);
	const char* GetSuffix() const;
	void SetSuffix(const char* suffix);

	void SetVariant(const FrgBase_PrptsVrntOneValue<Type, IsBounded>& variant);

private:

	const char* theDisplayName_ = "";
	Type theValue_;

	Type theMinValue_;
	Type theMaxValue_;
	Type theStepValue_;

	const char* thePrefix_ = "";
	const char* theSuffix_ = "";
};

EndForgBaseLib

#include <FrgBase_PrptsVrntOneValueI.hxx>

#endif // !_FrgBase_PrptsVrntOneValue_Header
