#pragma once
#ifndef _FrgVisual_Plot2DAxisTitle_TItem_Header
#define _FrgVisual_Plot2DAxisTitle_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_PrptsVrntBool.hxx>
#include <FrgBase_PrptsVrntString.hxx>
#include <FrgBase_PrptsVrntCombo.hxx>

#include <FrgVisual_Serialization_Global.hxx>

BeginForgVisualLib

class FrgVisual_Plot2D_TItem;

class FORGVISUAL_EXPORT FrgVisual_Plot2DAxisTitle_TItem
	: public ForgBaseLib::FrgBase_TreeItem
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
		ForgBaseLib::FrgBase_Tree* parentTree,
		FrgVisual_Plot2D_TItem* plot2DTItem
	);

	FrgVisual_Plot2D_TItem* GetPlot2DTItem() const { return thePlot2DTItem_; }

	virtual ~FrgVisual_Plot2DAxisTitle_TItem() {}

	ForgBaseLib::FrgBase_PrptsVrntBool* GetVisible() const { return theVisible_; }
	void SetVisible(ForgBaseLib::FrgBase_PrptsVrntBool* visible) { theVisible_ = visible; }

	ForgBaseLib::FrgBase_PrptsVrntString* GetTitle() const { return theTitle_; }
	void SetTitle(ForgBaseLib::FrgBase_PrptsVrntString* title) { theTitle_ = title; }

	ForgBaseLib::FrgBase_PrptsVrntCombo* GetRotation() { return theRotation_; }
	void SetRotation(ForgBaseLib::FrgBase_PrptsVrntCombo* rotation) { theRotation_ = rotation; }

private:

	DECLARE_SAVE_LOAD_HEADER

private:

	QString GetRotationFromPlot2DTItem() const;

private:

	ForgBaseLib::FrgBase_PrptsVrntBool* theVisible_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntString* theTitle_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntCombo* theRotation_ = nullptr;

	FrgVisual_Plot2D_TItem* thePlot2DTItem_ = nullptr;

protected slots:

	void VisibilityChangedSlot(const bool& condition);
	void TitleChangedSlot(const QString& title);
	void RotationChangedSlot(const QString& degreeChar);

public slots:

	void TItemClickedSlot() override;
	void TItemNotClickedSlot() override;
};

EndForgVisualLib

// override for non-default constructor
DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem)

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem)

#endif // !_FrgVisual_Plot2DAxisTitle_TItem_Header
