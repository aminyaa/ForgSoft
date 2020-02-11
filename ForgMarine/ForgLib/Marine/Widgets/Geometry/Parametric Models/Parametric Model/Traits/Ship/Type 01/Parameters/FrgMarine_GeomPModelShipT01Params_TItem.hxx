#pragma once
#ifndef _FrgMarine_GeomPModelShipT01Params_TItem_Header
#define _FrgMarine_GeomPModelShipT01Params_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

namespace tnbLib
{
	class LegModel_DispNo1;
}

BeginForgMarineLib

class FrgMarine_GeomPModelShipT01Params_Dimensions_TItem;
class FrgMarine_GeomPModelShipT01Params_Hull_TItem;
class FrgMarine_GeomPModelShipT01Params_Keel_TItem;
class FrgMarine_GeomPModelShipT01Params_Stem_TItem;
class FrgMarine_GeomPModelShipT01Params_Transom_TItem;

class FORGMARINE_EXPORT FrgMarine_GeomPModelShipT01Params_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgMarine_GeomPModelShipT01Params_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree,
		std::shared_ptr<tnbLib::LegModel_DispNo1> model
	);

Q_SIGNALS:

	void ModelPerformedToPreviewSignal();

private:

	std::shared_ptr<tnbLib::LegModel_DispNo1> theModel;

	FrgMarine_GeomPModelShipT01Params_Dimensions_TItem* theDimension_ = NullPtr;
	FrgMarine_GeomPModelShipT01Params_Hull_TItem* theHull_ = NullPtr;
	FrgMarine_GeomPModelShipT01Params_Keel_TItem* theKeel_ = NullPtr;
	FrgMarine_GeomPModelShipT01Params_Stem_TItem* theStem_ = NullPtr;
	FrgMarine_GeomPModelShipT01Params_Transom_TItem* theTransom_ = NullPtr;
};

EndForgMarineLib

#endif // !_FrgMarine_GeomPModelShipT01Params_TItem_Header
