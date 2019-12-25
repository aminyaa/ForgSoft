#pragma once
#ifndef _CADScene_Header
#define _CADScene_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseCADScene.hxx>

namespace AutLib
{
	template <class T>
	class Cad_BlockEntity;

	class TModel_Surface;
	class TModel_Paired;
}

BeginFrgBaseLib

class FrgBaseTree;
//class NihadVesselPartTreeItem;
class FrgBaseCADPart_Entity;
class FrgBase_CADScene_TreeItem;

template<class Entity>
class FrgBaseCADPartFeatureEntity;

class CADScene : public FrgBaseCADScene
{

	Q_OBJECT

public:

	CADScene(FrgBase_CADScene_TreeItem* parentCADSceneTreeItem, FrgBaseTree* parentTree);

	//void DoAfterConstruct() override;

public slots:

	//void RenderSceneSlot();
	virtual void ExportSelectedPartClickedSlot(bool) override;

public:

	void AddActorToTheRenderer(vtkSmartPointer<vtkActor> actor);

	void CreateActor(FrgBaseCADPart_Entity* part);

	void CreateActor(std::shared_ptr<AutLib::TModel_Surface> surface, FrgBaseCADPartFeatureEntity<AutLib::TModel_Surface>* item);
	void CreateActor(std::shared_ptr<AutLib::TModel_Paired> curve, FrgBaseCADPartFeatureEntity<AutLib::TModel_Paired>* item);

	void ClearScene();

};

EndFrgBaseLib

#endif // !_CADScene_Header
