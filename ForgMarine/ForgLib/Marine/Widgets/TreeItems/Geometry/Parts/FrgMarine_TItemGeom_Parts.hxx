#pragma once
#ifndef _FrgMarine_TItem_Parts_Header
#define _FrgMarine_TItem_Parts_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_TItemGeom_Parts
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgMarine_TItemGeom_Parts
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);
};

EndForgMarineLib

#endif // !_FrgMarine_TItem_Parts_Header
