#pragma once
#ifndef _FrgVisual_Plot2D_TItem_Header
#define _FrgVisual_Plot2D_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Plot_TItem.hxx>
#include <FrgBase_PrptsVrntString.hxx>

class vtkPlot;

BeginForgVisualLib

class FrgVisual_Plot2D;
class FrgVisual_Plot2DAxes_TItem;
class FrgVisual_Plot2DLegend_TItem;

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

	FrgVisual_Plot2D* GetPlot2D() const;

	void SetLegendVisible(bool condition);

	void SetBottomAxisTitle(const char* title);
	void SetLeftAxisTitle(const char* title);

	void SetBottomAxisTitleVisible(bool condition);
	void SetLeftAxisTitleVisible(bool condition);

	void SetBottomAxisVisible(bool condition);
	void SetLeftAxisVisible(bool condition);

	void SetBottomAxisLogarithmic(bool condition);
	void SetLeftAxisLogarithmic(bool condition);

	vtkPlot* AddPlot(std::vector<double> x, std::vector<double> y, const char* title);

protected:

	void Init() override {}

protected slots:

	vtkPlot* AddPlotSinXSlot();
	vtkPlot* AddPlotCosXSlot();

private:

	ForgBaseLib::FrgBase_TreeItem* theDataSeriesTItem_ = nullptr;
	FrgVisual_Plot2DAxes_TItem* theAxesTItem_ = nullptr;
	FrgVisual_Plot2DLegend_TItem* theLegendTItem_ = nullptr;
};

EndForgVisualLib

#endif // !_FrgVisual_Plot2D_TItem_Header
