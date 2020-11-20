#include <FrgVisual_Plot2DLnStyle_TItem.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgVisual_Plot2DDataSeries_TItem.hxx>

#include <vtkPlot.h>
#include <vtkPen.h>

#define STYLE_NONE "None"
#define STYLE_SOLID_LINE "Solid Line"
#define STYLE_DASH_LINE "Dash Line"
#define STYLE_DOT_LINE "Dot Line"
#define STYLE_DASH_DOT_LINE "Dash Dot Line"
#define STYLE_DASH_DOT_DOT_LINE "Dash Dot Dot Line"

//BOOST_CLASS_EXPORT_GUID(ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem, "ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem")
//BOOST_CLASS_EXPORT_IMPLEMENT(ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem)

ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem::FrgVisual_Plot2DLnStyle_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	this->setIcon(0, QIcon(ICONTreeItemCircle));

	auto myVTKPlot = GetVTKPlot();

	std::vector<QString> items;
	items.push_back(STYLE_NONE);
	items.push_back(STYLE_SOLID_LINE);
	items.push_back(STYLE_DASH_LINE);
	items.push_back(STYLE_DOT_LINE);
	items.push_back(STYLE_DASH_DOT_LINE);
	items.push_back(STYLE_DASH_DOT_DOT_LINE);

	theStyle_ = new ForgBaseLib::FrgBase_PrptsVrntCombo(items, "Style", GetStyleFromVTKPlot());

	double color[3]; // = { 255, 255, 255 };
	GetVTKPlot()->GetPen()->GetColorF(color);
	theColor_ = new ForgBaseLib::FrgBase_PrptsVrntColor("Color", QColor(255 * color[0], 255 * color[1], 255 * color[2]));
	theWidth_ = new ForgBaseLib::FrgBase_PrptsVrntInt("Width", GetVTKPlot()->GetPen()->GetWidth(), 1, 10);
	theOpacity_ = new ForgBaseLib::FrgBase_PrptsVrntDouble("Opacity", GetVTKPlot()->GetPen()->GetOpacity() / 255.0, 0.0, 1.0, 0.05);

	thePropertiesPanel_->AddRow(theStyle_);
	thePropertiesPanel_->AddRow(theColor_);
	thePropertiesPanel_->AddRow(theWidth_);
	thePropertiesPanel_->AddRow(theOpacity_);

	connect(theStyle_, SIGNAL(ValueChangedSignal(const QString&)), this, SLOT(StyleChangedSlot(const QString&)));
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

QString ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem::GetStyleFromVTKPlot() const
{
	auto VTKPlot = GetVTKPlot();
	if (VTKPlot)
	{
		auto myLineType = VTKPlot->GetPen()->GetLineType();

		if (myLineType == vtkPen::NO_PEN)
			return STYLE_NONE;
		else if (myLineType == vtkPen::SOLID_LINE)
			return STYLE_SOLID_LINE;
		else if (myLineType == vtkPen::DASH_LINE)
			return STYLE_DASH_LINE;
		else if (myLineType == vtkPen::DOT_LINE)
			return STYLE_DOT_LINE;
		else if (myLineType == vtkPen::DASH_DOT_LINE)
			return STYLE_DASH_DOT_LINE;
		else if (myLineType == vtkPen::DASH_DOT_DOT_LINE)
			return STYLE_DASH_DOT_DOT_LINE;

		this->RenderView();
	}

	return STYLE_DASH_LINE;
}

void ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem::StyleChangedSlot(const QString& style)
{
	if (sender() != theStyle_)
	{
		theStyle_->SetValue(style);
		return;
	}

	auto VTKPlot = GetVTKPlot();
	if (VTKPlot)
	{
		if (style == STYLE_NONE)
			VTKPlot->GetPen()->SetLineType(vtkPen::NO_PEN);
		else if (style == STYLE_SOLID_LINE)
			VTKPlot->GetPen()->SetLineType(vtkPen::SOLID_LINE);
		else if (style == STYLE_DASH_LINE)
			VTKPlot->GetPen()->SetLineType(vtkPen::DASH_LINE);
		else if (style == STYLE_DOT_LINE)
			VTKPlot->GetPen()->SetLineType(vtkPen::DOT_LINE);
		else if (style == STYLE_DASH_DOT_LINE)
			VTKPlot->GetPen()->SetLineType(vtkPen::DASH_DOT_LINE);
		else if (style == STYLE_DASH_DOT_DOT_LINE)
			VTKPlot->GetPen()->SetLineType(vtkPen::DASH_DOT_DOT_LINE);

		this->RenderView();
	}
}

void ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem::ColorChangedSlot(const QColor & color)
{
	if (sender() != theColor_)
	{
		theColor_->SetValue(color);
		return;
	}

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
	if (sender() != theWidth_)
	{
		theWidth_->SetValue(width);
		return;
	}

	auto VTKPlot = GetVTKPlot();
	if (VTKPlot)
	{
		VTKPlot->GetPen()->SetWidth(width);

		this->RenderView();
	}
}

void ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem::OpacityChangedSlot(const double & opacity)
{
	if (sender() != theOpacity_)
	{
		theOpacity_->SetValue(opacity);
		return;
	}

	auto VTKPlot = GetVTKPlot();
	if (VTKPlot)
	{
		VTKPlot->GetPen()->SetOpacityF(opacity);

		this->RenderView();
	}
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem)
{

}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem)
{

}

DECLARE_SAVE_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem)
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem)
}

BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DLnStyle_TItem)