#include <FrgVisual_Plot2D_TItem.hxx>
#include <FrgVisual_Plot2D.hxx>
#include <FrgBase_Global_Icons.hxx>

ForgVisualLib::FrgVisual_Plot2D_TItem::FrgVisual_Plot2D_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgVisual_Plot_TItem(itemTitle, parentItem, parentTree)
{
	this->setIcon(0, QIcon(ICONPlot_2D));

	thePlot_ = new FrgVisual_Plot2D(GetParentMainWindow());

	FrgVisual_Plot_TItem::Init();
}