#pragma once
#ifndef _FrgBase_PrptsWdgStringDouble_Header
#define _FrgBase_PrptsWdgStringDouble_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgOneValue.hxx>

class QLineEdit;
class QLabel;
class QDoubleValidator;

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsWdgStringDouble
	: public FrgBase_PrptsWdgOneValue<double, false>
{
	Q_OBJECT

public:

	FrgBase_PrptsWdgStringDouble
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgStringDouble();

	void SetValue(const double& value) override;

	void SetPrefix(const QString& prefix) override;
	void SetSuffix(const QString& suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<double, false>& variant) override;

	void FormWidget() override;

	bool eventFilter(QObject* watched, QEvent* event) override;

Q_SIGNALS:

	void EditingFinishedSignal();

public slots:

	void DisplayNameChangedSlot(const QString& displayName);
	void ValueChangedSlot(const double& value);
	void PrefixChangedSlot(const QString& prefix);
	void SuffixChangedSlot(const QString& suffix);

	void WdgValueChangedSlot();

	void LimitedChangedSlot(const bool&);
	void MinimumValueChangedSlot(const double&);
	void MaximumValueChangedSlot(const double&);

protected:

	QLineEdit* theLineEdit_ = nullptr;

	QLabel* thePrefixLabel_ = nullptr;
	QLabel* theSuffixLabel_ = nullptr;

	QDoubleValidator* theDoubleValidator_ = nullptr;

	bool theInClearFocus_ = false;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgStringDouble_Header
