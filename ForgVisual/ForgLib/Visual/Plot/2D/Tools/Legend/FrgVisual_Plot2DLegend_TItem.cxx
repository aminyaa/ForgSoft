#include <FrgVisual_Plot2DLegend_TItem.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgVisual_Plot2D_TItem.hxx>
#include <FrgVisual_Plot.hxx>

#include <vtkChartXY.h>
#include <vtkChartLegend.h>
#include <vtkContextView.h>

ForgVisualLib::FrgVisual_Plot2DLegend_TItem::FrgVisual_Plot2DLegend_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
	, thePlot2DTItem_(dynamic_cast<FrgVisual_Plot2D_TItem*>(parentItem))
{
	this->setIcon(0, QIcon(ICONTreeItemCircle));

	theVisible_ = new ForgBaseLib::FrgBase_PrptsVrntBool("Visible", true);

	std::vector<const char*> positionItems;
	positionItems.push_back("North");
	positionItems.push_back("North East");
	positionItems.push_back("East");
	positionItems.push_back("South East");
	positionItems.push_back("South");
	positionItems.push_back("South West");
	positionItems.push_back("West");
	positionItems.push_back("North West");
	positionItems.push_back("Custom");
	
	thePosition_ = new ForgBaseLib::FrgBase_PrptsVrntCombo(positionItems, "Position", "North East");

	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntBool>(theVisible_);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntCombo>(thePosition_);

	connect(theVisible_, SIGNAL(ValueChangedSignal(const bool&)), this, SLOT(VisibilityChangedSlot(const bool&)));
	connect(thePosition_, SIGNAL(ValueChangedSignal(const char*)), this, SLOT(PositionChangedSlot(const char*)));
}

void ForgVisualLib::FrgVisual_Plot2DLegend_TItem::VisibilityChangedSlot(const bool& condition)
{
	if (!thePlot2DTItem_)
	{
		std::cout << "theParentPlot2DTItem_ is null in void ForgVisualLib::FrgVisual_Plot2DLegend_TItem::VisibilityChangedSlot(const bool& condition)\n";
		return;
	}

	thePlot2DTItem_->SetLegendVisible(condition);
}

void ForgVisualLib::FrgVisual_Plot2DLegend_TItem::PositionChangedSlot(const char * position)
{
	if (!thePlot2DTItem_)
	{
		std::cout << "theParentPlot2DTItem_ is null in void ForgVisualLib::FrgVisual_Plot2DLegend_TItem::PositionChangedSlot(const char * position)\n";
		return;
	}

	if (!std::strcmp(position, "Custom"))
	{
		auto legend = thePlot2DTItem_->GetPlot()->GetChartXY()->GetLegend();
		legend->SetInline(true);
		legend->SetDragEnabled(true);
	}
	else
	{
		auto legend = thePlot2DTItem_->GetPlot()->GetChartXY()->GetLegend();
		legend->SetInline(false);
		legend->SetDragEnabled(false);
	}

	thePlot2DTItem_->GetPlot()->GetView()->Render();
}