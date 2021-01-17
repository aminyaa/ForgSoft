#pragma once
#ifndef _FrgCAD_DlgOneValue_Header
#define _FrgCAD_DlgOneValue_Header

#include <FrgCAD_DlgEntity.hxx>

class QLabel;
class QLineEdit;

BeginForgCADLib

class FORGCAD_EXPORT FrgCAD_DlgOneValue
	: public ForgCADLib::FrgCAD_DlgEntity
{

	Q_OBJECT

public:

	FrgCAD_DlgOneValue(const QString& label, QWidget* parent = nullptr);

	void SetFocused(bool condition = true) override;

	void SetValue(std::vector<double> values) override;

protected:

	void FormDlg() override;

Q_SIGNALS:

	void ValueChangedSignal(double);

protected:

	QLabel* theLabel_ = nullptr;
	QLineEdit* theValueLineEdit_ = nullptr;
};

EndForgCADLib

#endif // !_FrgCAD_DlgOneValue_Header
