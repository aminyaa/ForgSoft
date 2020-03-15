#pragma once
#ifndef _FrgVisual_Plot2DAxisEntity_TItem_Header
#define _FrgVisual_Plot2DAxisEntity_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_PrptsVrntBool.hxx>

BeginForgVisualLib

class FrgVisual_Plot2DAxisTitle_TItem;

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
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	ForgBaseLib::FrgBase_PrptsVrntBool* GetVisible() const { return theVisible_; }
	void SetVisible(ForgBaseLib::FrgBase_PrptsVrntBool* visible) { theVisible_ = visible; }

	ForgBaseLib::FrgBase_PrptsVrntBool*GetLogarithmic() const { return theLogarithmic_; }
	void SetLogarithmic(ForgBaseLib::FrgBase_PrptsVrntBool* logarithmic) { theLogarithmic_ = logarithmic; }

private:

	ForgBaseLib::FrgBase_PrptsVrntBool* theVisible_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntBool* theLogarithmic_ = nullptr;

	FrgVisual_Plot2DAxisTitle_TItem* theTitleTItem_ = nullptr;
};

EndForgVisualLib

#endif // !_FrgVisual_Plot2DAxisEntity_TItem_Header
