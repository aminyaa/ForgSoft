#pragma once
#ifndef _NihadVesselPartTreeItem_Header
#define _NihadVesselPartTreeItem_Header

#include <FrgBaseGlobals.hxx>
//#include <FrgBaseTreeItem.hxx>
#include <FrgBaseCADPart.hxx>

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

	virtual void DoAfterConstruct() override;

};

/*class NihadPartSurfacesEntity;
class NihadPartCurvesEntity;

//class NihadVesselGeometryTreeItem;

class NihadVesselPartTreeItem : public FrgBaseTreeItem
{

private:

	FrgSharedPtr<AutLib::Cad3d_TModel> theTModel_ = FrgNullPtr;

	NihadPartSurfacesEntity* theSurfaces_ = FrgNullPtr;
	NihadPartCurvesEntity* theCurves_ = FrgNullPtr;

public:

	NihadVesselPartTreeItem
	(
		const FrgString& title,
		FrgBaseTreeItem* parent = FrgNullPtr,
		FrgBaseTree* parentTree = FrgNullPtr,
		FrgBaseMainWindow* parentMainwindow = FrgNullPtr,
		FrgSharedPtr<AutLib::Cad3d_TModel> TModel = FrgNullPtr
	);

	FrgGetMacro(FrgSharedPtr<AutLib::Cad3d_TModel>, TModel, theTModel_);

	FrgGetMacro(NihadPartSurfacesEntity*, Surfaces, theSurfaces_);
	FrgGetMacro(NihadPartCurvesEntity*, Curves, theCurves_);
};*/

EndFrgBaseLib

#endif // !_NihadVesselPartTreeItem_Header
