#pragma once
#ifndef _FrgVisual_Plot2DAxes_TItem_Header
#define _FrgVisual_Plot2DAxes_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>

#include <FrgVisual_Serialization_Global.hxx>

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

	FrgVisual_Plot2D_TItem* GetPlot2DTItem() const;

	void FormAxes();

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)

private:

	FrgVisual_Plot2DBtmAxis_TItem* theBottomAxisTItem_ = nullptr;
	FrgVisual_Plot2DLeftAxis_TItem* theLeftAxisTItem_ = nullptr;

	FrgVisual_Plot2D_TItem* thePlot2DTItem_ = nullptr;
};

EndForgVisualLib

// override for non-default constructor
DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DAxes_TItem, FORGVISUAL_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Plot2DAxes_TItem)

#endif // !_FrgVisual_Plot2DAxes_TItem_Header
