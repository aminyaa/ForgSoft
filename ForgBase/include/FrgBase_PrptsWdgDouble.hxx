#pragma once
#ifndef _FrgBase_PrptsWdgDouble_Header
#define _FrgBase_PrptsWdgDouble_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgOneValue.hxx>

class QDoubleSpinBox;
class QLabel;

BeginForgBaseLib

class FrgBase_PrptsVrnt;

class FORGBASE_EXPORT FrgBase_PrptsWdgDouble
	: public FrgBase_PrptsWdgOneValue<double>
{
	Q_OBJECT

public:

	FrgBase_PrptsWdgDouble
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgDouble();

	void SetValue(const double& value) override;
	const double& GetMinimumValue() const;
	void SetMinimumValue(const double& value);
	const double& GetMaximumValue() const;
	void SetMaxmimumValue(const double& value);
	const double& GetStepValue() const;
	void SetStepValue(const double& stepValue);

	void SetPrefix(const QString& prefix) override;
	void SetSuffix(const QString& suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<double>& variant) override;

	void FormWidget() override;

private slots:

	void DisplayNameChangedSlot(const QString& displayName);
	void ValueChangedSlot(const double& value);
	void MinimumValueChangedSlot(const double& value);
	void MaximumValueChangedSlot(const double& value);
	void StepValueChangedSlot(const double& value);
	void PrefixChangedSlot(const QString& prefix);
	void SuffixChangedSlot(const QString& suffix);
	void WdgValueChangedSlot();

private:

	QDoubleSpinBox* theSpinBox_ = nullptr;
	QLabel* thePrefixLabel_ = nullptr;
	QLabel* theSuffixLabel_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgDouble_Header
