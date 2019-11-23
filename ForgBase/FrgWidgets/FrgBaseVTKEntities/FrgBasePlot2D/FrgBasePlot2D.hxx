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
class vtkChartXY;

BeginFrgBaseLib

class FORGBASE_EXPORT FrgBasePlot2D : public QVTKOpenGLNativeWidget, public FrgBaseTreeItem
{

	Q_OBJECT

private:
	vtkSmartPointer<vtkContextView> theView_;
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> theRenderWindow_;
	QList<vtkSmartPointer<vtkTable>> theTables_;

	vtkSmartPointer<vtkChartXY> theChart_;

public:

	FrgBasePlot2D
	(
		const FrgString& itemName,
		FrgBaseTreeItem* parentItem = FrgNullPtr,
		FrgBaseTree* parentTree = FrgNullPtr,
		FrgBaseMainWindow* parentMainWindow = FrgNullPtr
	);

	void AddChart(QList<double>& x, QList<double>& y, FrgString xTitle = "x", FrgString yTitle = "y");

	FrgGetMacro(QList<vtkSmartPointer<vtkTable>>, Tables, theTables_);

	//void AddColumn(vtkSmartPointer<vtkFloatArray> array);

public slots:

	void NewSineClickedSlot(bool);
	void NewCosineClickedSlot(bool);


};

EndFrgBaseLib

#endif // !_FrgBasePlot2D_Header
