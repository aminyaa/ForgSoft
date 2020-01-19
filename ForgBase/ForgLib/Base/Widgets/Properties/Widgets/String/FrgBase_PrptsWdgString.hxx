#pragma once
#ifndef _FrgBase_PrptsWdgString_Header
#define _FrgBase_PrptsWdgString_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgOneValue.hxx>

class QLineEdit;
class QLabel;

BeginForgBaseLib

class FrgBase_PrptsVrntString;

class FORGBASE_EXPORT FrgBase_PrptsWdgString
	: public FrgBase_PrptsWdgOneValue<QString>
{
	Q_OBJECT

public:

	FrgBase_PrptsWdgString(QWidget* parent = nullptr, FrgBase_PrptsVrntString* variant = nullptr);

	void SetValue(const QString& value) override;

	void SetPrefix(const char* prefix) override;
	void SetSuffix(const char* suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<QString>& variant) override;

	void FormWidget();

signals:

	void valueChanged(const QString&);

private:

	QLineEdit* theLineEdit_ = nullptr;
	QLabel* thePrefixLabel_ = nullptr;
	QLabel* theSuffixLabel_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgString_Header
