#include <FrgVisual_Scene_TItem.hxx>
#include <FrgVisual_Scene.hxx>

ForgVisualLib::FrgVisual_Scene_TItem::FrgVisual_Scene_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	this->AddRenameOptionInContextMenu();
	this->AddDeleteOptionInContextMenu();
}

ForgVisualLib::FrgVisual_Scene_TItem::~FrgVisual_Scene_TItem()
{
	FreePointer(theScene_);
}