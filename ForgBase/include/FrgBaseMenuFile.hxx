#pragma once
#ifndef _FrgBaseMenuFile_Header
#define _FrgBaseMenuFile_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseMenu.hxx>

BeginFrgBaseLib

class FrgMainWindow;

class FORGBASE_EXPORT FrgBaseMenuFile : public FrgBaseMenu
{

private:

public:

	FrgBaseMenuFile(FrgBaseMainWindow* parentMainWindow = FrgNullPtr);

};

EndFrgBaseLib

#endif // !_FrgBaseMenuFile_Header
