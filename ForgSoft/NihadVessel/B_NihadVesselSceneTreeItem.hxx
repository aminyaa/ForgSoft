#pragma once
#ifndef _NihadVesselSceneTreeItem_Header
#define _NihadVesselSceneTreeItem_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseSceneTreeItem.hxx>

class QPushButton;

BeginFrgBaseLib

struct NihadVesselPartTreeItem;

class NihadVesselSceneTreeItem : public FrgBaseSceneTreeItem
{

	Q_OBJECT

private:

	QList<FrgSharedPtr<NihadVesselPartTreeItem>> thePartsPointer_;

public:

	NihadVesselSceneTreeItem
	(
		const FrgString& title,
		FrgBaseTreeItem* parent = FrgNullPtr,
		FrgBaseTree* parentTree = FrgNullPtr,
		FrgBaseMainWindow* parentMainwindow = FrgNullPtr
	);

	FrgGetMacro(QList<FrgSharedPtr<NihadVesselPartTreeItem>>, PartsPointer, thePartsPointer_);

public slots:

	void RenderSceneSlot();

private:

	void AddActorToTheRenderer(vtkSmartPointer<vtkActor> actor);

	void CreateActor();
	void CreateActor2();
};

EndFrgBaseLib

#endif // !_NihadVesselSceneTreeItem_Header
