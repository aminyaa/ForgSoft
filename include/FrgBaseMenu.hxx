#pragma once
#ifndef _FrgBaseMenu_Header
#define _FrgBaseMenu_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QMenu>

class QToolBar;

BeginFrgBaseLib

class FrgBaseMainWindow;

class FORGBASE_EXPORT FrgBaseMenu : public QMenu
{

private:

	FrgBaseMainWindow* theParentMainWindow_ = FrgNullPtr;

	FrgVector<QAction*> theItems_;

	QToolBar* theToolBar_ = FrgNullPtr;

	FrgBool theItemIsInToolBarCondition_ = FrgTrue;

public:

	FrgBaseMenu(const FrgString& title, FrgBaseMainWindow* parentMainWindow = FrgNullPtr);

	FrgBaseMenu(FrgBaseMainWindow* parentMainWindow = FrgNullPtr);

	void AddItem(const FrgString& title);

	void AddItem(const FrgString& iconAddress, const FrgString& title);

	void AddItem(const FrgString& iconAddress, const FrgString& title, const FrgString& shortcut, FrgBool isInToolbar = FrgTrue);

	void SetEnabledItem(const FrgString& title, FrgBool condition = FrgTrue);

	QAction* GetItem(const FrgString& title);

	FrgGetMacro(FrgBaseMainWindow*, ParentMainWindow, theParentMainWindow_);

	FrgGetMacro(QToolBar*, ToolBar, theToolBar_);
};

EndFrgBaseLib

#endif // !_FrgBaseMenu_Header
