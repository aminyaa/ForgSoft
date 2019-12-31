#include <FrgBase_MenuFile.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgBase_Global_Icons.hxx>

#include <QtWidgets/QMenuBar>
#include <QtWidgets/QAction>

ForgBaseLib::FrgBase_MenuFile::FrgBase_MenuFile
(
	FrgBase_MainWindow* parentMainWindow
)
	: FrgBase_Menu("&File", parentMainWindow)
{
	auto newAction = AddItem(ICON_Menu_File_New, "&New");
	auto loadAction = AddItem(ICON_Menu_File_Load, "&Load");
	addSeparator();
	auto saveAction = AddItem(ICON_Menu_File_Save, "&Save");
	auto saveAsAction = AddItem(ICON_Menu_File_SaveAs, "Save As...");
	addSeparator();

	auto importAction = AddItem(ICON_Menu_File_Import, "&Import");
	auto exportAction = AddItem(ICON_Menu_File_Export, "&Export");
	addSeparator();

	auto exitAction = AddItem(ICON_Menu_File_Exit, "E&xit");

	newAction->setShortcut(QMainWindow::tr("Ctrl+N"));
	loadAction->setShortcut(QMainWindow::tr("Ctrl+L"));
	saveAction->setShortcut(QMainWindow::tr("Ctrl+S"));
	saveAsAction->setShortcut(QMainWindow::tr("Ctrl+Shift+S"));

	importAction->setShortcut(QMainWindow::tr("Ctrl+I"));
	exportAction->setShortcut(QMainWindow::tr("Ctrl+E"));

	exitAction->setShortcut(QMainWindow::tr("Ctrl+Q"));

	saveAction->setEnabled(false);
	saveAsAction->setEnabled(false);

	GetParentMainWindow()->menuBar()->addMenu(this);
	GetParentMainWindow()->addToolBar(this->GetToolBar());
}