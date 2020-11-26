#pragma once
#ifndef _FrgMarine_GeomPModel_TItem_Header
#define _FrgMarine_GeomPModel_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

#include <FrgMarine_Serialization_Global.hxx>

#include <TopoDS_Shape.hxx>

BeginForgMarineLib

class FrgMarine_Scene3D_TItem;

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

	~FrgMarine_GeomPModel_TItem();

	void FormTItem() override;

	virtual const TopoDS_Shape& GetShape() const { return TopoDS_Shape(); }

	virtual FrgMarine_Scene3D_TItem* GetPreviewTItem() const { return thePreviewTItem_; }

private:

	DECLARE_SAVE_LOAD_HEADER(FORGMARINE_EXPORT)

private slots:

	void CreatePartFromModelSlot();

protected:

	FrgMarine_Scene3D_TItem* thePreviewTItem_ = nullptr;
};

EndForgMarineLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPModel_TItem, FORGMARINE_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgMarineLib::FrgMarine_GeomPModel_TItem)

#endif // !_FrgMarine_GeomPModel_TItem_Header
