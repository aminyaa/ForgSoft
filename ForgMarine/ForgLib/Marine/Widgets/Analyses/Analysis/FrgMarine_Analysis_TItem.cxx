#include <FrgMarine_Analysis_TItem.hxx>

ForgMarineLib::FrgMarine_Analysis_TItem::FrgMarine_Analysis_TItem
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

void ForgMarineLib::FrgMarine_Analysis_TItem::FormTItem()
{
	ForgBaseLib::FrgBase_TreeItem::FormTItem();
}