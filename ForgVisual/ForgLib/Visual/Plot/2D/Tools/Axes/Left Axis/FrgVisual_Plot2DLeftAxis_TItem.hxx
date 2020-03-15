#pragma once
#ifndef _FrgVisual_Plot2DLeftAxis_TItem_Header
#define _FrgVisual_Plot2DLeftAxis_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Plot2DAxisEntity_TItem.hxx>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_Plot2DLeftAxis_TItem
	: FrgVisual_Plot2DAxisEntity_TItem
{
	Q_OBJECT

public:

	FrgVisual_Plot2DLeftAxis_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);
};

EndForgVisualLib

#endif // !_FrgVisual_Plot2DLeftAxis_TItem_Header
