#pragma once
#ifndef _NihadVesselSceneTreeItem_Header
#define _NihadVesselSceneTreeItem_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseSceneTreeItem.hxx>

BeginFrgBaseLib

class NihadVesselSceneTreeItem : public FrgBaseSceneTreeItem
{

public:

	NihadVesselSceneTreeItem(const FrgString& title, FrgBaseTreeItem* parent = FrgNullPtr, FrgBaseTree* parentTree = FrgNullPtr, FrgBaseMainWindow* parentMainwindow = FrgNullPtr);

	void StartScene() override;
};

EndFrgBaseLib

#endif // !_NihadVesselSceneTreeItem_Header
