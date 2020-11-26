#pragma once
#ifndef _FrgVisual_Plot2DBtmAxis_TItem_Header
#define _FrgVisual_Plot2DBtmAxis_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Plot2DAxisEntity_TItem.hxx>
#include <FrgVisual_Plot2D_TItem.hxx>

#include <FrgVisual_Serialization_Global.hxx>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_Plot2DBtmAxis_TItem
	: public FrgVisual_Plot2DAxisEntity_TItem
{
	Q_OBJECT

public:

	FrgVisual_Plot2DBtmAxis_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree,
		FrgVisual_Plot2D_TItem* plot2DTItem
	);

	virtual ~FrgVisual_Plot2DBtmAxis_TItem() {}

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)

protected slots:

	void VisibilityChangedSlot(const bool& condition) override;
	void LogarithmicChangedSlot(const bool& condition) override;

public slots:

	void TItemClickedSlot() override;
	void TItemNotClickedSlot() override;
};

EndForgVisualLib

// override for non-default constructor
DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DBtmAxis_TItem, FORGVISUAL_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Plot2DBtmAxis_TItem)

#endif // !_FrgVisual_Plot2DBtmAxis_TItem_Header
