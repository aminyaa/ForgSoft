#include <FrgMarine_TItemGeomParMdls_Ship.hxx>
#include <FrgBase_Global_Icons.hxx>

ForgMarineLib::FrgMarine_TItemGeomParMdls_Ship::FrgMarine_TItemGeomParMdls_Ship
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgMarine_TItemGeom_ParMdls(itemTitle, parentItem, parentTree)
{
	this->setIcon(0, QIcon(ICON_Menu_Models_Ship));
}