#pragma once
#ifndef _FrgBase_MenuFile_Header
#define _FrgBase_MenuFile_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Menu.hxx>

BeginForgBaseLib

class FrgBase_MainWindow;

class FORGBASE_EXPORT FrgBase_MenuFile
	: public FrgBase_Menu
{

public:

	FrgBase_MenuFile(FrgBase_MainWindow* parentMainWindow);
};

EndForgBaseLib

#endif // !_FrgBase_MenuFile_Header
