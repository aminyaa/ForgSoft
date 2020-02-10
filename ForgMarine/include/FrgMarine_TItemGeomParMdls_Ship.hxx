#pragma once
#ifndef _FrgMarine_TItemGeomParMdls_Ship_Header
#define _FrgMarine_TItemGeomParMdls_Ship_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

namespace tnbLib
{
	class CadModel_Entity;
}

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_TItemGeomParMdls_Ship
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	std::shared_ptr<tnbLib::CadModel_Entity> GetModel() const { return theModel_; }
	std::shared_ptr<tnbLib::CadModel_Entity>& GetModel() { return theModel_; }

protected:

	FrgMarine_TItemGeomParMdls_Ship
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);



protected:

	std::shared_ptr<tnbLib::CadModel_Entity> theModel_;
};

EndForgMarineLib

#endif // !_FrgMarine_TItemGeomParMdls_Ship_Header
