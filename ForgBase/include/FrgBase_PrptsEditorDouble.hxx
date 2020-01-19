#pragma once
#ifndef _FrgBase_PrptsEditorDouble_Header
#define _FrgBase_PrptsEditorDouble_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsEditorBase.hxx>

class QDoubleSpinBox;

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsEditorDouble
	: public FrgBase_PrptsEditorBase
{
	Q_OBJECT

public:

	FrgBase_PrptsEditorDouble(QWidget* parent = nullptr);

	double GetMaximumValue() const;
	void SetMaximumValue(double value);
	double GetMinimumValue() const;
	void SetMinimumValue(double value);
	double GetValue() const;
	void SetValue(double value);
	double GetStep() const;
	void SetStep(double step);

	QString GetSuffix() const;
	void SetSuffix(const QString& text);

signals:

	void editingFinished();

private:

	QDoubleSpinBox* theSpinBox_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsEditorDouble_Header
