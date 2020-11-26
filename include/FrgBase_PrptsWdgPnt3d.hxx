#pragma once
#ifndef _FrgBase_PrptsWdgPnt3d_Header
#define _FrgBase_PrptsWdgPnt3d_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgOneValue.hxx>

class QLineEdit;
class QLabel;

BeginForgBaseLib

class FrgBase_Pnt3d;

class FORGBASE_EXPORT FrgBase_PrptsWdgPnt3d
	: public FrgBase_PrptsWdgOneValue<FrgBase_Pnt3d*, false>
{

	Q_OBJECT

public:

	FrgBase_PrptsWdgPnt3d
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgPnt3d();

	void SetValue(FrgBase_Pnt3d* const& value) override;

	void SetPrefix(const QString& prefix) override;
	void SetSuffix(const QString& suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<FrgBase_Pnt3d*, false>& variant) override;

	void FormWidget() override;

	bool eventFilter(QObject *watched, QEvent *event) override;

private slots:

	void DisplayNameChangedSlot(const QString& displayName);
	void ValueChangedSlot(FrgBase_Pnt3d* value);
	void PrefixChangedSlot(const QString& prefix);
	void SuffixChangedSlot(const QString& suffix);

	void XPrefixLabelChangedSlot(const QString&);
	void YPrefixLabelChangedSlot(const QString&);
	void ZPrefixLabelChangedSlot(const QString&);

	void XSuffixLabelChangedSlot(const QString&);
	void YSuffixLabelChangedSlot(const QString&);
	void ZSuffixLabelChangedSlot(const QString&);

	void WdgXValueChangedSlot();
	void WdgYValueChangedSlot();
	void WdgZValueChangedSlot();

private:

	QLineEdit* theXLineEdit_ = nullptr;
	QLineEdit* theYLineEdit_ = nullptr;
	QLineEdit* theZLineEdit_ = nullptr;

	QLabel* thePrefixLabel_ = nullptr;
	QLabel* theSuffixLabel_ = nullptr;

	QLabel* theXPrefixLabel_ = nullptr;
	QLabel* theYPrefixLabel_ = nullptr;
	QLabel* theZPrefixLabel_ = nullptr;

	QLabel* theXSuffixLabel_ = nullptr;
	QLabel* theYSuffixLabel_ = nullptr;
	QLabel* theZSuffixLabel_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgPnt3d_Header
