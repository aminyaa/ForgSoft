#include <FrgMarine_GeomPart_TItem.hxx>

ForgMarineLib::FrgMarine_GeomPart_TItem::FrgMarine_GeomPart_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	this->AddRenameOptionInContextMenu();
}