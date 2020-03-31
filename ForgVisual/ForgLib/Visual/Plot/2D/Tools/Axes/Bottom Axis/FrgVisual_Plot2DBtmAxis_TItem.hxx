#pragma once
#ifndef _FrgVisual_Plot2DBtmAxis_TItem_Header
#define _FrgVisual_Plot2DBtmAxis_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Plot2DAxisEntity_TItem.hxx>

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

protected slots:

	void VisibilityChangedSlot(const bool& condition) override;
	void LogarithmicChangedSlot(const bool& condition) override;

public slots:

	void TItemClickedSlot() override;
	void TItemNotClickedSlot() override;
};

EndForgVisualLib

#endif // !_FrgVisual_Plot2DBtmAxis_TItem_Header
