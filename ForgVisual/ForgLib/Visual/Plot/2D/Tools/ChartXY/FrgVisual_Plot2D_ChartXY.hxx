#pragma once
#ifndef _FrgVisual_Plot2D_ChartXY_Header
#define _FrgVisual_Plot2D_ChartXY_Header

#include <FrgVisual_Global.hxx>
#include <vtkChartXY.h>

#include <FrgVisual_Serialization_Global.hxx>
#include <FrgVisual_Plot2DChartXY_BoundingBox.hxx>
#include <FrgBase_Pnt.hxx>

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
	bool KeyPressEvent(const vtkContextKeyEvent& key) override;

	void SetLegendVisible(bool condition);
	bool GetLegendVisible() const;

	bool ExportData(const std::string& myFileName, const char delimiter = ',');
	bool ExportDataAsCSV(const std::string& myFileName);
	bool ExportDataMerged(const std::string& myFileName, const char delimiter = ','); // All X values should be same size
	bool ExportDataAsCSVMerged(const std::string& myFileName); // All X values should be same size
	bool ExportDataAsXLSX(const std::string& fileName);

	virtual void RecalculateAndUpdateBoundingBox();
	virtual void UpdateBoundingBox(const ForgBaseLib::FrgBase_Pnt<2>& P);
	virtual void FitWindowToBoundingBox();

	void RecalculateBounds() override;

protected:

	static double LinearEquation
	(
		ForgBaseLib::FrgBase_Pnt<2> P0,
		ForgBaseLib::FrgBase_Pnt<2> P1,
		double x
	);

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)

private:

	vtkTypeMacro(FrgVisual_Plot2D_ChartXY, vtkChartXY);

	double theMouseFraction_;
	bool theLegendIsVisible_ = true;

	vtkPlot* theHorizontalIndicatorLine_ = nullptr;
	vtkPlot* theVericalIndicatorLine_ = nullptr;

	FrgVisual_Plot2DChartXY_BoundingBox theBoundingBox_;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Plot2D_ChartXY)

#endif // !_FrgVisual_Plot2D_ChartXY_Header
