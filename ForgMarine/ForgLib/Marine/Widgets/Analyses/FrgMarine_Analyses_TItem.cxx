#include <FrgMarine_Analyses_TItem.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgMarine_AnalysisHStatics_TItem.hxx>
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

	auto newHydrostaticsAction = newAnalyseMenu->AddItem("Hydrostatics", false);

	theContextMenu_->addMenu(newAnalyseMenu);

	connect(newHydrostaticsAction, SIGNAL(triggered()), this, SLOT(NewHydrostaticsClickedSlot()));
}

void ForgMarineLib::FrgMarine_Analyses_TItem::NewHydrostaticsClickedSlot()
{
	auto hydroItem = new FrgMarine_AnalysisHStatics_TItem("Hydrostatics 01", this, GetParentTree());
	GetParentTree()->ScrollToItem(hydroItem);
}