#pragma once
#ifndef _CADPartItem_Header
#define _CADPartItem_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseCADPart.hxx>
//#include <TModel_EntityManager.hxx>

namespace AutLib
{
	//class TModel_EntityManager;
	class Cad3d_TModel;
}

BeginFrgBaseLib

class FrgBaseTree;

template<class SurfaceEntity, class CurveEntity>
class CADPartItem : public FrgBaseCADPart<SurfaceEntity, CurveEntity>
{


private:

	FrgSharedPtr<AutLib::Cad3d_TModel> theModel_ = FrgNullPtr;

	FrgBool theIsTriangulated_ = FrgFalse;

public:

	CADPartItem
	(
		const FrgString& title,
		FrgBaseTreeItem* parent,
		FrgSharedPtr<AutLib::Cad3d_TModel> model
	);

	CADPartItem
	(
		const FrgString& title,
		FrgBaseTree* parentTree,
		FrgSharedPtr<AutLib::Cad3d_TModel> model
	);

	FrgGetMacro(FrgSharedPtr<AutLib::Cad3d_TModel>, Model, theModel_);
	FrgGetMacro(FrgBool, IsTriangulated, theIsTriangulated_);

	virtual void DoAfterConstruct() override;

};

EndFrgBaseLib

#include <CADPartItemI.hxx>

#endif // !_CADPartItem_Header
