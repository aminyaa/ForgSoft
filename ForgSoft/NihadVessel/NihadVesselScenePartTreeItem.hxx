#pragma once
#ifndef _NihadVesselScenePartTreeItem_Header
#define _NihadVesselScenePartTreeItem_Header

#include <FrgBaseGlobals.hxx>
//#include <FrgBaseSceneTreeItem.hxx>
#include <FrgBaseCADScene.hxx>
#include <FrgBaseCADPartFeatures.hxx>

namespace AutLib
{
	class TModel_Entity;
}

BeginFrgBaseLib

class NihadVesselPartTreeItem;
//class NihadPartFeature;
//typedef QMap<vtkSmartPointer<vtkActor>, NihadPartFeature*> QMapActorToPartFeature;
//typedef QMap<NihadPartFeature*, vtkSmartPointer<vtkActor>> QMapPartFeatureToActor;

typedef QMap<vtkSmartPointer<vtkActor>, FrgBaseCADPartFeatureEntity<AutLib::TModel_Entity>*> QMapActorToPartFeature;
typedef QMap<FrgBaseCADPartFeatureEntity<AutLib::TModel_Entity>*, vtkSmartPointer<vtkActor>> QMapPartFeatureToActor;

class NihadVesselScenePartTreeItem : public FrgBaseCADScene
{

	Q_OBJECT

private:

	QList<NihadVesselPartTreeItem*> thePartsPointer_;

	FrgBool theDiscreteParametersBool_;

	//QMap<vtkSmartPointer<vtkActor>, NihadPartFeature*> theActorToPartFeature_;
	//QMap<NihadPartFeature*, vtkSmartPointer<vtkActor>> thePartFeatureToActor_;
	QMap<vtkSmartPointer<vtkActor>, FrgBaseCADPartFeatureEntity<AutLib::TModel_Entity>*> theActorToPartFeature_;
	QMap<FrgBaseCADPartFeatureEntity<AutLib::TModel_Entity>*, vtkSmartPointer<vtkActor>> thePartFeatureToActor_;

public:

	NihadVesselScenePartTreeItem
	(
		const FrgString& title,
		FrgBaseTreeItem* parent,
		FrgBool discreteParameters = FrgTrue
	);
	
	FrgGetMacro(QList<NihadVesselPartTreeItem*>, PartsPointer, thePartsPointer_);
	FrgGetMacro(QMapActorToPartFeature, ActorToPartFeature, theActorToPartFeature_);
	FrgGetMacro(QMapPartFeatureToActor, PartFeatureToActor, thePartFeatureToActor_);

	void DoAfterConstruct() override;

public slots:

	void RenderSceneSlot();

private:

	void AddActorToTheRenderer(vtkSmartPointer<vtkActor> actor);

	void CreateActor();
};

EndFrgBaseLib

#endif // !_NihadVesselScenePartTreeItem_Header
