#include <FrgBaseMenuFile.hxx>
#include <FrgBaseMainWindow.hxx>
#include <FrgBaseGlobalsICONS.hxx>

#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>

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

	//GetToolBar() = FrgNew QToolBar(" Toolbar", parentMainWindow);

	GetParentMainWindow()->addToolBar(GetToolBar());

	/*FrgBaseMenu* EditMenu = new FrgBaseMenu("Edit", parentMainWindow);
	FrgBaseMenu* ToolsMenu = new FrgBaseMenu("Tools", parentMainWindow);
	FrgBaseMenu* ModelsMenu = new FrgBaseMenu("Models", parentMainWindow);
	FrgBaseMenu* WindowMenu = new FrgBaseMenu("Window", parentMainWindow);
	FrgBaseMenu* HelpMenu = new FrgBaseMenu("Help", parentMainWindow);

	GetParentMainWindow()->menuBar()->addMenu(EditMenu);
	GetParentMainWindow()->menuBar()->addMenu(ToolsMenu);
	GetParentMainWindow()->menuBar()->addMenu(ModelsMenu);
	GetParentMainWindow()->menuBar()->addMenu(WindowMenu);
	GetParentMainWindow()->menuBar()->addMenu(HelpMenu);

	QAction* shipAction = new QAction(QIcon(":/Icons/Models/Ship.png"), "New Ship");
	QAction* propellerAction = new QAction(QIcon(":/Icons/Models/Propeller.png"), "New Propeller");
	QAction* ductAction = new QAction(QIcon(":/Icons/Models/Duct.png"), "New Duct");

	QToolBar* ModelsToolbar = new QToolBar();
	ModelsToolbar->addAction(shipAction);
	ModelsToolbar->addAction(propellerAction);
	ModelsToolbar->addAction(ductAction);

	GetParentMainWindow()->addToolBar(ModelsToolbar);*/
}