#pragma once
#ifndef _FrgMarine_ShipT01ParamsHullSection_TItem_Header
#define _FrgMarine_ShipT01ParamsHullSection_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_PrptsVrntDouble.hxx>

namespace tnbLib
{
	class LegModel_DispNo1;
	class LegModel_DispNo1_SectionParamsBase;
}

BeginForgMarineLib

class FrgMarine_ShipT01Params_TItem;

class FORGMARINE_EXPORT FrgMarine_ShipT01ParamsHullSection_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* Tightness READ GetTightness WRITE SetTightness)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* Deadrise READ GetDeadrise WRITE SetDeadrise)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* SideSlope READ GetSideSlope WRITE SetSideSlope)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* Flare READ GetFlare WRITE SetFlare)

public:

	FrgMarine_ShipT01ParamsHullSection_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree,
		std::shared_ptr<tnbLib::LegModel_DispNo1> model,
		tnbLib::LegModel_DispNo1_SectionParamsBase* modelSection,
		FrgMarine_ShipT01Params_TItem* parametersTItem
	);

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetTightness() const { return theTightness_; }
	void SetTightness(ForgBaseLib::FrgBase_PrptsVrntDouble* tightness) { theTightness_ = tightness; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetDeadrise() const { return theDeadrise_; }
	void SetDeadrise(ForgBaseLib::FrgBase_PrptsVrntDouble* deadrise) { theDeadrise_ = deadrise; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetSideSlope() const { return theSideSlope_; }
	void SetSideSlope(ForgBaseLib::FrgBase_PrptsVrntDouble* sideSlope) { theSideSlope_ = sideSlope; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetFlare() const { return theFlare_; }
	void SetFlare(ForgBaseLib::FrgBase_PrptsVrntDouble* flare) { theFlare_ = flare; }

private:

	std::shared_ptr<tnbLib::LegModel_DispNo1> theModel_;
	tnbLib::LegModel_DispNo1_SectionParamsBase* theModelSection_;

	ForgBaseLib::FrgBase_PrptsVrntDouble* theTightness_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theDeadrise_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theSideSlope_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theFlare_ = NullPtr;

	FrgMarine_ShipT01Params_TItem* theParametersTItem_ = NullPtr;

private slots:

	void TightnessValueChangedSlot();
	void DeadriseValueChangedSlot();
	void SideSlopeValueChangedSlot();
	void FlareValueChangedSlot();

	void PerformToPreview();
};

EndForgMarineLib

#endif // !_FrgMarine_ShipT01ParamsHullSection_TItem_Header
