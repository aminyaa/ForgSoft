#pragma once
#ifndef _FrgBase_PrptsWdgOneValue_Header
#define _FrgBase_PrptsWdgOneValue_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>

#include <QtWidgets/QWidget>

BeginForgBaseLib

template <typename T>
class FORGBASE_EXPORT FrgBase_PrptsWdgOneValue
	: public QWidget
{

public:
	
	FrgBase_PrptsWdgOneValue(QWidget* parent = nullptr, FrgBase_PrptsVrntOneValue<T>* variant = nullptr);

	virtual const T& GetValue() const;
	virtual void SetValue(const T& value);

	virtual const char* GetPrefix() const;
	virtual void SetPrefix(const char* prefix);
	virtual const char* GetSuffix() const;
	virtual void SetSuffix(const char* suffix);

	virtual const FrgBase_PrptsVrntOneValue<T>& GetVariant() const;
	virtual void SetVariant(const FrgBase_PrptsVrntOneValue<T>& variant);

protected:

	FrgBase_PrptsVrntOneValue<T>* theVariant_ = nullptr;
};

EndForgBaseLib

#include <FrgBase_PrptsWdgOneValueI.hxx>

#endif // !_FrgBase_PrptsWdgOneValue_Header
