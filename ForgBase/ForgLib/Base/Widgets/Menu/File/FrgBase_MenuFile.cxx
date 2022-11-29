#include <FrgBase_MenuFile.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_MenuAction.hxx>

#include <QtWidgets/QMenuBar>

ForgBaseLib::FrgBase_MenuFile::FrgBase_MenuFile
(
	FrgBase_MainWindow* parentMainWindow
)
	: FrgBase_Menu("&File", parentMainWindow)
{
	theNewAction_ = AddItem(ICON_Menu_File_New, FrgString("&New"));
	theLoadAction_ = AddItem(ICON_Menu_File_Load, FrgString("&Load"));
	addSeparator();

	theSaveAction_ = AddItem(ICON_Menu_File_Save, FrgString("&Save"));
	theSaveAsAction_ = AddItem(ICON_Menu_File_SaveAs, FrgString("Save As..."));
	addSeparator();

	theImportAction_ = AddItem(ICON_Menu_File_Import, FrgString("&Import"), false);
	theExportAction_ = AddItem(ICON_Menu_File_Export, FrgString("&Export"), false);
	addSeparator();

	theExitAction_ = AddItem(ICON_Menu_File_Exit, FrgString("E&xit"), false);

	theNewAction_->setShortcut(QMainWindow::tr("Ctrl+N"));
	theLoadAction_->setShortcut(QMainWindow::tr("Ctrl+L"));
	theSaveAction_->setShortcut(QMainWindow::tr("Ctrl+S"));
	theSaveAsAction_->setShortcut(QMainWindow::tr("Ctrl+Shift+S"));

	theImportAction_->setShortcut(QMainWindow::tr("Ctrl+I"));
	theExportAction_->setShortcut(QMainWindow::tr("Ctrl+E"));

	theExitAction_->setShortcut(QMainWindow::tr("Ctrl+Q"));

	theSaveAction_->setEnabled(false);
	theSaveAsAction_->setEnabled(false);

	GetParentMainWindow()->menuBar()->addMenu(this);
	GetParentMainWindow()->addToolBar(this->GetToolBar());
}