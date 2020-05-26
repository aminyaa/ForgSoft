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
#include <vtkPlotPoints.h>
#include <vtkContextMouseEvent.h>
#include <vtkInteractorStyleRubberBandZoom.h>
#include <vtkWindowToImageFilter.h>
#include <vtkImageWriter.h>
#include <vtkPNGWriter.h>
#include <vtkJPEGWriter.h>
#include <vtkPostScriptWriter.h>
#include <vtkPDFExporter.h>
#include <vtkOpenGLGL2PSExporter.h>

#include <QtCore/QRandomGenerator>

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
	
	theRenderWindow_->GetInteractor()->SetDesiredUpdateRate(1);
	theView_->GetInteractor()->Initialize();

	SetBottomAxisTitle("X Axis");
	SetLeftAxisTitle("Y Axis");

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

	//line->SetColor(rand0, rand1, rand2, 255);
	auto rndColor = QColor::fromRgb(QRandomGenerator::global()->generate());
	line->SetColor(rndColor.redF(), rndColor.greenF(), rndColor.blueF());
	line->SetWidth(1.0);
	line->SetTooltipLabelFormat("%l: (%x, %y)");
	line->GetXAxis()->GetLabelProperties()->SetFontFamilyToTimes();
	line->GetXAxis()->GetLabelProperties()->SetFontSize(15);
	line->GetYAxis()->GetLabelProperties()->SetFontFamilyToTimes();
	line->GetYAxis()->GetLabelProperties()->SetFontSize(15);
	line->GetPen()->SetLineType(vtkPen::SOLID_LINE);

	auto VTKPlotPoints = dynamic_cast<vtkPlotPoints*>(line);
	if (VTKPlotPoints)
		VTKPlotPoints->SetMarkerSize(6);

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

	int nbPts = 350;
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

	int nbPts = 350;
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

bool ForgVisualLib::FrgVisual_Plot2D::GetLegendVisible() const
{
	if (theChart_)
		return theChart_->GetShowLegend();

	return true;
}

void ForgVisualLib::FrgVisual_Plot2D::SetBottomAxisTitle(const char * title)
{
	if (theChart_)
	{
		theChart_->GetAxis(vtkAxis::BOTTOM)->SetTitle(title);
		RenderView();

		theBottomAxisTitle_ = title;
	}
}

const char * ForgVisualLib::FrgVisual_Plot2D::GetBottomAxisTitle() const
{
	if (theChart_)
	{
		//return theChart_->GetAxis(vtkAxis::BOTTOM)->GetTitle();

		return theBottomAxisTitle_.toLocal8Bit().constData();
	}

	return "X Axis";

}

void ForgVisualLib::FrgVisual_Plot2D::SetLeftAxisTitle(const char * title)
{
	if (theChart_)
	{
		theChart_->GetAxis(vtkAxis::LEFT)->SetTitle(title);
		RenderView();

		theLeftAxisTitle_ = title;
	}
}

const char * ForgVisualLib::FrgVisual_Plot2D::GetLeftAxisTitle() const
{
	if (theChart_)
	{
		//return theChart_->GetAxis(vtkAxis::LEFT)->GetTitle();

		return theLeftAxisTitle_.toLocal8Bit().constData();
	}

	return "Y Axis";
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

bool ForgVisualLib::FrgVisual_Plot2D::GetAxisVisible(int axisNumber) const
{
	if (theChart_)
	{
		if (
			theChart_->GetAxis(axisNumber)->GetAxisVisible() &&
			theChart_->GetAxis(axisNumber)->GetGridVisible() &&
			theChart_->GetAxis(axisNumber)->GetLabelsVisible() &&
			theChart_->GetAxis(axisNumber)->GetTicksVisible() &&
			theChart_->GetAxis(axisNumber)->GetTitleVisible()
			)
			return true;

		return false;
	}
}

void ForgVisualLib::FrgVisual_Plot2D::SetBottomAxisVisible(bool condition)
{
	SetAxisVisible(vtkAxis::BOTTOM, condition);
}

bool ForgVisualLib::FrgVisual_Plot2D::GetBottomAxisVisible() const
{
	return GetAxisVisible(vtkAxis::BOTTOM);
}

void ForgVisualLib::FrgVisual_Plot2D::SetLeftAxisVisible(bool condition)
{
	SetAxisVisible(vtkAxis::LEFT, condition);
}

bool ForgVisualLib::FrgVisual_Plot2D::GetLeftAxisVisible() const
{
	return GetAxisVisible(vtkAxis::LEFT);
}

void ForgVisualLib::FrgVisual_Plot2D::SetAxisTitleVisible(int axisNumber, bool condition)
{
	if (theChart_)
	{
		theChart_->GetAxis(axisNumber)->SetTitleVisible(condition);
		RenderView();
	}
}

bool ForgVisualLib::FrgVisual_Plot2D::GetAxisTitleVisible(int axisNumber) const
{
	if (theChart_)
		return theChart_->GetAxis(axisNumber)->GetTitleVisible();

	return true;
}

void ForgVisualLib::FrgVisual_Plot2D::SetBottomAxisTitleVisible(bool condition)
{
	SetAxisTitleVisible(vtkAxis::BOTTOM, condition);
}

bool ForgVisualLib::FrgVisual_Plot2D::GetBottomAxisTitleVisible() const
{
	return GetAxisTitleVisible(vtkAxis::BOTTOM);
}

void ForgVisualLib::FrgVisual_Plot2D::SetLeftAxisTitleVisible(bool condition)
{
	SetAxisTitleVisible(vtkAxis::LEFT, condition);
}

bool ForgVisualLib::FrgVisual_Plot2D::GetLeftAxisTitleVisible() const
{
	return GetAxisTitleVisible(vtkAxis::LEFT);
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

bool ForgVisualLib::FrgVisual_Plot2D::GetAxisLogarithmic(int axisNumber) const
{
	if (theChart_)
	{
		auto axis = theChart_->GetAxis(axisNumber);

		return axis->GetLogScale();
	}

	return false;
}

void ForgVisualLib::FrgVisual_Plot2D::SetBottomAxisLogarithmic(bool condition)
{
	SetAxisLogarithmic(vtkAxis::BOTTOM, condition);
}

bool ForgVisualLib::FrgVisual_Plot2D::GetBottomAxisLogarithmic() const
{
	return GetAxisLogarithmic(vtkAxis::BOTTOM);
}

void ForgVisualLib::FrgVisual_Plot2D::SetLeftAxisLogarithmic(bool condition)
{
	SetAxisLogarithmic(vtkAxis::LEFT, condition);
}

bool ForgVisualLib::FrgVisual_Plot2D::GetLeftAxisLogarithmic() const
{
	return GetAxisLogarithmic(vtkAxis::LEFT);
}

void ForgVisualLib::FrgVisual_Plot2D::SetAxisTitleRotation(int axisNumber, int degree)
{
	if (theChart_)
	{
		theChart_->GetAxis(axisNumber)->GetTitleProperties()->SetOrientation((double)degree);

		RenderView();
	}
}

int ForgVisualLib::FrgVisual_Plot2D::GetAxisTitleRotation(int axisNumber) const
{
	if (theChart_)
		return (int)theChart_->GetAxis(axisNumber)->GetTitleProperties()->GetOrientation();

	return 0;
}

void ForgVisualLib::FrgVisual_Plot2D::SetBottomAxisTitleRotation(int degree)
{
	SetAxisTitleRotation(vtkAxis::BOTTOM, degree);
}

int ForgVisualLib::FrgVisual_Plot2D::GetBottomAxisTitleRotation() const
{
	return GetAxisTitleRotation(vtkAxis::BOTTOM);
}

void ForgVisualLib::FrgVisual_Plot2D::SetLeftAxisTitleRotation(int degree)
{
	SetAxisTitleRotation(vtkAxis::LEFT, degree);
}

int ForgVisualLib::FrgVisual_Plot2D::GetLeftAxisTitleRotation() const
{
	return GetAxisTitleRotation(vtkAxis::LEFT);
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

void ForgVisualLib::FrgVisual_Plot2D::SetLegendPosition(LEGEND_POSITION_ENUM position)
{
	if (theChart_)
	{
		auto myLegend = theChart_->GetLegend();
		if (myLegend)
		{
			if (position != CUSTOM && position != NOT_VALID)
			{
				myLegend->SetInline(false);
				myLegend->SetDragEnabled(false);
			}
			if (position == CUSTOM)
			{
				myLegend->SetInline(true);
				myLegend->SetVerticalAlignment(vtkChartLegend::CUSTOM);
				myLegend->SetHorizontalAlignment(vtkChartLegend::CUSTOM);
				myLegend->SetDragEnabled(true);
			}
			else if (position == NORTH)
			{
				myLegend->SetVerticalAlignment(vtkChartLegend::TOP);
				myLegend->SetHorizontalAlignment(vtkChartLegend::CENTER);
			}
			else if (position == NORTH_EAST)
			{
				myLegend->SetVerticalAlignment(vtkChartLegend::TOP);
				myLegend->SetHorizontalAlignment(vtkChartLegend::RIGHT);
			}
			else if (position == EAST)
			{
				myLegend->SetVerticalAlignment(vtkChartLegend::CENTER);
				myLegend->SetHorizontalAlignment(vtkChartLegend::RIGHT);
			}
			else if (position == SOUTH_EAST)
			{
				myLegend->SetVerticalAlignment(vtkChartLegend::BOTTOM);
				myLegend->SetHorizontalAlignment(vtkChartLegend::RIGHT);
			}
			else if (position == SOUTH)
			{
				myLegend->SetVerticalAlignment(vtkChartLegend::BOTTOM);
				myLegend->SetHorizontalAlignment(vtkChartLegend::CENTER);
			}
			else if (position == SOUTH_WEST)
			{
				myLegend->SetVerticalAlignment(vtkChartLegend::BOTTOM);
				myLegend->SetHorizontalAlignment(vtkChartLegend::LEFT);
			}
			else if (position == WEST)
			{
				myLegend->SetVerticalAlignment(vtkChartLegend::CENTER);
				myLegend->SetHorizontalAlignment(vtkChartLegend::LEFT);
			}
			else if (position == NORTH_WEST)
			{
				myLegend->SetVerticalAlignment(vtkChartLegend::TOP);
				myLegend->SetHorizontalAlignment(vtkChartLegend::LEFT);
			}
			else if (position == NOT_VALID)
			{
				SetLegendPosition(NORTH_EAST);
			}
		}

		RenderView();
	}
}

ForgVisualLib::LEGEND_POSITION_ENUM ForgVisualLib::FrgVisual_Plot2D::GetLegendPosition() const
{
	if (theChart_)
	{
		auto myLegend = theChart_->GetLegend();
		if (myLegend)
		{
			if (myLegend->GetInline())
				return CUSTOM;
			else if (myLegend->GetVerticalAlignment() == vtkChartLegend::TOP && myLegend->GetHorizontalAlignment() == vtkChartLegend::CENTER)
				return NORTH;
			else if (myLegend->GetVerticalAlignment() == vtkChartLegend::TOP && myLegend->GetHorizontalAlignment() == vtkChartLegend::RIGHT)
				return NORTH_EAST;
			else if (myLegend->GetVerticalAlignment() == vtkChartLegend::CENTER && myLegend->GetHorizontalAlignment() == vtkChartLegend::RIGHT)
				return EAST;
			else if (myLegend->GetVerticalAlignment() == vtkChartLegend::BOTTOM && myLegend->GetHorizontalAlignment() == vtkChartLegend::RIGHT)
				return SOUTH_EAST;
			else if (myLegend->GetVerticalAlignment() == vtkChartLegend::BOTTOM && myLegend->GetHorizontalAlignment() == vtkChartLegend::CENTER)
				return SOUTH;
			else if (myLegend->GetVerticalAlignment() == vtkChartLegend::BOTTOM && myLegend->GetHorizontalAlignment() == vtkChartLegend::LEFT)
				return SOUTH_WEST;
			else if (myLegend->GetVerticalAlignment() == vtkChartLegend::CENTER && myLegend->GetHorizontalAlignment() == vtkChartLegend::LEFT)
				return WEST;
			else if (myLegend->GetVerticalAlignment() == vtkChartLegend::TOP && myLegend->GetHorizontalAlignment() == vtkChartLegend::LEFT)
				return NORTH_WEST;
			else
				return NOT_VALID;
		}
	}
}

bool ForgVisualLib::FrgVisual_Plot2D::ExportDataAsCSV(std::string myFileName)
{
	const auto& myChartXY = dynamic_cast<FrgVisual_Plot2D_ChartXY*>(this->GetChartXY().Get());
	if (myChartXY)
	{
		return myChartXY->ExportDataAsCSV(myFileName);
	}
}

bool ForgVisualLib::FrgVisual_Plot2D::ExportDataAsImage(QString myFileName)
{
	std::fstream testForOpen;
	testForOpen.open(myFileName.toStdString(), std::ios::out);
	if (!testForOpen.is_open())
		return false;
	else
		testForOpen.close();

	if (
		myFileName.contains(".pdf", Qt::CaseInsensitive) ||
		myFileName.contains(".eps", Qt::CaseInsensitive) ||
		myFileName.contains(".svg", Qt::CaseInsensitive) ||
		myFileName.contains(".ps", Qt::CaseInsensitive)
		)
	{
		vtkSmartPointer<vtkOpenGLGL2PSExporter> exporter = vtkSmartPointer<vtkOpenGLGL2PSExporter>::New();
		exporter->SetInput(theRenderWindow_);
		QString bareFileName;

		if (myFileName.contains(".pdf", Qt::CaseInsensitive))
		{
			bareFileName = myFileName.remove(".pdf", Qt::CaseInsensitive);
			exporter->SetFileFormatToPDF();
		}
		else if (myFileName.contains(".eps", Qt::CaseInsensitive))
		{
			bareFileName = myFileName.remove(".eps", Qt::CaseInsensitive);
			exporter->SetFileFormatToEPS();
		}
		else if (myFileName.contains(".svg", Qt::CaseInsensitive))
		{
			bareFileName = myFileName.remove(".svg", Qt::CaseInsensitive);
			exporter->SetFileFormatToSVG();
		}
		else if (myFileName.contains(".ps", Qt::CaseInsensitive))
		{
			bareFileName = myFileName.remove(".ps", Qt::CaseInsensitive);
			exporter->SetFileFormatToPS();
		}

		exporter->SetFilePrefix(bareFileName.toStdString().c_str());
		exporter->SetTitle("Forg Soft");
		exporter->SetCompress(false);
		exporter->Write();

		theRenderWindow_->Render();

		return true;
	}

	vtkSmartPointer<vtkImageWriter> writer;

	if (myFileName.contains(".png", Qt::CaseInsensitive))
	{
		writer = vtkSmartPointer<vtkPNGWriter>::New();
	}
	else if (myFileName.contains(".jpg", Qt::CaseInsensitive) || myFileName.contains(".jpeg", Qt::CaseInsensitive))
	{
		writer = vtkSmartPointer<vtkJPEGWriter>::New();
	}
	else
		return false;

	// Screenshot  
	vtkSmartPointer<vtkWindowToImageFilter> windowToImageFilter =
		vtkSmartPointer<vtkWindowToImageFilter>::New();
	windowToImageFilter->SetInput(theRenderWindow_);

	int Magnification = 2;

	windowToImageFilter->SetScale(Magnification); // image quality
	windowToImageFilter->ReadFrontBufferOff(); // read from the back buffer
	windowToImageFilter->Update();

	writer->SetFileName(myFileName.toStdString().c_str());
	writer->SetInputConnection(windowToImageFilter->GetOutputPort());
	writer->Write();

	theRenderWindow_->Render();

	return true;
}