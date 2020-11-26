#pragma once
#ifndef _FrgBase_PrptsWdgCombo_Header
#define _FrgBase_PrptsWdgCombo_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgOneValue.hxx>

class QComboBox;
class QLabel;

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsWdgCombo
	: public FrgBase_PrptsWdgOneValue<QString, false>
{
	Q_OBJECT

public:

	FrgBase_PrptsWdgCombo
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgCombo();

	void SetValue(const QString& value) override;

	void SetPrefix(const QString& prefix) override;
	void SetSuffix(const QString& suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<QString, false>& variant) override;

	void FormWidget() override;

private slots:

	void DisplayNameChangedSlot(const QString& displayName);
	void ValueChangedSlot(const QString& value);
	void PrefixChangedSlot(const QString& prefix);
	void SuffixChangedSlot(const QString& suffix);
	void WdgValueChangedSlot(const QString& value);

private:

	QComboBox* theComboBox_ = nullptr;
	QLabel* thePrefixLabel_ = nullptr;
	QLabel* theSuffixLabel_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgCombo_Header
