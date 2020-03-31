#pragma once
#ifndef _FrgVisual_Plot2DAxes_TItem_Header
#define _FrgVisual_Plot2DAxes_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>

BeginForgVisualLib

class FrgVisual_Plot2D_TItem;
class FrgVisual_Plot2DBtmAxis_TItem;
class FrgVisual_Plot2DLeftAxis_TItem;

class FORGVISUAL_EXPORT FrgVisual_Plot2DAxes_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgVisual_Plot2DAxes_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	FrgVisual_Plot2D_TItem* GetPlot2dTItem() const;

	/*void SetBottomAxisTitle(const char* title);
	void SetLeftAxisTitle(const char* title);

	void SetBottomAxisTitleVisible(bool condition);
	void SetLeftAxisTitleVisible(bool condition);

	void SetBottomAxisVisible(bool condition);
	void SetLeftAxisVisible(bool condition);*/

private:

	FrgVisual_Plot2DBtmAxis_TItem* theBottomAxisTItem_ = nullptr;
	FrgVisual_Plot2DLeftAxis_TItem* theLeftAxisTItem_ = nullptr;

	FrgVisual_Plot2D_TItem* thePlot2DTItem_ = nullptr;
};

EndForgVisualLib

#endif // !_FrgVisual_Plot2DAxes_TItem_Header
