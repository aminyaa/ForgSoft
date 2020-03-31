#include <FrgVisual_Plot2DLeftAxis_TItem.hxx>
#include <FrgVisual_Plot2DAxisTitle_TItem.hxx>
#include <FrgVisual_Plot2DAxes_TItem.hxx>
#include <FrgVisual_Plot2D_TItem.hxx>
#include <FrgVisual_Plot2D.hxx>
#include <FrgBase_Tree.hxx>

ForgVisualLib::FrgVisual_Plot2DLeftAxis_TItem::FrgVisual_Plot2DLeftAxis_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree,
	FrgVisual_Plot2D_TItem* plot2DTItem
)
	: FrgVisual_Plot2DAxisEntity_TItem(itemTitle, parentItem, parentTree, plot2DTItem)
{
	theTitleTItem_ = new FrgVisual_Plot2DAxisTitle_TItem("Title", this, parentTree, plot2DTItem);
}

void ForgVisualLib::FrgVisual_Plot2DLeftAxis_TItem::VisibilityChangedSlot(const bool& condition)
{
	if (thePlot2DTItem_)
	{
		thePlot2DTItem_->SetLeftAxisVisible(condition);

		FrgVisual_Plot2DAxisEntity_TItem::VisibilityChangedSlot(!condition);
	}
}

void ForgVisualLib::FrgVisual_Plot2DLeftAxis_TItem::LogarithmicChangedSlot(const bool & condition)
{
	if (thePlot2DTItem_)
		thePlot2DTItem_->SetLeftAxisLogarithmic(condition);
}

void ForgVisualLib::FrgVisual_Plot2DLeftAxis_TItem::TItemClickedSlot()
{
	auto plot2D = thePlot2DTItem_->GetPlot2D();
	if (plot2D)
		plot2D->HighlightLeftAxis(true);
}

void ForgVisualLib::FrgVisual_Plot2DLeftAxis_TItem::TItemNotClickedSlot()
{
	if (theParentTree_->isItemSelected(this))
		return;

	auto plot2D = thePlot2DTItem_->GetPlot2D();
	if (plot2D)
		plot2D->HighlightLeftAxis(false);
}