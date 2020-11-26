#pragma once
#ifndef _FrgMarine_TItem_Geom_Header
#define _FrgMarine_TItem_Geom_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

#include <FrgMarine_Serialization_Global.hxx>

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

	void FormTItem() override;

	FrgMarine_GeomPModels_TItem* GetParametricModelsTItem() const { return theParametricModels_; }
	FrgMarine_GeomParts_TItem* GetPartsTItem() const { return theParts_; }

private:

	DECLARE_SAVE_LOAD_HEADER(FORGMARINE_EXPORT)

private:

	FrgMarine_GeomPModels_TItem* theParametricModels_ = NullPtr;
	FrgMarine_GeomParts_TItem* theParts_ = NullPtr;
};

EndForgMarineLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgMarineLib::FrgMarine_Geometry_TItem, FORGMARINE_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgMarineLib::FrgMarine_Geometry_TItem)

#endif // !_FrgMarine_TItem_Geom_Header
