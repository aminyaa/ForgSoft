#pragma once
#ifndef _FrgMarine_ShipT01Params_TItem_TItem_Header
#define _FrgMarine_ShipT01Params_TItem_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

namespace tnbLib
{
	class LegModel_DispNo1;
}

BeginForgMarineLib

class FrgMarine_ShipT01ParamsDim_TItem;
class FrgMarine_ShipT01ParamsHull_TItem;
class FrgMarine_ShipT01ParamsKeel_TItem;
class FrgMarine_ShipT01ParamsStem_TItem;
class FrgMarine_ShipT01ParamsTransom_TItem;

class FORGMARINE_EXPORT FrgMarine_ShipT01Params_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgMarine_ShipT01Params_TItem
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

	FrgMarine_ShipT01ParamsDim_TItem* theDimension_ = NullPtr;
	FrgMarine_ShipT01ParamsHull_TItem* theHull_ = NullPtr;
	FrgMarine_ShipT01ParamsKeel_TItem* theKeel_ = NullPtr;
	FrgMarine_ShipT01ParamsStem_TItem* theStem_ = NullPtr;
	FrgMarine_ShipT01ParamsTransom_TItem* theTransom_ = NullPtr;
};

EndForgMarineLib

#endif // !_FrgMarine_ShipT01Params_TItem_TItem_Header
