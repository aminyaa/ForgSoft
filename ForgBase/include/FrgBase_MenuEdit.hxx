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
};

EndForgBaseLib

#endif // !_FrgBase_MenuEdit_Header
