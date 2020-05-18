#include <FrgVisual_Plot2DDataSeries_TItem.hxx>
#include <FrgVisual_Plot2DLnStyle_TItem.hxx>
#include <FrgVisual_Plot2DSmblStyle_TItem.hxx>
#include <FrgVisual_Plot2D_TItem.hxx>
#include <FrgVisual_Plot.hxx>

ForgVisualLib::FrgVisual_Plot2DDataSeries_TItem::FrgVisual_Plot2DDataSeries_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree,
	vtkPlot* VTKPlot
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
	, theVTKPlot_(VTKPlot)
{
	theLineStyle_ = new FrgVisual_Plot2DLnStyle_TItem("Line Style", this, parentTree);
	theSymbolStyle_ = new FrgVisual_Plot2DSmblStyle_TItem("Symbol Style", this, parentTree);
}

ForgVisualLib::FrgVisual_Plot2D_TItem * ForgVisualLib::FrgVisual_Plot2DDataSeries_TItem::GetPlot2DTItem() const
{
	auto parentPlot2DTItem = dynamic_cast<FrgVisual_Plot2D_TItem*>(QTreeWidgetItem::parent()->parent());

	if (!parentPlot2DTItem)
	{
		std::cout << "parentPlot2DTItem is null in void ForgVisualLib::FrgVisual_Plot2DDataSeries_TItem::RenderView() const\n";
		return nullptr;
	}

	return parentPlot2DTItem;
}

void ForgVisualLib::FrgVisual_Plot2DDataSeries_TItem::RenderView() const
{
	auto parentPlot2DTItem = GetPlot2DTItem();

	if (parentPlot2DTItem)
	{
		auto plot = parentPlot2DTItem->GetPlot();
		if (plot)
			plot->RenderView();
	}
}