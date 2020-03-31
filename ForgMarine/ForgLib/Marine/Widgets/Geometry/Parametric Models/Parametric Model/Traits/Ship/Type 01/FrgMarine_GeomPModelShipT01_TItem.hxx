#pragma once
#ifndef _FrgMarine_TItemGeomParMdlsShip_01_Header
#define _FrgMarine_TItemGeomParMdlsShip_01_Header

#include <FrgMarine_Global.hxx>
#include <FrgMarine_GeomPModelShip_TItem.hxx>

class TopoDS_Shape;

namespace tnbLib
{
	class LegModel_DispNo1;
}

BeginForgMarineLib

class FrgMarine_ShipT01Params_TItem;

class FORGMARINE_EXPORT FrgMarine_GeomPModelShipT01_TItem
	: public FrgMarine_GeomPModelShip_TItem
{
	Q_OBJECT



public:

	FrgMarine_GeomPModelShipT01_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	~FrgMarine_GeomPModelShipT01_TItem();

	const TopoDS_Shape& GetShape() const override;

Q_SIGNALS:

	void ModelPerformedToPreviewSignal();

private:

	FrgMarine_ShipT01Params_TItem* theParameters_ = NullPtr;
};

EndForgMarineLib

#endif // !_FrgMarine_TItemGeomParMdlsShip_01_Header
