#pragma once
#ifndef _NihadVesselGeometryTreeItem_Header
#define _NihadVesselGeometryTreeItem_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTreeItem.hxx>

namespace AutLib
{
	class Leg_Model_Entity;
}

class TopoDS_Shape;

BeginFrgBaseLib

typedef AutLib::Leg_Model_Entity ModelEntity;

class NihadVesselGeometryTreeItem : public QObject, public FrgBaseTreeItem
{

	Q_OBJECT

private:

	FrgSharedPtr<ModelEntity> theEntity_ = FrgNullPtr;

public:

	NihadVesselGeometryTreeItem
	(
		const FrgString& title,
		FrgBaseTreeItem* parent = FrgNullPtr,
		FrgBaseTree* parentTree = FrgNullPtr,
		FrgBaseMainWindow* parentMainwindow = FrgNullPtr
	);

	FrgGetMacro(FrgSharedPtr<AutLib::Leg_Model_Entity>, Entity, theEntity_);

	const TopoDS_Shape& GetTopoDS_Shape();

};

EndFrgBaseLib

#endif // !_NihadVesselGeometryTreeItem_Header
