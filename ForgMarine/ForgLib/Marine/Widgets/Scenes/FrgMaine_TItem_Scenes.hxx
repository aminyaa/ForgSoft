#pragma once
#ifndef _FrgMaine_TItem_Scenes_Header
#define _FrgMaine_TItem_Scenes_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

BeginForgMarineLib

class FrgMaine_TItem_Scenes
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgMaine_TItem_Scenes
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);
};

EndForgMarineLib

#endif // !_FrgMaine_TItem_Scenes_Header
