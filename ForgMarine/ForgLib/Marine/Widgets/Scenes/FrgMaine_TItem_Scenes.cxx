#include <FrgMaine_TItem_Scenes.hxx>

ForgMarineLib::FrgMaine_TItem_Scenes::FrgMaine_TItem_Scenes
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{

}