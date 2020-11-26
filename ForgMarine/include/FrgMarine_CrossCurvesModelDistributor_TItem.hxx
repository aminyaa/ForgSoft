#pragma once
#ifndef _FrgMarine_CrossCurvesModelDistributor_TItem_Header
#define _FrgMarine_CrossCurvesModelDistributor_TItem_Header

#include <FrgBase_PrptsVrntCombo.hxx>
#include <FrgBase_PrptsVrntDouble.hxx>
#include <FrgBase_PrptsVrntInt.hxx>

#include <Entity3d_BoxFwd.hxx>

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

namespace tnbLib
{
	class Marine_SectionDistribution;
}

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_CrossCurvesModelDistributor_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntCombo* DistributorVrnt READ GetDistributorVrnt WRITE SetDistributorVrnt)
	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* Lower READ GetLower WRITE SetLower)
	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* Upper READ GetUpper WRITE SetUpper)
	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntInt* NbSections READ GetNbSections WRITE SetNbSections)

public:

	FrgMarine_CrossCurvesModelDistributor_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree,
		tnbLib::Entity3d_Box* box
	);

	~FrgMarine_CrossCurvesModelDistributor_TItem();

	ForgBaseLib::FrgBase_PrptsVrntCombo* GetDistributorVrnt() const { return theDistributorVrnt_; }
	void SetDistributorVrnt(ForgBaseLib::FrgBase_PrptsVrntCombo* distributorVrnt) { theDistributorVrnt_ = distributorVrnt; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetLower() const { return theLower_; }
	void SetLower(ForgBaseLib::FrgBase_PrptsVrntDouble* lower) { theLower_ = lower; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetUpper() const { return theUpper_; }
	void SetUpper(ForgBaseLib::FrgBase_PrptsVrntDouble* upper) { theUpper_ = upper; }

	ForgBaseLib::FrgBase_PrptsVrntInt* GetNbSections() const { return theNbSections_; }
	void SetNbSections(ForgBaseLib::FrgBase_PrptsVrntInt* nbSections) { theNbSections_ = nbSections; }

	const std::shared_ptr<tnbLib::Marine_SectionDistribution>& GetDistribution() const { return theDistribution_; }

private:

	std::shared_ptr<tnbLib::Marine_SectionDistribution> theDistribution_;

	ForgBaseLib::FrgBase_PrptsVrntCombo* theDistributorVrnt_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theLower_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theUpper_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntInt* theNbSections_ = nullptr;

	tnbLib::Entity3d_Box* theBox_ = nullptr;
};

EndForgMarineLib

#endif // !_FrgMarine_CrossCurvesModelDistributor_TItem_Header
