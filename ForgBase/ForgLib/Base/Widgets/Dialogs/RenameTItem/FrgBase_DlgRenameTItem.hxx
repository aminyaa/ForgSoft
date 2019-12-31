#pragma once
#ifndef _FrgBase_DlgRenameTItem_header
#define _FrgBase_DlgRenameTItem_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Dlg.hxx>

#include <QtCore/QObject>

class QVBoxLayout;
class QHBoxLayout;
class QPushButton;
class QLabel;
class QLineEdit;
class QKeyEvent;
class QShowEvent;

BeginForgBaseLib

class FrgBase_MainWindow;

class FrgBase_DlgRenameTItem
	: public FrgBase_Dlg
{
	Q_OBJECT

private:

	QVBoxLayout* theMainLayout_ = NullPtr;
	QHBoxLayout* theButtonsLayout_ = NullPtr;
	QHBoxLayout* theNameLayout_ = NullPtr;

	QPushButton* theOKButton_ = NullPtr;
	QPushButton* theCloseButton_ = NullPtr;

	QLabel* theNameLabel_ = NullPtr;
	QLineEdit* theNameLineEdit_ = NullPtr;

	QString theCurrentName_ = "";

	void setupLayout() override;

public:

	FrgBase_DlgRenameTItem(const QString& currentName, FrgBase_MainWindow* parentMainWindow);

	QString GetLineEditName() const;

private slots:

	void onOK();

protected:

	void keyPressEvent(QKeyEvent* event) override;
	void showEvent(QShowEvent*) override;
};

EndForgBaseLib

#endif // !_FrgBase_DlgRenameTItem_header
