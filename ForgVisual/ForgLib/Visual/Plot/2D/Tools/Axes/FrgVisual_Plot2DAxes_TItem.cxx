#include <FrgVisual_Plot2DAxes_TItem.hxx>
#include <FrgVisual_Plot2DBtmAxis_TItem.hxx>
#include <FrgVisual_Plot2DLeftAxis_TItem.hxx>
#include <FrgVisual_Plot2D_TItem.hxx>
#include <FrgBase_Tree.hxx>

//BOOST_CLASS_EXPORT_GUID(ForgVisualLib::FrgVisual_Plot2DAxes_TItem, "ForgVisualLib::FrgVisual_Plot2DAxes_TItem")
//BOOST_CLASS_EXPORT_IMPLEMENT(ForgVisualLib::FrgVisual_Plot2DAxes_TItem)

ForgVisualLib::FrgVisual_Plot2DAxes_TItem::FrgVisual_Plot2DAxes_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
	, thePlot2DTItem_(dynamic_cast<FrgVisual_Plot2D_TItem*>(parentItem))
{
	FormAxes();
}

void ForgVisualLib::FrgVisual_Plot2DAxes_TItem::FormAxes()
{
	theBottomAxisTItem_ = new FrgVisual_Plot2DBtmAxis_TItem("Bottom Axis", this, GetParentTree(), thePlot2DTItem_);
	theLeftAxisTItem_ = new FrgVisual_Plot2DLeftAxis_TItem("Left Axis", this, GetParentTree(), thePlot2DTItem_);
}

ForgVisualLib::FrgVisual_Plot2D_TItem * ForgVisualLib::FrgVisual_Plot2DAxes_TItem::GetPlot2DTItem() const
{
	auto plot2DTItem = dynamic_cast<FrgVisual_Plot2D_TItem*>(QTreeWidgetItem::parent());

	if (plot2DTItem)
		return plot2DTItem;

	return nullptr;
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Plot2DAxes_TItem)
{
	ar & theBottomAxisTItem_;
	ar & theLeftAxisTItem_;
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Plot2DAxes_TItem)
{
	ar & theBottomAxisTItem_;
	ar & theLeftAxisTItem_;
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DAxes_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Plot2DAxes_TItem)
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DAxes_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Plot2DAxes_TItem)
}

BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DAxes_TItem)