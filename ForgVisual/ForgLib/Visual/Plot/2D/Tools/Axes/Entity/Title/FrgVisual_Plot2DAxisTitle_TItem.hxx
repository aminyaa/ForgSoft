#pragma once
#ifndef _FrgVisual_Plot2DAxisTitle_TItem_Header
#define _FrgVisual_Plot2DAxisTitle_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_PrptsVrntBool.hxx>
#include <FrgBase_PrptsVrntString.hxx>
#include <FrgBase_PrptsVrntCombo.hxx>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_Plot2DAxisTitle_TItem
	:public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntBool* Visible READ GetVisible WRITE SetVisible)
	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntString* Title READ GetTitle WRITE SetTitle)
	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntCombo* Rotation READ GetRotation WRITE SetRotation)

public:

	FrgVisual_Plot2DAxisTitle_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	ForgBaseLib::FrgBase_PrptsVrntBool* GetVisible() const { return theVisible_; }
	void SetVisible(ForgBaseLib::FrgBase_PrptsVrntBool* visible) { theVisible_ = visible; }

	ForgBaseLib::FrgBase_PrptsVrntString* GetTitle() const { return theTitle_; }
	void SetTitle(ForgBaseLib::FrgBase_PrptsVrntString* title) { theTitle_ = title; }

	ForgBaseLib::FrgBase_PrptsVrntCombo* GetRotation() { return theRotation_; }
	void SetRotation(ForgBaseLib::FrgBase_PrptsVrntCombo* rotation) { theRotation_ = rotation; }

private:

	ForgBaseLib::FrgBase_PrptsVrntBool* theVisible_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntString* theTitle_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntCombo* theRotation_ = nullptr;
};

EndForgVisualLib

#endif // !_FrgVisual_Plot2DAxisTitle_TItem_Header
