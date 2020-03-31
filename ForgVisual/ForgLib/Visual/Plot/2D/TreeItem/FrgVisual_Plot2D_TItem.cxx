#include <FrgVisual_Plot2D_TItem.hxx>
#include <FrgVisual_Plot2D.hxx>
#include <FrgBase_Global_Icons.hxx>
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

	theDataSeriesTItem_ = new ForgBaseLib::FrgBase_TreeItem("Data Series", this, parentTree);
	theAxesTItem_ = new FrgVisual_Plot2DAxes_TItem("Axes", this, parentTree);
	theLegendTItem_ = new FrgVisual_Plot2DLegend_TItem("Legend", this, parentTree);
}

ForgVisualLib::FrgVisual_Plot2D * ForgVisualLib::FrgVisual_Plot2D_TItem::GetPlot2D() const
{
	auto plot2D = dynamic_cast<FrgVisual_Plot2D*>(thePlot_);

	if (plot2D)
		return plot2D;

	return nullptr;
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetLegendVisible(bool condition)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetLegendVisible(condition);
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetBottomAxisTitle(const char * title)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetBottomAxisTitle(title);
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetLeftAxisTitle(const char * title)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetLeftAxisTitle(title);
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetBottomAxisTitleVisible(bool condition)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetBottomAxisTitleVisible(condition);
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetLeftAxisTitleVisible(bool condition)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetLeftAxisTitleVisible(condition);
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetBottomAxisVisible(bool condition)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetBottomAxisVisible(condition);
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetLeftAxisVisible(bool condition)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetLeftAxisVisible(condition);
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetBottomAxisLogarithmic(bool condition)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetBottomAxisLogarithmic(condition);
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetLeftAxisLogarithmic(bool condition)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetLeftAxisLogarithmic(condition);
}

vtkPlot* ForgVisualLib::FrgVisual_Plot2D_TItem::AddPlot(std::vector<double> x, std::vector<double> y, const char* title)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
	{
		auto sinXTItem = new FrgVisual_Plot2DDataSeries_TItem(title, theDataSeriesTItem_, GetParentTree());
		auto VTKPlot = plot2D->AddPlot(x, y, title);
		sinXTItem->SetVTKPlot(VTKPlot);

		return VTKPlot;
	}

	return nullptr;
}

vtkPlot* ForgVisualLib::FrgVisual_Plot2D_TItem::AddPlotSinXSlot()
{
	auto plot2D = GetPlot2D();

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
	auto plot2D = GetPlot2D();

	if (plot2D)
	{
		auto cosXTItem = new FrgVisual_Plot2DDataSeries_TItem("Cos(x)", theDataSeriesTItem_, GetParentTree());
		auto VTKPlot = plot2D->AddCosX(cosXTItem->text(0).toStdString().c_str());
		cosXTItem->SetVTKPlot(VTKPlot);

		return VTKPlot;
	}

	return nullptr;
}