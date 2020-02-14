#pragma once
#ifndef _FrgMarine_Scene2D_TItem_Header
#define _FrgMarine_Scene2D_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgVisual_Scene2D_TItem.hxx>

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_Scene2D_TItem
	: public ForgVisualLib::FrgVisual_Scene2D_TItem
{
	Q_OBJECT

public:

	FrgMarine_Scene2D_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);
};

EndForgMarineLib

#endif // !_FrgMarine_Scene2D_TItem_Header
