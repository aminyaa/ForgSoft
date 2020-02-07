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
	auto helpAction = AddItem(FrgString(""), FrgString("&View Help"), false);
	addSeparator();
	auto aboutAction = AddItem(FrgString(""), FrgString("&About"), false);

	GetParentMainWindow()->menuBar()->addMenu(this);
	if (GetToolBar())
		GetToolBar()->setHidden(true);
}