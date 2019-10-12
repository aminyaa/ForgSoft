#pragma once
#ifndef _NihadMainWindow_Header
#define _NihadMainWindow_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseMainWindow.hxx>

BeginFrgBaseLib

class NihadMainWindow : public FrgBaseMainWindow
{

public:

	NihadMainWindow(QWidget* parent = FrgNullPtr);

	void CreateTree() override;
};

EndFrgBaseLib

#endif // !_NihadMainWindow_Header
