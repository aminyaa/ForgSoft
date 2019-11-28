#pragma once
#ifndef _FrgMenu_Solution_Header
#define _FrgMenu_Solution_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseMenu.hxx>

BeginFrgBaseLib

class FrgBaseMainWindow;

class FORGBASE_EXPORT FrgMenu_Solution :public FrgBaseMenu
{

private:

public:

	FrgMenu_Solution(FrgBaseMainWindow* parentMainWindow = FrgNullPtr);
};

EndFrgBaseLib

#endif // !_FrgMenu_Solution_Header
