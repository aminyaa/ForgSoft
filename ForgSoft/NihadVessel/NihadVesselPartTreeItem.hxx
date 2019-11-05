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

//class NihadVesselGeometryTreeItem;

class NihadVesselPartTreeItem : public QObject, public FrgBaseTreeItem
{

	Q_OBJECT

private:

	//FrgSharedPtr<NihadVesselGeometryTreeItem> theGeometryPointer_ = FrgNullPtr;

	FrgSharedPtr<AutLib::Cad3d_TModel> theTModel_ = FrgNullPtr;

public:

	NihadVesselPartTreeItem
	(
		const FrgString& title,
		FrgBaseTreeItem* parent = FrgNullPtr,
		FrgBaseTree* parentTree = FrgNullPtr,
		FrgBaseMainWindow* parentMainwindow = FrgNullPtr,
		FrgBaseTreeItem* parentGeometry = FrgNullPtr
	);

	//FrgGetMacro(FrgSharedPtr<NihadVesselGeometryTreeItem>, GeometryPointer, theGeometryPointer_);
	FrgGetMacro(FrgSharedPtr<AutLib::Cad3d_TModel>, TModel, theTModel_);
};

EndFrgBaseLib

#endif // !_NihadVesselPartTreeItem_Header
