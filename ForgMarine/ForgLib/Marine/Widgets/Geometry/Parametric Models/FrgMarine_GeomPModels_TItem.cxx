#include <FrgMarine_GeomPModels_TItem.hxx>
#include <FrgMarine_GeomPModelShipT01_TItem.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgMarine_Tree.hxx>
//#include <FrgMarine_GeomPModelPView_TItem.hxx>

#include <FrgMarine_GeomPModel_TItem.hxx>
#include <CadModel_Entity.hxx>
#include <LegModel_DispNo1.hxx>

ForgMarineLib::FrgMarine_GeomPModels_TItem::FrgMarine_GeomPModels_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	ForgBaseLib::FrgBase_Menu* newModelMenu = new ForgBaseLib::FrgBase_Menu("New Model", GetParentMainWindow());
	newModelMenu->SetToolBarHidden(true);

	ForgBaseLib::FrgBase_Menu* newShipMenu = new ForgBaseLib::FrgBase_Menu("Ship", GetParentMainWindow());
	newShipMenu->SetToolBarHidden(true);
	newShipMenu->setIcon(QIcon(ICON_Menu_Models_Ship));
	auto newShip01Action = newShipMenu->AddItem("Type 01", false);

	ForgBaseLib::FrgBase_Menu* newPropellerMenu = new ForgBaseLib::FrgBase_Menu("Propeller", GetParentMainWindow());
	newPropellerMenu->SetToolBarHidden(true);
	newPropellerMenu->setIcon(QIcon(ICON_Menu_Models_Propeller));
	auto newPropeller01Action = newPropellerMenu->AddItem("Type 01", false);

	ForgBaseLib::FrgBase_Menu* newDuctMenu = new ForgBaseLib::FrgBase_Menu("Duct", GetParentMainWindow());
	newDuctMenu->SetToolBarHidden(true);
	newDuctMenu->setIcon(QIcon(ICON_Menu_Models_Duct));
	auto newDuct01Action = newDuctMenu->AddItem("Type 01", false);

	newModelMenu->addMenu(newShipMenu);
	newModelMenu->addMenu(newPropellerMenu);
	newModelMenu->addMenu(newDuctMenu);

	theContextMenu_->addMenu(newModelMenu);

	connect(newShip01Action, SIGNAL(triggered()), this, SLOT(Ship01CreateSlot()));
}

ForgMarineLib::FrgMarine_GeomPModels_TItem::~FrgMarine_GeomPModels_TItem()
{

}

void ForgMarineLib::FrgMarine_GeomPModels_TItem::Ship01CreateSlot()
{
	auto shipItem = new FrgMarine_GeomPModelShipT01_TItem("Ship Type 01", this, GetParentTree());

	GetParentTree()->ScrollToItem(shipItem);

	//auto previewItem = new FrgMarine_GeomPModelPView_TItem("Preview", shipItem, GetParentTree(), shipItem->GetModel());

	//connect(shipItem, SIGNAL(ModelPerformedToPreviewSignal()), previewItem, SLOT(UpdatePreviewSlot()));
}

DECLARE_SAVE_IMP(ForgMarineLib::FrgMarine_GeomPModels_TItem)
{
	std::list<FrgMarine_GeomPModel_TItem*> myTItems;

	QTreeWidgetItemIterator it((QTreeWidgetItem*)this);
	while (*it)
	{
		auto myPModelTItem = dynamic_cast<FrgMarine_GeomPModel_TItem*>(*it);
		if (myPModelTItem)
			myTItems.push_back(myPModelTItem);

		++it;
	}

	ar & myTItems;
}

DECLARE_LOAD_IMP(ForgMarineLib::FrgMarine_GeomPModels_TItem)
{
	std::list<FrgMarine_GeomPModel_TItem*> myTItems;

	ar & myTItems;
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPModels_TItem)
{
	//SAVE_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_GeomPModels_TItem)
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPModels_TItem)
{
	//LOAD_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_GeomPModels_TItem)
}

BOOST_CLASS_EXPORT_CXX(ForgMarineLib::FrgMarine_GeomPModels_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPModels_TItem)