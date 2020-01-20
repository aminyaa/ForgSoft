#include "FrgBase_PrptsWdgOneValue.hxx"
#pragma once

template<typename Type, bool IsBounded>
inline ForgBaseLib::FrgBase_PrptsWdgOneValue<Type, IsBounded>::FrgBase_PrptsWdgOneValue(QWidget * parent, ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>* variant)
	: QWidget(parent)
	, theVariant_(variant)
{

}

template<typename Type, bool IsBounded>
inline const Type& ForgBaseLib::FrgBase_PrptsWdgOneValue<Type, IsBounded>::GetValue() const
{
	return theVariant_->GetValue();
}

template<typename Type, bool IsBounded>
inline void ForgBaseLib::FrgBase_PrptsWdgOneValue<Type, IsBounded>::SetValue(const Type& value)
{
	theVariant_->SetValue(value);
}

template<typename Type, bool IsBounded>
inline const char * ForgBaseLib::FrgBase_PrptsWdgOneValue<Type, IsBounded>::GetPrefix() const
{
	return theVariant_->GetPrefix();
}

template<typename Type, bool IsBounded>
inline void ForgBaseLib::FrgBase_PrptsWdgOneValue<Type, IsBounded>::SetPrefix(const char * prefix)
{
	theVariant_->SetPrefix(prefix);
}

template<typename Type, bool IsBounded>
inline const char * ForgBaseLib::FrgBase_PrptsWdgOneValue<Type, IsBounded>::GetSuffix() const
{
	return theVariant_->GetSuffix();
}

template<typename Type, bool IsBounded>
inline void ForgBaseLib::FrgBase_PrptsWdgOneValue<Type, IsBounded>::SetSuffix(const char * suffix)
{
	theVariant_->SetSuffix(suffix);
}

template<typename Type, bool IsBounded>
inline const ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>& ForgBaseLib::FrgBase_PrptsWdgOneValue<Type, IsBounded>::GetVariant() const
{
	return *theVariant_;
}

template<typename Type, bool IsBounded>
inline void ForgBaseLib::FrgBase_PrptsWdgOneValue<Type, IsBounded>::SetVariant(const ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>& variant)
{
	theVariant_->SetVariant(variant);
}
