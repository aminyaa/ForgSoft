#include <FrgMarine_Plots_TItem.hxx>
#include <FrgMarine_Plot2D_TItem.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgMarine_Tree.hxx>
#include <FrgBase_Global_Icons.hxx>

ForgMarineLib::FrgMarine_Plots_TItem::FrgMarine_Plots_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	ForgBaseLib::FrgBase_Menu* newMenu = new ForgBaseLib::FrgBase_Menu("New", GetParentMainWindow());
	newMenu->SetToolBarHidden(true);
	auto addPlot2DAction = newMenu->AddItem("2D", false);
	addPlot2DAction->setIcon(QIcon(ICONPlot_2D));
	GetContextMenu()->addMenu(newMenu);

	connect(addPlot2DAction, SIGNAL(triggered()), this, SLOT(AddPlot2DSlot()));
}

ForgMarineLib::FrgMarine_Plot2D_TItem * ForgMarineLib::FrgMarine_Plots_TItem::AddPlot2D()
{
	auto plotItem = new FrgMarine_Plot2D_TItem("Plot 01", this, GetParentTree());
	GetParentTree()->ScrollToItem(plotItem);

	return plotItem;
}

void ForgMarineLib::FrgMarine_Plots_TItem::AddPlot2DSlot()
{
	AddPlot2D();
}