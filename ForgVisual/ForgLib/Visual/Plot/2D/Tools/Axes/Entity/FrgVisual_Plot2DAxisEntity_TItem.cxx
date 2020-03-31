#include <FrgVisual_Plot2DAxisEntity_TItem.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgVisual_Plot2DAxisTitle_TItem.hxx>
#include <FrgVisual_Plot2DAxes_TItem.hxx>

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
	theVisible_ = new ForgBaseLib::FrgBase_PrptsVrntBool("Visible", true);
	theLogarithmic_ = new ForgBaseLib::FrgBase_PrptsVrntBool("Logarithmic", false);

	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntBool>(theVisible_);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntBool>(theLogarithmic_);

	//theTitleTItem_ = new FrgVisual_Plot2DAxisTitle_TItem("Title", this, parentTree, plot2DTItem);

	connect(theVisible_, SIGNAL(ValueChangedSignal(const bool&)), this, SLOT(VisibilityChangedSlot(const bool&)));
	connect(theLogarithmic_, SIGNAL(ValueChangedSignal(const bool&)), this, SLOT(LogarithmicChangedSlot(const bool&)));
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