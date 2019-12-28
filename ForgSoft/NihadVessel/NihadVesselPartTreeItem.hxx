#pragma once
#ifndef _NihadVesselPartTreeItem_Header
#define _NihadVesselPartTreeItem_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseCADPart.hxx>
#include <FrgBaseTree.hxx>

namespace AutLib
{
	class Cad3d_TModel;
	class TModel_Surface;
	class TModel_Paired;
}

BeginFrgBaseLib

class NihadVesselPartTreeItem : public FrgBaseCADPart<AutLib::TModel_Surface, AutLib::TModel_Paired>
{

private:

	FrgSharedPtr<AutLib::Cad3d_TModel> theModel_ = FrgNullPtr;

	FrgBool theIsTriangulated_ = FrgFalse;

public:

	NihadVesselPartTreeItem
	(
		const FrgString& title,
		FrgBaseTreeItem* parent,
		FrgSharedPtr<AutLib::Cad3d_TModel> model
	);

	NihadVesselPartTreeItem
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

#endif // !_NihadVesselPartTreeItem_Header
