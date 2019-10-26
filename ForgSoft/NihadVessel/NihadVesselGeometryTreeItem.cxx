#include <NihadVesselGeometryTreeItem.hxx>
#include <Leg_Model_Entity.hxx>

//#include <Leg_Vessel_Nihad2.hxx>

ForgBaseLib::NihadVesselGeometryTreeItem::NihadVesselGeometryTreeItem
(
	const FrgString& title,
	FrgBaseTreeItem* parent,
	FrgBaseTree* parentTree,
	FrgBaseMainWindow* parentMainwindow
)
	: FrgBaseTreeItem(title, parent, parentTree, parentMainwindow)
{

}

const TopoDS_Shape& ForgBaseLib::NihadVesselGeometryTreeItem::GetTopoDS_Shape()
{
	return theEntity_->Entity();
}