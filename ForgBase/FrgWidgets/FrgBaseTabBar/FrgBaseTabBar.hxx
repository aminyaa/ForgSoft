#pragma once
#ifndef _FrgBaseTabBar_Header
#define _FrgBaseTabBar_Header

#include <FrgBaseGlobals.hxx>
#include <QtWidgets/QTabBar>

BeginFrgBaseLib

class FrgBaseMainWindow;

class FORGBASE_EXPORT FrgBaseTabBar : public QTabBar
{

	Q_OBJECT

public:

	FrgBaseTabBar(FrgBaseMainWindow* parentMainWindow = FrgNullPtr);
};

EndFrgBaseLib

#endif // !_FrgBaseTabBar_Header
