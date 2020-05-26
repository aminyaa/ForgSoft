#pragma once
#ifndef _FrgVisual_Plot2D_TItem_Header
#define _FrgVisual_Plot2D_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Plot_TItem.hxx>
#include <FrgBase_PrptsVrntString.hxx>

#include <FrgVisual_Serialization_Global.hxx>

namespace ForgBaseLib
{
	class FrgBase_Tree;
}

class vtkPlot;

BeginForgVisualLib

class FrgVisual_Plot2D;
class FrgVisual_Plot2DAxes_TItem;
class FrgVisual_Plot2DLegend_TItem;
enum LEGEND_POSITION_ENUM;
class FrgVisual_Plot2DDataSeries_TItem;

class FORGVISUAL_EXPORT FrgVisual_Plot2D_TItem
	: public FrgVisual_Plot_TItem
{
	Q_OBJECT

public:

	FrgVisual_Plot2D_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	virtual ~FrgVisual_Plot2D_TItem() {}

	ForgBaseLib::FrgBase_TreeItem* GetDataSeriesTItem() const { return theDataSeriesTItem_; }
	FrgVisual_Plot2DAxes_TItem* GetAxesTItem() const { return theAxesTItem_; }
	FrgVisual_Plot2DLegend_TItem* GetLegendTItem() const { return theLegendTItem_; }

public slots:
	
	void ExportDataAsCSVSlot();
	void ExportDataAsImageSlot();

protected:

	void Init() override;

public:

	FrgVisual_Plot2D* GetPlot2D() const;

	void SetLegendVisible(bool condition);
	bool GetLegendVisible() const;

	void SetBottomAxisTitle(const char* title);
	const char* GetBottomAxisTitle() const;

	void SetLeftAxisTitle(const char* title);
	const char* GetLeftAxisTitle() const;

	void SetBottomAxisTitleVisible(bool condition);
	bool GetBottomAxisTitleVisible() const;

	void SetLeftAxisTitleVisible(bool condition);
	bool GetLeftAxisTitleVisible() const;

	void SetBottomAxisVisible(bool condition);
	bool GetBottomAxisVisible() const;

	void SetLeftAxisVisible(bool condition);
	bool GetLeftAxisVisible() const;

	void SetBottomAxisLogarithmic(bool condition);
	bool GetBottomAxisLogarithmic() const;

	void SetLeftAxisLogarithmic(bool condition);
	bool GetLeftAxisLogarithmic() const;

	void SetBottomAxisTitleRotation(int degree);
	int GetBottomAxisTitleRotation() const;

	void SetLeftAxisTitleRotation(int degree);
	int GetLeftAxisTitleRotation() const;

	void SetLegendPosition(LEGEND_POSITION_ENUM);
	LEGEND_POSITION_ENUM GetLegendPosition() const;

	vtkPlot* AddPlot(std::vector<double> x, std::vector<double> y, const char* title);

private:

	DECLARE_SAVE_LOAD_HEADER

protected slots:

	vtkPlot* AddPlotSinXSlot();
	vtkPlot* AddPlotCosXSlot();

private:

	ForgBaseLib::FrgBase_TreeItem* theDataSeriesTItem_ = nullptr;
	FrgVisual_Plot2DAxes_TItem* theAxesTItem_ = nullptr;
	FrgVisual_Plot2DLegend_TItem* theLegendTItem_ = nullptr;

	std::vector<FrgVisual_Plot2DDataSeries_TItem*> thePlotsTItem_;
};

EndForgVisualLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2D_TItem)

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Plot2D_TItem)

#endif // !_FrgVisual_Plot2D_TItem_Header
