#pragma once
#ifndef _FrgBase_MenuHelp_Header
#define _FrgBase_MenuHelp_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Menu.hxx>

BeginForgBaseLib

class FrgBase_MainWindow;

class FORGBASE_EXPORT FrgBase_MenuHelp
	: public FrgBase_Menu
{

public:

	FrgBase_MenuHelp(FrgBase_MainWindow* parentMainWindow);
};

EndForgBaseLib

#endif // !_FrgBase_MenuHelp_Header
