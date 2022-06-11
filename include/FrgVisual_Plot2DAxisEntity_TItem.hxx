#pragma once
#ifndef _FrgVisual_Plot2DAxisEntity_TItem_Header
#define _FrgVisual_Plot2DAxisEntity_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_PrptsVrntBool.hxx>

#include <FrgVisual_Serialization_Global.hxx>

BeginForgVisualLib

class FrgVisual_Plot2DAxes_TItem;
class FrgVisual_Plot2DAxisTitle_TItem;
class FrgVisual_Plot2D_TItem;

class FORGVISUAL_EXPORT FrgVisual_Plot2DAxisEntity_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntBool* Visible READ GetVisible WRITE SetVisible)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntBool* Logarithmic READ GetLogarithmic WRITE SetLogarithmic)

public:

	FrgVisual_Plot2DAxisEntity_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree,
		FrgVisual_Plot2D_TItem* plot2D
	);

	virtual ~FrgVisual_Plot2DAxisEntity_TItem() {}

	ForgBaseLib::FrgBase_PrptsVrntBool* GetVisible() const { return theVisible_; }
	void SetVisible(ForgBaseLib::FrgBase_PrptsVrntBool* visible) { theVisible_ = visible; }

	ForgBaseLib::FrgBase_PrptsVrntBool*GetLogarithmic() const { return theLogarithmic_; }
	void SetLogarithmic(ForgBaseLib::FrgBase_PrptsVrntBool* logarithmic) { theLogarithmic_ = logarithmic; }

	FrgVisual_Plot2DAxes_TItem* GetPlot2DAxesTItem() const;

	FrgVisual_Plot2D_TItem* GetPlot2DTItem() const { return thePlot2DTItem_; }

	FrgVisual_Plot2DAxisTitle_TItem* GetTitleTItem() const { return theTitleTItem_; }

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)

protected:

	ForgBaseLib::FrgBase_PrptsVrntBool* theVisible_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntBool* theLogarithmic_ = nullptr;

	FrgVisual_Plot2DAxisTitle_TItem* theTitleTItem_ = nullptr;

protected:

	FrgVisual_Plot2D_TItem* thePlot2DTItem_ = nullptr;

protected slots:

	virtual void VisibilityChangedSlot(const bool& condition);
	virtual void LogarithmicChangedSlot(const bool& condition) {}
};

EndForgVisualLib

// override for non-default constructor
DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DAxisEntity_TItem, FORGVISUAL_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Plot2DAxisEntity_TItem)

#endif // !_FrgVisual_Plot2DAxisEntity_TItem_Header
