#include <FrgVisual_Plot2DLeftAxis_TItem.hxx>
#include <FrgVisual_Plot2DAxisTitle_TItem.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgVisual_Plot2DAxes_TItem.hxx>
#include <FrgVisual_Plot2D_TItem.hxx>
#include <FrgVisual_Plot2D.hxx>

//BOOST_CLASS_EXPORT_GUID(ForgVisualLib::FrgVisual_Plot2DLeftAxis_TItem, "ForgVisualLib::FrgVisual_Plot2DLeftAxis_TItem")
//BOOST_CLASS_EXPORT_IMPLEMENT(ForgVisualLib::FrgVisual_Plot2DLeftAxis_TItem)

ForgVisualLib::FrgVisual_Plot2DLeftAxis_TItem::FrgVisual_Plot2DLeftAxis_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree,
	FrgVisual_Plot2D_TItem* plot2DTItem
)
	: FrgVisual_Plot2DAxisEntity_TItem(itemTitle, parentItem, parentTree, plot2DTItem)
{
	theVisible_ = new ForgBaseLib::FrgBase_PrptsVrntBool("Visible", thePlot2DTItem_ ? thePlot2DTItem_->GetLeftAxisVisible() : true);
	theLogarithmic_ = new ForgBaseLib::FrgBase_PrptsVrntBool("Logarithmic", thePlot2DTItem_ ? thePlot2DTItem_->GetLeftAxisLogarithmic() : false);

	thePropertiesPanel_->AddRow(theVisible_);
	thePropertiesPanel_->AddRow(theLogarithmic_);

	theTitleTItem_ = new FrgVisual_Plot2DAxisTitle_TItem("Title", this, parentTree, plot2DTItem);

	connect(theVisible_, SIGNAL(ValueChangedSignal(const bool&)), this, SLOT(VisibilityChangedSlot(const bool&)));
	connect(theLogarithmic_, SIGNAL(ValueChangedSignal(const bool&)), this, SLOT(LogarithmicChangedSlot(const bool&)));
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

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Plot2DLeftAxis_TItem)
{

}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Plot2DLeftAxis_TItem)
{

}

DECLARE_SAVE_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DLeftAxis_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Plot2DLeftAxis_TItem)

		ForgVisualLib::FrgVisual_Plot2D_TItem* myPlot2DTItem = t->GetPlot2DTItem();

	ar & myPlot2DTItem;
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DLeftAxis_TItem)
{
	// ============================================
			// load FrgBase_TreeItem title
			// ============================================
	QString myTItemTitle;;
	ar & myTItemTitle;

	// ============================================
	// load FrgBase_TreeItem parentTItem
	// ============================================
	QString parentTItemIsNull;
	ForgBaseLib::FrgBase_TreeItem* parentTItem;

	ar & parentTItemIsNull;

	if (parentTItemIsNull == "PARENT_TITEM_IS_NULL")
		parentTItem = nullptr;
	else if (parentTItemIsNull == "PARENT_TITEM_IS_NOT_NULL")
		ar & parentTItem;

	// ============================================
	// load FrgBase_TreeItem parentTree
	// ============================================
	QString parentTreeIsNull;
	ForgBaseLib::FrgBase_Tree* parentTree;

	ar & parentTreeIsNull;

	if (parentTreeIsNull == "PARENT_TREE_IS_NULL")
		parentTree = nullptr;
	else if (parentTreeIsNull == "PARENT_TREE_IS_NOT_NULL")
		ar & parentTree;

	// =============================================================
	// invoke inplace constructor to initialize instance of my_class
	// =============================================================
	ForgVisualLib::FrgVisual_Plot2D_TItem* myPlot2DTItem;

	ar & myPlot2DTItem;

	::new(t)ForgVisualLib::FrgVisual_Plot2DLeftAxis_TItem(myTItemTitle, parentTItem, parentTree, myPlot2DTItem);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Plot2DLeftAxis_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DLeftAxis_TItem)