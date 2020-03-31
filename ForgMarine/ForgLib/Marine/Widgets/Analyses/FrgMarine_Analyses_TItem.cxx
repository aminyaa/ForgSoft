#include <FrgMarine_Analyses_TItem.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgMarine_HStaticsCrossCurves_TItem.hxx>
#include <FrgBase_Tree.hxx>

ForgMarineLib::FrgMarine_Analyses_TItem::FrgMarine_Analyses_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	ForgBaseLib::FrgBase_Menu* newAnalyseMenu = new ForgBaseLib::FrgBase_Menu("New Analysis", GetParentMainWindow());
	newAnalyseMenu->SetToolBarHidden(true);

	ForgBaseLib::FrgBase_Menu* hydrostaticsMenu = new ForgBaseLib::FrgBase_Menu("Hydrostatics", GetParentMainWindow());
	hydrostaticsMenu->SetToolBarHidden(true);
	newAnalyseMenu->addMenu(hydrostaticsMenu);

	auto newCrosscurvesAction = hydrostaticsMenu->AddItem("Cross Curves Analysis", false);

	theContextMenu_->addMenu(newAnalyseMenu);

	connect(newCrosscurvesAction, SIGNAL(triggered()), this, SLOT(NewHydrostaticsCrossCurvesClickedSlot()));
}

void ForgMarineLib::FrgMarine_Analyses_TItem::NewHydrostaticsCrossCurvesClickedSlot()
{
	auto hydroCrossCurvesItem = new FrgMarine_HStaticsCrossCurves_TItem("Cross Curves Analysis 01", this, GetParentTree());
	GetParentTree()->ScrollToItem(hydroCrossCurvesItem);
}