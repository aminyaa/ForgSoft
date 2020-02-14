#include <FrgVisual_Scene3D_TItem.hxx>
#include <FrgVisual_Scene3D.hxx>

ForgVisualLib::FrgVisual_Scene3D_TItem::FrgVisual_Scene3D_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgVisual_Scene_TItem(itemTitle, parentItem, parentTree)
{
	theScene_ = new FrgVisual_Scene3D(GetParentMainWindow());
	dynamic_cast<FrgVisual_Scene3D*>(theScene_)->Init();
}