#pragma once
#ifndef _FrgMenu_View_Header
#define _FrgMenu_View_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseMenu.hxx>

BeginFrgBaseLib

class FrgBaseMainWindow;

class FORGBASE_EXPORT FrgMenu_View : public FrgBaseMenu
{

private:

public:

	FrgMenu_View(FrgBaseMainWindow* parentMainWindow = FrgNullPtr);
};

EndFrgBaseLib

#endif // !_FrgMenu_View_Header
