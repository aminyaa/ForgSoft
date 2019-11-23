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
class FrgBaseCADScene;
class FrgBasePlot2D;

class NihadTree : public FrgBaseTree
{

	Q_OBJECT

private:

	QList<NihadVesselGeometryTreeItem*> theGeometryTreeItems_;
	QList<NihadVesselPartTreeItem*> thePartTreeItems_;
	QList<FrgBaseCADScene*> theSceneTreeItems_;
	QList<FrgBasePlot2D*> thePlotsItems_;

public:

	NihadTree(FrgBaseMainWindow* parent = FrgNullPtr);

	void FormTree() override;

	FrgGetMacro(QList<NihadVesselGeometryTreeItem*>, GeometryTreeItems, theGeometryTreeItems_);
	FrgGetMacro(QList<NihadVesselPartTreeItem*>, PartTreeItems, thePartTreeItems_);

	NihadVesselGeometryTreeItem* GetGeometryTreeItem(FrgBaseTreeItem* item);
	NihadVesselPartTreeItem* GetPartTreeItem(FrgBaseTreeItem* item);

protected Q_SLOTS:

	virtual void itemClickedSlot(QTreeWidgetItem* item, int column) override;

public slots:

	void NewGeometryNihadClickedSlot(bool b);
	void NewGeometryPropellerClickedSlot(bool b);
	void NewGeometryDuctClickedSlot(bool b);

	void NewSceneClickedSlot(bool b);

	void GeometryPropertyValueChangedSlot(QtProperty* property, const QVariant& value);

	void CreatePartFromGeometryClickedSlot(bool b);

	void ExportPartSlot(bool b);

	void ObjectsSelectedUpdateInSceneSlot(QList<QTreeWidgetItem*>);

	void PreviewGeometryClickedSlot(bool);

	void NewPlotClickedSlot(bool);

	void TabBarClickedSlot(int index);

	void itemDoubleClickedSlot(QTreeWidgetItem*, int);

private:

	void UpdateTree();

};

EndFrgBaseLib

#endif // !_NihadTree_Header
