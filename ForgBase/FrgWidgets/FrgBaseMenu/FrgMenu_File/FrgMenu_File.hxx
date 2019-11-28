#pragma once
#ifndef _FrgMenu_File_Header
#define _FrgMenu_File_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseMenu.hxx>

BeginFrgBaseLib

class FrgMainWindow;

class FORGBASE_EXPORT FrgMenu_File : public FrgBaseMenu
{

private:

public:

	FrgMenu_File(FrgBaseMainWindow* parentMainWindow = FrgNullPtr);

};

EndFrgBaseLib

#endif // !_FrgMenu_File_Header
