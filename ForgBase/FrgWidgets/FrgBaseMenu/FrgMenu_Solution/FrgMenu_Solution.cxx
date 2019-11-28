#include <FrgMenu_Solution.hxx>
#include <FrgBaseGlobalsICONS.hxx>
#include <FrgBaseMainWindow.hxx>
#include <QtWidgets/QMenuBar>

ForgBaseLib::FrgMenu_Solution::FrgMenu_Solution(FrgBaseMainWindow * parentMainWindow)
	: FrgBaseMenu("&Solution", parentMainWindow)
{
	AddItem(FrgICON_Menu_Solution_InitializeSolution, "&Initialize Solution", "Ctrl+Shift+B");
	AddItem(FrgICON_Menu_Solution_Run, "&Run", "F5");
	AddItem(FrgICON_Menu_Solution_Step, "S&tep", "F6");
	AddItem(FrgICON_Menu_Solution_Stop, "&Stop", "F7");

	GetParentMainWindow()->menuBar()->addMenu(this);
	GetParentMainWindow()->addToolBar(GetToolBar());
}