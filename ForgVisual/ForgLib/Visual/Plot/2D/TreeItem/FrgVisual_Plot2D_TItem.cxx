#include <FrgVisual_Plot2D_TItem.hxx>
#include <FrgVisual_Plot2D.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgVisual_Plot2DDataSeries_TItem.hxx>
#include <FrgVisual_Plot2DAxes_TItem.hxx>
#include <FrgVisual_Plot2DLegend_TItem.hxx>

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

	theBottomAxisTitle = new ForgBaseLib::FrgBase_PrptsVrntString("Bottom Axis Title", "X Axis");
	theLeftAxisTitle = new ForgBaseLib::FrgBase_PrptsVrntString("Left Axis Title", "Y Axis");

	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntString>(theBottomAxisTitle);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntString>(theLeftAxisTitle);

	theDataSeriesTItem_ = new ForgBaseLib::FrgBase_TreeItem("Data Series", this, parentTree);
	theAxesTItem_ = new FrgVisual_Plot2DAxes_TItem("Axes", this, parentTree);
	theLegendTItem_ = new FrgVisual_Plot2DLegend_TItem("Legend", this, parentTree);
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetLegendVisible(bool condition)
{
	auto plot2D = dynamic_cast<FrgVisual_Plot2D*>(thePlot_);

	if (plot2D)
		plot2D->SetLegendVisible(condition);
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetBottomTitle(const char * title)
{
	auto plot2D = dynamic_cast<FrgVisual_Plot2D*>(thePlot_);

	if (plot2D)
		plot2D->SetBottomTitle(title);
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetLeftTitle(const char * title)
{
	auto plot2D = dynamic_cast<FrgVisual_Plot2D*>(thePlot_);

	if (plot2D)
		plot2D->SetLeftTitle(title);
}

vtkPlot* ForgVisualLib::FrgVisual_Plot2D_TItem::AddPlotSinXSlot()
{
	auto plot2D = dynamic_cast<FrgVisual_Plot2D*>(thePlot_);

	if (plot2D)
	{
		auto sinXTItem = new FrgVisual_Plot2DDataSeries_TItem("Sin(x)", theDataSeriesTItem_, GetParentTree());
		auto VTKPlot = plot2D->AddSinX(sinXTItem->text(0).toStdString().c_str());
		sinXTItem->SetVTKPlot(VTKPlot);
	
		return VTKPlot;
	}

	return nullptr;
}

vtkPlot* ForgVisualLib::FrgVisual_Plot2D_TItem::AddPlotCosXSlot()
{
	auto plot2D = dynamic_cast<FrgVisual_Plot2D*>(thePlot_);

	if (plot2D)
	{
		auto cosXTItem = new FrgVisual_Plot2DDataSeries_TItem("Cos(x)", theDataSeriesTItem_, GetParentTree());
		auto VTKPlot = plot2D->AddCosX(cosXTItem->text(0).toStdString().c_str());
		cosXTItem->SetVTKPlot(VTKPlot);

		return VTKPlot;
	}
	return nullptr;
}