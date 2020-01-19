#include "FrgBase_PrptsWdgOneValue.hxx"
#pragma once

template<typename T>
inline ForgBaseLib::FrgBase_PrptsWdgOneValue<T>::FrgBase_PrptsWdgOneValue(QWidget * parent, ForgBaseLib::FrgBase_PrptsVrntOneValue<T>* variant)
	: QWidget(parent)
	, theVariant_(variant)
{

}

template<typename T>
inline const T& ForgBaseLib::FrgBase_PrptsWdgOneValue<T>::GetValue() const
{
	return theVariant_->GetValue();
}

template<typename T>
inline void ForgBaseLib::FrgBase_PrptsWdgOneValue<T>::SetValue(const T& value)
{
	theVariant_->SetValue(value);
}

template<typename T>
inline const char * ForgBaseLib::FrgBase_PrptsWdgOneValue<T>::GetPrefix() const
{
	return theVariant_->GetPrefix();
}

template<typename T>
inline void ForgBaseLib::FrgBase_PrptsWdgOneValue<T>::SetPrefix(const char * prefix)
{
	theVariant_->SetPrefix(prefix);
}

template<typename T>
inline const char * ForgBaseLib::FrgBase_PrptsWdgOneValue<T>::GetSuffix() const
{
	return theVariant_->GetSuffix();
}

template<typename T>
inline void ForgBaseLib::FrgBase_PrptsWdgOneValue<T>::SetSuffix(const char * suffix)
{
	theVariant_->SetSuffix(suffix);
}

template<typename T>
inline const ForgBaseLib::FrgBase_PrptsVrntOneValue<T>& ForgBaseLib::FrgBase_PrptsWdgOneValue<T>::GetVariant() const
{
	return *theVariant_;
}

template<typename T>
inline void ForgBaseLib::FrgBase_PrptsWdgOneValue<T>::SetVariant(const ForgBaseLib::FrgBase_PrptsVrntOneValue<T>& variant)
{
	theVariant_->SetVariant(variant);
}
