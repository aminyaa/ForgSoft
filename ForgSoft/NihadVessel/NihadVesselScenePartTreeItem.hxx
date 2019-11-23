#pragma once
#ifndef _NihadVesselScenePartTreeItem_Header
#define _NihadVesselScenePartTreeItem_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseCADScene.hxx>
#include <FrgBaseCADPartFeatures.hxx>

BeginFrgBaseLib

class NihadVesselPartTreeItem;

class NihadVesselScenePartTreeItem : public FrgBaseCADScene
{

	Q_OBJECT

private:

	QList<NihadVesselPartTreeItem*> thePartsPointer_;

	FrgBool theDiscreteParametersBool_;

public:

	NihadVesselScenePartTreeItem
	(
		const FrgString& title,
		FrgBaseTreeItem* parent,
		FrgBool discreteParameters = FrgTrue
	);
	
	FrgGetMacro(QList<NihadVesselPartTreeItem*>, PartsPointer, thePartsPointer_);

	void DoAfterConstruct() override;

public slots:

	void RenderSceneSlot();

private:

	void AddActorToTheRenderer(vtkSmartPointer<vtkActor> actor);

	void CreateActor();
};

EndFrgBaseLib

#endif // !_NihadVesselScenePartTreeItem_Header
