#include <FrgMarine_GeomParts_TItem.hxx>

ForgMarineLib::FrgMarine_GeomParts_TItem::FrgMarine_GeomParts_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{

}