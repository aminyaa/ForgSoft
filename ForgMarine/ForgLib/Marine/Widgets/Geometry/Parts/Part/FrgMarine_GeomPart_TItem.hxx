#pragma once
#ifndef _FrgMarine_TItemGeom_Part_Header
#define _FrgMarine_TItemGeom_Part_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

#include <TopoDS_Shape.hxx>

BeginForgMarineLib

class FrgMarine_GeomPart_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgMarine_GeomPart_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	const TopoDS_Shape &GetShape() const { return TopoDS_Shape(); }
};

EndForgMarineLib

#endif // !_FrgMarine_TItemGeom_Part_Header
