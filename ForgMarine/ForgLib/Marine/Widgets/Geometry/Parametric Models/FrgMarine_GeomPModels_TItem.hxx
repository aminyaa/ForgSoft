#pragma once
#ifndef _FrgMarine_TItemGeom_ParMdls_Header
#define _FrgMarine_TItemGeom_ParMdls_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

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

private slots:

	void Ship01CreateSlot();
};

EndForgMarineLib

#endif // !_FrgMarine_TItemGeom_ParMdls_Header
