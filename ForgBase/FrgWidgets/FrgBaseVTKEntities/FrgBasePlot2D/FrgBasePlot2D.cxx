#include <FrgBasePlot2D.hxx>

#include <FrgBaseMainWindow.hxx>
#include <FrgBaseTabWidget.hxx>

#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkChartXY.h>
#include <vtkTable.h>
#include <vtkPlot.h>
#include <vtkFloatArray.h>
#include <vtkContextView.h>
#include <vtkContextScene.h>
#include <vtkPen.h>
#include <vtkChartLegend.h>
#include <vtkTextProperty.h>
#include <vtkAxis.h>
#include <vtkGenericOpenGLRenderWindow.h>

#include <vtkAutoInit.h>

VTK_MODULE_INIT(vtkRenderingContextOpenGL2)
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)
VTK_MODULE_INIT(vtkRenderingFreeType)

ForgBaseLib::FrgBasePlot2D::FrgBasePlot2D
(
	const FrgString& itemName,
	FrgBaseTreeItem* parentItem,
	FrgBaseTree* parentTree,
	FrgBaseMainWindow* parentMainWindow
)
	: FrgBaseTreeItem(itemName, parentItem, parentTree, parentMainWindow)
{
	// Create a table with some points in it
	theTable_ =	vtkSmartPointer<vtkTable>::New();

	vtkSmartPointer<vtkFloatArray> arrX =
		vtkSmartPointer<vtkFloatArray>::New();
	arrX->SetName("X Axis");
	theTable_->AddColumn(arrX);

	vtkSmartPointer<vtkFloatArray> arrC =
		vtkSmartPointer<vtkFloatArray>::New();
	arrC->SetName("Cosine");
	theTable_->AddColumn(arrC);

	vtkSmartPointer<vtkFloatArray> arrS =
		vtkSmartPointer<vtkFloatArray>::New();
	arrS->SetName("Sine");
	theTable_->AddColumn(arrS);

	// Fill in the table with some example values
	int numPoints = 69;
	float inc = 7.5 / ((float)numPoints - 1);
	theTable_->SetNumberOfRows(numPoints);
	for (int i = 0; i < numPoints; ++i)
	{
		theTable_->SetValue(i, 0, i * inc);
		theTable_->SetValue(i, 1, cos(i * inc));
		theTable_->SetValue(i, 2, sin(i * inc));
	}

	// Set up the view
	theView_ = vtkSmartPointer<vtkContextView>::New();
	theView_->GetRenderer()->SetBackground(1.0, 1.0, 1.0);

	// Add multiple line plots, setting the colors etc
	vtkSmartPointer<vtkChartXY> chart =
		vtkSmartPointer<vtkChartXY>::New();

	chart->SetShowLegend(true);
	chart->GetLegend()->SetInline(false);
	chart->GetLegend()->GetLabelProperties()->SetFontFamilyToTimes();

	theView_->GetScene()->AddItem(chart);
	vtkPlot *line = chart->AddPlot(vtkChart::LINE);
	line->SetInputData(theTable_, 0, 1);
	line->SetColor(0, 255, 0, 255);
	line->SetWidth(1.0);
	line->SetTooltipLabelFormat("%l: (%x, %y)");
	line->GetXAxis()->GetLabelProperties()->SetFontFamilyToTimes();
	line->GetXAxis()->GetLabelProperties()->BoldOn();
	line->GetXAxis()->GetLabelProperties()->SetFontSize(15);
	line = chart->AddPlot(vtkChart::LINE);
	line->SetInputData(theTable_, 0, 2);
	line->SetColor(255, 0, 0, 255);
	line->SetWidth(5.0);

	// For dotted line, the line type can be from 2 to 5 for different dash/dot
	// patterns (see enum in vtkPen containing DASH_LINE, value 2):
#ifndef WIN32
	line->GetPen()->SetLineType(vtkPen::DASH_LINE);
#endif
	// (ifdef-ed out on Windows because DASH_LINE does not work on Windows
	//  machines with built-in Intel HD graphics card...)

	//view->GetRenderWindow()->SetMultiSamples(0);

	// Start interactor
	//theView_->GetRenderWindow()->Render();
	//theView_->GetInteractor()->Initialize();

	theRenderWindow_ = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();

	theView_->GetInteractor()->SetRenderWindow(theRenderWindow_);
	theRenderWindow_->SetInteractor(theView_->GetInteractor());

	theView_->SetRenderWindow(theRenderWindow_);
	theRenderWindow_->AddRenderer(theView_->GetRenderer());

	this->SetRenderWindow(theRenderWindow_);
	theView_->GetInteractor()->Initialize();
	//theView_->GetInteractor()->Start();
	theRenderWindow_->Render();


	GetParentMainWindow()->GetTabWidget()->addTab(this, this->text(0));
}