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

class FrgBase_PrptsVrntInt;

class FORGBASE_EXPORT FrgBase_PrptsWdgInt
	: public FrgBase_PrptsWdgOneValue<int>
{
	Q_OBJECT

public:

	FrgBase_PrptsWdgInt(QWidget* parent = nullptr, FrgBase_PrptsVrntInt* variant = nullptr);

	void SetValue(const int& value) override;
	const int& GetMinimumValue() const;
	void SetMinimumValue(const int& value);
	const int& GetMaximumValue() const;
	void SetMaxmimumValue(const int& value);
	const int& GetStepValue() const;
	void SetStepValue(const int& stepValue);

	void SetPrefix(const char* prefix) override;
	void SetSuffix(const char* suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<int>& variant) override;

	void FormWidget();

protected:

	bool event(QEvent *event) override;
	bool eventFilter(QObject *obj, QEvent *event) override;

signals:

	void valueChanged(int);

public slots:

	void editingFinished();

private:

	QSpinBox* theSpinBox_ = nullptr;
	QLabel* thePrefixLabel_ = nullptr;
	QLabel* theSuffixLabel_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgInt_Header