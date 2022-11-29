#include <FrgBase_MenuHelp.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgBase_Global_Icons.hxx>

#include <QtWidgets/QMenuBar>
#include <QtWidgets/QAction>
#include <QtWidgets/QToolBar>

ForgBaseLib::FrgBase_MenuHelp::FrgBase_MenuHelp
(
	FrgBase_MainWindow * parentMainWindow
)
	: FrgBase_Menu("&Help", parentMainWindow)
{
	theViewHelpAction_ = AddItem(ICON_Menu_Help_Help, FrgString("&View Help"), false);
	addSeparator();
	theAboutAction_ = AddItem(ICON_Menu_Help_AboutUs, FrgString("&About"), false);

	GetParentMainWindow()->menuBar()->addMenu(this);
}