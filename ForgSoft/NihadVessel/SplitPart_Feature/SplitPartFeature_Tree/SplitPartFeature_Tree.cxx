#include <SplitPartFeature_Tree.hxx>

ForgBaseLib::SplitPartFeature_Tree_Base::SplitPartFeature_Tree_Base
(
	FrgBaseMainWindow * parentMainWindow,
	FrgBaseCADPart_Feature_Base * partFeature
)
	: FrgBaseTree(parentMainWindow)
	, thePartFeatureBase_(partFeature)
	, theParentMainWindow_(parentMainWindow)
{
}

void ForgBaseLib::SplitPartFeature_Tree_Base::CreateButtonClickedSlot()
{
	CreateButtonClicked();
}