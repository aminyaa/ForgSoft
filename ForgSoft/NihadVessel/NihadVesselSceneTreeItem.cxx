#include <NihadVesselSceneTreeItem.hxx>
#include <FrgBaseTreeItem.hxx>
#include <FrgBaseTree.hxx>
#include <FrgBaseMainWindow.hxx>

#include <Pnt2d.hxx>
#include <Entity2d_Box.hxx>
#include <FastDiscrete_Params.hxx>
#include <Leg_Vessel_Nihad2.hxx>
#include <IO_IGES.hxx>

ForgBaseLib::NihadVesselSceneTreeItem::NihadVesselSceneTreeItem(const FrgString& title, FrgBaseTreeItem* parent, FrgBaseTree* parentTree, FrgBaseMainWindow* parentMainwindow)
	: FrgBaseSceneTreeItem(title, parent, parentTree, parentMainwindow)
{
	StartScene();
}

void ForgBaseLib::NihadVesselSceneTreeItem::StartScene()
{
	AutLib::Leg_Nihad2_HullPatch patch;

	patch.FwdSection().Tightness0()->SetValue(0.9);
	patch.FwdSection().Tightness1()->SetValue(0.9);

	patch.AftSection().Trim()->SetValue(0.1);
	patch.MidSection().Trim()->SetValue(0.1);
	patch.FwdSection().Trim()->SetValue(0.1);

	patch.Perform();

	patch.FileFormat() = AutLib::Leg_EntityIO_Format::IGES;
	patch.ExportToFile();
}
