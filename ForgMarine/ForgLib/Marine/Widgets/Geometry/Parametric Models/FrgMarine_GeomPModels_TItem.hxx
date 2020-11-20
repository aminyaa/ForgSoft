#pragma once
#ifndef _FrgMarine_TItemGeom_ParMdls_Header
#define _FrgMarine_TItemGeom_ParMdls_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

#include <FrgMarine_Serialization_Global.hxx>

namespace tnbLib
{
	class CadModel_Entity;
}

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_GeomPModels_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgMarine_GeomPModels_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	~FrgMarine_GeomPModels_TItem();

	void FormTItem() override;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGMARINE_EXPORT)

private slots:

	void Ship01CreateSlot();
};

EndForgMarineLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPModels_TItem, FORGMARINE_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgMarineLib::FrgMarine_GeomPModels_TItem)

#endif // !_FrgMarine_TItemGeom_ParMdls_Header
