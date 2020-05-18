#pragma once
#ifndef _FrgVisual_Plot2D_ChartXY_Header
#define _FrgVisual_Plot2D_ChartXY_Header

#include <FrgVisual_Global.hxx>
#include <vtkChartXY.h>

#include <FrgVisual_Serialization_Global.hxx>

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

	void SetLegendVisible(bool condition);
	bool GetLegendVisible() const;

private:

	DECLARE_SAVE_LOAD_HEADER

private:

	vtkTypeMacro(FrgVisual_Plot2D_ChartXY, vtkChartXY);

	double theMouseFraction_;
	bool theLegendIsVisible_ = true;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Plot2D_ChartXY)

#endif // !_FrgVisual_Plot2D_ChartXY_Header
