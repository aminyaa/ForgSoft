#include <NihadVesselGeometryTreeItem.hxx>
#include <Leg_Model_Entity.hxx>
#include <FrgBaseTreeItem.hxx>

ForgBaseLib::NihadVesselGeometryTreeItem::NihadVesselGeometryTreeItem
(
	const FrgString& title,
	FrgBaseTreeItem* parent
)
	: FrgBaseCADGeometry(title, parent)
{

}

ForgBaseLib::NihadVesselGeometryTreeItem::NihadVesselGeometryTreeItem
(
	const FrgString& title,
	FrgBaseTree* parentTree
)
	: FrgBaseCADGeometry(title, parentTree)
{
}

ForgBaseLib::NihadVesselGeometryTreeItem::~NihadVesselGeometryTreeItem()
{

}

const TopoDS_Shape& ForgBaseLib::NihadVesselGeometryTreeItem::GetTopoDS_Shape()
{
	return GetEntity()->Entity();
}