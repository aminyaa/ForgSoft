#include <FrgMarine_TItem_Analysis.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgMarine_TItemAnlys_Hydrostatics.hxx>

ForgMarineLib::FrgMarine_TItem_Analysis::FrgMarine_TItem_Analysis
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	ForgBaseLib::FrgBase_Menu* newAnalyseMenu = new ForgBaseLib::FrgBase_Menu("New Analyse", GetParentMainWindow());

	auto newHydrostaticsAction = newAnalyseMenu->AddItem("Hydrostatics", false);

	theContextMenu_->addMenu(newAnalyseMenu);

	connect(newHydrostaticsAction, SIGNAL(triggered()), this, SLOT(NewHydrostaticsClickedSlot()));
}

void ForgMarineLib::FrgMarine_TItem_Analysis::NewHydrostaticsClickedSlot()
{
	auto hydroItem = new FrgMarine_TItemAnlys_Hydrostatics("", this, GetParentTree());
	hydroItem->RenameTItemSlot("Hydrostatics 01");
}