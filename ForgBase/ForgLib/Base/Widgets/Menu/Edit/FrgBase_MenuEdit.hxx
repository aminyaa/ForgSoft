#pragma once
#ifndef _FrgBase_MenuEdit_Header
#define _FrgBase_MenuEdit_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Menu.hxx>

BeginForgBaseLib

class FrgBase_MainWindow;

class FORGBASE_EXPORT FrgBase_MenuEdit
	: public FrgBase_Menu
{

public:

	FrgBase_MenuEdit(FrgBase_MainWindow* parentMainWindow);

	QAction* GetUndoAction() const { return theUndoAction_; }
	QAction* GetRedoAction() const { return theRedoAction_; }
	QAction* GetCutAction() const { return theCutAction_; }
	QAction* GetCopyAction() const { return theCopyAction_; }
	QAction* GetPasteAction() const { return thePasteAction_; }
	QAction* GetDeleteAction() const { return theDeleteAction_; }
	QAction* GetSelectAllAction() const { return theSelectAllAction_; }

protected:

	QAction* theUndoAction_ = nullptr;
	QAction* theRedoAction_ = nullptr;
	QAction* theCutAction_ = nullptr;
	QAction* theCopyAction_ = nullptr;
	QAction* thePasteAction_ = nullptr;
	QAction* theDeleteAction_ = nullptr;
	QAction* theSelectAllAction_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_MenuEdit_Header
