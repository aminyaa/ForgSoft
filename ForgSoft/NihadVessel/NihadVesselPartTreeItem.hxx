#pragma once
#ifndef _NihadVesselPartTreeItem_Header
#define _NihadVesselPartTreeItem_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTreeItem.hxx>

namespace AutLib
{
	class Cad3d_TModel;
}

BeginFrgBaseLib

class NihadPartSurfacesEntity;
class NihadPartCurvesEntity;

//class NihadVesselGeometryTreeItem;

class NihadVesselPartTreeItem : public QObject, public FrgBaseTreeItem
{

	Q_OBJECT

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
};

EndFrgBaseLib

#endif // !_NihadVesselPartTreeItem_Header
