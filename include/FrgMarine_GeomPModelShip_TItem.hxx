#pragma once
#ifndef _FrgMarine_TItemGeomParMdls_Ship_Header
#define _FrgMarine_TItemGeomParMdls_Ship_Header

#include <FrgMarine_Global.hxx>
#include <FrgMarine_GeomPModel_TItem.hxx>

#include <FrgMarine_Serialization_Global.hxx>

namespace tnbLib
{
	class CadModel_Entity;
}

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_GeomPModelShip_TItem
	: public FrgMarine_GeomPModel_TItem
{
	Q_OBJECT

public:

	std::shared_ptr<tnbLib::CadModel_Entity> GetModel() const { return theModel_; }
	std::shared_ptr<tnbLib::CadModel_Entity>& GetModel() { return theModel_; }

public:

	FrgMarine_GeomPModelShip_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	void FormTItem() override;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGMARINE_EXPORT)

protected:

	mutable std::shared_ptr<tnbLib::CadModel_Entity> theModel_;
};

EndForgMarineLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPModelShip_TItem, FORGMARINE_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgMarineLib::FrgMarine_GeomPModelShip_TItem)

#endif // !_FrgMarine_TItemGeomParMdls_Ship_Header
