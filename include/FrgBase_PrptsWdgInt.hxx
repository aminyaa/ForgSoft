#pragma once
#ifndef _FrgBase_PrptsWdgInt_Header
#define _FrgBase_PrptsWdgInt_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgOneValue.hxx>

class QSpinBox;
class QLabel;
class QEvent;
class QObject;

BeginForgBaseLib

class FrgBase_PrptsVrnt;

class FORGBASE_EXPORT FrgBase_PrptsWdgInt
	: public FrgBase_PrptsWdgOneValue<int>
{
	Q_OBJECT

public:

	FrgBase_PrptsWdgInt
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgInt();

	void SetValue(const int& value) override;
	const int& GetMinimumValue() const;
	void SetMinimumValue(const int& value);
	const int& GetMaximumValue() const;
	void SetMaxmimumValue(const int& value);
	const int& GetStepValue() const;
	void SetStepValue(const int& stepValue);

	void SetPrefix(const QString& prefix) override;
	void SetSuffix(const QString& suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<int>& variant) override;

	void FormWidget() override;

protected:

	bool event(QEvent *event) override;
	bool eventFilter(QObject *obj, QEvent *event) override;

private slots:

	void DisplayNameChangedSlot(const QString& displayName);
	void ValueChangedSlot(const int& value);
	void MinimumValueChangedSlot(const int& value);
	void MaximumValueChangedSlot(const int& value);
	void StepValueChangedSlot(const int& value);
	void PrefixChangedSlot(const QString& prefix);
	void SuffixChangedSlot(const QString& suffix);
	void WdgValueChangedSlot();

private:

	QSpinBox* theSpinBox_ = nullptr;
	QLabel* thePrefixLabel_ = nullptr;
	QLabel* theSuffixLabel_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgInt_Header
