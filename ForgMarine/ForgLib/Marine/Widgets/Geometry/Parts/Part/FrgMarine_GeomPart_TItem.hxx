#pragma once
#ifndef _FrgMarine_TItemGeom_Part_Header
#define _FrgMarine_TItemGeom_Part_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

#include <FrgMarine_Serialization_Global.hxx>

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

	void FormTItem() override;

	const TopoDS_Shape &GetShape() const { return TopoDS_Shape(); }

private:

	DECLARE_SAVE_LOAD_HEADER(FORGMARINE_EXPORT)
};

EndForgMarineLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPart_TItem, FORGMARINE_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgMarineLib::FrgMarine_GeomPart_TItem)

#endif // !_FrgMarine_TItemGeom_Part_Header
