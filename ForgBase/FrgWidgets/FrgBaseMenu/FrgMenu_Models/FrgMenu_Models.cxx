#include <FrgMenu_Models.hxx>
#include <FrgBaseGlobalsICONS.hxx>
#include <FrgBaseMainWindow.hxx>
#include <QtWidgets/QMenuBar>

ForgBaseLib::FrgMenu_Models::FrgMenu_Models(FrgBaseMainWindow * parentMainWindow)
	: FrgBaseMenu("M&odels", parentMainWindow)
{
	AddItem(FrgICON_Menu_Models_Ship, "New &Ship", "");
	AddItem(FrgICON_Menu_Models_Propeller, "New &Propeller", "");
	AddItem(FrgICON_Menu_Models_Duct, "New &Duct", "");

	SetEnabledItem("New Ship", FrgFalse);
	SetEnabledItem("New Propeller", FrgFalse);
	SetEnabledItem("New Duct", FrgFalse);

	GetParentMainWindow()->menuBar()->addMenu(this);
	GetParentMainWindow()->addToolBar(GetToolBar());
}