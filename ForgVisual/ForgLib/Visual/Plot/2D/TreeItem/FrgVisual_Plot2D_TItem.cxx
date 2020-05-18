#include <FrgVisual_Plot2D_TItem.hxx>
#include <FrgVisual_Plot2D.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgVisual_Plot2DDataSeries_TItem.hxx>
#include <FrgVisual_Plot2DAxes_TItem.hxx>
#include <FrgVisual_Plot2DLegend_TItem.hxx>

#include <FrgVisual_Plot2D.hxx>
#include <FrgVisual_Plot2DDataSeries_TItem.hxx>
#include <FrgVisual_Plot2DLnStyle_TItem.hxx>
#include <FrgVisual_Plot2DSmblStyle_TItem.hxx>
#include <FrgBase_SerialSpec_QColor.hxx>
#include <vtkChartXY.h>
#include <vtkPlot.h>
#include <vtkTable.h>
#include <vtkAbstractArray.h>
#include <vtkVariant.h>
#include <vtkPen.h>
#include <FrgBase_Tree.hxx>

ForgVisualLib::FrgVisual_Plot2D_TItem::FrgVisual_Plot2D_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgVisual_Plot_TItem(itemTitle, parentItem, parentTree)
{
	this->setIcon(0, QIcon(ICONPlot_2D));

	thePlot_ = new FrgVisual_Plot2D(GetParentMainWindow());

	FrgVisual_Plot_TItem::Init();
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::Init()
{
	if (theDataSeriesTItem_)
	{
		delete theDataSeriesTItem_;
		theDataSeriesTItem_ = nullptr;
	}
	if (theAxesTItem_)
	{
		delete theAxesTItem_;
		theAxesTItem_ = nullptr;
	}
	if (theLegendTItem_)
	{
		delete theLegendTItem_;
		theLegendTItem_ = nullptr;
	}

	theDataSeriesTItem_ = new ForgBaseLib::FrgBase_TreeItem("Data Series", this, GetParentTree());
	theAxesTItem_ = new FrgVisual_Plot2DAxes_TItem("Axes", this, GetParentTree());
	theLegendTItem_ = new FrgVisual_Plot2DLegend_TItem("Legend", this, GetParentTree());
}

ForgVisualLib::FrgVisual_Plot2D * ForgVisualLib::FrgVisual_Plot2D_TItem::GetPlot2D() const
{
	auto plot2D = dynamic_cast<FrgVisual_Plot2D*>(thePlot_);

	if (plot2D)
		return plot2D;

	return nullptr;
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetLegendVisible(bool condition)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetLegendVisible(condition);
}

bool ForgVisualLib::FrgVisual_Plot2D_TItem::GetLegendVisible() const
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		return plot2D->GetLegendVisible();

	return true;
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetBottomAxisTitle(const char * title)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetBottomAxisTitle(title);
}

const char * ForgVisualLib::FrgVisual_Plot2D_TItem::GetBottomAxisTitle() const
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		return plot2D->GetBottomAxisTitle();

	return "X Axis";
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetLeftAxisTitle(const char * title)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetLeftAxisTitle(title);
}

const char * ForgVisualLib::FrgVisual_Plot2D_TItem::GetLeftAxisTitle() const
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		return plot2D->GetLeftAxisTitle();

	return "Y Axis";
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetBottomAxisTitleVisible(bool condition)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetBottomAxisTitleVisible(condition);
}

bool ForgVisualLib::FrgVisual_Plot2D_TItem::GetBottomAxisTitleVisible() const
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		return plot2D->GetBottomAxisTitleVisible();

	return true;
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetLeftAxisTitleVisible(bool condition)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetLeftAxisTitleVisible(condition);
}

bool ForgVisualLib::FrgVisual_Plot2D_TItem::GetLeftAxisTitleVisible() const
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		return plot2D->GetLeftAxisTitleVisible();

	return true;
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetBottomAxisVisible(bool condition)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetBottomAxisVisible(condition);
}

bool ForgVisualLib::FrgVisual_Plot2D_TItem::GetBottomAxisVisible() const
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		return plot2D->GetBottomAxisVisible();
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetLeftAxisVisible(bool condition)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetLeftAxisVisible(condition);
}

bool ForgVisualLib::FrgVisual_Plot2D_TItem::GetLeftAxisVisible() const
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		return plot2D->GetLeftAxisVisible();
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetBottomAxisLogarithmic(bool condition)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetBottomAxisLogarithmic(condition);
}

bool ForgVisualLib::FrgVisual_Plot2D_TItem::GetBottomAxisLogarithmic() const
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		return plot2D->GetBottomAxisLogarithmic();
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetLeftAxisLogarithmic(bool condition)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetLeftAxisLogarithmic(condition);
}

bool ForgVisualLib::FrgVisual_Plot2D_TItem::GetLeftAxisLogarithmic() const
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		return plot2D->GetLeftAxisLogarithmic();
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetBottomAxisTitleRotation(int degree)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetBottomAxisTitleRotation(degree);
}

int ForgVisualLib::FrgVisual_Plot2D_TItem::GetBottomAxisTitleRotation() const
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		return plot2D->GetBottomAxisTitleRotation();

	return 0;
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetLeftAxisTitleRotation(int degree)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetLeftAxisTitleRotation(degree);
}

int ForgVisualLib::FrgVisual_Plot2D_TItem::GetLeftAxisTitleRotation() const
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		return plot2D->GetLeftAxisTitleRotation();

	return 90;
}

void ForgVisualLib::FrgVisual_Plot2D_TItem::SetLegendPosition(LEGEND_POSITION_ENUM position)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		plot2D->SetLegendPosition(position);
}

ForgVisualLib::LEGEND_POSITION_ENUM ForgVisualLib::FrgVisual_Plot2D_TItem::GetLegendPosition() const
{
	auto plot2D = GetPlot2D();

	if (plot2D)
		return plot2D->GetLegendPosition();
}

vtkPlot* ForgVisualLib::FrgVisual_Plot2D_TItem::AddPlot(std::vector<double> x, std::vector<double> y, const char* title)
{
	auto plot2D = GetPlot2D();

	if (plot2D)
	{
		if (!theDataSeriesTItem_ || !theAxesTItem_ || !theLegendTItem_)
			Init();

		auto VTKPlot = plot2D->AddPlot(x, y, title);
		//auto sinXTItem = new FrgVisual_Plot2DDataSeries_TItem(title, theDataSeriesTItem_, GetParentTree(), VTKPlot);
		thePlotsTItem_.push_back(new FrgVisual_Plot2DDataSeries_TItem(title, theDataSeriesTItem_, GetParentTree(), VTKPlot));

		return VTKPlot;
	}

	return nullptr;
}

vtkPlot* ForgVisualLib::FrgVisual_Plot2D_TItem::AddPlotSinXSlot()
{
	auto plot2D = GetPlot2D();

	if (plot2D)
	{
		if (!theDataSeriesTItem_ || !theAxesTItem_ || !theLegendTItem_)
			Init();

		QString TItemName = CorrectName(theDataSeriesTItem_, "Sin(x)");
		auto VTKPlot = plot2D->AddSinX(TItemName.toLatin1().constData());
		//auto sinXTItem = new FrgVisual_Plot2DDataSeries_TItem(TItemName.toLatin1().constData(), theDataSeriesTItem_, GetParentTree(), VTKPlot);
		thePlotsTItem_.push_back(new FrgVisual_Plot2DDataSeries_TItem(TItemName.toLatin1().constData(), theDataSeriesTItem_, GetParentTree(), VTKPlot));
	
		return VTKPlot;
	}

	return nullptr;
}

vtkPlot* ForgVisualLib::FrgVisual_Plot2D_TItem::AddPlotCosXSlot()
{
	auto plot2D = GetPlot2D();

	if (plot2D)
	{
		if (!theDataSeriesTItem_ || !theAxesTItem_ || !theLegendTItem_)
			Init();

		QString TItemName = CorrectName(theDataSeriesTItem_, "Cos(x)");
		auto VTKPlot = plot2D->AddCosX(TItemName.toLatin1().constData());
		//auto cosXTItem = new FrgVisual_Plot2DDataSeries_TItem(TItemName.toLatin1().constData(), theDataSeriesTItem_, GetParentTree(), VTKPlot);
		thePlotsTItem_.push_back(new FrgVisual_Plot2DDataSeries_TItem(TItemName.toLatin1().constData(), theDataSeriesTItem_, GetParentTree(), VTKPlot));

		return VTKPlot;
	}

	return nullptr;
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Plot2D_TItem)
{
	bool isLegendVisible = GetLegendVisible();
	ar & isLegendVisible;

	QString bottomAxisTitle = GetBottomAxisTitle();
	QString leftAxisTitle = GetLeftAxisTitle();
	ar & bottomAxisTitle;
	ar & leftAxisTitle;

	bool isBottomAxisTitleVisible = GetBottomAxisTitleVisible();
	bool isLeftAxisTitleVisible = GetLeftAxisTitleVisible();
	ar & isBottomAxisTitleVisible;
	ar & isLeftAxisTitleVisible;

	bool isBottomAxisVisible = GetBottomAxisVisible();
	bool isLeftAxisVisible = GetLeftAxisVisible();
	ar & isBottomAxisVisible;
	ar & isLeftAxisVisible;

	bool isBottomAxisLogarithmic = GetBottomAxisLogarithmic();
	bool LeftAxisLogarithmic = GetLeftAxisLogarithmic();
	ar & isBottomAxisLogarithmic;
	ar & LeftAxisLogarithmic;

	int isBottomAxisTitleRotation = GetBottomAxisTitleRotation();
	int isLeftAxisTitleRotation = GetLeftAxisTitleRotation();
	ar & isBottomAxisTitleRotation;
	ar & isLeftAxisTitleRotation;

	ForgVisualLib::LEGEND_POSITION_ENUM legendPosition = GetLegendPosition();
	ar & legendPosition;

	// ========================
	// Save plots
	// ========================

	auto myChartXY = GetPlot2D()->GetChartXY();

	// write number of plots
	vtkIdType numberOfPlots = myChartXY->GetNumberOfPlots();
	ar & numberOfPlots;

	for (vtkIdType i = 0; i < numberOfPlots; i++)
	{
		vtkPlot* myPlot = myChartXY->GetPlot(i);
		vtkTable* myTable = myPlot->GetInput();

		// write table title
		const auto myAbstractArray = myTable->GetColumn(1);
		QString myTableTitle = QString(myAbstractArray->GetName());
		ar & myTableTitle;

		auto myPen = myPlot->GetPen();

		// write plot line style
		QString myPlotLineStyle = thePlotsTItem_[i]->GetLineStyleTItem()->GetStyle()->GetValue();
		ar & myPlotLineStyle;

		// write plot line color
		QColor myPlotLineColor = thePlotsTItem_[i]->GetLineStyleTItem()->GetColor()->GetValue();
		ar & myPlotLineColor;

		// write plot line width
		int myPlotLineWidth = thePlotsTItem_[i]->GetLineStyleTItem()->GetWidth()->GetValue();
		ar & myPlotLineWidth;

		// write plot line opacity
		double myPlotLineOpacity = thePlotsTItem_[i]->GetLineStyleTItem()->GetOpacity()->GetValue();
		ar & myPlotLineOpacity;

		// write plot symbol shape
		QString myPlotSymbolShape = thePlotsTItem_[i]->GetSymbolStyleTItem()->GetShape()->GetValue();
		ar & myPlotSymbolShape;

		// write plot symbol size
		int myPlotSymbolSize = thePlotsTItem_[i]->GetSymbolStyleTItem()->GetSize()->GetValue();
		ar & myPlotSymbolSize;

		// write plot symbol spacing
		int myPlotSymbolSpacing = thePlotsTItem_[i]->GetSymbolStyleTItem()->GetSpacing()->GetValue();
		ar & myPlotSymbolSpacing;

		// write number of rows
		vtkIdType nbOfRows = myTable->GetNumberOfRows();
		ar & nbOfRows;
		// write number of columns
		vtkIdType nbOfColumns = myTable->GetNumberOfColumns();
		ar & nbOfColumns;

		for (vtkIdType col = 0; col < nbOfColumns; col++)
		{
			for (vtkIdType row = 0; row < nbOfRows; row++)
			{
				// write value
				auto myValue = myTable->GetValue(row, col);
				double myDoubleValue = myValue.ToDouble();

				ar & myDoubleValue;
			}
		}
	}
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Plot2D_TItem)
{
	bool legendIsVisible;
	QString bottomAxisTitle, leftAxisTitle;
	bool bottomAxisTitleIsVisible, leftAxisTitleIsVisible;
	bool bottomAxisVisible, leftAxisVisible;
	bool bottomAxisLogarithmic, leftAxisLogarithmic;
	int bottomAxisTitleRotation, leftAxisTitleRotation;
	LEGEND_POSITION_ENUM legendPosition;

	// ==========================
	// Read from file
	// ==========================

	ar & legendIsVisible;

	ar & bottomAxisTitle;
	ar & leftAxisTitle;

	ar & bottomAxisTitleIsVisible;
	ar & leftAxisTitleIsVisible;

	ar & bottomAxisVisible;
	ar & leftAxisVisible;

	ar & bottomAxisLogarithmic;
	ar & leftAxisLogarithmic;

	ar & bottomAxisTitleRotation;
	ar & leftAxisTitleRotation;

	ar & legendPosition;

	// ==========================
	// Set data to class
	// ==========================

	SetLegendVisible(legendIsVisible);

	SetBottomAxisTitle(bottomAxisTitle.toStdString().c_str());
	SetLeftAxisTitle(leftAxisTitle.toStdString().c_str());

	SetBottomAxisTitleVisible(bottomAxisTitleIsVisible);
	SetLeftAxisTitleVisible(leftAxisTitleIsVisible);

	SetBottomAxisVisible(bottomAxisVisible);
	SetLeftAxisVisible(leftAxisVisible);

	SetBottomAxisLogarithmic(bottomAxisLogarithmic);
	SetLeftAxisLogarithmic(leftAxisLogarithmic);

	SetBottomAxisTitleRotation(bottomAxisTitleRotation);
	SetLeftAxisTitleRotation(leftAxisTitleRotation);

	SetLegendPosition(legendPosition);

	// ========================
	// Load plots
	// ========================

	// read number of plots
	vtkIdType numberOfPlots;
	ar & numberOfPlots;

	for (vtkIdType i = 0; i < numberOfPlots; i++)
	{
		// read table title
		QString myTableTitle;
		ar & myTableTitle;

		// read plot line style
		QString myPlotLineStyle;
		ar & myPlotLineStyle;

		// read plot line color
		QColor myPlotLineColor;
		ar & myPlotLineColor;

		// write plot line width
		int myPlotLineWidth;
		ar & myPlotLineWidth;

		// write plot line opacity
		double myPlotLineOpacity;
		ar & myPlotLineOpacity;

		// write plot symbol shape
		QString myPlotSymbolShape;
		ar & myPlotSymbolShape;

		// write plot symbol size
		int myPlotSymbolSize;
		ar & myPlotSymbolSize;

		// write plot symbol spacing
		int myPlotSymbolSpacing;
		ar & myPlotSymbolSpacing;

		// read number of rows
		vtkIdType nbOfRows;
		ar & nbOfRows;
		// read number of columns
		vtkIdType nbOfColumns;
		ar & nbOfColumns;

		std::vector<double> xValue;
		std::vector<double> yValue;

		for (vtkIdType col = 0; col < nbOfColumns; col++)
		{
			for (vtkIdType row = 0; row < nbOfRows; row++)
			{
				// read value
				double myValue;

				ar & myValue;

				if (col == 0)
					xValue.push_back(myValue);
				else
					yValue.push_back(myValue);
			}
		}

		AddPlot(xValue, yValue, myTableTitle.toStdString().c_str());

		// set plot line properties
		thePlotsTItem_[i]->GetLineStyleTItem()->StyleChangedSlot(myPlotLineStyle);
		thePlotsTItem_[i]->GetLineStyleTItem()->ColorChangedSlot(myPlotLineColor);
		thePlotsTItem_[i]->GetLineStyleTItem()->WidthChangedSlot(myPlotLineWidth);
		thePlotsTItem_[i]->GetLineStyleTItem()->OpacityChangedSlot(myPlotLineOpacity);

		// set plot symbol properties
		thePlotsTItem_[i]->GetSymbolStyleTItem()->ShapeChangedSlot(myPlotSymbolShape);
		thePlotsTItem_[i]->GetSymbolStyleTItem()->SizeChangedSlot(myPlotSymbolSize);
		thePlotsTItem_[i]->GetSymbolStyleTItem()->SpacingChangedSlot(myPlotSymbolSpacing);
	}
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2D_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Plot2D_TItem)
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2D_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Plot2D_TItem)
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Plot2D_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2D_TItem)