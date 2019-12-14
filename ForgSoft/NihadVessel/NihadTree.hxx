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
//class NihadVesselPartTreeItem;
class FrgBaseCADPart_Entity;
class FrgBase_CADScene_TreeItem;
class FrgBasePlot2D;

class NihadTree : public FrgBaseTree
{

	Q_OBJECT

private:

	QList<NihadVesselGeometryTreeItem*> theGeometryTreeItems_;
	QList<FrgBaseCADPart_Entity*> thePartTreeItems_;
	//QList<NihadVesselPartTreeItem*> thePartTreeItems_;
	QList<FrgBase_CADScene_TreeItem*> theSceneTreeItems_;
	QList<FrgBasePlot2D*> thePlotsItems_;

public:

	NihadTree(FrgBaseMainWindow* parent = FrgNullPtr);

	void FormTree() override;

	FrgGetMacro(QList<NihadVesselGeometryTreeItem*>, GeometryTreeItems, theGeometryTreeItems_);
	//FrgGetMacro(QList<NihadVesselPartTreeItem*>, PartTreeItems, thePartTreeItems_);
	FrgGetMacro(QList<FrgBaseCADPart_Entity*>, PartTreeItems, thePartTreeItems_);

	NihadVesselGeometryTreeItem* GetGeometryTreeItem(FrgBaseTreeItem* item);
	//NihadVesselPartTreeItem* GetPartTreeItem(FrgBaseTreeItem* item);
	FrgBaseCADPart_Entity* GetPartTreeItem(FrgBaseTreeItem* item);

protected Q_SLOTS:

	virtual void itemClickedSlot(QTreeWidgetItem* item, int column) override;

public slots:

	void NewGeometryShipClickedSlot(bool b);
	void NewGeometryPropellerClickedSlot(bool b);
	void NewGeometryDuctClickedSlot(bool b);

	void NewSceneClickedSlot(bool b);

	void GeometryPropertyValueChangedSlot(QtProperty* property, const QVariant& value);

	void CreatePartFromGeometryClickedSlot(bool b);

	void ExportPartSlot(bool b);
	void SplitByPatchPartSlot(bool);

	void ObjectsSelectedUpdateInSceneSlot(QList<QTreeWidgetItem*>);
	void ObjectsSelectedUpdateInSceneSlot(QList<QTreeWidgetItem*>parts, QList<QTreeWidgetItem*> scenes);

	void PreviewGeometryClickedSlot(bool);

	void NewPlotClickedSlot(bool);

	void TabBarClickedSlot(int index);

	void itemDoubleClickedSlot(QTreeWidgetItem*, int);

private:

	void UpdateTree();

public slots:

	void itemInSplitTreeClickedSlot(FrgBaseTree* tree, QTreeWidgetItem* item, int column);

};

EndFrgBaseLib

#endif // !_NihadTree_Header
