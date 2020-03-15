#include <FrgVisual_Plot2DSmblStyle_TItem.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgVisual_Plot2DDataSeries_TItem.hxx>

#include <vtkPlotPoints.h>

ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem::FrgVisual_Plot2DSmblStyle_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	this->setIcon(0, QIcon(ICONTreeItemCircle));

	std::vector<const char*> items;
	items.push_back("None");
	items.push_back("Cross");
	items.push_back("Plus");
	items.push_back("Square");
	items.push_back("Circle");
	items.push_back("Diamond");

	theShape_ = new ForgBaseLib::FrgBase_PrptsVrntCombo(items, "Shape", items[0]);
	theSize_ = new ForgBaseLib::FrgBase_PrptsVrntInt("Size", 6, 1, 50);
	theSpacing_ = new ForgBaseLib::FrgBase_PrptsVrntInt("Spacing", 1, 1, 1E50);

	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntCombo>(theShape_);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntInt>(theSize_);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntInt>(theSpacing_);

	connect(theShape_, SIGNAL(ValueChangedSignal(const char*)), this, SLOT(ShapeChangedSlot(const char*)));
	connect(theSize_, SIGNAL(ValueChangedSignal(const int&)), this, SLOT(SizeChangedSlot(const int&)));
	connect(theSpacing_, SIGNAL(ValueChangedSignal(const int&)), this, SLOT(SpacingChangedSlot(const int&)));
}

ForgVisualLib::FrgVisual_Plot2DDataSeries_TItem * ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem::GetDataSeries() const
{
	auto parentDataSeries = dynamic_cast<FrgVisual_Plot2DDataSeries_TItem*>(QTreeWidgetItem::parent());
	if (!parentDataSeries)
	{
		std::cout << "parentDataSeries is null in vtkPlot * ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem::GetVTKPlot() const\n";
		return nullptr;
	}

	return parentDataSeries;
}

vtkPlot * ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem::GetVTKPlot() const
{
	auto parentDataSeries = GetDataSeries();
	if (parentDataSeries)
		return parentDataSeries->GetVTKPlot();

	return nullptr;
}

void ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem::RenderView() const
{
	auto parentDataSeries = GetDataSeries();
	if (parentDataSeries)
		parentDataSeries->RenderView();
}

void ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem::ShapeChangedSlot(const char* shape)
{
	auto VTKPlot = GetVTKPlot();
	if (VTKPlot)
	{
		auto VTKPlotPoints = vtkPlotPoints::SafeDownCast(VTKPlot);
		if (VTKPlotPoints)
		{
			if (!std::strcmp(shape, "None"))
				VTKPlotPoints->SetMarkerStyle(vtkPlotPoints::NONE);
			else if (!std::strcmp(shape, "Cross"))
				VTKPlotPoints->SetMarkerStyle(vtkPlotPoints::CROSS);
			else if (!std::strcmp(shape, "Plus"))
				VTKPlotPoints->SetMarkerStyle(vtkPlotPoints::PLUS);
			else if (!std::strcmp(shape, "Square"))
				VTKPlotPoints->SetMarkerStyle(vtkPlotPoints::SQUARE);
			else if (!std::strcmp(shape, "Circle"))
				VTKPlotPoints->SetMarkerStyle(vtkPlotPoints::CIRCLE);
			else if (!std::strcmp(shape, "Diamond"))
				VTKPlotPoints->SetMarkerStyle(vtkPlotPoints::DIAMOND);

			this->RenderView();
		}
	}
}

void ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem::SizeChangedSlot(const int & size)
{
	auto VTKPlot = GetVTKPlot();
	if (VTKPlot)
	{
		auto VTKPlotPoints = dynamic_cast<vtkPlotPoints*>(VTKPlot);
		if (VTKPlotPoints)
		{
			VTKPlotPoints->SetMarkerSize(size);

			this->RenderView();
		}
	}
}

void ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem::SpacingChangedSlot(const int & spacing)
{
	auto VTKPlot = GetVTKPlot();
	if (VTKPlot)
	{
		auto VTKPlotPoints = dynamic_cast<vtkPlotPoints*>(VTKPlot);
		if (VTKPlotPoints)
		{

		}
	}
}