#pragma once
#ifndef _NihadVesselScenePartTreeItem_Header
#define _NihadVesselScenePartTreeItem_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseSceneTreeItem.hxx>

BeginFrgBaseLib

class NihadVesselPartTreeItem;

class NihadVesselScenePartTreeItem : public FrgBaseSceneTreeItem
{

	Q_OBJECT

private:

	QList<FrgSharedPtr<NihadVesselPartTreeItem>> thePartsPointer_;

public:

	NihadVesselScenePartTreeItem
	(
		const FrgString& title,
		FrgBaseTreeItem* parent = FrgNullPtr,
		FrgBaseTree* parentTree = FrgNullPtr,
		FrgBaseMainWindow* parentMainwindow = FrgNullPtr,
		FrgBool discreteParameters = FrgTrue
	);
	
	FrgGetMacro(QList<FrgSharedPtr<NihadVesselPartTreeItem>>, PartsPointer, thePartsPointer_);

public slots:

	void RenderSceneSlot();

private:

	void AddActorToTheRenderer(vtkSmartPointer<vtkActor> actor);

	void CreateActor();
};

EndFrgBaseLib

#endif // !_NihadVesselScenePartTreeItem_Header
