#include <FrgMenu_View.hxx>
#include <FrgBaseGlobalsICONS.hxx>
#include <FrgBaseMainWindow.hxx>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>

ForgBaseLib::FrgMenu_View::FrgMenu_View(FrgBaseMainWindow * parentMainWindow)
	: FrgBaseMenu("&View", parentMainWindow)
{
	AddItem(FrgICON_Menu_View_XY, "Set View to XY Plane", "");
	AddItem(FrgICON_Menu_View_XZ, "Set View to XZ Plane", "");
	AddItem(FrgICON_Menu_View_YZ, "Set View to YZ Plane", "");
	AddItem(FrgICON_Menu_View_XYZ, "Set View to XYZ", "");

	//GetParentMainWindow()->menuBar()->addMenu(this);
	GetToolBar()->setHidden(FrgTrue);
}