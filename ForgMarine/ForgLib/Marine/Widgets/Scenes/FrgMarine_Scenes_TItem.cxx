#include <FrgMarine_Scenes_TItem.hxx>

ForgMarineLib::FrgMarine_Scenes_TItem::FrgMarine_Scenes_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{

}