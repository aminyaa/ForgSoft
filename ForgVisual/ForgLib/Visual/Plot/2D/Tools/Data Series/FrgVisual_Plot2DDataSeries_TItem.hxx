#pragma once
#ifndef _FrgVisual_Plot2DDataSeries_TItem_Header
#define _FrgVisual_Plot2DDataSeries_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>

class vtkPlot;

BeginForgVisualLib

class FrgVisual_Plot2DLnStyle_TItem;
class FrgVisual_Plot2DSmblStyle_TItem;
class FrgVisual_Plot2D_TItem;

class FORGVISUAL_EXPORT FrgVisual_Plot2DDataSeries_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgVisual_Plot2DDataSeries_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	vtkPlot* GetVTKPlot() const { return theVTKPlot_; }
	void SetVTKPlot(vtkPlot* plot) { theVTKPlot_ = plot; }

	FrgVisual_Plot2D_TItem* GetPlot2DTItem() const;

	void RenderView() const;

private:

	FrgVisual_Plot2DLnStyle_TItem* theLineStyle_ = nullptr;
	FrgVisual_Plot2DSmblStyle_TItem* theSymbolStyle_ = nullptr;

	vtkPlot* theVTKPlot_ = nullptr;
};

EndForgVisualLib

#endif // !_FrgVisual_Plot2DDataSeries_TItem_Header
