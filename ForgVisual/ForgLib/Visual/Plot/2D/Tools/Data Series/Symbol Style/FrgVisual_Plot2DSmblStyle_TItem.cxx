#include <FrgVisual_Plot2DSmblStyle_TItem.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgVisual_Plot2DDataSeries_TItem.hxx>
#include <FrgBase_Icon.hxx>

#include <FrgBase_SerialSpec_QString.hxx>
#include <FrgBase_Tree.hxx>

#include <vtkPlotPoints.h>

#define SYMBOL_NONE "None"
#define SYMBOL_CROSS "Cross"
#define SYMBOL_PLUS "Plus"
#define SYMBOL_SQUARE "Square"
#define SYMBOL_CIRCLE "Circle"
#define SYMBOL_DIAMOND "Diamond"

//BOOST_CLASS_EXPORT_GUID(ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem, "ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem")
//BOOST_CLASS_EXPORT_IMPLEMENT(ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem)

ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem::FrgVisual_Plot2DSmblStyle_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	this->SetIcon(0, ForgBaseLib::FrgBase_Icon(ICONTreeItemCircle));

	std::vector<QString> items;
	items.push_back(SYMBOL_NONE);
	items.push_back(SYMBOL_CROSS);
	items.push_back(SYMBOL_PLUS);
	items.push_back(SYMBOL_SQUARE);
	items.push_back(SYMBOL_CIRCLE);
	items.push_back(SYMBOL_DIAMOND);

	theShape_ = new ForgBaseLib::FrgBase_PrptsVrntCombo(items, "Shape", GetShapeFromVTKPlot());

	theSize_ = new ForgBaseLib::FrgBase_PrptsVrntInt("Size", GetSymbolSizeFromVTKPlot(), 1, 50);
	theSpacing_ = new ForgBaseLib::FrgBase_PrptsVrntInt("Spacing", 1, 1, 1E50);

	thePropertiesPanel_->AddRow(theShape_);
	thePropertiesPanel_->AddRow(theSize_);
	thePropertiesPanel_->AddRow(theSpacing_);

	connect(theShape_, SIGNAL(ValueChangedSignal(const QString&)), this, SLOT(ShapeChangedSlot(const QString&)));
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

QString ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem::GetShapeFromVTKPlot() const
{
	auto VTKPlot = GetVTKPlot();
	if (VTKPlot)
	{
		auto VTKPlotPoints = vtkPlotPoints::SafeDownCast(VTKPlot);
		if (VTKPlotPoints)
		{
			auto myMarkerStyle = VTKPlotPoints->GetMarkerStyle();

			if (myMarkerStyle == vtkPlotPoints::NONE)
				return SYMBOL_NONE;
			else if (myMarkerStyle == vtkPlotPoints::CROSS)
				return SYMBOL_CROSS;
			else if (myMarkerStyle == vtkPlotPoints::PLUS)
				return SYMBOL_PLUS;
			else if (myMarkerStyle == vtkPlotPoints::SQUARE)
				return SYMBOL_SQUARE;
			else if (myMarkerStyle == vtkPlotPoints::CIRCLE)
				return SYMBOL_CIRCLE;
			else if (myMarkerStyle == vtkPlotPoints::DIAMOND)
				return SYMBOL_DIAMOND;

			this->RenderView();
		}
	}

	return SYMBOL_NONE;
}

float ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem::GetSymbolSizeFromVTKPlot() const
{
	auto VTKPlot = GetVTKPlot();
	if (VTKPlot)
	{
		auto VTKPlotPoints = vtkPlotPoints::SafeDownCast(VTKPlot);
		if (VTKPlotPoints)
			return VTKPlotPoints->GetMarkerSize();
	}

	return 1.0f;
}

void ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem::ShapeChangedSlot(const QString& shape)
{
	if (sender() != theShape_)
	{
		theShape_->SetValue(shape);
		return;
	}

	auto VTKPlot = GetVTKPlot();
	if (VTKPlot)
	{
		auto VTKPlotPoints = vtkPlotPoints::SafeDownCast(VTKPlot);
		if (VTKPlotPoints)
		{
			if (shape == SYMBOL_NONE)
				VTKPlotPoints->SetMarkerStyle(vtkPlotPoints::NONE);
			else if (shape == SYMBOL_CROSS)
				VTKPlotPoints->SetMarkerStyle(vtkPlotPoints::CROSS);
			else if (shape == SYMBOL_PLUS)
				VTKPlotPoints->SetMarkerStyle(vtkPlotPoints::PLUS);
			else if (shape == SYMBOL_SQUARE)
				VTKPlotPoints->SetMarkerStyle(vtkPlotPoints::SQUARE);
			else if (shape == SYMBOL_CIRCLE)
				VTKPlotPoints->SetMarkerStyle(vtkPlotPoints::CIRCLE);
			else if (shape == SYMBOL_DIAMOND)
				VTKPlotPoints->SetMarkerStyle(vtkPlotPoints::DIAMOND);

			this->RenderView();
		}
	}
}

void ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem::SizeChangedSlot(const int & size)
{
	if (sender() != theSize_)
	{
		theSize_->SetValue(size);
		return;
	}

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
	if (sender() != theSpacing_)
	{
		theSpacing_->SetValue(spacing);
		return;
	}

	auto VTKPlot = GetVTKPlot();
	if (VTKPlot)
	{
		auto VTKPlotPoints = dynamic_cast<vtkPlotPoints*>(VTKPlot);
		if (VTKPlotPoints)
		{

		}
	}
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem)
{

}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem)
{

}

DECLARE_SAVE_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem)
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem)
}

BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DSmblStyle_TItem)