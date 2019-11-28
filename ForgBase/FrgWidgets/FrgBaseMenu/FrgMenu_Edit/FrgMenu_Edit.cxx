#include <FrgMenu_Edit.hxx>
#include <FrgBaseGlobalsICONS.hxx>
#include <FrgBaseMainWindow.hxx>
#include <QtWidgets/QMenuBar>

ForgBaseLib::FrgMenu_Edit::FrgMenu_Edit(FrgBaseMainWindow * parentMainWindow)
	: FrgBaseMenu("&Edit", parentMainWindow)
{
	AddItem(FrgICON_Menu_Edit_Undo, "&Undo", "Ctrl+Z");
	AddItem(FrgICON_Menu_Edit_Redo, "&Redo", "Ctrl+Y");
	addSeparator();
	AddItem(FrgICON_Menu_Edit_Cut, "Cu&t", "Ctrl+X");
	AddItem(FrgICON_Menu_Edit_Copy, "&Copy", "Ctrl+C");
	AddItem(FrgICON_Menu_Edit_Paste, "&Paste", "Ctrl+V");
	AddItem(FrgICON_Menu_Edit_Delete, "&Delete", "Del");
	addSeparator();
	AddItem(FrgICON_Menu_Edit_SelectAll, "Select &All", "Ctrl+A");

	GetParentMainWindow()->menuBar()->addMenu(this);
	GetParentMainWindow()->addToolBar(GetToolBar());
}