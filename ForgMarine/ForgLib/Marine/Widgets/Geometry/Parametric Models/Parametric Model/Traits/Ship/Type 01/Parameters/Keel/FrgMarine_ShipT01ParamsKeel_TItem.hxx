#pragma once
#ifndef _FrgMarine_ShipT01ParamsKeel_TItem_Header
#define _FrgMarine_ShipT01ParamsKeel_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_PrptsVrntDouble.hxx>

namespace tnbLib
{
	class LegModel_DispNo1;
}

BeginForgMarineLib

class FrgMarine_ShipT01Params_TItem;

class FORGMARINE_EXPORT FrgMarine_ShipT01ParamsKeel_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* Position READ GetPosition WRITE SetPosition)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* RisePoint READ GetRisePoint WRITE SetRisePoint)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* RiseSlope READ GetRiseSlope WRITE SetRiseSlope)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* TransomSlope READ GetTransomSlope WRITE SetTransomSlope)

public:

	FrgMarine_ShipT01ParamsKeel_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree,
		std::shared_ptr<tnbLib::LegModel_DispNo1> model,
		FrgMarine_ShipT01Params_TItem* parametersTItem
	);

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetPosition() const { return thePosition_; }
	void SetPosition(ForgBaseLib::FrgBase_PrptsVrntDouble* position) { thePosition_ = position; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetRisePoint() const { return theRisePoint_; }
	void SetRisePoint(ForgBaseLib::FrgBase_PrptsVrntDouble* risePoint) { theRisePoint_ = risePoint; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetRiseSlope() const { return theRiseSlope_; }
	void SetRiseSlope(ForgBaseLib::FrgBase_PrptsVrntDouble* riseSlope) { theRiseSlope_ = riseSlope; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetTransomSlope() const { return theTransomSlope_; }
	void SetTransomSlope(ForgBaseLib::FrgBase_PrptsVrntDouble* transomSlope) { theTransomSlope_ = transomSlope; }

private:

	std::shared_ptr<tnbLib::LegModel_DispNo1> theModel_;

	ForgBaseLib::FrgBase_PrptsVrntDouble* thePosition_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theRisePoint_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theRiseSlope_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theTransomSlope_ = NullPtr;

	FrgMarine_ShipT01Params_TItem* theParametersTItem_ = NullPtr;

private slots:

	void PositionValueChangedSlot();
	void RisePointValueChangedSlot();
	void RiseSlopeValueChangedSlot();
	void TransomSlopeValueChangedSlot();

	void PerformToPreview();
};

EndForgMarineLib

#endif // !_FrgMarine_ShipT01ParamsKeel_TItem_Header
