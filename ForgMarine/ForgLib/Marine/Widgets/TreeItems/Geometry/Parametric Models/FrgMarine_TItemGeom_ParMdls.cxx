#include <FrgMarine_TItemGeom_ParMdls.hxx>
#include <FrgMarine_TItemGeomParMdlsShip_01.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgMarine_Tree.hxx>

ForgMarineLib::FrgMarine_TItemGeom_ParMdls::FrgMarine_TItemGeom_ParMdls
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	ForgBaseLib::FrgBase_Menu* newModelMenu = new ForgBaseLib::FrgBase_Menu("New Model", GetParentMainWindow());

	ForgBaseLib::FrgBase_Menu* newShipMenu = new ForgBaseLib::FrgBase_Menu("Ship", GetParentMainWindow());
	newShipMenu->setIcon(QIcon(ICON_Menu_Models_Ship));
	auto newShip01Action = newShipMenu->AddItem("Type 01", false);

	ForgBaseLib::FrgBase_Menu* newPropellerMenu = new ForgBaseLib::FrgBase_Menu("Propeller", GetParentMainWindow());
	newPropellerMenu->setIcon(QIcon(ICON_Menu_Models_Propeller));
	auto newPropeller01Action = newPropellerMenu->AddItem("Type 01", false);

	ForgBaseLib::FrgBase_Menu* newDuctMenu = new ForgBaseLib::FrgBase_Menu("Duct", GetParentMainWindow());
	newDuctMenu->setIcon(QIcon(ICON_Menu_Models_Duct));
	auto newDuct01Action = newDuctMenu->AddItem("Type 01", false);

	newModelMenu->addMenu(newShipMenu);
	newModelMenu->addMenu(newPropellerMenu);
	newModelMenu->addMenu(newDuctMenu);

	theContextMenu_->addMenu(newModelMenu);

	connect(newShip01Action, SIGNAL(triggered()), this, SLOT(Ship01CreateSlot()));
}

void ForgMarineLib::FrgMarine_TItemGeom_ParMdls::Ship01CreateSlot()
{
	auto shipItem = new FrgMarine_TItemGeomParMdlsShip_01("", this, GetParentTree());
	shipItem->RenameTItemSlot("Ship Type 01");

	GetParentTree()->ScrollToItem(shipItem);
}