#include <FrgBase_MenuEdit.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgBase_Global_Icons.hxx>

#include <QtWidgets/QMenuBar>

ForgBaseLib::FrgBase_MenuEdit::FrgBase_MenuEdit
(
	FrgBase_MainWindow* parentMainWindow
)
	: FrgBase_Menu("&Edit", parentMainWindow)
{
	auto undoAction = AddItem(ICON_Menu_Edit_Undo, "&Undo");
	auto redoAction = AddItem(ICON_Menu_Edit_Redo, "&Redo");
	addSeparator();
	auto cutAction = AddItem(ICON_Menu_Edit_Cut, "Cu&t");
	auto copyAction = AddItem(ICON_Menu_Edit_Copy, "&Copy");
	auto pasteAction = AddItem(ICON_Menu_Edit_Paste, "&Paste");
	auto deleteAction = AddItem(ICON_Menu_Edit_Delete, "&Delete");
	addSeparator();
	auto selectAllAction = AddItem(ICON_Menu_Edit_SelectAll, "Select &All");

	undoAction->setShortcut(QMainWindow::tr("Ctrl+Z"));
	redoAction->setShortcut(QMainWindow::tr("Ctrl+Y"));
	cutAction->setShortcut(QMainWindow::tr("Ctrl+X"));
	copyAction->setShortcut(QMainWindow::tr("Ctrl+C"));
	pasteAction->setShortcut(QMainWindow::tr("Ctrl+V"));
	deleteAction->setShortcut(QMainWindow::tr("Del"));
	selectAllAction->setShortcut(QMainWindow::tr("Ctrl+A"));

	undoAction->setEnabled(false);
	redoAction->setEnabled(false);
	pasteAction->setEnabled(false);

	GetParentMainWindow()->menuBar()->addMenu(this);
	GetParentMainWindow()->addToolBar(this->GetToolBar());
}