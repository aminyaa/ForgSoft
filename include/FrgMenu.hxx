#pragma once
#ifndef _FrgMenu_Header
#define _FrgMenu_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QMenu>

class QToolBar;

BeginFrgBaseLib

class FrgMainWindow;

class FORGBASE_EXPORT FrgMenu : public QMenu
{

private:

	FrgMainWindow* theParentMainWindow_ = FrgNullPtr;

	FrgVector<QAction*> theItems_;

	QToolBar* theToolBar_ = FrgNullPtr;

	FrgBool theItemIsInToolBarCondition_ = FrgTrue;

public:

	FrgMenu(const FrgString& title, FrgMainWindow* parentMainWindow = FrgNullPtr);

	FrgMenu(FrgMainWindow* parentMainWindow = FrgNullPtr);

	void AddItem(const FrgString& title);

	void AddItem(const FrgString& iconAddress, const FrgString& title);

	void AddItem(const FrgString& iconAddress, const FrgString& title, const FrgString& shortcut, FrgBool isInToolbar = FrgTrue);

	void SetEnabledItem(const FrgString& title, FrgBool condition = FrgTrue);

	QAction* GetItem(const FrgString& title);

	FrgGetMacro(FrgMainWindow*, ParentMainWindow, theParentMainWindow_);

	FrgGetMacro(QToolBar*, ToolBar, theToolBar_);
};

EndFrgBaseLib

#endif // !_FrgMenu_Header
