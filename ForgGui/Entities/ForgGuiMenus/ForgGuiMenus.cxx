#include <ForgGuiMenus.hxx>
#include <ForgGuiMainWindow.hxx>

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtCore/QObject>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QMenuBar>

#define CreateAction(Action, IconAddress, Text, Parent, Shortcut, StatusTip)\
Action = new QAction(QIcon(IconAddress), QMainWindow::tr(Text), Parent);\
Action->setShortcut(QMainWindow::tr(Shortcut));\
Action->setStatusTip(QMainWindow::tr(StatusTip));

#define ConnectAction(Action, Receiver, Slot)\
QObject::connect(Action, SIGNAL(triggered()), Receiver, SLOT(Slot()));

ForgGuiLib::ForgGuiMenus::ForgGuiMenus(ForgGuiMainWindow* parent)
	: theParentMainWindow_(parent)
{
	theMenus_ = new Menus;

	theMenus_->theFileMenu_ = new FileMenuStruct;

	CreateActions();
	CreateMenus();
	ConnectActions();
	CreateToolBars();
}

void ForgGuiLib::ForgGuiMenus::CreateActions()
{
	/*=============*/
	/* File Actions*/
	/*=============*/

	CreateAction(theMenus_->theFileMenu_->theNewAction_, ":/Icons/Menus/File/New.png", "&New", theParentMainWindow_, "Ctrl+N", "");
	CreateAction(theMenus_->theFileMenu_->theLoadAction_, ":/Icons/Menus/File/Load.png", "&Load", theParentMainWindow_, "Ctrl+L", "");
	CreateAction(theMenus_->theFileMenu_->theSaveAction_, ":/Icons/Menus/File/Save.png", "&Save", theParentMainWindow_, "Ctrl+S", "");
	CreateAction(theMenus_->theFileMenu_->theSaveAsAction_, ":/Icons/Menus/File/SaveAs.png", "Save &As...", theParentMainWindow_, "Ctrl+Shift+S", "");
	CreateAction(theMenus_->theFileMenu_->theSaveAllAction_, ":/Icons/Menus/File/SaveAll.png", "Save All", theParentMainWindow_, "", "");
	CreateAction(theMenus_->theFileMenu_->theImportAction_, ":/Icons/Menus/File/Import.png", "&Import", theParentMainWindow_, "Ctrl+I", "Import file");
	CreateAction(theMenus_->theFileMenu_->theExportAction_, ":/Icons/Menus/File/Export.png", "&Export", theParentMainWindow_, "Ctrl+E", "Export file");
	CreateAction(theMenus_->theFileMenu_->theExitAction_, ":/Icons/Menus/File/Exit.png", "E&xit", theParentMainWindow_, "Ctrl+Q", "Exit");

	theMenus_->theFileMenu_->theSaveAction_->setEnabled(false);
	theMenus_->theFileMenu_->theSaveAsAction_->setEnabled(false);
	theMenus_->theFileMenu_->theSaveAllAction_->setEnabled(false);
}

void ForgGuiLib::ForgGuiMenus::CreateMenus()
{
	theMenus_->theFileMenu_->theMenu_ = new QMenu(QMainWindow::tr("&File"), (QMainWindow*)theParentMainWindow_);

	theMenus_->theFileMenu_->theMenu_->addAction(theMenus_->theFileMenu_->theNewAction_);
	theMenus_->theFileMenu_->theMenu_->addAction(theMenus_->theFileMenu_->theLoadAction_);
	theMenus_->theFileMenu_->theMenu_->addSeparator();
	theMenus_->theFileMenu_->theMenu_->addAction(theMenus_->theFileMenu_->theSaveAction_);
	theMenus_->theFileMenu_->theMenu_->addAction(theMenus_->theFileMenu_->theSaveAsAction_);
	theMenus_->theFileMenu_->theMenu_->addAction(theMenus_->theFileMenu_->theSaveAllAction_);
	theMenus_->theFileMenu_->theMenu_->addSeparator();
	theMenus_->theFileMenu_->theMenu_->addAction(theMenus_->theFileMenu_->theImportAction_);
	theMenus_->theFileMenu_->theMenu_->addAction(theMenus_->theFileMenu_->theExportAction_);
	theMenus_->theFileMenu_->theMenu_->addSeparator();
	theMenus_->theFileMenu_->theMenu_->addAction(theMenus_->theFileMenu_->theExitAction_);

	theParentMainWindow_->menuBar()->addMenu(theMenus_->theFileMenu_->theMenu_);
}

void ForgGuiLib::ForgGuiMenus::ConnectActions()
{
	ConnectAction(theMenus_->theFileMenu_->theNewAction_, theParentMainWindow_, FileNewAction);
	ConnectAction(theMenus_->theFileMenu_->theLoadAction_, theParentMainWindow_, FileLoadAction);
	ConnectAction(theMenus_->theFileMenu_->theSaveAction_, theParentMainWindow_, FileSaveAction);
	ConnectAction(theMenus_->theFileMenu_->theSaveAsAction_, theParentMainWindow_, FileSaveAsAction);
	ConnectAction(theMenus_->theFileMenu_->theSaveAllAction_, theParentMainWindow_, FileSaveAllAction);
	ConnectAction(theMenus_->theFileMenu_->theImportAction_, theParentMainWindow_, FileImportAction);
	ConnectAction(theMenus_->theFileMenu_->theExportAction_, theParentMainWindow_, FileExportAction);
	ConnectAction(theMenus_->theFileMenu_->theExitAction_, theParentMainWindow_, FileExitAction);
}

void ForgGuiLib::ForgGuiMenus::CreateToolBars()
{
	/*==================*/
	/* Add File Toolbar */
	/*==================*/
	theMenus_->theFileMenu_->theToolBar_ = new QToolBar(QMainWindow::tr("File Toolbar"), theParentMainWindow_);
	theMenus_->theFileMenu_->theToolBar_->setIconSize(QSize(25, 25));

	theMenus_->theFileMenu_->theToolBar_->addAction(theMenus_->theFileMenu_->theNewAction_);
	theMenus_->theFileMenu_->theToolBar_->addAction(theMenus_->theFileMenu_->theLoadAction_);
	theMenus_->theFileMenu_->theToolBar_->addAction(theMenus_->theFileMenu_->theSaveAction_);
	theMenus_->theFileMenu_->theToolBar_->addAction(theMenus_->theFileMenu_->theSaveAsAction_);

	theMenus_->theFileMenu_->theToolBar_->setContextMenuPolicy(Qt::PreventContextMenu);

	theParentMainWindow_->addToolBar(theMenus_->theFileMenu_->theToolBar_);
}