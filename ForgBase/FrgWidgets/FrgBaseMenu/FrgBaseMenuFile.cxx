#include <FrgFileMenu.hxx>
#include <FrgMainWindow.hxx>

#include <QtWidgets/QMenuBar>

#define CreateAction(Action, IconAddress, Text, Parent, Shortcut, StatusTip)\
Action = new QAction(QIcon(IconAddress), QMainWindow::tr(Text), Parent);\
Action->setShortcut(QMainWindow::tr(Shortcut));\
Action->setStatusTip(QMainWindow::tr(StatusTip));

ForgBaseLib::FrgFileMenu::FrgFileMenu(FrgMainWindow* parentMainWindow)
	: FrgMenu("&File", parentMainWindow)
{
	AddItem(":/Icons/Menus/File/New.png", "&New", "Ctrl+N");
	AddItem(":/Icons/Menus/File/Load.png", "&Load", "Ctrl+L");
	AddItem(":/Icons/Menus/File/Save.png", "&Save", "Ctrl+S");
	AddItem(":/Icons/Menus/File/SaveAs.png", "Save As...", "Ctrl+Shift+S");
	AddItem(":/Icons/Menus/File/Exit.png", "E&xit", "Ctrl+Q", FrgFalse);

	SetEnabledItem("Save", FrgFalse);
	SetEnabledItem("Save As...", FrgFalse);

	GetParentMainWindow()->menuBar()->addMenu(this);

	connect(GetItem("New"), SIGNAL(triggered()), GetParentMainWindow(), SLOT(FileNewActionSlot()));
	connect(GetItem("Load"), SIGNAL(triggered()), GetParentMainWindow(), SLOT(FileLoadActionSlot()));
	connect(GetItem("Save"), SIGNAL(triggered()), GetParentMainWindow(), SLOT(FileSaveActionSlot()));

	GetParentMainWindow()->addToolBar(GetToolBar());
}