#pragma once
#ifndef _FrgMarine_TItemGeomParMdls_Ship_Header
#define _FrgMarine_TItemGeomParMdls_Ship_Header

#include <FrgMarine_Global.hxx>
#include <FrgMarine_TItemGeom_ParMdls.hxx>

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_TItemGeomParMdls_Ship
	: public FrgMarine_TItemGeom_ParMdls
{
	Q_OBJECT

public:

	FrgMarine_TItemGeomParMdls_Ship
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);
};

EndForgMarineLib

#endif // !_FrgMarine_TItemGeomParMdls_Ship_Header
