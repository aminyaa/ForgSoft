#pragma once
#ifndef _NihadPartSurfaceEntity_Header
#define _NihadPartSurfaceEntity_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTreeItem.hxx>
#include <NihadPartFeature.hxx>

namespace AutLib
{
	class TModel_Surface;
}

BeginFrgBaseLib

class NihadVesselScenePartTreeItem;

class NihadPartSurfaceEntity : public NihadPartFeature, public FrgBaseTreeItem
{

	Q_OBJECT

private:

	FrgSharedPtr<AutLib::TModel_Surface> theTModelSurface_;

	NihadVesselScenePartTreeItem* thePointerToScene_ = FrgNullPtr;

public:

	NihadPartSurfaceEntity
	(
		const FrgString& itemName,
		FrgBaseTreeItem* parentItem = FrgNullPtr,
		FrgBaseTree* parentTree = FrgNullPtr,
		FrgBaseMainWindow* parentMainWindow = FrgNullPtr
	);

	FrgGetMacro(FrgSharedPtr<AutLib::TModel_Surface>, TModelSurface, theTModelSurface_);
	FrgGetMacro(NihadVesselScenePartTreeItem*, PointerToScene, thePointerToScene_);
};

class NihadPartSurfacesEntity : public FrgBaseTreeItem
{

private:

	QList<NihadPartSurfaceEntity*> theSurfaces_;

public:

	NihadPartSurfacesEntity
	(
		const FrgString& itemName,
		FrgBaseTreeItem* parentItem = FrgNullPtr,
		FrgBaseTree* parentTree = FrgNullPtr,
		FrgBaseMainWindow* parentMainWindow = FrgNullPtr
	);

	FrgGetMacro(QList<NihadPartSurfaceEntity*>, SurfacesEntity, theSurfaces_);
};

EndFrgBaseLib

#endif // !_NihadPartSurfaceEntity_Header
