#pragma once
#ifndef _FrgVisual_Plot2DLegend_TItem_Header
#define _FrgVisual_Plot2DLegend_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_PrptsVrntBool.hxx>
#include <FrgBase_PrptsVrntCombo.hxx>

#include <FrgVisual_Serialization_Global.hxx>

BeginForgVisualLib

class FrgVisual_Plot2D_TItem;

class FORGVISUAL_EXPORT FrgVisual_Plot2DLegend_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntBool* Visible READ GetVisible WRITE SetVisible)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntCombo* Position READ GetPosition WRITE SetPosition)

public:

	FrgVisual_Plot2DLegend_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	ForgBaseLib::FrgBase_PrptsVrntBool* GetVisible() const { return theVisible_; }
	void SetVisible(ForgBaseLib::FrgBase_PrptsVrntBool* visible) { theVisible_ = visible; }

	ForgBaseLib::FrgBase_PrptsVrntCombo* GetPosition() const { return thePosition_; }
	void SetPosition(ForgBaseLib::FrgBase_PrptsVrntCombo* position) { thePosition_ = position; }

private:

	DECLARE_SAVE_LOAD_HEADER

private:

	QString GetLegendPositionFromPlot2DTItem() const;

private:

	FrgVisual_Plot2D_TItem* thePlot2DTItem_ = nullptr;

	ForgBaseLib::FrgBase_PrptsVrntBool* theVisible_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntCombo* thePosition_ = nullptr;

private slots:

	void VisibilityChangedSlot(const bool& condition);
	void PositionChangedSlot(const QString& position);
};

EndForgVisualLib

// override for non-default constructor
DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DLegend_TItem)

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Plot2DLegend_TItem)

#endif // !_FrgVisual_Plot2DLegend_TItem_Header
