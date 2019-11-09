#include <NihadVesselPartTreeItem.hxx>
#include <NihadVesselGeometryTreeItem.hxx>
#include <NihadTree.hxx>

#include <FrgBaseMenu.hxx>
#include <FrgBaseMainWindow.hxx>
#include <NihadPartSurfaceEntity.hxx>

//#include <Leg_Vessel_Nihad2.hxx>
//#include <TModel_Surface.hxx>
//#include <Cad3d_TModel.hxx>

ForgBaseLib::NihadVesselPartTreeItem::NihadVesselPartTreeItem
(
	const FrgString& title,
	FrgBaseTreeItem* parent,
	FrgBaseTree* parentTree,
	FrgBaseMainWindow* parentMainwindow,
	FrgSharedPtr<AutLib::Cad3d_TModel> TModel
)
	: FrgBaseTreeItem(title, parent, parentTree, parentMainwindow)
	, theTModel_(TModel)
{
	FrgString ExportPartString = "&Export";
	this->GetContextMenu()->AddItem(ExportPartString);
	connect
	(
		this->GetContextMenu()->GetItem(ExportPartString.remove('&'))
		, SIGNAL(triggered(bool))
		, (NihadTree*)parentTree
		, SLOT(ExportPartSlot(bool))
	);

	if(TModel)
		theSurfaces_ = FrgNew NihadPartSurfacesEntity("Surfaces", this, GetParentTree(), GetParentMainWindow());

	GetParentMainWindow()->ParseInfoToConsole("\"" + this->text(0) + "\" part successfully created.");
}