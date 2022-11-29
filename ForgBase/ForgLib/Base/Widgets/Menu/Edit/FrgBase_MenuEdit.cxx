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
	theUndoAction_ = AddItem(ICON_Menu_Edit_Undo, FrgString("&Undo"));
	theRedoAction_ = AddItem(ICON_Menu_Edit_Redo, FrgString("&Redo"));
	addSeparator();
	theCutAction_ = AddItem(ICON_Menu_Edit_Cut, FrgString("Cu&t"));
	theCopyAction_ = AddItem(ICON_Menu_Edit_Copy, FrgString("&Copy"));
	thePasteAction_ = AddItem(ICON_Menu_Edit_Paste, FrgString("&Paste"));
	theDeleteAction_ = AddItem(ICON_Menu_Edit_Delete, FrgString("&Delete"));
	addSeparator();
	theSelectAllAction_ = AddItem(ICON_Menu_Edit_SelectAll, FrgString("Select &All"));

	theUndoAction_->setShortcut(QMainWindow::tr("Ctrl+Z"));
	theRedoAction_->setShortcut(QMainWindow::tr("Ctrl+Y"));
	theCutAction_->setShortcut(QMainWindow::tr("Ctrl+X"));
	theCopyAction_->setShortcut(QMainWindow::tr("Ctrl+C"));
	thePasteAction_->setShortcut(QMainWindow::tr("Ctrl+V"));
	theDeleteAction_->setShortcut(QMainWindow::tr("Del"));
	theSelectAllAction_->setShortcut(QMainWindow::tr("Ctrl+A"));

	theUndoAction_->setEnabled(false);
	theRedoAction_->setEnabled(false);
	thePasteAction_->setEnabled(false);

	GetParentMainWindow()->menuBar()->addMenu(this);
	GetParentMainWindow()->addToolBar(this->GetToolBar());
}