#pragma once
#ifndef _FrgMarine_GeomPModel_TItem_Header
#define _FrgMarine_GeomPModel_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

#include <TopoDS_Shape.hxx>

BeginForgMarineLib

class FrgMarine_GeomPModel_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgMarine_GeomPModel_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	virtual const TopoDS_Shape& GetShape() const { return TopoDS_Shape(); }

private slots:

	void CreatePartFromModelSlot();
};

EndForgMarineLib

#endif // !_FrgMarine_GeomPModel_TItem_Header
