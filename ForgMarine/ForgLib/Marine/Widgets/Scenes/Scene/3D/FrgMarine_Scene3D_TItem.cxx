#include <FrgMarine_Scene3D_TItem.hxx>
#include <FrgVisual_Scene.hxx>

ForgMarineLib::FrgMarine_Scene3D_TItem::FrgMarine_Scene3D_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgVisual_Scene3D_TItem(itemTitle, parentItem, parentTree)
{
	theScene_->SetLogoText("Tonb");
}