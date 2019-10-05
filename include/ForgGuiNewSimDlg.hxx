#pragma once
#ifndef _ForgGuiNewSimDlg_Header
#define _ForgGuiNewSimDlg_Header

#include <ForgGuiGlobals.hxx>

#include <QtWidgets/QDialog>

class QGroupBox;
class QVBoxLayout;
class QHBoxLayout;
class QRadioButton;
class QLabel;
class QSpinBox;
class QPushButton;
class QLineEdit;

BeginForgGuiLib

class ForgGuiMainWindow;

class ForgGuiNewSimDlg : public QDialog
{
	Q_OBJECT

private:

	QRadioButton* theRadioBtn1_ = ForgNullPtr;
	QRadioButton* theRadioBtn2_ = ForgNullPtr;
	QVBoxLayout* theLayout_MPI_Group_ = ForgNullPtr;
	QGroupBox* theMPI_GroupBox_ = ForgNullPtr;
	QVBoxLayout* the_Layout_NewSim_ = ForgNullPtr;

	QLabel* theParallelLabel_ = ForgNullPtr;
	QSpinBox* theParallelSpin_ = ForgNullPtr;
	QHBoxLayout* theParallelLayout_ = ForgNullPtr;

	QPushButton* theBtnOK_ = ForgNullPtr;
	QPushButton* theBtnCancel_ = ForgNullPtr;
	QHBoxLayout* theBtnLayout_ = ForgNullPtr;

	void setupLayout();

public:

	ForgGuiNewSimDlg(ForgGuiMainWindow* parent = ForgNullPtr);

	ForgGetMacro(QVBoxLayout*, WindowLayout, the_Layout_NewSim_);

private slots:

	void onOK();

public slots:

	void ShowParallelOptions();

protected:

	void keyPressEvent(QKeyEvent* event);

};

EndForgGuiLib

#endif // !_ForgGuiNewSimDlg_Header
