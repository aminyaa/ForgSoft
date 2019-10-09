#pragma once
#ifndef _FrgBaseDlgNewSim_Header
#define _FrgBaseDlgNewSim_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QDialog>

class QGroupBox;
class QVBoxLayout;
class QHBoxLayout;
class QRadioButton;
class QLabel;
class QSpinBox;
class QPushButton;
class QLineEdit;

BeginFrgBaseLib

class FrgBaseMainWindow;

class FORGBASE_EXPORT FrgBaseDlgNewSim : public QDialog
{
	Q_OBJECT

private:

	QRadioButton* theRadioBtn1_ = FrgNullPtr;
	QRadioButton* theRadioBtn2_ = FrgNullPtr;
	QVBoxLayout* theLayout_MPI_Group_ = FrgNullPtr;
	QGroupBox* theMPI_GroupBox_ = FrgNullPtr;
	QVBoxLayout* the_Layout_NewSim_ = FrgNullPtr;

	QLabel* theParallelLabel_ = FrgNullPtr;
	QSpinBox* theParallelSpin_ = FrgNullPtr;
	QHBoxLayout* theParallelLayout_ = FrgNullPtr;

	QPushButton* theBtnOK_ = FrgNullPtr;
	QPushButton* theBtnCancel_ = FrgNullPtr;
	QHBoxLayout* theBtnLayout_ = FrgNullPtr;

	void setupLayout();

public:

	FrgBaseDlgNewSim(FrgBaseMainWindow* parent = FrgNullPtr);

	QVBoxLayout* GetWindowLayout() const
	{
		return the_Layout_NewSim_;
	}

	QVBoxLayout*& GetWindowLayout()
	{
		return the_Layout_NewSim_;
	}

private slots:

	void onOK();

public slots:

	void ShowParallelOptions();

protected:

	void keyPressEvent(QKeyEvent* event);
};

EndFrgBaseLib

#endif // !_FrgBaseDlgNewSim_Header
