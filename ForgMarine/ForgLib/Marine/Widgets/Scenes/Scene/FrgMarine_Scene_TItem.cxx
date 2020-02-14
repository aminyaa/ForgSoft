#include <FrgMarine_Scene_TItem.hxx>
#include <FrgVisual_Scene.hxx>

ForgMarineLib::FrgMarine_Scene_TItem::FrgMarine_Scene_TItem
(
	const FrgString & itemTitle,
	ForgBaseLib::FrgBase_TreeItem * parentItem,
	ForgBaseLib::FrgBase_Tree * parentTree
)
	: FrgVisual_Scene_TItem(itemTitle, parentItem, parentTree)

{
	theScene_->SetLogoText("Tonb");
}