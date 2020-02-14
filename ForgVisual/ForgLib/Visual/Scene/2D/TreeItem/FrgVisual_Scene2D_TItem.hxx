#pragma once
#ifndef _FrgVisual_Scene2D_TItem_Header
#define _FrgVisual_Scene2D_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Scene_TItem.hxx>

BeginForgVisualLib

class FrgVisual_Scene2D;

class FORGVISUAL_EXPORT FrgVisual_Scene2D_TItem
	: public FrgVisual_Scene_TItem
{
	Q_OBJECT

public:

	FrgVisual_Scene2D_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

};

EndForgVisualLib

#endif // !_FrgVisual_Scene2D_TItem_Header
