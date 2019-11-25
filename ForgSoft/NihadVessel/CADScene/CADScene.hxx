#pragma once
#ifndef _CADScene_Header
#define _CADScene_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseCADScene.hxx>

BeginFrgBaseLib

class FrgBaseTree;
class NihadVesselPartTreeItem;

class CADScene : public FrgBaseCADScene
{

public:

	CADScene(FrgBaseTree* parentTree);

	//void DoAfterConstruct() override;

public slots:

	void RenderSceneSlot();

public:

	void AddActorToTheRenderer(vtkSmartPointer<vtkActor> actor);

	void CreateActor(NihadVesselPartTreeItem* part);

	void ClearScene();

};

EndFrgBaseLib

#endif // !_CADScene_Header
