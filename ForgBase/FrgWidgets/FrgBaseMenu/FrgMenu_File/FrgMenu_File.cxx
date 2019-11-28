#include <FrgMenu_File.hxx>
#include <FrgBaseMainWindow.hxx>
#include <FrgBaseGlobalsICONS.hxx>
#include <FrgMenu_Globals.hxx>

#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>

ForgBaseLib::FrgMenu_File::FrgMenu_File(FrgBaseMainWindow* parentMainWindow)
	: FrgBaseMenu("&File", parentMainWindow)
{

	AddItem(FrgICON_Menu_File_New, "&New", "Ctrl+N");
	AddItem(FrgICON_Menu_File_Load, "&Load", "Ctrl+L");
	AddItem(FrgICON_Menu_File_Save, "&Save", "Ctrl+S");
	AddItem(FrgICON_Menu_File_SaveAs, "Save As...", "Ctrl+Shift+S");

	AddItem(FrgICON_Menu_File_Import, "Import", "Ctrl+I", FrgFalse);
	AddItem(FrgICON_Menu_File_Exit, "E&xit", "Ctrl+Q", FrgFalse);

	SetEnabledItem("Save", FrgFalse);
	SetEnabledItem("Save As...", FrgFalse);

	GetParentMainWindow()->menuBar()->addMenu(this);

	connect(GetItem("New"), SIGNAL(triggered()), GetParentMainWindow(), SLOT(FileNewActionSlot()));
	connect(GetItem("Load"), SIGNAL(triggered()), GetParentMainWindow(), SLOT(FileLoadActionSlot()));
	connect(GetItem("Save"), SIGNAL(triggered()), GetParentMainWindow(), SLOT(FileSaveActionSlot()));
	connect(GetItem("Import"), SIGNAL(triggered()), GetParentMainWindow(), SLOT(FileImportActionSlot()));

	GetParentMainWindow()->addToolBar(GetToolBar());
}