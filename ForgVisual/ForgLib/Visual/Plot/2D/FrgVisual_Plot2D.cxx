#include <FrgVisual_Plot2D.hxx>
#include <FrgVisual_Plot2D_ChartXY.hxx>

#include <vtkContextView.h>
#include <vtkRenderer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkFloatArray.h>
#include <vtkTable.h>
//#include <vtkChartXY.h>
#include <vtkChartLegend.h>
#include <vtkContextScene.h>
#include <vtkTextProperty.h>
#include <vtkPlot.h>
#include <vtkAxis.h>
#include <vtkPen.h>
#include <vtkContextMouseEvent.h>
#include <vtkInteractorStyleRubberBandZoom.h>

QColor* ForgVisualLib::FrgVisual_Plot2D::theHighlightColor_ = new QColor(255, 0, 255);

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

	theChart_ = vtkSmartPointer<FrgVisual_Plot2D_ChartXY>::New();
	theView_->GetScene()->AddItem(theChart_);
	/*theChart_->ForceAxesToBoundsOn();
	theChart_->GetAxis(0)->GetGridPen()->SetColor(220, 220, 220);
	theChart_->GetAxis(1)->GetGridPen()->SetColor(220, 220, 220);*/

	/*auto style = vtkSmartPointer<vtkInteractorStyleRubberBandZoom>::New();
	theRenderWindow_->GetInteractor()->SetInteractorStyle(style);*/
	theRenderWindow_->GetInteractor()->SetDesiredUpdateRate(1);
	theView_->GetInteractor()->Initialize();

	RenderView();
}

vtkPlot* ForgVisualLib::FrgVisual_Plot2D::AddPlot
(
	QList<double>& x,
	QList<double>& y,
	const char* title
)
{
	//theTables_.push_back(vtkSmartPointer<vtkTable>::New());
	auto& table = vtkSmartPointer<vtkTable>::New();

	vtkSmartPointer<vtkFloatArray> arrX =
		vtkSmartPointer<vtkFloatArray>::New();
	arrX->SetName("bottom-axis");
	table->AddColumn(arrX);

	vtkSmartPointer<vtkFloatArray> arrY =
		vtkSmartPointer<vtkFloatArray>::New();
	arrY->SetName(title);
	table->AddColumn(arrY);

	table->SetNumberOfRows(x.size());
	for (int i = 0; i < x.size(); i++)
	{
		table->SetValue(i, 0, x.at(i));
		table->SetValue(i, 1, y.at(i));
	}

	// Add multiple line plots, setting the colors etc
	//if (theChart_ == NullPtr)
		//theChart_ = vtkSmartPointer<vtkChartXY>::New();

	/*theChart_->SetShowLegend(true);
	theChart_->GetLegend()->SetInline(false);
	theChart_->GetLegend()->GetLabelProperties()->SetFontFamilyToTimes();*/
	//theChart_->GetAxis(vtkAxis::BOTTOM)->SetTitle("x");

	//theView_->GetScene()->AddItem(theChart_);
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
	line->GetXAxis()->GetLabelProperties()->SetFontSize(15);
	line->GetYAxis()->GetLabelProperties()->SetFontFamilyToTimes();
	line->GetYAxis()->GetLabelProperties()->SetFontSize(15);
	line->GetPen()->SetLineType(vtkPen::SOLID_LINE);

	//dynamic_cast<vtkPlotPoints*>(line)->SetMarkerStyle(vtkPlotPoints::SQUARE);

	/*theChart_->SetActionToButton(vtkChart::PAN, vtkContextMouseEvent::RIGHT_BUTTON);
	theChart_->SetActionToButton(vtkChart::SELECT, vtkContextMouseEvent::LEFT_BUTTON);*/

	//theChart_->SetSelectionMode(vtkContextScene::SELECTION_ADDITION);

	theView_->GetRenderWindow()->SetMultiSamples(0);
	RenderView();

	return line;
}

vtkPlot* ForgVisualLib::FrgVisual_Plot2D::AddPlot
(
	std::vector<double>& x,
	std::vector<double>& y,
	const char * title
)
{
	QList<double> Qx, Qy;

	for (int i = 0; i < x.size(); i++)
	{
		Qx.push_back(x[i]);
		Qy.push_back(y[i]);
	}

	return AddPlot(Qx, Qy, title);
}

vtkPlot* ForgVisualLib::FrgVisual_Plot2D::AddSinX(const char* title)
{
	QList<double>x, y;

	int nbPts = 50;
	double dx = 2.0 * 3.1415 / (double)nbPts;

	for (int i = 0; i <= nbPts; i++)
	{
		double xi = (double)i * dx;

		x.push_back(xi);
		y.push_back(sin(xi));
	}

	return AddPlot(x, y, title);
}

vtkPlot* ForgVisualLib::FrgVisual_Plot2D::AddCosX(const char* title)
{
	QList<double>x, y;

	int nbPts = 50;
	double dx = 2.0 * 3.1415 / (double)nbPts;

	for (int i = 0; i <= nbPts; i++)
	{
		double xi = (double)i * dx;

		x.push_back(xi);
		y.push_back(cos(xi));
	}

	return AddPlot(x, y, title);
}

void ForgVisualLib::FrgVisual_Plot2D::SetLegendVisible(bool condition)
{
	if (theChart_)
	{
		theChart_->SetShowLegend(condition);
		RenderView();
	}
}

void ForgVisualLib::FrgVisual_Plot2D::SetBottomAxisTitle(const char * title)
{
	if (theChart_)
	{
		theChart_->GetAxis(vtkAxis::BOTTOM)->SetTitle(title);
		RenderView();
	}
}

void ForgVisualLib::FrgVisual_Plot2D::SetLeftAxisTitle(const char * title)
{
	if (theChart_)
	{
		theChart_->GetAxis(vtkAxis::LEFT)->SetTitle(title);
		RenderView();
	}
}

void ForgVisualLib::FrgVisual_Plot2D::SetAxisVisible(int axisNumber, bool condition)
{
	if (theChart_)
	{
		theChart_->GetAxis(axisNumber)->SetAxisVisible(condition);
		theChart_->GetAxis(axisNumber)->SetGridVisible(condition);
		theChart_->GetAxis(axisNumber)->SetLabelsVisible(condition);
		theChart_->GetAxis(axisNumber)->SetTicksVisible(condition);
		theChart_->GetAxis(axisNumber)->SetTitleVisible(condition);
		RenderView();
	}
}

void ForgVisualLib::FrgVisual_Plot2D::SetBottomAxisVisible(bool condition)
{
	SetAxisVisible(vtkAxis::BOTTOM, condition);
}

void ForgVisualLib::FrgVisual_Plot2D::SetLeftAxisVisible(bool condition)
{
	SetAxisVisible(vtkAxis::LEFT, condition);
}

void ForgVisualLib::FrgVisual_Plot2D::SetAxisTitleVisible(int axisNumber, bool condition)
{
	if (theChart_)
	{
		theChart_->GetAxis(axisNumber)->SetTitleVisible(condition);
		RenderView();
	}
}

void ForgVisualLib::FrgVisual_Plot2D::SetBottomAxisTitleVisible(bool condition)
{
	SetAxisTitleVisible(vtkAxis::BOTTOM, condition);
}

void ForgVisualLib::FrgVisual_Plot2D::SetLeftAxisTitleVisible(bool condition)
{
	SetAxisTitleVisible(vtkAxis::LEFT, condition);
}

void ForgVisualLib::FrgVisual_Plot2D::SetAxisLogarithmic(int axisNumber, bool condition)
{
	if (theChart_)
	{
		auto axis = theChart_->GetAxis(axisNumber);
		theChart_->SetAdjustLowerBoundForLogPlot(condition);
		axis->SetLogScale(condition);
		theChart_->RecalculateBounds();

		RenderView();
	}
}

void ForgVisualLib::FrgVisual_Plot2D::SetBottomAxisLogarithmic(bool condition)
{
	SetAxisLogarithmic(vtkAxis::BOTTOM, condition);
}

void ForgVisualLib::FrgVisual_Plot2D::SetLeftAxisLogarithmic(bool condition)
{
	SetAxisLogarithmic(vtkAxis::LEFT, condition);
}

void ForgVisualLib::FrgVisual_Plot2D::SetAxisTitleRotation(int axisNumber, int degree)
{
	if (theChart_)
	{
		theChart_->GetAxis(axisNumber)->GetTitleProperties()->SetOrientation((double)degree);

		RenderView();
	}
}

void ForgVisualLib::FrgVisual_Plot2D::SetBottomAxisTitleRotation(int degree)
{
	SetAxisTitleRotation(vtkAxis::BOTTOM, degree);
}

void ForgVisualLib::FrgVisual_Plot2D::SetLeftAxisTitleRotation(int degree)
{
	SetAxisTitleRotation(vtkAxis::LEFT, degree);
}

void ForgVisualLib::FrgVisual_Plot2D::HighlightAxisTitle(int axisNumber, bool condition)
{
	if (axisNumber == vtkAxis::BOTTOM)
	{
		if (!condition)
			if (!theHighlightBottomAxisTitleColor_)
				return;

		if (condition)
			if (theHighlightBottomAxisTitleColor_)
				return;
	}
	else if (axisNumber == vtkAxis::LEFT)
	{
		if (!condition)
			if (!theHighlightLeftAxisTitleColor_)
				return;

		if (condition)
			if (theHighlightLeftAxisTitleColor_)
				return;
	}


	if (theChart_)
	{
		auto axis = theChart_->GetAxis(axisNumber);

		if (axisNumber == vtkAxis::BOTTOM)
		{
			if (!theHighlightBottomAxisTitleColor_)
				theHighlightBottomAxisTitleColor_ = new QColor;
		}
		else if (axisNumber == vtkAxis::LEFT)
		{
			if (!theHighlightLeftAxisTitleColor_)
				theHighlightLeftAxisTitleColor_ = new QColor;
		}

		double* color = axis->GetTitleProperties()->GetColor();

		if (color[0] != theHighlightColor_->redF() || color[1] != theHighlightColor_->greenF() || color[2] != theHighlightColor_->blueF())
		{
			if (!condition)
				return;
			if (axisNumber == vtkAxis::BOTTOM)
			{
				theHighlightBottomAxisTitleColor_->setRedF(color[0]);
				theHighlightBottomAxisTitleColor_->setGreenF(color[1]);
				theHighlightBottomAxisTitleColor_->setBlueF(color[2]);
			}
			else if (axisNumber == vtkAxis::LEFT)
			{
				theHighlightLeftAxisTitleColor_->setRedF(color[0]);
				theHighlightLeftAxisTitleColor_->setGreenF(color[1]);
				theHighlightLeftAxisTitleColor_->setBlueF(color[2]);
			}
		}

		if (condition)
		{
			axis->GetTitleProperties()->SetColor
			(
				theHighlightColor_->redF(),
				theHighlightColor_->greenF(),
				theHighlightColor_->blueF()
			);
		}
		else
		{
			if (axisNumber == vtkAxis::BOTTOM)
			{
				axis->GetTitleProperties()->SetColor
				(
					theHighlightBottomAxisTitleColor_->redF(),
					theHighlightBottomAxisTitleColor_->greenF(),
					theHighlightBottomAxisTitleColor_->blueF()
				);

				delete theHighlightBottomAxisTitleColor_;
				theHighlightBottomAxisTitleColor_ = nullptr;
			}
			else if (axisNumber == vtkAxis::LEFT)
			{
				axis->GetTitleProperties()->SetColor
				(
					theHighlightLeftAxisTitleColor_->redF(),
					theHighlightLeftAxisTitleColor_->greenF(),
					theHighlightLeftAxisTitleColor_->blueF()
				);

				delete theHighlightLeftAxisTitleColor_;
				theHighlightLeftAxisTitleColor_ = nullptr;
			}
		}

		RenderView();
	}
}

void ForgVisualLib::FrgVisual_Plot2D::HighlightBottomAxisTitle(bool condition)
{
	HighlightAxisTitle(vtkAxis::BOTTOM, condition);
}

void ForgVisualLib::FrgVisual_Plot2D::HighlightLeftAxisTitle(bool condition)
{
	HighlightAxisTitle(vtkAxis::LEFT, condition);
}

void ForgVisualLib::FrgVisual_Plot2D::HighlightAxis(int axisNumber, bool condition)
{
	if (axisNumber == vtkAxis::BOTTOM)
	{
		if (!condition)
			if (!theHighlightBottomAxisColor_)
				return;

		if (condition)
			if (theHighlightBottomAxisColor_)
				return;
	}
	else if (axisNumber == vtkAxis::LEFT)
	{
		if (!condition)
			if (!theHighlightLeftAxisColor_)
				return;

		if (condition)
			if (theHighlightLeftAxisColor_)
				return;
	}

	if (theChart_)
	{
		auto axis = theChart_->GetAxis(axisNumber);

		if (axisNumber == vtkAxis::BOTTOM)
		{
			if (!theHighlightBottomAxisColor_)
				theHighlightBottomAxisColor_ = new QColor;
		}
		else if (axisNumber == vtkAxis::LEFT)
		{
			if (!theHighlightLeftAxisColor_)
				theHighlightLeftAxisColor_ = new QColor;
		}

		double* color = axis->GetLabelProperties()->GetColor();

		if (color[0] != theHighlightColor_->redF() || color[1] != theHighlightColor_->greenF() || color[2] != theHighlightColor_->blueF())
		{
			if (!condition)
				return;
			if (axisNumber == vtkAxis::BOTTOM)
			{
				theHighlightBottomAxisColor_->setRedF(color[0]);
				theHighlightBottomAxisColor_->setGreenF(color[1]);
				theHighlightBottomAxisColor_->setBlueF(color[2]);
			}
			else if (axisNumber == vtkAxis::LEFT)
			{
				theHighlightLeftAxisColor_->setRedF(color[0]);
				theHighlightLeftAxisColor_->setGreenF(color[1]);
				theHighlightLeftAxisColor_->setBlueF(color[2]);
			}
		}

		if (condition)
		{
			double red = theHighlightColor_->redF();
			double green = theHighlightColor_->greenF();
			double blue = theHighlightColor_->blueF();

			axis->GetTitleProperties()->SetColor(red, green, blue);
			axis->GetLabelProperties()->SetColor(red, green, blue);
			axis->GetLabelProperties()->BoldOn();
			axis->GetPen()->SetColorF(red, green, blue);
			axis->GetPen()->SetWidth(axis->GetPen()->GetWidth()*2.0);
		}
		else
		{
			double red, green, blue;

			if (axisNumber == vtkAxis::BOTTOM)
			{
				red = theHighlightBottomAxisColor_->redF();
				green = theHighlightBottomAxisColor_->greenF();
				blue = theHighlightBottomAxisColor_->blueF();

				delete theHighlightBottomAxisColor_;
				theHighlightBottomAxisColor_ = nullptr;
			}
			else if (axisNumber == vtkAxis::LEFT)
			{
				red = theHighlightLeftAxisColor_->redF();
				green = theHighlightLeftAxisColor_->greenF();
				blue = theHighlightLeftAxisColor_->blueF();

				delete theHighlightLeftAxisColor_;
				theHighlightLeftAxisColor_ = nullptr;
			}

			axis->GetTitleProperties()->SetColor(red, green, blue);
			axis->GetLabelProperties()->SetColor(red, green, blue);
			axis->GetLabelProperties()->BoldOff();
			axis->GetPen()->SetColorF(red, green, blue);
			axis->GetPen()->SetWidth(axis->GetPen()->GetWidth() / 2.0);

		}

		RenderView();
	}
}

void ForgVisualLib::FrgVisual_Plot2D::HighlightBottomAxis(bool condition)
{
	HighlightAxis(vtkAxis::BOTTOM, condition);
}

void ForgVisualLib::FrgVisual_Plot2D::HighlightLeftAxis(bool condition)
{
	HighlightAxis(vtkAxis::LEFT, condition);
}