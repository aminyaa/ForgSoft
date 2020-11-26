#pragma once
#ifndef _FrgMarine_CrossCurvesHeel_TItem_Header
#define _FrgMarine_CrossCurvesHeel_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_PrptsVrntDouble.hxx>
#include <FrgBase_PrptsVrntInt.hxx>

namespace tnbLib
{
	class Geo_xDistb;
}

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_CrossCurvesHeel_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* Degree0 READ GetDegree0 WRITE SetDegree0)
	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* Degree1 READ GetDegree1 WRITE SetDegree1)
	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntInt* NbHeels READ GetNbHeels WRITE SetNbHeels)

public:

	FrgMarine_CrossCurvesHeel_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	~FrgMarine_CrossCurvesHeel_TItem();

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetDegree0() const { return theDegree0_; }
	void SetDegree0(ForgBaseLib::FrgBase_PrptsVrntDouble* degree0) { theDegree0_ = degree0; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetDegree1() const { return theDegree1_; }
	void SetDegree1(ForgBaseLib::FrgBase_PrptsVrntDouble* degree1) { theDegree1_ = degree1; }

	ForgBaseLib::FrgBase_PrptsVrntInt* GetNbHeels() const { return theNbHeels_; }
	void SetNbHeels(ForgBaseLib::FrgBase_PrptsVrntInt* nbHeels) { theNbHeels_ = nbHeels; }

	const std::shared_ptr<tnbLib::Geo_xDistb>& GetHeel() const { return theHeel_; }

private:

	std::shared_ptr<tnbLib::Geo_xDistb> theHeel_;

	ForgBaseLib::FrgBase_PrptsVrntDouble* theDegree0_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theDegree1_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntInt* theNbHeels_ = nullptr;
};

EndForgMarineLib

#endif // !_FrgMarine_CrossCurvesHeel_TItem_Header
