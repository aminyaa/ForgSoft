#include <FrgBaseTabWidget.hxx>
#include <FrgBaseMainWindow.hxx>
#include <FrgBaseTabBar.hxx>

ForgBaseLib::FrgBaseTabWidget::FrgBaseTabWidget(FrgBaseMainWindow* parentMainWindow)
	: QTabWidget(parentMainWindow)
	, theParentMainWindow_(parentMainWindow)
{
	FrgString style = "QTabWidget {"
		"padding: 2px;"
		"selection-background-color: #32414B;"
		"}"
		"QTabWidget QWidget{"
		" border: 1px solid #32414B;"
		"}"
		"QTabWidget::pane{"
		"  border: 1px solid #32414B;"
		"  border-radius: 4px;"
		"  margin: 0px;"
		"  padding: 0px;"
		"}"
		"QTabWidget::pane:selected{"
		"  background-color: #32414B;"
		"  border: 1px solid #1464A0;"
		"}";

	this->setStyleSheet(style);
	theTabBar_ = FrgNew FrgBaseTabBar(parentMainWindow);
	this->setTabBar(theTabBar_);
}