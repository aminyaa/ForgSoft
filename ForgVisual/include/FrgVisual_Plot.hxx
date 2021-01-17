#pragma once
#ifndef _FrgVisual_Plot_Header
#define _FrgVisual_Plot_Header

#include <FrgVisual_Global.hxx>
#include <QVTKOpenGLNativeWidget.h>
#include <FrgBase_Object.hxx>

class vtkContextView;
class vtkTable;
class vtkPlot;

namespace ForgBaseLib
{
	class FrgBase_MainWindow;
}

BeginForgVisualLib

class FrgVisual_Plot2D_ChartXY;

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
	, public ForgBaseLib::FrgBase_Object
{

	Q_OBJECT

public:

	FrgVisual_Plot
	(
		ForgBaseLib::FrgBase_MainWindow* parentMainWindow = nullptr
	);

	vtkSmartPointer<vtkContextView> GetView() const { return theView_; }
	vtkSmartPointer<FrgVisual_Plot2D_ChartXY> GetChartXY() const { return theChart_; }

	bool RemovePlot(vtkPlot* plot);

	virtual void SetParentMainWindow(ForgBaseLib::FrgBase_MainWindow* parentMainWindow);

Q_SIGNALS:

	void RenderView() const;
	virtual void SetThemeDark(bool condition) const;

protected slots:

	void RenderViewSlot() const;
	virtual void SetThemeDarkSlot(bool condition) const = 0;

protected:

	vtkSmartPointer<vtkContextView> theView_;
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> theRenderWindow_;
	//QList<vtkSmartPointer<vtkTable>> theTables_;
	vtkSmartPointer<FrgVisual_Plot2D_ChartXY> theChart_;

	ForgBaseLib::FrgBase_MainWindow* theParentMainWindow_ = nullptr;

	virtual void Init() {}
};

EndForgVisualLib

#endif // !_FrgVisual_Plot_Header
