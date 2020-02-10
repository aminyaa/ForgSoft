#pragma once
#ifndef _FrgMarine_TItem_Geom_Header
#define _FrgMarine_TItem_Geom_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

BeginForgMarineLib

class FrgMarine_TItemGeom_ParMdls;

class FORGMARINE_EXPORT FrgMarine_TItem_Geom
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgMarine_TItem_Geom
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

private:

	FrgMarine_TItemGeom_ParMdls* theParametricModels_ = NullPtr;
};

EndForgMarineLib

#endif // !_FrgMarine_TItem_Geom_Header
