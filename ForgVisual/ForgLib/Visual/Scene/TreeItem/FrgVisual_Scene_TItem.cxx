#include <FrgVisual_Scene_TItem.hxx>

ForgVisualLib::FrgVisual_Scene_TItem::FrgVisual_Scene_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	this->AddRenameOptionInContextMenu();
}