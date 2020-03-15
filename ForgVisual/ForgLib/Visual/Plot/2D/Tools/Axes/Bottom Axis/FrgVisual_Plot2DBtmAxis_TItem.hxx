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
		ForgBaseLib::FrgBase_Tree* parentTree
	);
};

EndForgVisualLib

#endif // !_FrgVisual_Plot2DBtmAxis_TItem_Header
