#include <FrgVisual_Scene3DTItem.hxx>
#include <FrgVisual_Scene3D.hxx>

ForgVisualLib::FrgVisual_Scene3DTItem::FrgVisual_Scene3DTItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	theScene_ = new FrgVisual_Scene3D(GetParentMainWindow());
}