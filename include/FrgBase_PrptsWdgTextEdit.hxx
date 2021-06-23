#pragma once
#ifndef _FrgBase_PrptsWdgTextEdit_Header
#define _FrgBase_PrptsWdgTextEdit_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgOneValue.hxx>

class QTextEdit;
class QLabel;

BeginForgBaseLib

class FrgBase_PrptsVrnt;

class FORGBASE_EXPORT FrgBase_PrptsWdgTextEdit
	: public FrgBase_PrptsWdgOneValue<QString, false>
{

	Q_OBJECT

public:

	FrgBase_PrptsWdgTextEdit
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgTextEdit();

	void SetValue(const QString& value) override;

	void SetPrefix(const QString& prefix) override;
	void SetSuffix(const QString& suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<QString, false>& variant) override;

	QTextEdit* GetTextEdit() const { return theTextEdit_; }

	void FormWidget() override;

private slots:

	void DisplayNameChangedSlot(const QString& displayName);
	void ValueChangedSlot(const QString& value);
	void PrefixChangedSlot(const QString& prefix);
	void SuffixChangedSlot(const QString& suffix);
	void WdgValueChangedSlot();

protected:

	//void mouseReleaseEvent(QMouseEvent *event) override;
	//bool eventFilter(QObject *obj, QEvent *event) override;

private slots:

private:

	QTextEdit* theTextEdit_ = nullptr;
	QLabel* thePrefixLabel_ = nullptr;
	QLabel* theSuffixLabel_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgTextEdit_Header
