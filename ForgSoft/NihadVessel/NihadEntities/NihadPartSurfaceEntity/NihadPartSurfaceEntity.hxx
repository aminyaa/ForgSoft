#pragma once
#ifndef _NihadPartSurfaceEntity_Header
#define _NihadPartSurfaceEntity_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTreeItem.hxx>

namespace AutLib
{
	class TModel_Surface;
}

BeginFrgBaseLib

class NihadPartSurfaceEntity : public FrgBaseTreeItem
{

private:

	FrgSharedPtr<AutLib::TModel_Surface> theTModelSurface_;

public:

	NihadPartSurfaceEntity
	(
		const FrgString& itemName,
		FrgBaseTreeItem* parentItem = FrgNullPtr,
		FrgBaseTree* parentTree = FrgNullPtr,
		FrgBaseMainWindow* parentMainWindow = FrgNullPtr
	);

	FrgGetMacro(FrgSharedPtr<AutLib::TModel_Surface>, TModelSurface, theTModelSurface_);
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
};

EndFrgBaseLib

#endif // !_NihadPartSurfaceEntity_Header
