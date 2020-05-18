#include <FrgVisual_Plot2D_ChartXY.hxx>

#include <vtkObjectFactory.h>
#include <vtkAxis.h>
#include <vtkPen.h>
#include <vtkContextMouseEvent.h>
#include <vtkChartLegend.h>
#include <vtkTextProperty.h>
#include <vtkTooltipItem.h>
#include <vtkContextScene.h>
#include <vtkCommand.h>

#include <FrgBase_SerialSpec_QString.hxx>

//BOOST_CLASS_EXPORT_GUID(ForgVisualLib::FrgVisual_Plot2D_ChartXY, "ForgVisualLib::FrgVisual_Plot2D_ChartXY")
//BOOST_CLASS_EXPORT_IMPLEMENT(ForgVisualLib::FrgVisual_Plot2D_ChartXY)

ForgVisualLib::FrgVisual_Plot2D_ChartXY* ForgVisualLib::FrgVisual_Plot2D_ChartXY::New()
{
	VTK_STANDARD_NEW_BODY(ForgVisualLib::FrgVisual_Plot2D_ChartXY)
}

ForgVisualLib::FrgVisual_Plot2D_ChartXY::FrgVisual_Plot2D_ChartXY()
	: theMouseFraction_(0.01)
{
	this->ForceAxesToBoundsOn();
	this->GetAxis(0)->GetGridPen()->SetColor(220, 220, 220);
	this->GetAxis(1)->GetGridPen()->SetColor(220, 220, 220);

	this->SetActionToButton(vtkChart::PAN, vtkContextMouseEvent::RIGHT_BUTTON);
	this->SetActionToButton(vtkChart::SELECT, vtkContextMouseEvent::LEFT_BUTTON);

	this->SetShowLegend(true);
	//this->GetLegend()->SetInline(false);
	this->GetLegend()->GetLabelProperties()->SetFontFamilyToTimes();
}

void ForgVisualLib::FrgVisual_Plot2D_ChartXY::SetLegendVisible(bool condition)
{
	this->SetShowLegend(condition);

	theLegendIsVisible_ = condition;
}

bool ForgVisualLib::FrgVisual_Plot2D_ChartXY::GetLegendVisible() const
{
	return theLegendIsVisible_;
}

bool ForgVisualLib::FrgVisual_Plot2D_ChartXY::MouseWheelEvent(const vtkContextMouseEvent & mouse, int delta)
{
	return vtkChartXY::MouseWheelEvent(mouse, delta);

	//if (this->Tooltip)
	//{
	//	this->Tooltip->SetVisible(false);
	//}
	//if (!this->ZoomWithMouseWheel)
	//{
	//	return false;
	//}

	//// Zoom into the chart by the specified amount, and recalculate the bounds
	//vtkVector2f point2(mouse.GetPos());

	//this->ZoomInAxes(this->ChartPrivate->axes[vtkAxis::BOTTOM],
	//	this->ChartPrivate->axes[vtkAxis::LEFT], this->MouseBox.GetData(), point2.GetData());
	//this->ZoomInAxes(this->ChartPrivate->axes[vtkAxis::TOP],
	//	this->ChartPrivate->axes[vtkAxis::RIGHT], this->MouseBox.GetData(), point2.GetData());

	//this->RecalculatePlotTransforms();
	//this->MouseBox.SetWidth(0.0);
	//this->MouseBox.SetHeight(0.0);
	//this->DrawBox = false;
	//// Mark the scene as dirty
	//this->Scene->SetDirty(true);
	//this->InvokeEvent(vtkCommand::InteractionEvent);
	//return true;


	vtkVector2f point2(mouse.GetPos());

	// Get the bounds of each plot.
	for (int i = 0; i < 4; ++i)
	{
		vtkAxis* axis = this->GetAxis(i);
		double min = axis->GetMinimum();
		double max = axis->GetMaximum();
		double maxMmin = max - min;

		if (delta > 0)
		{
			double center = 0;
			if (i == vtkAxis::BOTTOM || i == vtkAxis::TOP)
				center = (double)(point2.GetX()) / (double)(this->GetGeometry()[0]);
			else if (i == vtkAxis::LEFT || i == vtkAxis::RIGHT)
				center = (double)(point2.GetY()) / (double)(this->GetGeometry()[1]);

			center = center*(max - min) + min;

			min = center - (1.0 - theMouseFraction_)*maxMmin / 2.0;
			max = center + (1.0 - theMouseFraction_)*maxMmin / 2.0;
		}
		else
		{
			/*min -= delta * frac;
			max += delta * frac;*/
		}
		axis->SetRange(min, max);
		axis->RecalculateTickSpacing();
	}

	this->RecalculatePlotTransforms();

	// Mark the scene as dirty
	this->Scene->SetDirty(true);

	this->InvokeEvent(vtkCommand::InteractionEvent);

	return true;
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Plot2D_ChartXY)
{
	QString isLegendVisibleText;

	if (this->GetLegendVisible())
		isLegendVisibleText = "TRUE";
	else
		isLegendVisibleText = "FALSE";

	ar & isLegendVisibleText;
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Plot2D_ChartXY)
{
	QString isLegendVisible;

	ar & isLegendVisible;

	if (isLegendVisible == "TRUE")
		this->SetLegendVisible(true);
	else if (isLegendVisible == "FALSE")
		this->SetLegendVisible(false);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Plot2D_ChartXY)