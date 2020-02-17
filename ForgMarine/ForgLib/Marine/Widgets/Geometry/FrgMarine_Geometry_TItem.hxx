#pragma once
#ifndef _FrgMarine_TItem_Geom_Header
#define _FrgMarine_TItem_Geom_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

BeginForgMarineLib

class FrgMarine_GeomPModels_TItem;
class FrgMarine_GeomParts_TItem;

class FORGMARINE_EXPORT FrgMarine_Geometry_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgMarine_Geometry_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	~FrgMarine_Geometry_TItem();

private:

	FrgMarine_GeomPModels_TItem* theParametricModels_ = NullPtr;
	FrgMarine_GeomParts_TItem* theParts_ = NullPtr;
};

EndForgMarineLib

#endif // !_FrgMarine_TItem_Geom_Header
