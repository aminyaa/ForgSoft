#include <FrgBase_TabBar.hxx>
#include <FrgBase_MainWindow.hxx>

ForgBaseLib::FrgBase_TabBar::FrgBase_TabBar
(
	FrgBase_MainWindow* parentMainWindow
)
	: QTabBar(parentMainWindow)
{
	FrgString style = "QTabBar {"
		"qproperty-drawBase: 0;"
		"border-radius: 4px;"
		"margin: 0px;"
		"padding: 2px;"
		"border : 0;"
		"}";


	this->setStyleSheet(style);

	this->setMovable(FrgTrue);
	this->setTabsClosable(FrgTrue);
	this->setShape(QTabBar::TriangularNorth);
	this->setUsesScrollButtons(FrgTrue);
}