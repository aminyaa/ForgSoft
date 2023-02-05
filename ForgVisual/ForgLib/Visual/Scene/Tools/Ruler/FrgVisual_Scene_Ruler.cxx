#include "FrgVisual_Scene_Ruler.hxx"

#include <FrgVisual_scene.hxx>

#include <vtkAxisActor2D.h>
#include <vtkMath.h>
#include <vtkTextMapper.h>
#include <vtkPoints.h>
#include <vtkTextProperty.h>
#include <vtkProperty2D.h>
#include <vtkViewPort.h>
#include <vtkInteractorObserver.h>

#include <vtkObjectFactory.h>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_Scene_Ruler);

ForgVisualLib::FrgVisual_Scene_Ruler::FrgVisual_Scene_Ruler()
	: vtkLegendScaleActor()
{
	auto topAxis = GetTopAxis();

	SetLabelModeToDistance();

	TurnOn();
	LegendVisibilityOff();

	SetRightBorderOffset(60);

	std::vector<vtkAxisActor2D*> axes =
	{
		GetRightAxis(),
		GetBottomAxis(),
		GetTopAxis(),
		GetLeftAxis(),
	};

	for (auto axis : axes)
	{
		axis->SetLabelFormat("%3.2g m");

		axis->GetLabelTextProperty()->SetColor(0.0, 0.0, 0.0);
		axis->GetLabelTextProperty()->SetFrameColor(0.0, 0.0, 0.0);

		axis->GetProperty()->SetColor(0.0, 0.0, 0.0);
	}

	const int nHTicks = 10;
	const int nVTicks = 5;

	const int nHLabels = 10;
	const int nVLabels = 6;

	GetRightAxis()->SetNumberOfMinorTicks(nVTicks);
	GetRightAxis()->SetNumberOfLabels(nVLabels);

	GetBottomAxis()->SetNumberOfMinorTicks(nHTicks);
	GetBottomAxis()->SetNumberOfLabels(nHLabels);

	GetTopAxis()->SetNumberOfMinorTicks(nHTicks);
	GetTopAxis()->SetNumberOfLabels(nHLabels);

	GetLeftAxis()->SetNumberOfMinorTicks(nVTicks);
	GetLeftAxis()->SetNumberOfLabels(nVLabels);
}

void ForgVisualLib::FrgVisual_Scene_Ruler::TurnOn(const bool render)
{
	RightAxisVisibilityOn();
	TopAxisVisibilityOn();
	LeftAxisVisibilityOff();
	BottomAxisVisibilityOff();

	if (theParentScene_ && render)
		theParentScene_->RenderScene(false, false);
}

void ForgVisualLib::FrgVisual_Scene_Ruler::TurnOff(const bool render)
{
	RightAxisVisibilityOff();
	TopAxisVisibilityOff();
	LeftAxisVisibilityOff();
	BottomAxisVisibilityOff();

	if (theParentScene_ && render)
		theParentScene_->RenderScene(false, false);
}

static double CalcDistance(vtkRenderer* renderer, int* displayPos1, int* displayPos2)
{
	double pt[4], pt2[4];
	vtkInteractorObserver::ComputeDisplayToWorld(renderer, double(displayPos1[0]), double(displayPos1[1]), 0.0, pt);
	vtkInteractorObserver::ComputeDisplayToWorld(renderer, double(displayPos2[0]), double(displayPos2[1]), 0.0, pt2);

	double a = pt2[0] - pt[0];
	double b = pt2[1] - pt[1];
	double c = pt2[2] - pt[2];

	double distance = std::sqrt(std::pow(a, 2) + std::pow(b, 2) + std::pow(c, 2));

	return distance;
}

void ForgVisualLib::FrgVisual_Scene_Ruler::BuildRepresentation
(
	vtkViewport* viewport
)
{
	if (!theParentScene_)
		return;

	auto renderer = theParentScene_->GetRenderer();

	//double* bounds = renderer->ComputeVisiblePropBounds();
	//std::cout << "(" << bounds[0] << ", " << bounds[1] << ", " << bounds[2] << ", " << bounds[3] << ", " << bounds[4] << ", " << bounds[5] << ")\n";
	{
		// Specify the locations of the axes.
		const int* size = viewport->GetSize();

		this->RightAxis->GetPositionCoordinate()->SetValue(
			size[0] - this->RightBorderOffset, this->CornerOffsetFactor * this->BottomBorderOffset, 0.0);
		this->RightAxis->GetPosition2Coordinate()->SetValue(size[0] - this->RightBorderOffset,
			size[1] - this->CornerOffsetFactor * this->TopBorderOffset, 0.0);

		this->TopAxis->GetPositionCoordinate()->SetValue(
			size[0] - this->CornerOffsetFactor * this->RightBorderOffset/* * 2.0*/, size[1] - this->TopBorderOffset,
			0.0);
		this->TopAxis->GetPosition2Coordinate()->SetValue(
			this->CornerOffsetFactor * this->LeftBorderOffset * 2.0, size[1] - this->TopBorderOffset, 0.0);

		this->LeftAxis->GetPositionCoordinate()->SetValue(
			this->LeftBorderOffset, size[1] - this->CornerOffsetFactor * this->TopBorderOffset, 0.0);
		this->LeftAxis->GetPosition2Coordinate()->SetValue(
			this->LeftBorderOffset, this->CornerOffsetFactor * this->BottomBorderOffset, 0.0);

		this->BottomAxis->GetPositionCoordinate()->SetValue(
			this->CornerOffsetFactor * this->LeftBorderOffset * 2.0, this->BottomBorderOffset, 0.0);
		this->BottomAxis->GetPosition2Coordinate()->SetValue(
			size[0] - this->CornerOffsetFactor * this->RightBorderOffset * 2.0, this->BottomBorderOffset,
			0.0);

		// Set Axes Ranges
		int* xLi = this->RightAxis->GetPositionCoordinate()->GetComputedDisplayValue(viewport);
		int* xRi = this->RightAxis->GetPosition2Coordinate()->GetComputedDisplayValue(viewport);
		this->RightAxis->SetRange(0.0, CalcDistance(renderer, xLi, xRi));

		xLi = this->TopAxis->GetPositionCoordinate()->GetComputedDisplayValue(viewport);
		xRi = this->TopAxis->GetPosition2Coordinate()->GetComputedDisplayValue(viewport);
		this->TopAxis->SetRange(CalcDistance(renderer, xLi, xRi), 0.0);

		xLi = this->LeftAxis->GetPositionCoordinate()->GetComputedDisplayValue(viewport);
		xRi = this->LeftAxis->GetPosition2Coordinate()->GetComputedDisplayValue(viewport);
		this->LeftAxis->SetRange(0.0, CalcDistance(renderer, xLi, xRi));

		xLi = this->BottomAxis->GetPositionCoordinate()->GetComputedDisplayValue(viewport);
		xRi = this->BottomAxis->GetPosition2Coordinate()->GetComputedDisplayValue(viewport);
		this->BottomAxis->SetRange(0.0, CalcDistance(renderer, xLi, xRi));

		this->BuildTime.Modified();
	}
}