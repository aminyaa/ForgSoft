#pragma once
#ifndef _FrgBase_Menu_Header
#define _FrgBase_Menu_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Object.hxx>

#include <QtWidgets/QMenu>
#include <QtCore/QObject>

class QAction;
class QToolBar;

BeginForgBaseLib

class FrgBase_MainWindow;

class FORGBASE_EXPORT FrgBase_Menu
	: public QObject
	, public QMenu
	, public FrgBase_Object
{
	Q_OBJECT

private:

	FrgBase_MainWindow* theParentMainWindow_ = FrgNullPtr;
	QToolBar* theToolBar_ = FrgNullPtr;

public:

	FrgBase_Menu(const FrgString& menuTitle, FrgBase_MainWindow* parentMainWindow);
	FrgBase_Menu(FrgBase_MainWindow* parentMainWindow);

	QAction* AddItem(const FrgString& itemTitle, FrgBool isInToolBar = FrgTrue);
	QAction* AddItem(const FrgString& iconAddress, const FrgString& itemTitle, FrgBool isInToolBar = FrgTrue);
	QAction* AddItem(QIcon icon, const FrgString& itemTitle, FrgBool isInToolBar = FrgTrue);

	QAction* GetItem(const FrgString& itemTitle);

	FrgGetMacro(QToolBar*, ToolBar, theToolBar_);
	FrgGetMacro(FrgBase_MainWindow*, ParentMainWindow, theParentMainWindow_);
};

EndForgBaseLib

#endif // !_FrgBase_Menu_Header
