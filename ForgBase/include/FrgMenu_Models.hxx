#pragma once
#ifndef _FrgMenu_Models_Header
#define _FrgMenu_Models_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseMenu.hxx>

BeginFrgBaseLib

class FrgBaseMainWindow;

class FORGBASE_EXPORT FrgMenu_Models : public FrgBaseMenu
{

private:

public:

	FrgMenu_Models(FrgBaseMainWindow* parentMainWindow = FrgNullPtr);
};

EndFrgBaseLib

#endif // !_FrgMenu_Models_Header
