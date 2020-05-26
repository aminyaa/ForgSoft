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
	bool MouseMoveEvent(const vtkContextMouseEvent& mouse) override;
	bool MouseButtonPressEvent(const vtkContextMouseEvent& mouse) override;

	void SetLegendVisible(bool condition);
	bool GetLegendVisible() const;

	bool ExportDataAsCSV(std::string myFileName);

private:

	DECLARE_SAVE_LOAD_HEADER

private:

	vtkTypeMacro(FrgVisual_Plot2D_ChartXY, vtkChartXY);

	double theMouseFraction_;
	bool theLegendIsVisible_ = true;

	vtkPlot* theHorizontalIndicatorLine_ = nullptr;
	vtkPlot* theVericalIndicatorLine_ = nullptr;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Plot2D_ChartXY)

#endif // !_FrgVisual_Plot2D_ChartXY_Header
