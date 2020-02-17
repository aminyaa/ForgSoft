#include <FrgVisual_Plot2D.hxx>

#include <vtkContextView.h>
#include <vtkRenderer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkFloatArray.h>
#include <vtkTable.h>
#include <vtkChartXY.h>
#include <vtkChartLegend.h>
#include <vtkContextScene.h>
#include <vtkTextProperty.h>
#include <vtkPlot.h>
#include <vtkAxis.h>
#include <vtkPen.h>
#include <vtkContextMouseEvent.h>


ForgVisualLib::FrgVisual_Plot2D::FrgVisual_Plot2D
(
	ForgBaseLib::FrgBase_MainWindow* parentMainWindow
)
	: FrgVisual_Plot(parentMainWindow)
{
	Init();
}

void ForgVisualLib::FrgVisual_Plot2D::Init()
{
	// Set up the view
	theView_ = vtkSmartPointer<vtkContextView>::New();
	theView_->GetRenderer()->SetBackground(1.0, 1.0, 1.0);

	theRenderWindow_ = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();

	this->SetRenderWindow(theRenderWindow_);

	theView_->SetRenderWindow(theRenderWindow_);

	theView_->GetInteractor()->Initialize();
	theView_->Render();
}

void ForgVisualLib::FrgVisual_Plot2D::AddChart
(
	QList<double>& x,
	QList<double>& y,
	FrgString xTitle,
	FrgString yTitle
)
{
	theTables_.push_back(vtkSmartPointer<vtkTable>::New());
	auto& table = theTables_.last();

	vtkSmartPointer<vtkFloatArray> arrX =
		vtkSmartPointer<vtkFloatArray>::New();
	arrX->SetName(xTitle.toStdString().c_str());
	table->AddColumn(arrX);

	vtkSmartPointer<vtkFloatArray> arrY =
		vtkSmartPointer<vtkFloatArray>::New();
	arrY->SetName(yTitle.toStdString().c_str());
	table->AddColumn(arrY);

	table->SetNumberOfRows(x.size());
	for (int i = 0; i < x.size(); i++)
	{
		table->SetValue(i, 0, x.at(i));
		table->SetValue(i, 1, y.at(i));
	}

	// Add multiple line plots, setting the colors etc
	if (theChart_ == NullPtr)
		theChart_ = vtkSmartPointer<vtkChartXY>::New();

	theChart_->SetShowLegend(true);
	theChart_->GetLegend()->SetInline(false);
	theChart_->GetLegend()->GetLabelProperties()->SetFontFamilyToTimes();
	//theChart_->GetAxis(vtkAxis::BOTTOM)->SetTitle("x");

	theView_->GetScene()->AddItem(theChart_);
	vtkPlot* line = theChart_->AddPlot(vtkChart::LINE);

	int high = 255;
	int low = 0;

	line->SetInputData(table, 0, 1);

	std::srand(time(NULL));
	int rand0 = low + int((high - low + 1) * rand() / int(RAND_MAX + 1.0));
	int rand1 = low + int((high - low + 1) * rand() / int(RAND_MAX + 1.0));
	int rand2 = low + int((high - low + 1) * rand() / int(RAND_MAX + 1.0));

	line->SetColor(rand0, rand1, rand2, 255);
	line->SetWidth(1.0);
	line->SetTooltipLabelFormat("%l: (%x, %y)");
	line->GetXAxis()->GetLabelProperties()->SetFontFamilyToTimes();
	line->GetXAxis()->GetLabelProperties()->BoldOn();
	line->GetXAxis()->GetLabelProperties()->SetFontSize(15);
	line->GetPen()->SetLineType(vtkPen::SOLID_LINE);

	//dynamic_cast<vtkPlotPoints*>(line)->SetMarkerStyle(vtkPlotPoints::SQUARE);

	theChart_->SetActionToButton(vtkChart::PAN, vtkContextMouseEvent::RIGHT_BUTTON);
	theChart_->SetActionToButton(vtkChart::SELECT, vtkContextMouseEvent::LEFT_BUTTON);

	//theChart_->SetSelectionMode(vtkContextScene::SELECTION_ADDITION);

	theView_->Render();
}

void ForgVisualLib::FrgVisual_Plot2D::AddSinX()
{
	QList<double>x, y;

	int nbPts = 200;
	double dx = 2.0 * 3.1415 / (double)nbPts;

	for (int i = 0; i <= nbPts; i++)
	{
		double xi = (double)i * dx;

		x.push_back(xi);
		y.push_back(sin(xi));
	}

	AddChart(x, y, "x", "Sin(x)");
}

void ForgVisualLib::FrgVisual_Plot2D::AddCosX()
{
	QList<double>x, y;

	int nbPts = 200;
	double dx = 2.0 * 3.1415 / (double)nbPts;

	for (int i = 0; i <= nbPts; i++)
	{
		double xi = (double)i * dx;

		x.push_back(xi);
		y.push_back(cos(xi));
	}

	AddChart(x, y, "x", "Cos(x)");
}