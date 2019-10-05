#pragma once
#ifndef _ForgGuiLoadSimDlg_Header
#define _ForgGuiLoadSimDlg_Header

#include <ForgGuiGlobals.hxx>
#include <ForgGuiNewSimDlg.hxx>

#include <QtWidgets/QLineEdit>

BeginForgGuiLib

class ForgGuiMainWindow;

class ForgGuiLoadSimDlg : public ForgGuiNewSimDlg
{

	Q_OBJECT

private:

	QLabel* theBrowseLabel_ = ForgNullPtr;
	QLineEdit* theBrowseLineEdit_ = ForgNullPtr;
	QPushButton* theBrowseBtn_ = ForgNullPtr;
	QHBoxLayout* theBrowseLayout_ = ForgNullPtr;

public:

	ForgGuiLoadSimDlg(ForgGuiMainWindow* parent = ForgNullPtr);

	QString GetFileName() const { return theBrowseLineEdit_->text(); }

protected slots:

	void ShowBrowseDialog();
};

EndForgGuiLib

#endif // !_ForgGuiLoadSimDlg_Header
