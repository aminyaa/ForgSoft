#pragma once
#ifndef _FrgMenu_Edit_Header
#define _FrgMenu_Edit_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseMenu.hxx>

BeginFrgBaseLib

class FrgMainWindow;

class FORGBASE_EXPORT FrgMenu_Edit : public FrgBaseMenu
{

private:

public:

	FrgMenu_Edit(FrgBaseMainWindow* parentMainWindow = FrgNullPtr);
};

EndFrgBaseLib

#endif // !_FrgMenu_Edit_Header
