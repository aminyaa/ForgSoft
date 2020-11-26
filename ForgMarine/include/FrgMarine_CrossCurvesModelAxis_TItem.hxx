#pragma once
#ifndef _FrgMarine_CrossCurvesModelAxis_TItem_Header
#define _FrgMarine_CrossCurvesModelAxis_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_PrptsVrntCombo.hxx>
#include <FrgBase_PrptsVrntPnt3d.hxx>

#include <Entity3d_BoxFwd.hxx>
#include <gp_Ax2.hxx>

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_CrossCurvesModelAxis_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntCombo* Plane READ GetPlane WRITE SetPlane)
	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntPnt3d* Location READ GetLocation WRITE SetLocation)

public:
	
	FrgMarine_CrossCurvesModelAxis_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree,
		tnbLib::Entity3d_Box* box
	);

	~FrgMarine_CrossCurvesModelAxis_TItem();

	ForgBaseLib::FrgBase_PrptsVrntCombo* GetPlane() const { return thePlane_; }
	void SetPlane(ForgBaseLib::FrgBase_PrptsVrntCombo* plane) { thePlane_ = plane; }

	ForgBaseLib::FrgBase_PrptsVrntPnt3d* GetLocation() const { return theLocation_; }
	void SetLocation(ForgBaseLib::FrgBase_PrptsVrntPnt3d* location) { theLocation_ = location; }

	const gp_Ax2& GetAxis() const { return theAxis_; }

private:

	gp_Ax2 theAxis_;

	ForgBaseLib::FrgBase_PrptsVrntCombo* thePlane_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntPnt3d* theLocation_ = nullptr;

	tnbLib::Entity3d_Box* theBox_ = nullptr;
};

EndForgMarineLib

#endif // !_FrgMarine_CrossCurvesModelAxis_TItem_Header
