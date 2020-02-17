#pragma once
#ifndef _FrgVisual_Plot_Header
#define _FrgVisual_Plot_Header

#include <FrgVisual_Global.hxx>
#include <QVTKOpenGLNativeWidget.h>

class vtkContextView;
class vtkTable;
class vtkChartXY;

namespace ForgBaseLib
{
	class FrgBase_MainWindow;
}

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_Plot
	: public QVTKOpenGLNativeWidget
{

public:

	FrgVisual_Plot
	(
		ForgBaseLib::FrgBase_MainWindow* parentMainWindow
	);

protected:

	vtkSmartPointer<vtkContextView> theView_;
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> theRenderWindow_;
	QList<vtkSmartPointer<vtkTable>> theTables_;
	vtkSmartPointer<vtkChartXY> theChart_;

	virtual void Init() {}
};

EndForgVisualLib

#endif // !_FrgVisual_Plot_Header
