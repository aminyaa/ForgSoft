#pragma once
#ifndef _FrgBase_PrptsWdgBool_Header
#define _FrgBase_PrptsWdgBool_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgOneValue.hxx>

class QCheckBox;
class QLabel;

BeginForgBaseLib

class FrgBase_PrptsVrnt;

class FORGBASE_EXPORT FrgBase_PrptsWdgBool
	: public FrgBase_PrptsWdgOneValue<bool, false>
{

	Q_OBJECT

public:

	FrgBase_PrptsWdgBool
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgBool();

	void SetValue(const bool& value) override;

	void SetPrefix(const QString& prefix) override;
	void SetSuffix(const QString& suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<bool, false>& variant) override;

	QCheckBox* GetCheckBox() const { return theCheckBox_; }

	void FormWidget() override;

private slots:

	void DisplayNameChangedSlot(const QString& displayName);
	void ValueChangedSlot(const bool& value);
	void PrefixChangedSlot(const QString& prefix);
	void SuffixChangedSlot(const QString& suffix);
	void WdgValueChangedSlot(bool checked);

protected:

	//void mouseReleaseEvent(QMouseEvent *event) override;
	//bool eventFilter(QObject *obj, QEvent *event) override;

private slots:

private:

	QCheckBox* theCheckBox_ = nullptr;
	QLabel* thePrefixLabel_ = nullptr;
	QLabel* theSuffixLabel_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgBool_Header
