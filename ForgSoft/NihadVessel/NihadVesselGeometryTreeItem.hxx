#pragma once
#ifndef _NihadVesselGeometryTreeItem_Header
#define _NihadVesselGeometryTreeItem_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseCADGeometry.hxx>

namespace AutLib
{
	class Leg_Model_Entity;
}

class TopoDS_Shape;

BeginFrgBaseLib

class NihadVesselScenePreviewTreeItem;

typedef AutLib::Leg_Model_Entity ModelEntity;

class NihadVesselGeometryTreeItem : public FrgBaseCADGeometry<ModelEntity>
{

private:

	NihadVesselScenePreviewTreeItem* thePointerToPreview_ = FrgNullPtr;

public:

	NihadVesselGeometryTreeItem
	(
		const FrgString& title,
		FrgBaseTreeItem* parent
	);

	NihadVesselGeometryTreeItem
	(
		const FrgString& title,
		FrgBaseTree* parentTree
	);

	~NihadVesselGeometryTreeItem();

	const TopoDS_Shape& GetTopoDS_Shape();

	FrgGetMacro(NihadVesselScenePreviewTreeItem*, PointerToPreview, thePointerToPreview_);
};

EndFrgBaseLib

#endif // !_NihadVesselGeometryTreeItem_Header
