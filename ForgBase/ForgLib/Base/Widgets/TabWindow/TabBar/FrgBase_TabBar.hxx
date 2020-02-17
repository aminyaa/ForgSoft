#pragma once
#ifndef _FrgBase_TabBar_Header
#define _FrgBase_TabBar_Header

#include <FrgBase_Global.hxx>
#include <QtWidgets/QTabBar>

BeginForgBaseLib

class FrgBase_MainWindow;

class FORGBASE_EXPORT FrgBase_TabBar
	: public QTabBar
{
	Q_OBJECT

public:

	FrgBase_TabBar
	(
		FrgBase_MainWindow* parentMainWindow
	);
};

EndForgBaseLib

#endif // !_FrgBase_TabBar_Header
