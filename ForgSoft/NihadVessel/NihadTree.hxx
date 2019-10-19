#pragma once
#ifndef _NihadTree_Header
#define _NihadTree_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTree.hxx>

class QVariant;
class QtProperty;

namespace AutLib
{
	class Leg_Nihad2_HullPatch;
}

BeginFrgBaseLib

class FrgBaseMenu;
class NihadVesselSceneTreeItem;

struct NihadGeometryTreeItemStruct
{
	FrgBaseTreeItem* theTreeItem_ = FrgNullPtr;
	AutLib::Leg_Nihad2_HullPatch* thePatch_ = FrgNullPtr;
};

struct NihadPartTreeItemStruct
{
	FrgBaseTreeItem* theTreeItem_ = FrgNullPtr;
	NihadGeometryTreeItemStruct* theGeometryPointer_ = FrgNullPtr;
};

struct NihadSceneTreeItemStruct
{
	NihadVesselSceneTreeItem* theTreeItem_ = FrgNullPtr;
	NihadPartTreeItemStruct* thePartPointer_ = FrgNullPtr;
};

class NihadTree : public FrgBaseTree
{

	Q_OBJECT

private:

	QList<NihadGeometryTreeItemStruct*> theNihadGeometryTreeItems_;
	QList<NihadPartTreeItemStruct*> theNihadPartTreeItems_;
	QList<NihadSceneTreeItemStruct*> theNihadSceneTreeItems_;

public:

	NihadTree(FrgBaseMainWindow* parent = FrgNullPtr);

	void FormTree() override;

	FrgGetMacro(QList<NihadGeometryTreeItemStruct*>, NihadGeometryTreeItems, theNihadGeometryTreeItems_);

	NihadGeometryTreeItemStruct* GetGeometryTreeItem(FrgBaseTreeItem* item);
	NihadPartTreeItemStruct* GetPartTreeItem(FrgBaseTreeItem* item);

public slots:

	void NewGeometryClickedSlot(bool b);

	void NewSceneClickedSlot(bool b);

	void GeometryPropertyValueChangedSlot(QtProperty* property, const QVariant& value);

	void CreatePartFromGeometryClickedSlot(bool b);

	void ExportPartSlot(bool b);

	void ObjectsSelectedUpdateInSceneSlot(QList<QTreeWidgetItem*>);

private:

	void AddItemToTree(FrgBaseTreeItem* item);

	void UpdateTree();

};

EndFrgBaseLib

#endif // !_NihadTree_Header
