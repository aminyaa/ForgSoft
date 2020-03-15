#include <FrgVisual_Plot2DAxes_TItem.hxx>
#include <FrgVisual_Plot2DBtmAxis_TItem.hxx>
#include <FrgVisual_Plot2DLeftAxis_TItem.hxx>

ForgVisualLib::FrgVisual_Plot2DAxes_TItem::FrgVisual_Plot2DAxes_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	theBottomAxisTItem_ = new FrgVisual_Plot2DBtmAxis_TItem("Bottom Axis", this, parentTree);
	theLeftAxisTItem_ = new FrgVisual_Plot2DLeftAxis_TItem("Left Axis", this, parentTree);
}