#pragma once
#ifndef _FrgCAD_DlgPoint_Header
#define _FrgCAD_DlgPoint_Header

#include <FrgCAD_DlgEntity.hxx>

class QLabel;
class QLineEdit;

BeginForgCADLib

class FrgCAD_DlgPoint
	: public FrgCAD_DlgEntity
{

	Q_OBJECT

public:

	FrgCAD_DlgPoint(QWidget* parent = nullptr);

	void SetValue(std::vector<double> values) override;

	void SetXValue(double value);
	void SetYValue(double value);

	double GetXValue() const;
	double GetYValue() const;

	void SetFocused(bool condition = true) override;

protected:

	void FormDlg() override;

Q_SIGNALS:

	void XValueChangedSignal(double);
	void YValueChangedSignal(double);

protected:

	struct Data
	{
		QLabel* theLabel_ = nullptr;
		QLineEdit* theLineEdit_ = nullptr;
	};

	Data* theXData_ = nullptr;
	Data* theYData_ = nullptr;
};

EndForgCADLib

#endif // !_FrgCAD_DlgPoint_Header
