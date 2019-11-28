#pragma once
#ifndef _FrgMenu_Help_Header
#define _FrgMenu_Help_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseMenu.hxx>

BeginFrgBaseLib

class FrgBaseMainWindow;

class FORGBASE_EXPORT FrgMenu_Help : public FrgBaseMenu
{

private:

public:

	FrgMenu_Help(FrgBaseMainWindow* parentMainWindow = FrgNullPtr);
};

EndFrgBaseLib

#endif // !_FrgMenu_Help_Header
