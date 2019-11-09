#pragma once
#ifndef _NihadPartCurveEntity_Header
#define _NihadPartCurveEntity_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTreeItem.hxx>

namespace AutLib
{
	class TModel_Paired;
}

BeginFrgBaseLib

class NihadPartSurfaceEntity : public FrgBaseTreeItem
{

private:

	FrgSharedPtr<AutLib::TModel_Paired> theTModelCurve_ = FrgNullPtr;

public:

	NihadPartSurfaceEntity
	(
		const FrgString& itemName,
		FrgBaseTreeItem* parentItem = FrgNullPtr,
		FrgBaseTree* parentTree = FrgNullPtr,
		FrgBaseMainWindow* parentMainWindow = FrgNullPtr
	);

	FrgGetMacro(FrgSharedPtr<AutLib::TModel_Paired>, TModelCurve, theTModelCurve_);
};

EndFrgBaseLib

#endif // !_NihadPartCurveEntity_Header
