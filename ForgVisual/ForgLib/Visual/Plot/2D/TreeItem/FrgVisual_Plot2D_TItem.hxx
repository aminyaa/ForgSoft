#pragma once
#ifndef _FrgVisual_Plot2D_TItem_Header
#define _FrgVisual_Plot2D_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Plot_TItem.hxx>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_Plot2D_TItem
	: public FrgVisual_Plot_TItem
{
	Q_OBJECT

public:

	FrgVisual_Plot2D_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

protected:

	void Init() override {}
};

EndForgVisualLib

#endif // !_FrgVisual_Plot2D_TItem_Header
