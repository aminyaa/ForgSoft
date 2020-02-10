#pragma once
#ifndef _FrgMarine_TItemGeomParMdlsShip_01_Header
#define _FrgMarine_TItemGeomParMdlsShip_01_Header

#include <FrgMarine_Global.hxx>
#include <FrgMarine_TItemGeomParMdls_Ship.hxx>

namespace tnbLib
{
	class LegModel_DispNo1;
}

BeginForgMarineLib

class FrgMarine_Ship01_Params;

class FORGMARINE_EXPORT FrgMarine_TItemGeomParMdlsShip_01
	: public FrgMarine_TItemGeomParMdls_Ship
{
	Q_OBJECT



public:

	FrgMarine_TItemGeomParMdlsShip_01
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

private:

	std::shared_ptr<tnbLib::LegModel_DispNo1> theModel_;
	FrgMarine_Ship01_Params* theParameters_ = NullPtr;
};

EndForgMarineLib

#endif // !_FrgMarine_TItemGeomParMdlsShip_01_Header
