#pragma once
#ifndef _NihadVesselGeometryTreeItem_Header
#define _NihadVesselGeometryTreeItem_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTreeItem.hxx>

namespace AutLib
{
	class Leg_Nihad2_HullPatch;
}

class TopoDS_Shape;

BeginFrgBaseLib

class NihadVesselGeometryTreeItem : public QObject, public FrgBaseTreeItem
{

	Q_OBJECT

private:

	FrgSharedPtr<AutLib::Leg_Nihad2_HullPatch> thePatch_ = FrgNullPtr;

public:

	NihadVesselGeometryTreeItem
	(
		const FrgString& title,
		FrgBaseTreeItem* parent = FrgNullPtr,
		FrgBaseTree* parentTree = FrgNullPtr,
		FrgBaseMainWindow* parentMainwindow = FrgNullPtr
	);

	FrgGetMacro(FrgSharedPtr<AutLib::Leg_Nihad2_HullPatch>, Patch, thePatch_);

	const TopoDS_Shape& GetTopoDS_Shape();

};

EndFrgBaseLib

#endif // !_NihadVesselGeometryTreeItem_Header
