#pragma once
#ifndef _FrgBase_PrptsWdgCombo_Header
#define _FrgBase_PrptsWdgCombo_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgOneValue.hxx>

class QComboBox;
class QLabel;

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsWdgCombo
	: public FrgBase_PrptsWdgOneValue<const char*, false>
{
	Q_OBJECT

public:

	FrgBase_PrptsWdgCombo
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgCombo();

	void SetValue(const char* const & value) override;

	void SetPrefix(const char* prefix) override;
	void SetSuffix(const char* suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<const char*, false>& variant) override;

	void FormWidget();

private slots:

	void DisplayNameChangedSlot(const char* displayName);
	void ValueChangedSlot(const char* value);
	void PrefixChangedSlot(const char* prefix);
	void SuffixChangedSlot(const char* suffix);
	void WdgValueChangedSlot(const QString& value);

private:

	QComboBox* theComboBox_ = nullptr;
	QLabel* thePrefixLabel_ = nullptr;
	QLabel* theSuffixLabel_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgCombo_Header
