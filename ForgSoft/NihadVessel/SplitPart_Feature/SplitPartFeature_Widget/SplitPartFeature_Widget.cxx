#include <SplitPartFeature_Widget.hxx>
#include <FrgBaseMainWindow.hxx>

ForgBaseLib::SplitPartFeature_Widget_Base::SplitPartFeature_Widget_Base
(
	FrgBaseMainWindow* parentMainWindow
)
	: QWidget(parentMainWindow)
	, theParentMainWindow_(parentMainWindow)
{

}

void ForgBaseLib::SplitPartFeature_Widget_Base::CloseButtonClickedSlot()
{
	CloseButtonClicked();
}