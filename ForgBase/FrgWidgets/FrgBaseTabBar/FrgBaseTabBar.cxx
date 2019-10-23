#include <FrgBaseTabBar.hxx>
#include <FrgBaseMainWindow.hxx>

ForgBaseLib::FrgBaseTabBar::FrgBaseTabBar(FrgBaseMainWindow* parentMainWindow)
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