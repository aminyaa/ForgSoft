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
	: public FrgBase_PrptsWdgOneValue<QString, false>
{
	Q_OBJECT

public:

	FrgBase_PrptsWdgString
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrntString* variant = nullptr
	);

	~FrgBase_PrptsWdgString();

	void SetValue(const QString& value) override;

	void SetPrefix(const char* prefix) override;
	void SetSuffix(const char* suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<QString, false>& variant) override;

	void FormWidget();

private slots:

	void DisplayNameChangedSlot(const char* displayName);
	void ValueChangedSlot(const QString& value);
	void PrefixChangedSlot(const char* prefix);
	void SuffixChangedSlot(const char* suffix);
	void WdgValueChangedSlot();

private:

	QLineEdit* theLineEdit_ = nullptr;
	QLabel* thePrefixLabel_ = nullptr;
	QLabel* theSuffixLabel_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgString_Header
