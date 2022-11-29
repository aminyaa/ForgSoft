#pragma once
#ifndef _FrgBase_MenuFile_Header
#define _FrgBase_MenuFile_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Menu.hxx>

BeginForgBaseLib

class FrgBase_MainWindow;
class FrgBase_MenuAction;

class FORGBASE_EXPORT FrgBase_MenuFile
	: public FrgBase_Menu
{

public:

	FrgBase_MenuFile(FrgBase_MainWindow* parentMainWindow);

	auto GetNewAction() const { return theNewAction_; }
	auto GetLoadAction() const { return theLoadAction_; }
	auto GetSaveAction() const { return theSaveAction_; }
	auto GetSaveAsAction() const { return theSaveAsAction_; }
	auto GetImportAction() const { return theImportAction_; }
	auto GetExportAction() const { return theExportAction_; }
	auto GetExitAction() const { return theExitAction_; }

protected:

	FrgBase_MenuAction* theNewAction_ = nullptr;
	FrgBase_MenuAction* theLoadAction_ = nullptr;
	FrgBase_MenuAction* theSaveAction_ = nullptr;
	FrgBase_MenuAction* theSaveAsAction_ = nullptr;
	FrgBase_MenuAction* theImportAction_ = nullptr;
	FrgBase_MenuAction* theExportAction_ = nullptr;
	FrgBase_MenuAction* theExitAction_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_MenuFile_Header
