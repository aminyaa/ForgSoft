#pragma once
#ifndef _ForgGuiMenus_Header
#define _ForgGuiMenus_Header

#include <ForgGuiGlobals.hxx>

class QAction;
class QMenu;
class QToolBar;

BeginForgGuiLib

class ForgGuiMainWindow;

class FORGGUI_EXPORT ForgGuiMenus
{

public:

	struct FileMenuStruct
	{
		QMenu* theMenu_ = ForgNullPtr;
		QToolBar* theToolBar_ = ForgNullPtr;

		QAction* theNewAction_ = ForgNullPtr;
		QAction* theLoadAction_ = ForgNullPtr;
		QAction* theSaveAction_ = ForgNullPtr;
		QAction* theSaveAsAction_ = ForgNullPtr;
		QAction* theSaveAllAction_ = ForgNullPtr;
		QAction* theImportAction_ = ForgNullPtr;
		QAction* theExportAction_ = ForgNullPtr;
		QAction* theExitAction_ = ForgNullPtr;
	};

	struct Menus
	{
		FileMenuStruct* theFileMenu_ = ForgNullPtr;
	};

	ForgGetMacro(FileMenuStruct*, FileMenu, theMenus_->theFileMenu_);

	ForgGetMacro(ForgGuiMainWindow*, Parent, theParentMainWindow_);

private:

	ForgGuiMainWindow* theParentMainWindow_ = ForgNullPtr;

	Menus* theMenus_ = ForgNullPtr;

	void CreateActions();

	void CreateMenus();

	void ConnectActions();

	void CreateToolBars();

public:

	ForgGuiMenus(ForgGuiMainWindow* parent = ForgNullPtr);
};

EndForgGuiLib

#endif // !_ForgGuiMenus_Header
