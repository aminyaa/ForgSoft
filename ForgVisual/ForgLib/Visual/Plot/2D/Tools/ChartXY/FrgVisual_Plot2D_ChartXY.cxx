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

#include <FrgBase_SerialSpec_QString.hxx>

#include <string>
#include <QtCore/QList>

ForgVisualLib::FrgVisual_Plot2D_ChartXY* ForgVisualLib::FrgVisual_Plot2D_ChartXY::New()
{
	VTK_STANDARD_NEW_BODY(ForgVisualLib::FrgVisual_Plot2D_ChartXY)
}

ForgVisualLib::FrgVisual_Plot2D_ChartXY::FrgVisual_Plot2D_ChartXY()
	: theMouseFraction_(0.01)
{
	this->ForceAxesToBoundsOn();
	this->GetAxis(0)->GetGridPen()->SetColor(220, 220, 220);
	this->GetAxis(1)->GetGridPen()->SetColor(220, 220, 220);

	this->SetActionToButton(vtkChart::PAN, vtkContextMouseEvent::RIGHT_BUTTON);
	this->SetActionToButton(vtkChart::SELECT, vtkContextMouseEvent::LEFT_BUTTON);

	this->SetShowLegend(true);
	//this->GetLegend()->SetInline(false);
	this->GetLegend()->GetLabelProperties()->SetFontFamilyToTimes();
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

bool ForgVisualLib::FrgVisual_Plot2D_ChartXY::MouseWheelEvent(const vtkContextMouseEvent & mouse, int delta)
{
	if (theHorizontalIndicatorLine_ || theVericalIndicatorLine_)
	{
		this->RemovePlotInstance(theHorizontalIndicatorLine_);
		this->RemovePlotInstance(theVericalIndicatorLine_);
	}

	return vtkChartXY::MouseWheelEvent(mouse, delta);

	//if (this->Tooltip)
	//{
	//	this->Tooltip->SetVisible(false);
	//}
	//if (!this->ZoomWithMouseWheel)
	//{
	//	return false;
	//}

	//// Zoom into the chart by the specified amount, and recalculate the bounds
	//vtkVector2f point2(mouse.GetPos());

	//this->ZoomInAxes(this->ChartPrivate->axes[vtkAxis::BOTTOM],
	//	this->ChartPrivate->axes[vtkAxis::LEFT], this->MouseBox.GetData(), point2.GetData());
	//this->ZoomInAxes(this->ChartPrivate->axes[vtkAxis::TOP],
	//	this->ChartPrivate->axes[vtkAxis::RIGHT], this->MouseBox.GetData(), point2.GetData());

	//this->RecalculatePlotTransforms();
	//this->MouseBox.SetWidth(0.0);
	//this->MouseBox.SetHeight(0.0);
	//this->DrawBox = false;
	//// Mark the scene as dirty
	//this->Scene->SetDirty(true);
	//this->InvokeEvent(vtkCommand::InteractionEvent);
	//return true;


	vtkVector2f point2(mouse.GetPos());

	// Get the bounds of each plot.
	for (int i = 0; i < 4; ++i)
	{
		vtkAxis* axis = this->GetAxis(i);
		double min = axis->GetMinimum();
		double max = axis->GetMaximum();
		double maxMmin = max - min;

		if (delta > 0)
		{
			double center = 0;
			if (i == vtkAxis::BOTTOM || i == vtkAxis::TOP)
				center = (double)(point2.GetX()) / (double)(this->GetGeometry()[0]);
			else if (i == vtkAxis::LEFT || i == vtkAxis::RIGHT)
				center = (double)(point2.GetY()) / (double)(this->GetGeometry()[1]);

			center = center * (max - min) + min;

			min = center - (1.0 - theMouseFraction_)*maxMmin / 2.0;
			max = center + (1.0 - theMouseFraction_)*maxMmin / 2.0;
		}
		else
		{
			/*min -= delta * frac;
			max += delta * frac;*/
		}
		axis->SetRange(min, max);
		axis->RecalculateTickSpacing();
	}

	this->RecalculatePlotTransforms();

	// Mark the scene as dirty
	this->Scene->SetDirty(true);

	this->InvokeEvent(vtkCommand::InteractionEvent);

	return true;
}

bool ForgVisualLib::FrgVisual_Plot2D_ChartXY::MouseMoveEvent(const vtkContextMouseEvent & mouse)
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
					auto& table = vtkSmartPointer<vtkTable>::New();

					vtkSmartPointer<vtkFloatArray> arrX =
						vtkSmartPointer<vtkFloatArray>::New();
					arrX->SetName("bottom-axis");
					table->AddColumn(arrX);

					vtkSmartPointer<vtkFloatArray> arrY =
						vtkSmartPointer<vtkFloatArray>::New();
					arrY->SetName("");
					table->AddColumn(arrY);

					table->SetNumberOfRows(2);

					table->SetValue(0, 0, plotPosd.GetX());
					table->SetValue(0, 1, plotPosd.GetY());

					if (iLine == 0)
					{
						// Vertical Line
						table->SetValue(1, 0, plotPosd.GetX());
						double range[2];
						myPlot->GetYAxis()->GetRange(range);
						table->SetValue(1, 1, range[0]);
					}
					else
					{
						// Horizontal Line
						double range[2];
						myPlot->GetXAxis()->GetRange(range);
						table->SetValue(1, 0, range[0]);
						table->SetValue(1, 1, plotPosd.GetY());
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

bool ForgVisualLib::FrgVisual_Plot2D_ChartXY::MouseButtonPressEvent(const vtkContextMouseEvent & mouse)
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

bool ForgVisualLib::FrgVisual_Plot2D_ChartXY::ExportDataAsCSV(std::string myFileName)
{
	const auto& nbPlots = this->GetNumberOfPlots();

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
			titles += "\"" + myPlot->GetXAxis()->GetTitle() + "\", ";

		if (iPlot == nbPlots - 1)
			titles += "\"" + myTableTitle.toStdString() + "\"";
		else
			titles += "\"" + myTableTitle.toStdString() + "\", ";

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
				myFile << myData[j][i] << ", ";
		}
		if (i < nRow - 1)
			myFile << std::endl;
	}

	return true;
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Plot2D_ChartXY)
{
	QString isLegendVisibleText;

	if (this->GetLegendVisible())
		isLegendVisibleText = "TRUE";
	else
		isLegendVisibleText = "FALSE";

	ar & isLegendVisibleText;
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Plot2D_ChartXY)
{
	QString isLegendVisible;

	ar & isLegendVisible;

	if (isLegendVisible == "TRUE")
		this->SetLegendVisible(true);
	else if (isLegendVisible == "FALSE")
		this->SetLegendVisible(false);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Plot2D_ChartXY)