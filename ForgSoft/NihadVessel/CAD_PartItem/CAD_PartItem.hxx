#pragma once
#ifndef _CAD_PartItem_Header
#define _CAD_PartItem_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseCAD_Part.hxx>

namespace AutLib
{
	class Cad3d_TModel;
}

BeginFrgBaseLib

template<class SurfaceEntity, class CurveEntity>
class CAD_PartItem
	: public FrgBaseCAD_Part<SurfaceEntity, CurveEntity>
{

private:

	FrgSharedPtr<AutLib::Cad3d_TModel> theModel_ = FrgNullPtr;
	FrgBool theIsTriangulated_ = FrgFalse;

public:

	CAD_PartItem
	(
		const FrgString& title,
		FrgBaseTreeItem* parent,
		FrgSharedPtr<AutLib::Cad3d_TModel> model
	);

	CAD_PartItem
	(
		const FrgString& title,
		FrgBaseTree* parentTree,
		FrgSharedPtr<AutLib::Cad3d_TModel> model
	);

	FrgGetMacro(FrgSharedPtr<AutLib::Cad3d_TModel>, Model, theModel_);
	FrgGetMacro(FrgBool, IsTriangulated, theIsTriangulated_);

	void DoAfterConstruct() override;
};

EndFrgBaseLib

#include <CAD_PartItemI.hxx>

#endif // !_CAD_PartItem_Header
