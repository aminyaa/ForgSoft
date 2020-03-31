#include <FrgVisual_Plot2DAxes_TItem.hxx>
#include <FrgVisual_Plot2DBtmAxis_TItem.hxx>
#include <FrgVisual_Plot2DLeftAxis_TItem.hxx>
#include <FrgVisual_Plot2D_TItem.hxx>

ForgVisualLib::FrgVisual_Plot2DAxes_TItem::FrgVisual_Plot2DAxes_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
	, thePlot2DTItem_(dynamic_cast<FrgVisual_Plot2D_TItem*>(parentItem))
{
	theBottomAxisTItem_ = new FrgVisual_Plot2DBtmAxis_TItem("Bottom Axis", this, parentTree, thePlot2DTItem_);
	theLeftAxisTItem_ = new FrgVisual_Plot2DLeftAxis_TItem("Left Axis", this, parentTree, thePlot2DTItem_);
}

ForgVisualLib::FrgVisual_Plot2D_TItem * ForgVisualLib::FrgVisual_Plot2DAxes_TItem::GetPlot2dTItem() const
{
	auto plot2DTItem = dynamic_cast<FrgVisual_Plot2D_TItem*>(QTreeWidgetItem::parent());

	if (plot2DTItem)
		return plot2DTItem;

	return nullptr;
}

//void ForgVisualLib::FrgVisual_Plot2DAxes_TItem::SetBottomAxisTitle(const char * title)
//{
//	auto plot2DTItem = GetPlot2dTItem();
//
//	if (!plot2DTItem)
//	{
//		std::cout << "plot2DTitem is null in void ForgVisualLib::FrgVisual_Plot2DAxes_TItem::SetBottomAxisTitle(const char *)\n";
//		return;
//	}
//
//	plot2DTItem->SetBottomAxisTitle(title);
//}
//
//void ForgVisualLib::FrgVisual_Plot2DAxes_TItem::SetLeftAxisTitle(const char * title)
//{
//	auto plot2DTItem = GetPlot2dTItem();
//
//	if (!plot2DTItem)
//	{
//		std::cout << "plot2DTitem is null in void ForgVisualLib::FrgVisual_Plot2DAxes_TItem::SetLeftAxisTitle(const char *)\n";
//		return;
//	}
//
//	plot2DTItem->SetLeftAxisTitle(title);
//}
//
//void ForgVisualLib::FrgVisual_Plot2DAxes_TItem::SetBottomAxisTitleVisible(bool condition)
//{
//	auto plot2DTItem = GetPlot2dTItem();
//
//	if (!plot2DTItem)
//	{
//		std::cout << "plot2DTitem is null in void ForgVisualLib::FrgVisual_Plot2DAxes_TItem::SetBottomAxisTitleVisible(bool condition)\n";
//		return;
//	}
//
//	plot2DTItem->SetBottomAxisTitleVisible(condition);
//}
//
//void ForgVisualLib::FrgVisual_Plot2DAxes_TItem::SetLeftAxisTitleVisible(bool condition)
//{
//	auto plot2DTItem = GetPlot2dTItem();
//
//	if (!plot2DTItem)
//	{
//		std::cout << "plot2DTitem is null in void ForgVisualLib::FrgVisual_Plot2DAxes_TItem::SetLeftAxisTitleVisible(bool condition)\n";
//		return;
//	}
//
//	plot2DTItem->SetLeftAxisTitleVisible(condition);
//}
//
//void ForgVisualLib::FrgVisual_Plot2DAxes_TItem::SetBottomAxisVisible(bool condition)
//{
//	auto plot2DTItem = GetPlot2dTItem();
//
//	if (!plot2DTItem)
//	{
//		std::cout << "plot2DTitem is null in void ForgVisualLib::FrgVisual_Plot2DAxes_TItem::SetBottomAxisVisible(bool condition)\n";
//		return;
//	}
//
//	plot2DTItem->SetBottomAxisVisible(condition);
//}
//
//void ForgVisualLib::FrgVisual_Plot2DAxes_TItem::SetLeftAxisVisible(bool condition)
//{
//	auto plot2DTItem = GetPlot2dTItem();
//
//	if (!plot2DTItem)
//	{
//		std::cout << "plot2DTitem is null in void ForgVisualLib::FrgVisual_Plot2DAxes_TItem::SetLeftAxisVisible(bool condition)\n";
//		return;
//	}
//
//	plot2DTItem->SetLeftAxisVisible(condition);
//}