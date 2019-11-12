#pragma once
#ifndef _FrgBaseCADGeometry_Header
#define _FrgBaseCADGeometry_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTreeItem.hxx>

BeginFrgBaseLib

template<class Entity>
class FrgBaseCADGeometry : public FrgBaseTreeItem
{

private:

	FrgSharedPtr<Entity> theEntity_ = FrgNullPtr;

public:

	FrgBaseCADGeometry
		(
			const FrgString& title,
			FrgBaseTreeItem* parent
		);

	FrgBaseCADGeometry
	(
		const FrgString& title,
		FrgBaseTree* parentTree
	);

	FrgGetMacro(FrgSharedPtr<Entity>, Entity, theEntity_);
};

EndFrgBaseLib

#include <FrgBaseCADGeometryI.hxx>

#endif // !_FrgBaseCADGeometry_Header
