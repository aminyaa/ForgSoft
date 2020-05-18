#include <FrgVisual_Plot2DAxisEntity_TItem.hxx>
#include <FrgVisual_Plot2DAxisTitle_TItem.hxx>
#include <FrgVisual_Plot2DAxes_TItem.hxx>
#include <FrgBase_Tree.hxx>
#include <FrgVisual_Plot2D_TItem.hxx>
#include <FrgVisual_Plot2DLegend_TItem.hxx>

//BOOST_CLASS_EXPORT_IMPLEMENT(ForgVisualLib::FrgVisual_Plot2DAxisEntity_TItem)

ForgVisualLib::FrgVisual_Plot2DAxisEntity_TItem::FrgVisual_Plot2DAxisEntity_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree,
	FrgVisual_Plot2D_TItem* plot2DTItem
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
	, thePlot2DTItem_(plot2DTItem)
{
	
}

ForgVisualLib::FrgVisual_Plot2DAxes_TItem * ForgVisualLib::FrgVisual_Plot2DAxisEntity_TItem::GetPlot2DAxesTItem() const
{
	auto plot2DAxesTItem = dynamic_cast<FrgVisual_Plot2DAxes_TItem*>(QTreeWidgetItem::parent());

	if (plot2DAxesTItem)
		return plot2DAxesTItem;

	return nullptr;
}

void ForgVisualLib::FrgVisual_Plot2DAxisEntity_TItem::VisibilityChangedSlot(const bool& condition)
{
	auto listOfChildren = this->GetChildren();

	for (int i = 0; i < listOfChildren.size(); i++)
		listOfChildren[i]->setHidden(condition);
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Plot2DAxisEntity_TItem)
{

}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Plot2DAxisEntity_TItem)
{

}

DECLARE_SAVE_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DAxisEntity_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Plot2DAxisEntity_TItem)

		ForgVisualLib::FrgVisual_Plot2D_TItem* myPlot2DTItem = t->GetPlot2DTItem();

	ar & myPlot2DTItem;
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DAxisEntity_TItem)
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

	::new(t)ForgVisualLib::FrgVisual_Plot2DAxisEntity_TItem(myTItemTitle, parentTItem, parentTree, myPlot2DTItem);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Plot2DAxisEntity_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DAxisEntity_TItem)