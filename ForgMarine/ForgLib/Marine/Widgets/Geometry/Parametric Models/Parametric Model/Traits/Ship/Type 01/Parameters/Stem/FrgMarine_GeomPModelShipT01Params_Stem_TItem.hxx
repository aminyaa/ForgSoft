#pragma once
#ifndef _FrgMarine_Ship01Params_Stem_Header
#define _FrgMarine_Ship01Params_Stem_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_PrptsVrntDouble.hxx>

namespace tnbLib
{
	class LegModel_DispNo1;
}

BeginForgMarineLib

class FrgMarine_GeomPModelShipT01Params_TItem;

class FORGMARINE_EXPORT FrgMarine_GeomPModelShipT01Params_Stem_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* BowRounding READ GetBowRounding WRITE SetBowRounding)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* StemRake READ GetStemRake WRITE SetStemRake)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* ForeFootShape READ GetForeFootShape WRITE SetForeFootShape)

public:

	FrgMarine_GeomPModelShipT01Params_Stem_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree,
		std::shared_ptr<tnbLib::LegModel_DispNo1> model,
		FrgMarine_GeomPModelShipT01Params_TItem* parametersTItem
	);

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetBowRounding() const { return theBowRounding_; }
	void SetBowRounding(ForgBaseLib::FrgBase_PrptsVrntDouble* bowRounding) { theBowRounding_ = bowRounding; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetStemRake() const { return theStemRake_; }
	void SetStemRake(ForgBaseLib::FrgBase_PrptsVrntDouble* stemRake) { theStemRake_ = stemRake; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetForeFootShape() const { return theForeFootShape_; }
	void SetForeFootShape(ForgBaseLib::FrgBase_PrptsVrntDouble* foreFootShape) { theForeFootShape_ = foreFootShape; }

private:

	std::shared_ptr<tnbLib::LegModel_DispNo1> theModel;

	ForgBaseLib::FrgBase_PrptsVrntDouble* theBowRounding_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theStemRake_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theForeFootShape_ = NullPtr;

	FrgMarine_GeomPModelShipT01Params_TItem* theParametersTItem_ = NullPtr;

private slots:

	void BowRoundingValueChangedSlot();
	void StemRakeValueChangedSlot();
	void ForeFootShapeValueChangedSlot();

	void PerformToPreview();
};

EndForgMarineLib

#endif // !_FrgMarine_Ship01Params_Stem_Header
