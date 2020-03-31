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
	this->GetLegend()->SetInline(false);
	this->GetLegend()->GetLabelProperties()->SetFontFamilyToTimes();
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