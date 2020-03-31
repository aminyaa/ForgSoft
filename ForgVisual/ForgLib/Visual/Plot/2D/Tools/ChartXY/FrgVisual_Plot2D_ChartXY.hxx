#pragma once
#ifndef _FrgVisual_Plot2D_ChartXY_Header
#define _FrgVisual_Plot2D_ChartXY_Header

#include <FrgVisual_Global.hxx>
#include <vtkChartXY.h>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_Plot2D_ChartXY
	: public vtkChartXY
{
public:

	FrgVisual_Plot2D_ChartXY();

	static FrgVisual_Plot2D_ChartXY* New();

	double GetMouseFraction() const { return theMouseFraction_; }
	void SetMouseFraction(double frac) { theMouseFraction_ = frac; }

	bool MouseWheelEvent(const vtkContextMouseEvent&, int delta) override;

private:

	vtkTypeMacro(FrgVisual_Plot2D_ChartXY, vtkChartXY);

	double theMouseFraction_;
};

EndForgVisualLib

#endif // !_FrgVisual_Plot2D_ChartXY_Header
