#pragma once
#ifndef _FrgMenu_Mesh_Header
#define _FrgMenu_Mesh_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseMenu.hxx>

BeginFrgBaseLib

class FrgBaseMainWindow;

class FORGBASE_EXPORT FrgMenu_Mesh : public FrgBaseMenu
{

private:

public:

	FrgMenu_Mesh(FrgBaseMainWindow* parentMainWindow = FrgNullPtr);
};

EndFrgBaseLib

#endif // !_FrgMenu_Mesh_Header
