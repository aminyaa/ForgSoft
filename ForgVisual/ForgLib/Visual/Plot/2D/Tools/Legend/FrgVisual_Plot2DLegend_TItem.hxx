#pragma once
#ifndef _FrgVisual_Plot2DLegend_TItem_Header
#define _FrgVisual_Plot2DLegend_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_PrptsVrntBool.hxx>
#include <FrgBase_PrptsVrntCombo.hxx>

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

	FrgVisual_Plot2D_TItem* thePlot2DTItem_ = nullptr;

	ForgBaseLib::FrgBase_PrptsVrntBool* theVisible_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntCombo* thePosition_ = nullptr;

private slots:

	void VisibilityChangedSlot(const bool& condition);
	void PositionChangedSlot(const char* position);
};

EndForgVisualLib

#endif // !_FrgVisual_Plot2DLegend_TItem_Header
