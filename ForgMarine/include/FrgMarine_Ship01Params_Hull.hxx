#pragma once
#ifndef _FrgMarine_Ship01Params_Hull_Header
#define _FrgMarine_Ship01Params_Hull_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_PrptsVrntDouble.hxx>

namespace tnbLib
{
	class LegModel_DispNo1;
}

BeginForgMarineLib

class FrgMarine_Ship01ParamsHull_Section;

class FORGMARINE_EXPORT FrgMarine_Ship01Params_Hull
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* MaxAreaLocation READ GetMaxAreaLocation WRITE SetMaxAreaLocation)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* FwdFullness READ GetFwdFullness WRITE SetFwdFullness)
		Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* AftFullness READ GetAftFullness WRITE SetAftFullness)

public:

	FrgMarine_Ship01Params_Hull
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree,
		std::shared_ptr<tnbLib::LegModel_DispNo1> model
	);

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetMaxAreaLocation() const { return theMaxAreaLocation_; }
	void SetMaxAreaLocation(ForgBaseLib::FrgBase_PrptsVrntDouble* maxAreaLocation) { theMaxAreaLocation_ = maxAreaLocation; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetFwdFullness() const { return theFwdFullness_; }
	void SetFwdFullness(ForgBaseLib::FrgBase_PrptsVrntDouble* fwdFullness) { theFwdFullness_ = fwdFullness; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetAftFullness() const { return theAftFullness_; }
	void SetAftFullness(ForgBaseLib::FrgBase_PrptsVrntDouble* aftFullness) { theAftFullness_ = aftFullness; }

private:

	std::shared_ptr<tnbLib::LegModel_DispNo1> theModel_;

	FrgMarine_Ship01ParamsHull_Section* theAftSection_ = NullPtr;
	FrgMarine_Ship01ParamsHull_Section* theMidSection_ = NullPtr;
	FrgMarine_Ship01ParamsHull_Section* theFwdSection_ = NullPtr;

	ForgBaseLib::FrgBase_PrptsVrntDouble* theMaxAreaLocation_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theFwdFullness_ = NullPtr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theAftFullness_ = NullPtr;

private slots:

	void MaxAreaLocationValueChangedSlot();
	void FwdFullnessValueChangedSlot();
	void AftFullnessValueChangedSlot();

	void PerformToPreview();
};

EndForgMarineLib

#endif // !_FrgMarine_Ship01Params_Hull_Header
