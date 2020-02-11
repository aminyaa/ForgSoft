#include <FrgMarine_GeomPModelShip_TItem.hxx>
#include <FrgBase_Global_Icons.hxx>

ForgMarineLib::FrgMarine_GeomPModelShip_TItem::FrgMarine_GeomPModelShip_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgMarine_GeomPModel_TItem(itemTitle, parentItem, parentTree)
{
	this->setIcon(0, QIcon(ICON_Menu_Models_Ship));
}