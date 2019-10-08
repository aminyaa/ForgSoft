#pragma once
#ifndef _FrgFileMenu_Header
#define _FrgFileMenu_Header

#include <FrgBaseGlobals.hxx>
#include <FrgMenu.hxx>

BeginFrgBaseLib

class FrgMainWindow;

class FORGBASE_EXPORT FrgFileMenu : public FrgMenu
{

private:

public:

	FrgFileMenu(FrgMainWindow* parentMainWindow = FrgNullPtr);

};

EndFrgBaseLib

#endif // !_FrgFileMenu_Header
