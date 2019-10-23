#pragma once
#ifndef _FrgBaseTabWidget_Header
#define _FrgBaseTabWidget_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QTabWidget>

BeginFrgBaseLib

class FrgBaseMainWindow;
class FrgBaseTabBar;

class FORGBASE_EXPORT FrgBaseTabWidget : public QTabWidget
{

	Q_OBJECT

private:

	FrgBaseMainWindow* theParentMainWindow_ = FrgNullPtr;
	FrgBaseTabBar* theTabBar_ = FrgNullPtr;

public:

	FrgBaseTabWidget(FrgBaseMainWindow* parentMainWindow);

	FrgGetMacro(FrgBaseMainWindow*, ParentMainWindow, theParentMainWindow_);
	FrgGetMacro(FrgBaseTabBar*, TabBar, theTabBar_);
};

EndFrgBaseLib

#endif // !_FrgBaseTabWidget_Header
