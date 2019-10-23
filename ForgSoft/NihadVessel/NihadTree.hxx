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
class NihadVesselGeometryTreeItem;
class NihadVesselPartTreeItem;
class FrgBaseSceneTreeItem;
class FrgBasePlot2D;

//struct NihadGeometryTreeItemStruct
//{
//	FrgBaseTreeItem* theTreeItem_ = FrgNullPtr;
//	AutLib::Leg_Nihad2_HullPatch* thePatch_ = FrgNullPtr;
//};

//struct NihadPartTreeItemStruct
//{
//	FrgBaseTreeItem* theTreeItem_ = FrgNullPtr;
//	NihadVesselGeometryTreeItem* theGeometryPointer_ = FrgNullPtr;
//};

//struct NihadSceneTreeItemStruct
//{
//	NihadVesselSceneTreeItem* theTreeItem_ = FrgNullPtr;
//	NihadVesselPartTreeItem* thePartPointer_ = FrgNullPtr;
//};

class NihadTree : public FrgBaseTree
{

	Q_OBJECT

private:

	QList<FrgSharedPtr<NihadVesselGeometryTreeItem>> theGeometryTreeItems_;
	QList<FrgSharedPtr<NihadVesselPartTreeItem>> thePartTreeItems_;
	QList<FrgSharedPtr<FrgBaseSceneTreeItem>> theSceneTreeItems_;
	QList<FrgSharedPtr<FrgBasePlot2D>> thePlotsItems_;

public:

	NihadTree(FrgBaseMainWindow* parent = FrgNullPtr);

	void FormTree() override;

	FrgGetMacro(QList<FrgSharedPtr<NihadVesselGeometryTreeItem>>, GeometryTreeItems, theGeometryTreeItems_);
	FrgGetMacro(QList<FrgSharedPtr<NihadVesselPartTreeItem>>, PartTreeItems, thePartTreeItems_);

	FrgSharedPtr<NihadVesselGeometryTreeItem> GetGeometryTreeItem(FrgSharedPtr<FrgBaseTreeItem> item);
	FrgSharedPtr<NihadVesselPartTreeItem> GetPartTreeItem(FrgSharedPtr<FrgBaseTreeItem> item);

public slots:

	void NewGeometryClickedSlot(bool b);

	void NewSceneClickedSlot(bool b);

	void GeometryPropertyValueChangedSlot(QtProperty* property, const QVariant& value);

	void CreatePartFromGeometryClickedSlot(bool b);

	void ExportPartSlot(bool b);

	void ObjectsSelectedUpdateInSceneSlot(QList<QTreeWidgetItem*>);

	void PreviewGeometryClickedSlot(bool);

	void NewPlotClickedSlot(bool);

	void TabBarClickedSlot(int index);

private:

	//void AddItemToTree(FrgBaseTreeItem* item);

	void UpdateTree();

};

EndFrgBaseLib

#endif // !_NihadTree_Header
