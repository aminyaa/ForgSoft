#include <FrgVisual_Plot2DLegend_TItem.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgVisual_Plot2D_TItem.hxx>
#include <FrgVisual_Plot.hxx>
#include <FrgBase_Tree.hxx>

#include <vtkChartXY.h>
#include <vtkChartLegend.h>
#include <vtkContextView.h>

#define LEGEND_POSITION_NORTH_TEXT "North"
#define LEGEND_POSITION_NORTH_EAST_TEXT "North East"
#define LEGEND_POSITION_EAST_TEXT "East"
#define LEGEND_POSITION_SOUTH_EAST_TEXT "South East"
#define LEGEND_POSITION_SOUTH_TEXT "South"
#define LEGEND_POSITION_SOUTH_WEST_TEXT "South West"
#define LEGEND_POSITION_WEST_TEXT "West"
#define LEGEND_POSITION_NORTH_WEST_TEXT "North West"
#define LEGEND_POSITION_CUSTOM_TEXT "Custom"

//BOOST_CLASS_EXPORT_GUID(ForgVisualLib::FrgVisual_Plot2DLegend_TItem, "ForgVisualLib::FrgVisual_Plot2DLegend_TItem")

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

	theVisible_ = new ForgBaseLib::FrgBase_PrptsVrntBool("Visible", thePlot2DTItem_ ? thePlot2DTItem_->GetLegendVisible() : true);

	std::vector<QString> positionItems;
	positionItems.push_back(LEGEND_POSITION_NORTH_TEXT);
	positionItems.push_back(LEGEND_POSITION_NORTH_EAST_TEXT);
	positionItems.push_back(LEGEND_POSITION_EAST_TEXT);
	positionItems.push_back(LEGEND_POSITION_SOUTH_EAST_TEXT);
	positionItems.push_back(LEGEND_POSITION_SOUTH_TEXT);
	positionItems.push_back(LEGEND_POSITION_SOUTH_WEST_TEXT);
	positionItems.push_back(LEGEND_POSITION_WEST_TEXT);
	positionItems.push_back(LEGEND_POSITION_NORTH_WEST_TEXT);
	positionItems.push_back(LEGEND_POSITION_CUSTOM_TEXT);
	
	thePosition_ = new ForgBaseLib::FrgBase_PrptsVrntCombo(positionItems, "Position", GetLegendPositionFromPlot2DTItem());

	thePropertiesPanel_->AddRow(theVisible_);
	thePropertiesPanel_->AddRow(thePosition_);

	connect(theVisible_, SIGNAL(ValueChangedSignal(const bool&)), this, SLOT(VisibilityChangedSlot(const bool&)));
	connect(thePosition_, SIGNAL(ValueChangedSignal(const QString&)), this, SLOT(PositionChangedSlot(const QString&)));
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

void ForgVisualLib::FrgVisual_Plot2DLegend_TItem::PositionChangedSlot(const QString& position)
{
	if (!thePlot2DTItem_)
	{
		std::cout << "theParentPlot2DTItem_ is null in void ForgVisualLib::FrgVisual_Plot2DLegend_TItem::PositionChangedSlot(const char * position)\n";
		return;
	}

	if (position == LEGEND_POSITION_NORTH_TEXT)
		thePlot2DTItem_->SetLegendPosition(NORTH);
	else if (position == LEGEND_POSITION_NORTH_EAST_TEXT)
		thePlot2DTItem_->SetLegendPosition(NORTH_EAST);
	else if (position == LEGEND_POSITION_EAST_TEXT)
		thePlot2DTItem_->SetLegendPosition(EAST);
	else if (position == LEGEND_POSITION_SOUTH_EAST_TEXT)
		thePlot2DTItem_->SetLegendPosition(SOUTH_EAST);
	else if (position == LEGEND_POSITION_SOUTH_TEXT)
		thePlot2DTItem_->SetLegendPosition(SOUTH);
	else if (position == LEGEND_POSITION_SOUTH_WEST_TEXT)
		thePlot2DTItem_->SetLegendPosition(SOUTH_WEST);
	else if (position == LEGEND_POSITION_WEST_TEXT)
		thePlot2DTItem_->SetLegendPosition(WEST);
	else if (position == LEGEND_POSITION_NORTH_WEST_TEXT)
		thePlot2DTItem_->SetLegendPosition(NORTH_WEST);
	else if (position == LEGEND_POSITION_CUSTOM_TEXT)
		thePlot2DTItem_->SetLegendPosition(CUSTOM);
}

QString ForgVisualLib::FrgVisual_Plot2DLegend_TItem::GetLegendPositionFromPlot2DTItem() const
{
	if (!thePlot2DTItem_)
	{
		std::cout << "theParentPlot2DTItem_ is null in void ForgVisualLib::FrgVisual_Plot2DLegend_TItem::GetLegendPositionFromPlot2dTItem() const\n";
		return LEGEND_POSITION_NORTH_EAST_TEXT;
	}

	auto position = thePlot2DTItem_->GetLegendPosition();

	if (position == NORTH)
		return LEGEND_POSITION_NORTH_TEXT;
	else if (position == NORTH_EAST)
		return LEGEND_POSITION_NORTH_EAST_TEXT;
	else if (position == EAST)
		return LEGEND_POSITION_EAST_TEXT;
	else if (position == SOUTH_EAST)
		return LEGEND_POSITION_SOUTH_EAST_TEXT;
	else if (position == SOUTH)
		return LEGEND_POSITION_SOUTH_TEXT;
	else if (position == SOUTH_WEST)
		return LEGEND_POSITION_SOUTH_WEST_TEXT;
	else if (position == WEST)
		return LEGEND_POSITION_WEST_TEXT;
	else if (position == NORTH_WEST)
		return LEGEND_POSITION_NORTH_WEST_TEXT;
	else if (position == CUSTOM)
		return LEGEND_POSITION_CUSTOM_TEXT;
	else if (position == NOT_VALID)
		return LEGEND_POSITION_NORTH_EAST_TEXT;
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Plot2DLegend_TItem)
{

}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Plot2DLegend_TItem)
{

}

DECLARE_SAVE_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DLegend_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Plot2DLegend_TItem)
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DLegend_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Plot2DLegend_TItem)
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Plot2DLegend_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DLegend_TItem)