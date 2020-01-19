#pragma once
#ifndef _FrgBase_PrptsEditorInt_Header
#define _FrgBase_PrptsEditorInt_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsEditorBase.hxx>

class QSpinBox;

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsEditorInt
	: public FrgBase_PrptsEditorBase
{
	Q_OBJECT

public:

	FrgBase_PrptsEditorInt(QWidget* parent = nullptr);

	int GetMaximumValue() const;
	void SetMaximumValue(int value);
	int GetMinimumValue() const;
	void SetMinimumValue(int value);
	int GetValue() const;
	void SetValue(int value);
	int GetStep() const;
	void SetStep(int step);
	
	QString GetSuffix() const;
	void SetSuffix(const QString& text);

signals:

	void editingFinished();

protected:

	void mouseReleaseEvent(QMouseEvent *event) override;
	void keyReleaseEvent(QKeyEvent *event) override;

private:

	QSpinBox* theSpinBox_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsEditorInt_Header
