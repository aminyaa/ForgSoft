#pragma once
#ifndef _FrgBase_PrptsVrntOneValue_Header
#define _FrgBase_PrptsVrntOneValue_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Object.hxx>

BeginForgBaseLib

class FrgBase_PrptsVrnt
	: public FrgBase_Object
{

public:

	FrgBase_PrptsVrnt() {}

	virtual ~FrgBase_PrptsVrnt() {}

	virtual const char* GetDisplayName() const { return ""; }
	virtual const char* GetPrefix() const { return ""; }
	virtual void SetPrefix(const char* prefix) {}
	virtual const char* GetSuffix() const { return ""; }
	virtual void SetSuffix(const char* suffix) {}
};

template <typename Type, bool IsBounded = true>
class FrgBase_PrptsVrntOneValue
	: public FrgBase_PrptsVrnt
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

	const char* GetDisplayName() const override;
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

	const char* GetPrefix() const override;
	void SetPrefix(const char* prefix) override;
	const char* GetSuffix() const override;
	void SetSuffix(const char* suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<Type, IsBounded>& variant);

protected:

	virtual void DisplayNameChanged() {}
	virtual void ValueChanged() {}
	virtual void MinimumValueChanged() {}
	virtual void MaximumValueChanged() {}
	virtual void StepValueChanged() {}
	virtual void PrefixChanged() {}
	virtual void SuffixChanged() {}

	void GetValue(Type&);

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
