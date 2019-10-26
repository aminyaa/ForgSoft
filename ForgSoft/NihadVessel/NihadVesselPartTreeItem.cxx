#include <NihadVesselPartTreeItem.hxx>
#include <NihadVesselGeometryTreeItem.hxx>
#include <NihadTree.hxx>

#include <FrgBaseMenu.hxx>
#include <FrgBaseMainWindow.hxx>

//#include <Leg_Vessel_Nihad2.hxx>
//#include <TModel_Surface.hxx>
//#include <Cad3d_TModel.hxx>

ForgBaseLib::NihadVesselPartTreeItem::NihadVesselPartTreeItem
(
	const FrgString& title,
	FrgBaseTreeItem* parent,
	FrgBaseTree* parentTree,
	FrgBaseMainWindow* parentMainwindow,
	FrgSharedPtr<FrgBaseTreeItem> parentGeometry
)
	: FrgBaseTreeItem(title, parent, parentTree, parentMainwindow)
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

	/*GetGeometryPointer() = std::dynamic_pointer_cast<NihadVesselGeometryTreeItem>(parentGeometry);

	if (GetGeometryPointer())
	{
		this->GetGeometryPointer()->GetPatch()->Perform();
	}

	if (GetTModel())
	{
		
	}*/

	GetParentMainWindow()->ParseInfoToConsole("\"" + this->text(0) + "\" part successfully created.");
}