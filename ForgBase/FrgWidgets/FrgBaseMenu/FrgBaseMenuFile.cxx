#include <FrgBaseMenuFile.hxx>
#include <FrgBaseMainWindow.hxx>
#include <FrgBaseGlobalsICONS.hxx>

#include <QtWidgets/QMenuBar>

#define CreateAction(Action, IconAddress, Text, Parent, Shortcut, StatusTip)\
Action = new QAction(QIcon(IconAddress), QMainWindow::tr(Text), Parent);\
Action->setShortcut(QMainWindow::tr(Shortcut));\
Action->setStatusTip(QMainWindow::tr(StatusTip));

ForgBaseLib::FrgBaseMenuFile::FrgBaseMenuFile(FrgBaseMainWindow* parentMainWindow)
	: FrgBaseMenu("&File", parentMainWindow)
{
	AddItem(FrgICONFileNew, "&New", "Ctrl+N");
	AddItem(FrgICONFileLoad, "&Load", "Ctrl+L");
	AddItem(FrgICONFileSave, "&Save", "Ctrl+S");
	AddItem(FrgICONFileSaveAs, "Save As...", "Ctrl+Shift+S");

	AddItem(FrgICONFileImport, "Import", "Ctrl+I", FrgFalse);
	AddItem(FrgICONFileExit, "E&xit", "Ctrl+Q", FrgFalse);

	SetEnabledItem("Save", FrgFalse);
	SetEnabledItem("Save As...", FrgFalse);

	GetParentMainWindow()->menuBar()->addMenu(this);

	connect(GetItem("New"), SIGNAL(triggered()), GetParentMainWindow(), SLOT(FileNewActionSlot()));
	connect(GetItem("Load"), SIGNAL(triggered()), GetParentMainWindow(), SLOT(FileLoadActionSlot()));
	connect(GetItem("Save"), SIGNAL(triggered()), GetParentMainWindow(), SLOT(FileSaveActionSlot()));
	connect(GetItem("Import"), SIGNAL(triggered()), GetParentMainWindow(), SLOT(FileImportActionSlot()));

	GetParentMainWindow()->addToolBar(GetToolBar());
}