#pragma once
#ifndef _FrgBase_PrptsVrntOneValue_Header
#define _FrgBase_PrptsVrntOneValue_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Object.hxx>
#include <FrgBase_Serialization_Global.hxx>
#include <FrgBase_SerialSpec_FrgVariant.hxx>

#include <QtCore/QString>

BeginForgBaseLib

class FrgBase_PrptsVrnt
	: public FrgBase_Object
{

public:

	FrgBase_PrptsVrnt() {}

	virtual ~FrgBase_PrptsVrnt() {}

	virtual const QString& GetDisplayName() const = 0;
	virtual const QString& GetPrefix() const = 0;
	virtual void SetPrefix(const QString& prefix) = 0;
	virtual const QString& GetSuffix() const = 0;
	virtual void SetSuffix(const QString& suffix) = 0;
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
	FrgBase_PrptsVrntOneValue();

	template <typename = typename std::enable_if_t<IsBounded>>
	FrgBase_PrptsVrntOneValue(const QString& displayName, Type value, Type min, Type max, Type step, const QString& prefix, const QString& suffix);

	template <typename = typename std::enable_if_t<!IsBounded>>
	FrgBase_PrptsVrntOneValue(const QString& displayName, Type value, const QString& prefix, const QString& suffix);
	/*==============================================================================================================================*/

	virtual ~FrgBase_PrptsVrntOneValue() {}

	const QString& GetDisplayName() const override;
	void SetDisplayName(const QString& name);

	const Type& GetValue() const;
	Type& GetValueRef();
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

	const QString& GetPrefix() const override;
	void SetPrefix(const QString& prefix) override;
	const QString& GetSuffix() const override;
	void SetSuffix(const QString& suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<Type, IsBounded>& variant);

//private:
//
//	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

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

	QString theDisplayName_ = "";
	Type theValue_;

	Type theMinValue_;
	Type theMaxValue_;
	Type theStepValue_;

	QString thePrefix_ = "";
	QString theSuffix_ = "";
};

EndForgBaseLib

#include <FrgBase_PrptsVrntOneValueI.hxx>

//template<typename Type, bool IsBounded>
//using myArgument = ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>;
//
//namespace boost
//{
//	namespace serialization
//	{
//		
//		template <typename Type, bool IsBounded>
//		struct guid_defined<ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>> : boost::mpl::true_ {};
//
//		
//		template <typename Type, bool IsBounded>
//		inline const char* guid<ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>>()
//		{
//			return "ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>";
//		}
//	} /* serialization */
//} /* boost */

#endif // !_FrgBase_PrptsVrntOneValue_Header
