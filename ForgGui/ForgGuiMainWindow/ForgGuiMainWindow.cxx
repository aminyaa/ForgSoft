#include <ForgGuiMainWindow.hxx>
#include <ForgGuiNewSimDlg.hxx>
#include <ForgGuiLoadSimDlg.hxx>
#include <ForgGuiGlobals_Thread.hxx>

#include <QtWidgets/QMenu>

ForgGuiLib::ForgGuiMainWindow::ForgGuiMainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	theMenus_ = ForgMakeSharedPtr(ForgGuiMenus)(this);
}

void ForgGuiLib::ForgGuiMainWindow::FileNewAction()
{
	ForgSharedPtr<ForgGuiNewSimDlg> dlg = ForgMakeSharedPtr(ForgGuiNewSimDlg)(this);

	if (dlg->exec() == QDialog::Accepted)
	{
		//ParseInfoToConsole("New was clicked!");

		theMenus_->GetFileMenu()->theSaveAction_->setEnabled(true);
		theMenus_->GetFileMenu()->theSaveAsAction_->setEnabled(true);
	}
}

void ForgGuiLib::ForgGuiMainWindow::FileLoadAction()
{
	ForgSharedPtr<ForgGuiLoadSimDlg> dlg = ForgMakeSharedPtr(ForgGuiLoadSimDlg)(this);

	if (dlg->exec() == QDialog::Accepted)
	{
		//ParseInfoToConsole("Load was clicked!");

		theMenus_->GetFileMenu()->theSaveAction_->setEnabled(true);
		theMenus_->GetFileMenu()->theSaveAsAction_->setEnabled(true);
	}
}

void ForgGuiLib::ForgGuiMainWindow::FileSaveAction()
{
}

void ForgGuiLib::ForgGuiMainWindow::FileSaveAsAction()
{
}

void ForgGuiLib::ForgGuiMainWindow::FileSaveAllAction()
{
}

void ForgGuiLib::ForgGuiMainWindow::FileImportAction()
{
}

void ForgGuiLib::ForgGuiMainWindow::FileExportAction()
{
}

void ForgGuiLib::ForgGuiMainWindow::FileExitAction()
{
}