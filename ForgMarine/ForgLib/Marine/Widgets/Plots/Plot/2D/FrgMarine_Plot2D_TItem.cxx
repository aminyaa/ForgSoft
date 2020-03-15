#include <FrgMarine_Plot2D_TItem.hxx>
#include <FrgMarine_MainWindow.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgMarine_Tree.hxx>
#include <FrgVisual_Plot2D.hxx>

#include <FrgVisual_Plot.hxx>

ForgMarineLib::FrgMarine_Plot2D_TItem::FrgMarine_Plot2D_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgVisual_Plot2D_TItem(itemTitle, parentItem, parentTree)
{
	GetContextMenu()->addSeparator();

	ForgBaseLib::FrgBase_Menu* newPredefinedFunctions = new ForgBaseLib::FrgBase_Menu("New Predefined Functions", GetParentMainWindow());

	auto sinAction = newPredefinedFunctions->AddItem("Sin(x)", false);
	auto cosAction = newPredefinedFunctions->AddItem("Cos(x)", false);

	connect(sinAction, SIGNAL(triggered()), this, SLOT(AddPlotSinXSlot()));
	connect(cosAction, SIGNAL(triggered()), this, SLOT(AddPlotCosXSlot()));

	GetContextMenu()->addMenu(newPredefinedFunctions);
}