#pragma once
#ifndef _FrgBase_DlgDelete_Header
#define _FrgBase_DlgDelete_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Dlg.hxx>

class QVBoxLayout;
class QHBoxLayout;
class QPushButton;
class QLabel;
class QKeyEvent;
class QShowEvent;

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_DlgDelete
	: public FrgBase_Dlg
{
	Q_OBJECT

private:

	QVBoxLayout* theMainLayout_ = NullPtr;
	QHBoxLayout* theButtonsLayout_ = NullPtr;

	QPushButton* theYesButton_ = NullPtr;
	QPushButton* theNoButton_ = NullPtr;

	QLabel* theMessage_ = NullPtr;

	QString theCurrentName_ = "";

	void setupLayout();

public:

	FrgBase_DlgDelete
	(
		const QString& currentName,
		FrgBase_MainWindow* parentMainWindow
	);

	~FrgBase_DlgDelete();

private slots:

	void onOK();

protected:

	void keyPressEvent(QKeyEvent* event) override;
};

EndForgBaseLib

#endif // !_FrgBase_DlgDelete_Header
