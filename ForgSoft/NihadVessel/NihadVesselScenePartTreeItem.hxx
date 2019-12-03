#pragma once
#ifndef _NihadVesselScenePartTreeItem_Header
#define _NihadVesselScenePartTreeItem_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBase_CADScene_TreeItem.hxx>
#include <FrgBaseCADPartFeatures.hxx>

BeginFrgBaseLib

//class NihadVesselPartTreeItem;
class FrgBaseCADPart_Entity;
class ViewPorts;

class NihadVesselScenePartTreeItem : public QObject, public FrgBase_CADScene_TreeItem
{

	Q_OBJECT

private:

	//QList<NihadVesselPartTreeItem*> thePartsPointer_;
	QList<FrgBaseCADPart_Entity*> thePartsPointer_;
	ViewPorts* theViewPorts_ = FrgNullPtr;

	FrgBool theDiscreteParametersBool_;

public:

	NihadVesselScenePartTreeItem
	(
		const FrgString& title,
		FrgBaseTreeItem* parent,
		FrgBool discreteParameters = FrgTrue
	);
	
	//FrgGetMacro(QList<NihadVesselPartTreeItem*>, PartsPointer, thePartsPointer_);
	FrgGetMacro(QList<FrgBaseCADPart_Entity*>, PartsPointer, thePartsPointer_);
	FrgGetMacro(ViewPorts*, ViewPorts, theViewPorts_);

	void DoAfterConstruct() override;

public slots:

	void RenderSceneSlot();

private:

	//void AddActorToTheRenderer(vtkSmartPointer<vtkActor> actor);

	void CreateActor();
};

EndFrgBaseLib

#endif // !_NihadVesselScenePartTreeItem_Header
