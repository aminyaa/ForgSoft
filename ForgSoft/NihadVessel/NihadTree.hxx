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

class NihadTree : public FrgBaseTree
{

	Q_OBJECT

private:

	struct NihadGeometryTreeItemStruct
	{
		FrgBaseTreeItem* theTreeItem_ = FrgNullPtr;
		AutLib::Leg_Nihad2_HullPatch* thePatch_ = FrgNullPtr;
	};

	struct NihadPartTreeItemStruct
	{
		FrgBaseTreeItem* theTreeItem_ = FrgNullPtr;
	};

	QList<NihadGeometryTreeItemStruct*> theNihadGeometryTreeItems_;
	QList<NihadPartTreeItemStruct*> theNihadPartTreeItems_;

public:

	NihadTree(FrgBaseMainWindow* parent = FrgNullPtr);

	void FormTree() override;

public slots:

	void NewGeometryClickedSlot(bool b);

	void NewSceneClickedSlot(bool b);

	void PropertyValueChangedSlot(QtProperty* property, const QVariant& value);

	void CreatePartFromGeometryClickedSlot(bool b);
};

EndFrgBaseLib

#endif // !_NihadTree_Header
