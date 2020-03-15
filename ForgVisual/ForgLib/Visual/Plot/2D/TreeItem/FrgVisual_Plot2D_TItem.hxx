#pragma once
#ifndef _FrgVisual_Plot2D_TItem_Header
#define _FrgVisual_Plot2D_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Plot_TItem.hxx>
#include <FrgBase_PrptsVrntString.hxx>

class vtkPlot;

BeginForgVisualLib

class FrgVisual_Plot2DAxes_TItem;
class FrgVisual_Plot2DLegend_TItem;

class FORGVISUAL_EXPORT FrgVisual_Plot2D_TItem
	: public FrgVisual_Plot_TItem
{
	Q_OBJECT

	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntString* BottomAxisTitle READ GetBottomAxisTitle WRITE SetBottomAxisTitle)
	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntString* LeftAxisTitle READ GetLeftAxisTitle WRITE SetLeftAxisTitle)

public:

	FrgVisual_Plot2D_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	ForgBaseLib::FrgBase_PrptsVrntString* GetBottomAxisTitle() const { return theBottomAxisTitle; }
	void SetBottomAxisTitle(ForgBaseLib::FrgBase_PrptsVrntString* bottomAxisTitle) { theBottomAxisTitle = bottomAxisTitle; }
	ForgBaseLib::FrgBase_PrptsVrntString* GetLeftAxisTitle() const { return theLeftAxisTitle; }
	void SetLeftAxisTitle(ForgBaseLib::FrgBase_PrptsVrntString* leftAxisTitle) { theLeftAxisTitle = leftAxisTitle; }

	void SetLegendVisible(bool condition);
	void SetBottomTitle(const char* title);
	void SetLeftTitle(const char* title);

protected:

	void Init() override {}

protected slots:

	vtkPlot* AddPlotSinXSlot();
	vtkPlot* AddPlotCosXSlot();

private:

	ForgBaseLib::FrgBase_PrptsVrntString* theBottomAxisTitle;
	ForgBaseLib::FrgBase_PrptsVrntString* theLeftAxisTitle;

	ForgBaseLib::FrgBase_TreeItem* theDataSeriesTItem_ = nullptr;
	FrgVisual_Plot2DAxes_TItem* theAxesTItem_ = nullptr;
	FrgVisual_Plot2DLegend_TItem* theLegendTItem_ = nullptr;
};

EndForgVisualLib

#endif // !_FrgVisual_Plot2D_TItem_Header
