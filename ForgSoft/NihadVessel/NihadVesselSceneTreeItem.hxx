#pragma once
#ifndef _NihadVesselSceneTreeItem_Header
#define _NihadVesselSceneTreeItem_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseSceneTreeItem.hxx>

class QPushButton;

BeginFrgBaseLib

struct NihadPartTreeItemStruct;

class NihadVesselSceneTreeItem : public FrgBaseSceneTreeItem
{

	Q_OBJECT

private:

	QList<NihadPartTreeItemStruct*> thePartsPointer_;

	QPushButton* theOKButton_ = FrgNullPtr;

public:

	NihadVesselSceneTreeItem(const FrgString& title, FrgBaseTreeItem* parent = FrgNullPtr, FrgBaseTree* parentTree = FrgNullPtr, FrgBaseMainWindow* parentMainwindow = FrgNullPtr);

	FrgGetMacro(QList<NihadPartTreeItemStruct*>, PartsPointer, thePartsPointer_);

	FrgGetMacro(QPushButton*, OKButton, theOKButton_);

public slots:

	void RenderSceneSlot();

private:

	void AddActorToTheRenderer(vtkSmartPointer<vtkActor> actor);

	void CreateActor();
	void CreateActor2();
};

EndFrgBaseLib

#endif // !_NihadVesselSceneTreeItem_Header
