#pragma once
#ifndef _FrgMarine_TItemGeom_ParMdls_Header
#define _FrgMarine_TItemGeom_ParMdls_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

BeginForgMarineLib

class FrgMarine_TItemGeomParMdlsShip_01;

class FORGMARINE_EXPORT FrgMarine_TItemGeom_ParMdls
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgMarine_TItemGeom_ParMdls
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

private slots:

	void Ship01CreateSlot();
};

EndForgMarineLib

#endif // !_FrgMarine_TItemGeom_ParMdls_Header
