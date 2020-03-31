#include <FrgVisual_Plot2DLnStyle_TItem.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgVisual_Plot2DDataSeries_TItem.hxx>

#include <vtkPlot.h>
#include <vtkPen.h>

ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem::FrgVisual_Plot2DLnStyle_TItem
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
	items.push_back("Solid Line");
	items.push_back("Dash Line");
	items.push_back("Dot Line");
	items.push_back("Dash Dot Line");
	items.push_back("Dash Dot Dot Line");

	theStyle_ = new ForgBaseLib::FrgBase_PrptsVrntCombo(items, "Style", items[1]);

	double color[3] = { 255, 255, 255 };
	//GetVTKPlot()->GetPen()->GetColorF(color);
	theColor_ = new ForgBaseLib::FrgBase_PrptsVrntColor("Color", QColor(255 * color[0], 255 * color[1], 255 * color[2]));
	theWidth_ = new ForgBaseLib::FrgBase_PrptsVrntInt("Width", 1, 1, 10);
	theOpacity_ = new ForgBaseLib::FrgBase_PrptsVrntDouble("Opacity", 1.0, 0.0, 1.0, 0.05);

	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntCombo>(theStyle_);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntColor>(theColor_);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntInt>(theWidth_);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntDouble>(theOpacity_);

	connect(theStyle_, SIGNAL(ValueChangedSignal(const char*)), this, SLOT(StyleChangedSlot(const char*)));
	connect(theColor_, SIGNAL(ValueChangedSignal(const QColor&)), this, SLOT(ColorChangedSlot(const QColor&)));
	connect(theWidth_, SIGNAL(ValueChangedSignal(const int&)), this, SLOT(WidthChangedSlot(const int&)));
	connect(theOpacity_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(OpacityChangedSlot(const double&)));
}

vtkPlot * ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem::GetVTKPlot() const
{
	auto parentDataSeries = dynamic_cast<FrgVisual_Plot2DDataSeries_TItem*>(QTreeWidgetItem::parent());
	if (!parentDataSeries)
	{
		std::cout << "parentDataSeries is null in vtkPlot * ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem::GetVTKPlot() const\n";
		return nullptr;
	}

	return parentDataSeries->GetVTKPlot();
}

void ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem::RenderView() const
{
	auto parentDataSeries = dynamic_cast<FrgVisual_Plot2DDataSeries_TItem*>(QTreeWidgetItem::parent());
	if (!parentDataSeries)
	{
		std::cout << "parentDataSeries is null in void ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem::RenderView() const const\n";
		return;
	}

	parentDataSeries->RenderView();
}

void ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem::StyleChangedSlot(const char* style)
{
	auto VTKPlot = GetVTKPlot();
	if (VTKPlot)
	{
		if (!std::strcmp(style, "None"))
			VTKPlot->GetPen()->SetLineType(vtkPen::NO_PEN);
		else if (!std::strcmp(style, "Solid Line"))
			VTKPlot->GetPen()->SetLineType(vtkPen::SOLID_LINE);
		else if (!std::strcmp(style, "Dash Line"))
			VTKPlot->GetPen()->SetLineType(vtkPen::DASH_LINE);
		else if (!std::strcmp(style, "Dot Line"))
			VTKPlot->GetPen()->SetLineType(vtkPen::DOT_LINE);
		else if (!std::strcmp(style, "Dash Dot Line"))
			VTKPlot->GetPen()->SetLineType(vtkPen::DASH_DOT_LINE);
		else if (!std::strcmp(style, "Dash Dot Dot Line"))
			VTKPlot->GetPen()->SetLineType(vtkPen::DASH_DOT_DOT_LINE);

		this->RenderView();
	}
}

void ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem::ColorChangedSlot(const QColor & color)
{
	auto VTKPlot = GetVTKPlot();
	if (VTKPlot)
	{
		double red = color.redF();
		double green = color.greenF();
		double blue = color.blueF();
		VTKPlot->GetPen()->SetColorF(red, green, blue);

		this->RenderView();
	}
}

void ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem::WidthChangedSlot(const int & width)
{
	auto VTKPlot = GetVTKPlot();
	if (VTKPlot)
	{
		VTKPlot->GetPen()->SetWidth(width);

		this->RenderView();
	}
}

void ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem::OpacityChangedSlot(const double & opacity)
{
	auto VTKPlot = GetVTKPlot();
	if (VTKPlot)
	{
		VTKPlot->GetPen()->SetOpacityF(opacity);

		this->RenderView();
	}
}