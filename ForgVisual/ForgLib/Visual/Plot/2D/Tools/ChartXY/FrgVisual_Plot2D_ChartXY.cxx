#include <FrgVisual_Plot2D_ChartXY.hxx>

#include <vtkObjectFactory.h>
#include <vtkAxis.h>
#include <vtkPen.h>
#include <vtkContextMouseEvent.h>
#include <vtkChartLegend.h>
#include <vtkTextProperty.h>
#include <vtkTooltipItem.h>
#include <vtkContextScene.h>
#include <vtkCommand.h>
#include <vtkPlotBar.h>
#include <vtkTransform2D.h>
#include <vtkFloatArray.h>
#include <vtkTable.h>
#include <vtkContextTransform.h>
#include <vtkContextKeyEvent.h>
#include <vtkStringArray.h>

#include <FrgBase_SerialSpec_QString.hxx>

#include <string>
#include <sstream>
#include <QtCore/QList>

ForgVisualLib::FrgVisual_Plot2D_ChartXY* ForgVisualLib::FrgVisual_Plot2D_ChartXY::New()
{
	VTK_STANDARD_NEW_BODY(ForgVisualLib::FrgVisual_Plot2D_ChartXY)
}

ForgVisualLib::FrgVisual_Plot2D_ChartXY::FrgVisual_Plot2D_ChartXY()
	: theMouseFraction_(0.01)
{
	theBoundingBox_.P0().X() = 0.0;
	theBoundingBox_.P0().Y() = 0.0;
	theBoundingBox_.P1().X() = 0.0;
	theBoundingBox_.P1().Y() = 0.0;

	//this->ForceAxesToBoundsOn();
	/*this->GetAxis(0)->GetGridPen()->SetColor(220, 220, 220);
	this->GetAxis(1)->GetGridPen()->SetColor(220, 220, 220);

	this->GetAxis(0)->GetGridPen()->SetLineType(vtkPen::DASH_LINE);
	this->GetAxis(1)->GetGridPen()->SetLineType(vtkPen::DASH_LINE);*/

	this->SetActionToButton(vtkChart::PAN, vtkContextMouseEvent::RIGHT_BUTTON);
	this->SetActionToButton(vtkChart::SELECT, vtkContextMouseEvent::LEFT_BUTTON);

	this->SetShowLegend(true);
	//this->GetLegend()->SetInline(false);
	this->GetLegend()->GetLabelProperties()->SetFontFamilyToTimes();

	FitWindowToBoundingBox();
}

void ForgVisualLib::FrgVisual_Plot2D_ChartXY::SetLegendVisible(bool condition)
{
	this->SetShowLegend(condition);

	theLegendIsVisible_ = condition;
}

bool ForgVisualLib::FrgVisual_Plot2D_ChartXY::GetLegendVisible() const
{
	return theLegendIsVisible_;
}

bool ForgVisualLib::FrgVisual_Plot2D_ChartXY::MouseWheelEvent(const vtkContextMouseEvent& mouse, int delta)
{
	if (theHorizontalIndicatorLine_ || theVericalIndicatorLine_)
	{
		this->RemovePlotInstance(theHorizontalIndicatorLine_);
		this->RemovePlotInstance(theVericalIndicatorLine_);
	}

	if (this->Tooltip)
	{
		this->Tooltip->SetVisible(false);
	}
	if (!this->ZoomWithMouseWheel)
	{
		return false;
	}

	double deltaAxes[4];

	int amin = this->GetPoint1()[0];
	int amax = this->GetPoint2()[0];
	int bmin = this->GetPoint1()[1];
	int bmax = this->GetPoint2()[1];

	for (int i = 0; i < 2; ++i)
	{
		vtkAxis* axis = this->GetAxis(i);
		double minValue = axis->GetUnscaledMinimum();
		double maxValue = axis->GetUnscaledMaximum();
		ForgBaseLib::FrgBase_Pnt<2> P0;
		ForgBaseLib::FrgBase_Pnt<2> P1;

		P0.X() = (i == vtkAxis::BOTTOM || i == vtkAxis::TOP) ? amin : bmin;
		P1.X() = (i == vtkAxis::BOTTOM || i == vtkAxis::TOP) ? amax : bmax;

		P0.Y() = axis->GetLogScale() ? std::pow(10.0, minValue) : minValue;
		P1.Y() = axis->GetLogScale() ? std::pow(10.0, maxValue) : maxValue;

		double mousePos = (i == vtkAxis::BOTTOM || i == vtkAxis::TOP) ? (double)(mouse.GetPos()[0]) : (double)(mouse.GetPos()[1]);
		double xAxis = LinearEquation(P0, P1, mousePos);
 		if (axis->GetLogScale())
 			xAxis = std::log10(xAxis);

		if (xAxis < axis->GetUnscaledMinimum())
			xAxis = axis->GetUnscaledMinimum();

		if (xAxis > axis->GetUnscaledMaximum())
			xAxis = axis->GetUnscaledMaximum();

		double accuracy = 0.1;
		/*if (axis->GetLogScale())
			accuracy = std::log10(accuracy);*/

		double fracMax = std::abs(maxValue - xAxis) * accuracy;
		double fracMin = std::abs(xAxis - minValue) * accuracy;

		minValue += delta * fracMin;
		maxValue -= delta * fracMax;

		if (minValue < axis->GetUnscaledMinimumLimit())
			minValue = axis->GetUnscaledMinimumLimit();
		if (maxValue > axis->GetUnscaledMaximumLimit())
			maxValue = axis->GetUnscaledMaximumLimit();

		axis->SetUnscaledMinimum(minValue);
		axis->SetUnscaledMaximum(maxValue);
	}

	this->RecalculatePlotTransforms();
	// Mark the scene as dirty
	this->Scene->SetDirty(true);
	this->InvokeEvent(vtkCommand::InteractionEvent);

	return true;
}

bool ForgVisualLib::FrgVisual_Plot2D_ChartXY::MouseMoveEvent(const vtkContextMouseEvent& mouse)
{
	auto nbPlots = GetNumberOfPlots();

	if (nbPlots != 0)
	{
		static vtkPlot* staticPlot = nullptr;

		if (theHorizontalIndicatorLine_ || theVericalIndicatorLine_)
		{
			this->RemovePlotInstance(theHorizontalIndicatorLine_);
			this->RemovePlotInstance(theVericalIndicatorLine_);

			theHorizontalIndicatorLine_ = nullptr;
			theVericalIndicatorLine_ = nullptr;

			for (vtkIdType iPlot = 0; iPlot < nbPlots; iPlot++)
			{
				auto myPlot = GetPlot(iPlot);
				if (myPlot && myPlot != staticPlot)
				{
					myPlot->GetPen()->SetOpacity(myPlot->GetPen()->GetOpacity() * 3);

					// Mark the scene as dirty
					this->Scene->SetDirty(true);
					this->InvokeEvent(vtkCommand::InteractionEvent);
				}
			}
		}

		for (vtkIdType iPlot = 0; iPlot < nbPlots; iPlot++)
		{
			vtkPlot* myPlot = GetPlot(iPlot);

			if (!myPlot)
				break;

			vtkVector2f posd;
			vtkVector2f position;
			vtkTransform2D* transform = vtkTransform2D::New();

			this->RecalculatePlotTransforms();
			this->CalculatePlotTransform(myPlot->GetXAxis(), myPlot->GetYAxis(), transform);
			vtkVector2f tolerance(std::fabs(5.0 * (1.0 / transform->GetMatrix()->GetElement(0, 0))),
				std::fabs(5.0 * (1.0 / transform->GetMatrix()->GetElement(1, 1))));
			transform->InverseTransformPoints(mouse.GetPos().GetData(), position.GetData(), 1);

			auto seriesIndex = myPlot->GetNearestPoint(position, tolerance, &posd);

			vtkRectd ss(myPlot->GetShiftScale());
			vtkVector2d plotPosd(posd[0] / ss[2] - ss[0], posd[1] / ss[3] - ss[1]);

			if (seriesIndex >= 0)
			{
				staticPlot = myPlot;

				double xRange[2];
				double yRange[2];
				myPlot->GetXAxis()->GetRange(xRange);
				myPlot->GetYAxis()->GetRange(yRange);

				// Draw Horizontal and Vertical Dashed Lines
				for (int iLine = 0; iLine < 2; iLine++)
				{
					auto table = vtkSmartPointer<vtkTable>::New();

					vtkSmartPointer<vtkFloatArray> arrX =
						vtkSmartPointer<vtkFloatArray>::New();
					arrX->SetName("bottom-axis");
					table->AddColumn(arrX);

					vtkSmartPointer<vtkFloatArray> arrY =
						vtkSmartPointer<vtkFloatArray>::New();
					arrY->SetName("");
					table->AddColumn(arrY);

					table->SetNumberOfRows(2);

					double x0 = myPlot->GetXAxis()->GetLogScale() ? std::pow(10.0, plotPosd.GetX()) : plotPosd.GetX();
					double y0 = myPlot->GetYAxis()->GetLogScale() ? std::pow(10.0, plotPosd.GetY()) : plotPosd.GetY();

					table->SetValue(0, 0, x0);
					table->SetValue(0, 1, y0);

					if (iLine == 0)
					{
						// Vertical Line
						table->SetValue(1, 0, x0);
						table->SetValue(1, 1, myPlot->GetYAxis()->GetUnscaledMinimum());
					}
					else
					{
						// Horizontal Line
						table->SetValue(1, 0, myPlot->GetXAxis()->GetUnscaledMinimum());
						table->SetValue(1, 1, y0);
					}

					vtkPlot* myLine = nullptr;
					if (iLine == 0)
					{
						theVericalIndicatorLine_ = this->AddPlot(vtkChart::LINE);
						myLine = theVericalIndicatorLine_;
					}
					else
					{
						theHorizontalIndicatorLine_ = this->AddPlot(vtkChart::LINE);
						myLine = theHorizontalIndicatorLine_;
					}

					myLine->SetInputData(table, 0, 1);

					myLine->SetColor(0.7, 0.7, 0.7);
					myLine->SetLegendVisibility(false);
					myLine->GetPen()->SetLineType(vtkPen::DASH_LINE);
				}

				myPlot->GetXAxis()->SetRange(xRange);
				myPlot->GetYAxis()->SetRange(yRange);
				myPlot->GetXAxis()->RecalculateTickSpacing();
				myPlot->GetYAxis()->RecalculateTickSpacing();
				this->RecalculatePlotTransforms();

				for (vtkIdType iPlot0 = 0; iPlot0 < nbPlots; iPlot0++)
				{
					auto myPlot0 = GetPlot(iPlot0);
					if (myPlot0 != myPlot && myPlot0 != theHorizontalIndicatorLine_ && myPlot0 != theVericalIndicatorLine_)
					{
						myPlot0->GetPen()->SetOpacity(myPlot0->GetPen()->GetOpacity() / 3);
					}
				}

				// Mark the scene as dirty
				this->Scene->SetDirty(true);
				this->InvokeEvent(vtkCommand::InteractionEvent);
				transform->Delete();

				break;
			}
		}
	}

	return vtkChartXY::MouseMoveEvent(mouse);
}

bool ForgVisualLib::FrgVisual_Plot2D_ChartXY::MouseButtonPressEvent(const vtkContextMouseEvent& mouse)
{
	auto nbPlots = GetNumberOfPlots();

	for (int iPlot = 0; iPlot < nbPlots; iPlot++)
	{
		vtkPlot* myPlot = GetPlot(iPlot);

		vtkVector2f posd;
		vtkVector2f position;
		vtkTransform2D* transform = vtkTransform2D::New();

		this->RecalculatePlotTransforms();
		this->CalculatePlotTransform(myPlot->GetXAxis(), myPlot->GetYAxis(), transform);
		vtkVector2f tolerance(std::fabs(10.0 * (1.0 / transform->GetMatrix()->GetElement(0, 0))),
			std::fabs(10.0 * (1.0 / transform->GetMatrix()->GetElement(1, 1))));
		transform->InverseTransformPoints(mouse.GetPos().GetData(), position.GetData(), 1);

		auto seriesIndex = myPlot->GetNearestPoint(position, tolerance, &posd);

		if (seriesIndex >= 0)
		{

			// Mark the scene as dirty
			this->Scene->SetDirty(true);

			this->InvokeEvent(vtkCommand::InteractionEvent);
		}
		transform->Delete();

		break;
	}

	return vtkChartXY::MouseButtonPressEvent(mouse);
}

bool ForgVisualLib::FrgVisual_Plot2D_ChartXY::KeyPressEvent(const vtkContextKeyEvent& key)
{
	if (key.GetKeyCode() == 'r' || key.GetKeyCode() == 'R')
	{
		auto offset = theBoundingBox_.OffSet(0.01 * theBoundingBox_.Diameter());

		auto bottomAxis = this->GetAxis(vtkAxis::BOTTOM);
		auto leftAxis = this->GetAxis(vtkAxis::LEFT);

		bottomAxis->SetUnscaledMinimum(bottomAxis->GetUnscaledMinimumLimit());
		bottomAxis->SetUnscaledMaximum(bottomAxis->GetUnscaledMaximumLimit());
		leftAxis->SetUnscaledMinimum(leftAxis->GetUnscaledMinimumLimit());
		leftAxis->SetUnscaledMaximum(leftAxis->GetUnscaledMaximumLimit());
	}

	// Mark the scene as dirty
	this->Scene->SetDirty(true);
	this->InvokeEvent(vtkCommand::KeyPressEvent);
	
	return true;
}

bool ForgVisualLib::FrgVisual_Plot2D_ChartXY::ExportData(const std::string& myFileName, const char delimiter)
{
	const auto nbPlots = this->GetNumberOfPlots();

	if (nbPlots == 0)
		return false;

	fstream myFile;
	myFile.open(myFileName, std::ios::out);

	if (!myFile.is_open())
		return false;

	std::ostringstream titles;
	//std::vector<std::vector<std::string>> myData;
	std::ostringstream AllData;

	vtkIdType maxRows = 0;
	for (vtkIdType iPlot = 0; iPlot < nbPlots; iPlot++)
	{
		auto myPlot = GetPlot(iPlot);
		vtkTable* myTable = myPlot->GetInput();

		const auto nbOfRows = myTable->GetNumberOfRows();
		const auto nbOfColumns = myTable->GetNumberOfColumns();

		if (maxRows < nbOfRows)
			maxRows = nbOfRows;

		for (vtkIdType iCol = 0; iCol < nbOfColumns; iCol++)
		{
			const auto myAbstractArray = myTable->GetColumn(iCol);
			std::string myTableTitle = iCol == 0 ? (myPlot->GetXAxis()->GetTitle()) : myAbstractArray->GetName();

			if (iPlot == nbPlots - 1 && iCol == nbOfColumns - 1)
				titles << "\"" << myTableTitle << "\"";
			else
				titles << "\"" << myTableTitle << "\"" << delimiter << " ";
		}
	}

	titles << std::endl;

	for (vtkIdType i = 0, k = 0; i < maxRows; i++, k++)
	{
		for (vtkIdType iPlot = 0; iPlot < nbPlots; iPlot++)
		{
			auto myPlot = GetPlot(iPlot);
			auto myTable = myPlot->GetInput();

			const auto nbOfRows = myTable->GetNumberOfRows();
			const auto nbOfColumns = myTable->GetNumberOfColumns();

			for (vtkIdType iCol = 0; iCol < nbOfColumns; iCol++)
			{
				if (i < nbOfRows)
					AllData << myTable->GetValue(i, iCol).ToString();

				if (iPlot == nbPlots - 1 && iCol == nbOfColumns - 1)
				{
					// Do nothing
				}
				else
					AllData << delimiter;
			}
		}
		AllData << std::endl;
	}

	myFile << titles.str();
	myFile << AllData.str();

	myFile.close();

	return true;
}

bool ForgVisualLib::FrgVisual_Plot2D_ChartXY::ExportDataAsCSV(const std::string& myFileName)
{
	return ExportData(myFileName, ',');
}

bool ForgVisualLib::FrgVisual_Plot2D_ChartXY::ExportDataMerged(const std::string& myFileName, const char delimiter)
{
	const auto nbPlots = this->GetNumberOfPlots();

	if (nbPlots == 0)
		return false;

	fstream myFile;
	myFile.open(myFileName, std::ios::out);

	if (!myFile.is_open())
		return false;

	std::string titles = "";
	QList<QList<std::string>> myData;

	for (vtkIdType iPlot = 0; iPlot < nbPlots; iPlot++)
	{
		auto myPlot = GetPlot(iPlot);

		vtkTable* myTable = myPlot->GetInput();
		vtkIdType nbOfRows = myTable->GetNumberOfRows();
		vtkIdType nbOfColumns = myTable->GetNumberOfColumns();

		const auto myAbstractArray = myTable->GetColumn(1);
		QString myTableTitle = QString(myAbstractArray->GetName());

		if (iPlot == 0)
			titles += "\"" + myPlot->GetXAxis()->GetTitle() + "\"" + delimiter + " ";

		if (iPlot == nbPlots - 1)
			titles += "\"" + myTableTitle.toStdString() + "\"";
		else
			titles += "\"" + myTableTitle.toStdString() + "\"" + delimiter + " ";

		vtkIdType col0;
		if (iPlot == 0)
			col0 = 0;
		else
			col0 = 1;

		for (vtkIdType col = col0; col < nbOfColumns; col++)
		{
			QList<std::string> myDataRow;

			for (vtkIdType row = 0; row < nbOfRows; row++)
			{
				auto myValue = myTable->GetValue(row, col);
				double myDoubleValue = myValue.ToDouble();

				myDataRow.push_back(std::to_string(myDoubleValue));
			}
			myData.push_back(myDataRow);
		}
	}

	myFile << titles << std::endl;

	int nRow = myData[0].size();
	int nCol = myData.size();

	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			if (j == nCol - 1)
				myFile << myData[j][i];
			else
				myFile << myData[j][i] << delimiter << " ";
		}
		if (i < nRow - 1)
			myFile << std::endl;
	}

	myFile.close();

	return true;
}

bool ForgVisualLib::FrgVisual_Plot2D_ChartXY::ExportDataAsCSVMerged(const std::string& myFileName)
{
	return ExportDataMerged(myFileName, ',');
}

bool ForgVisualLib::FrgVisual_Plot2D_ChartXY::ExportDataAsXLSX(const std::string& fileName)
{
	const auto nbPlots = this->GetNumberOfPlots();

	if (nbPlots == 0)
		return false;

	fstream myFile;
	myFile.open(fileName, std::ios::out);

	if (!myFile.is_open())
		return false;

	return false;
}

void ForgVisualLib::FrgVisual_Plot2D_ChartXY::RecalculateAndUpdateBoundingBox()
{
	const auto& nbPlots = this->GetNumberOfPlots();

	for (vtkIdType iPlot = 0; iPlot < nbPlots; iPlot++)
	{
		auto myPlot = GetPlot(iPlot);
		vtkTable* myTable = myPlot->GetInput();
		auto nbRow = myTable->GetNumberOfRows();
		auto nbColumns = myTable->GetNumberOfColumns();

		for (vtkIdType j = 0; j < nbColumns - 1; j++)
			for (vtkIdType i = 0; i < nbRow; i++)
			{
				double x = myTable->GetValue(i, j).ToDouble();
				double y = myTable->GetValue(i, j + 1).ToDouble();

				UpdateBoundingBox(ForgBaseLib::FrgBase_Pnt<2>(x, y));
			}
	}
}

void ForgVisualLib::FrgVisual_Plot2D_ChartXY::UpdateBoundingBox(const ForgBaseLib::FrgBase_Pnt<2>& P)
{
	if (!theBoundingBox_.IsInside(P))
	{
		FrgVisual_Plot2DChartXY_BoundingBox b1(P, P);
		theBoundingBox_ = FrgVisual_Plot2DChartXY_BoundingBox::Union(b1, theBoundingBox_);

		FitWindowToBoundingBox();
	}
}

void ForgVisualLib::FrgVisual_Plot2D_ChartXY::FitWindowToBoundingBox()
{
	auto offset = theBoundingBox_.OffSet(0.01 * theBoundingBox_.Diameter());

	auto bottomAxis = this->GetAxis(vtkAxis::BOTTOM);
	auto leftAxis = this->GetAxis(vtkAxis::LEFT);

	if (bottomAxis->GetLogScale())
	{
		double x = theBoundingBox_.P0().X();
		if (x <= 0.0)
			x = 0.01;
		
		//if(bottomAxis->GetUnscaledMinimum() == bottomAxis->GetUnscaledMinimumLimit())
			bottomAxis->SetUnscaledMinimum(x);

		bottomAxis->SetUnscaledMinimumLimit(x);
	}
	else
	{
		//if (bottomAxis->GetUnscaledMinimum() == bottomAxis->GetUnscaledMinimumLimit())
			bottomAxis->SetUnscaledMinimum(offset.P0().X());

		bottomAxis->SetUnscaledMinimumLimit(offset.P0().X());
	}
	
	//if (bottomAxis->GetUnscaledMaximum() == bottomAxis->GetUnscaledMaximumLimit())
		bottomAxis->SetUnscaledMaximum(offset.P1().X());

	bottomAxis->SetUnscaledMaximumLimit(offset.P1().X());

	if (leftAxis->GetLogScale())
	{
		double y = theBoundingBox_.P0().Y();
		if (y <= 0.0)
			y = 0.01;
		
		//if (leftAxis->GetUnscaledMinimum() == leftAxis->GetUnscaledMinimumLimit())
			leftAxis->SetUnscaledMinimum(y);

		leftAxis->SetUnscaledMinimumLimit(y);
	}
	else
	{
		//if (leftAxis->GetUnscaledMinimum() == leftAxis->GetUnscaledMinimumLimit())
			leftAxis->SetUnscaledMinimum(offset.P0().Y());

		leftAxis->SetUnscaledMinimumLimit(offset.P0().Y());
	}
	
	//if (leftAxis->GetUnscaledMaximum() == leftAxis->GetUnscaledMaximumLimit())
		leftAxis->SetUnscaledMaximum(offset.P1().Y());

	leftAxis->SetUnscaledMaximumLimit(offset.P1().Y());
}

void ForgVisualLib::FrgVisual_Plot2D_ChartXY::RecalculateBounds()
{
	FitWindowToBoundingBox();
}

double ForgVisualLib::FrgVisual_Plot2D_ChartXY::LinearEquation
(
	ForgBaseLib::FrgBase_Pnt<2> P0,
	ForgBaseLib::FrgBase_Pnt<2> P1,
	double x
)
{
	double t = (P1.Y() - P0.Y()) / (P1.X() - P0.X());
	double y0 = P1.Y() - P1.X() * t;

	return x * t + y0;
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Plot2D_ChartXY)
{
	QString isLegendVisibleText;

	if (this->GetLegendVisible())
		isLegendVisibleText = "TRUE";
	else
		isLegendVisibleText = "FALSE";

	ar& isLegendVisibleText;
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Plot2D_ChartXY)
{
	QString isLegendVisible;

	ar& isLegendVisible;

	if (isLegendVisible == "TRUE")
		this->SetLegendVisible(true);
	else if (isLegendVisible == "FALSE")
		this->SetLegendVisible(false);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Plot2D_ChartXY)