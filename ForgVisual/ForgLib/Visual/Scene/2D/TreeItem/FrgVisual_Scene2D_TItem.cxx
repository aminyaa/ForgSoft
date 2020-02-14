#include <FrgVisual_Scene2D_TItem.hxx>
#include <FrgVisual_Scene2D.hxx>

ForgVisualLib::FrgVisual_Scene2D_TItem::FrgVisual_Scene2D_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgVisual_Scene_TItem(itemTitle, parentItem, parentTree)
{
	theScene_ = new FrgVisual_Scene2D(GetParentMainWindow());
	dynamic_cast<FrgVisual_Scene2D*>(theScene_)->Init();
}