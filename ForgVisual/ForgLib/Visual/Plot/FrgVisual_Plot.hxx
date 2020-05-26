#pragma once
#ifndef _FrgVisual_Plot_Header
#define _FrgVisual_Plot_Header

#include <FrgVisual_Global.hxx>
#include <QVTKOpenGLNativeWidget.h>

class vtkContextView;
class vtkTable;
class vtkChartXY;
class vtkPlot;

namespace ForgBaseLib
{
	class FrgBase_MainWindow;
}

BeginForgVisualLib

enum LEGEND_POSITION_ENUM
{
	NORTH,
	NORTH_EAST,
	EAST,
	SOUTH_EAST,
	SOUTH,
	SOUTH_WEST,
	WEST,
	NORTH_WEST,
	CUSTOM,
	NOT_VALID
};

class FORGVISUAL_EXPORT FrgVisual_Plot
	: public QVTKOpenGLNativeWidget
{

public:

	FrgVisual_Plot
	(
		ForgBaseLib::FrgBase_MainWindow* parentMainWindow = nullptr
	);

	void RenderView() const;

	vtkSmartPointer<vtkContextView> GetView() const { return theView_; }
	vtkSmartPointer<vtkChartXY> GetChartXY() const { return theChart_; }

	bool RemovePlot(vtkPlot* plot);

protected:

	vtkSmartPointer<vtkContextView> theView_;
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> theRenderWindow_;
	//QList<vtkSmartPointer<vtkTable>> theTables_;
	vtkSmartPointer<vtkChartXY> theChart_;

	virtual void Init() {}
};

EndForgVisualLib

#endif // !_FrgVisual_Plot_Header
