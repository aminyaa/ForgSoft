#include "FrgBase_PrptsWdgOneValue.hxx"
#pragma once

template<typename Type, bool IsBounded>
inline ForgBaseLib::FrgBase_PrptsWdgOneValue<Type, IsBounded>::FrgBase_PrptsWdgOneValue
(
	QWidget * parent,
	ForgBaseLib::FrgBase_PrptsVrnt* variant
)
	: FrgBase_PrptsWdg(parent, variant)
{

}

template<typename Type, bool IsBounded>
inline ForgBaseLib::FrgBase_PrptsWdgOneValue<Type, IsBounded>::~FrgBase_PrptsWdgOneValue()
{
	theVariant_ = nullptr;
}

template<typename Type, bool IsBounded>
inline const Type& ForgBaseLib::FrgBase_PrptsWdgOneValue<Type, IsBounded>::GetValue() const
{
	return static_cast<FrgBase_PrptsVrntOneValue<Type, IsBounded>*>(theVariant_)->GetValue();
}

template<typename Type, bool IsBounded>
inline void ForgBaseLib::FrgBase_PrptsWdgOneValue<Type, IsBounded>::SetValue(const Type& value)
{
	static_cast<FrgBase_PrptsVrntOneValue<Type, IsBounded>*>(theVariant_)->SetValue(value);
}

template<typename Type, bool IsBounded>
inline const QString& ForgBaseLib::FrgBase_PrptsWdgOneValue<Type, IsBounded>::GetPrefix() const
{
	return static_cast<FrgBase_PrptsVrntOneValue<Type, IsBounded>*>(theVariant_)->GetPrefix();
}

template<typename Type, bool IsBounded>
inline void ForgBaseLib::FrgBase_PrptsWdgOneValue<Type, IsBounded>::SetPrefix(const QString& prefix)
{
	static_cast<FrgBase_PrptsVrntOneValue<Type, IsBounded>*>(theVariant_)->SetPrefix(prefix);
}

template<typename Type, bool IsBounded>
inline const QString& ForgBaseLib::FrgBase_PrptsWdgOneValue<Type, IsBounded>::GetSuffix() const
{
	return static_cast<FrgBase_PrptsVrntOneValue<Type, IsBounded>*>(theVariant_)->GetSuffix();
}

template<typename Type, bool IsBounded>
inline void ForgBaseLib::FrgBase_PrptsWdgOneValue<Type, IsBounded>::SetSuffix(const QString& suffix)
{
	static_cast<FrgBase_PrptsVrntOneValue<Type, IsBounded>*>(theVariant_)->SetSuffix(suffix);
}

template<typename Type, bool IsBounded>
inline const ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>& ForgBaseLib::FrgBase_PrptsWdgOneValue<Type, IsBounded>::GetVariant() const
{
	return *static_cast<FrgBase_PrptsVrntOneValue<Type, IsBounded>*>(theVariant_);
}

template<typename Type, bool IsBounded>
inline void ForgBaseLib::FrgBase_PrptsWdgOneValue<Type, IsBounded>::SetVariant(const ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>& variant)
{
	static_cast<FrgBase_PrptsVrntOneValue<Type, IsBounded>*>(theVariant_)->SetVariant(variant);
}
