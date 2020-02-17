#pragma once
#ifndef _FrgBase_Dlg_Header
#define _FrgBase_Dlg_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Object.hxx>

#include <QtWidgets/QDialog>

BeginForgBaseLib

class FrgBase_MainWindow;

class FrgBase_Dlg
	: public QDialog
	, public FrgBase_Object
{
	Q_OBJECT

private:

	FrgBase_MainWindow* theParentMainWindow_ = NullPtr;

public:
	
	FrgBase_Dlg
	(
		FrgBase_MainWindow* parentMainWindow
	);

	~FrgBase_Dlg();

	FrgGetMacro(FrgBase_MainWindow*, ParentMainWindow, theParentMainWindow_);
};

EndForgBaseLib

#endif // !_FrgBase_Dlg_Header
