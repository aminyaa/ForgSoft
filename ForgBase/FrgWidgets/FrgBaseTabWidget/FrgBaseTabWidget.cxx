#include <FrgBaseTabWidget.hxx>
#include <FrgBaseMainWindow.hxx>

ForgBaseLib::FrgBaseTabWidget::FrgBaseTabWidget(FrgBaseMainWindow* parentMainWindow)
	: QTabWidget(parentMainWindow)
	, theParentMainWindow_(parentMainWindow)
{

}