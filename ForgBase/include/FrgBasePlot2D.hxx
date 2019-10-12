#pragma once
#ifndef _FrgBasePlot2D_Header
#define _FrgBasePlot2D_Header

#include <FrgBaseGlobals.hxx>

#include <vtkSmartPointer.h>

class vtkTable;
class vtkContextView;
class vtkFloatArray;

BeginFrgBaseLib

class FrgBasePlot2D
{

private:

	vtkSmartPointer<vtkTable> theTable_;
	vtkSmartPointer<vtkContextView> theView_;

public:

	FrgBasePlot2D();

	//void AddColumn(vtkSmartPointer<vtkFloatArray> array);


};

EndFrgBaseLib

#endif // !_FrgBasePlot2D_Header
