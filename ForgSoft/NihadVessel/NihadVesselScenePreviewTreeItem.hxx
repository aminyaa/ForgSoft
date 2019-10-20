#pragma once
#ifndef _NihadVesselScenePreviewTreeItem_Header
#define _NihadVesselScenePreviewTreeItem_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseSceneTreeItem.hxx>
#include <Entity3d_TriangulationFwd.hxx>

#include <vtkSmartPointer.h>

class vtkActor;

BeginFrgBaseLib

class NihadVesselScenePreviewTreeItem : public FrgBaseSceneTreeItem
{

	Q_OBJECT

private:

	FrgSharedPtr<AutLib::Entity3d_Triangulation> theEntityTriangulation_ = FrgNullPtr;

public:

	NihadVesselScenePreviewTreeItem
	(
		const FrgString& title,
		FrgBaseTreeItem* parent = FrgNullPtr,
		FrgBaseTree* parentTree = FrgNullPtr,
		FrgBaseMainWindow* parentMainwindow = FrgNullPtr
	);

	FrgGetMacro(FrgSharedPtr<AutLib::Entity3d_Triangulation>, EntityTriangulation, theEntityTriangulation_);

public slots:

	void RenderSceneSlot();

private:

	void AddActorToTheRenderer(vtkSmartPointer<vtkActor> actor);

	void CreateActor();
};

EndFrgBaseLib

#endif // !_NihadVesselScenePreviewTreeItem_Header
