#pragma once
#ifndef _NihadVesselScenePreviewTreeItem_Header
#define _NihadVesselScenePreviewTreeItem_Header

#include <FrgBaseGlobals.hxx>
#include <NihadVesselScenePartTreeItem.hxx>
#include <Entity3d_TriangulationFwd.hxx>

#include <vtkSmartPointer.h>

class vtkActor;

BeginFrgBaseLib

class NihadVesselScenePreviewTreeItem : public NihadVesselScenePartTreeItem
{

	Q_OBJECT

private:

	FrgVector<FrgSharedPtr<AutLib::Entity3d_Triangulation>> theEntitiesTriangulation_;

	QList<vtkSmartPointer<vtkActor>> thePreviewActors_;

public:

	NihadVesselScenePreviewTreeItem
	(
		const FrgString& title,
		FrgBaseTreeItem* parent = FrgNullPtr,
		FrgBaseTree* parentTree = FrgNullPtr,
		FrgBaseMainWindow* parentMainwindow = FrgNullPtr
	);

	FrgGetMacro(FrgVector<FrgSharedPtr<AutLib::Entity3d_Triangulation>>, EntitiesTriangulation, theEntitiesTriangulation_);

public slots:

	void RenderSceneSlot();

private:

	void AddActorToTheRenderer(vtkSmartPointer<vtkActor> actor);

	void CreateActor();
};

EndFrgBaseLib

#endif // !_NihadVesselScenePreviewTreeItem_Header
