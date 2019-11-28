#include <FrgMenu_Help.hxx>
#include <FrgBaseGlobalsICONS.hxx>
#include <FrgBaseMainWindow.hxx>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>

ForgBaseLib::FrgMenu_Help::FrgMenu_Help(FrgBaseMainWindow * parentMainWindow)
	: FrgBaseMenu("&Help", parentMainWindow)
{
	AddItem(FrgICON_Menu_Help_Help, "&Help", ":/Icons/Menus/Help/Help.png");
	AddItem(FrgICON_Menu_Help_AboutUs, "&About Us", ":/Icons/Menus/Help/AboutUs.png");

	GetParentMainWindow()->menuBar()->addMenu(this);
	GetToolBar()->setHidden(FrgTrue);
}