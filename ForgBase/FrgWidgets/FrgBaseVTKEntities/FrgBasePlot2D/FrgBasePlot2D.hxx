#pragma once
#ifndef _FrgBasePlot2D_Header
#define _FrgBasePlot2D_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTreeItem.hxx>

#include <vtkSmartPointer.h>
#include <QVTKOpenGLNativeWidget.h>

class vtkTable;
class vtkContextView;
class vtkFloatArray;

BeginFrgBaseLib

class FORGBASE_EXPORT FrgBasePlot2D : public QVTKOpenGLNativeWidget, public FrgBaseTreeItem
{

	Q_OBJECT

private:

	vtkSmartPointer<vtkTable> theTable_;
	vtkSmartPointer<vtkContextView> theView_;

	vtkSmartPointer<vtkGenericOpenGLRenderWindow> theRenderWindow_;

public:

	FrgBasePlot2D
	(
		const FrgString& itemName,
		FrgBaseTreeItem* parentItem = FrgNullPtr,
		FrgBaseTree* parentTree = FrgNullPtr,
		FrgBaseMainWindow* parentMainWindow = FrgNullPtr
	);

	//void AddColumn(vtkSmartPointer<vtkFloatArray> array);


};

EndFrgBaseLib

#endif // !_FrgBasePlot2D_Header
