#include <NihadVesselPartTreeItem.hxx>
#include <NihadVesselGeometryTreeItem.hxx>
#include <FrgBaseTree.hxx>

#include <FrgBaseMenu.hxx>
#include <FrgBaseMainWindow.hxx>
//#include <NihadPartSurfaceEntity.hxx>
//#include <NihadPartCurveEntity.hxx>

#include <Cad3d_TModel.hxx>

ForgBaseLib::NihadVesselPartTreeItem::NihadVesselPartTreeItem
(
	const FrgString& title,
	FrgBaseTreeItem* parent,
	FrgSharedPtr<AutLib::Cad3d_TModel> model
)
	: FrgBaseCADPart(title, parent)
	, theModel_(model)
{
	DoAfterConstruct();
}

ForgBaseLib::NihadVesselPartTreeItem::NihadVesselPartTreeItem
(
	const FrgString& title,
	FrgBaseTree* parentTree,
	FrgSharedPtr<AutLib::Cad3d_TModel> model
)
	: FrgBaseCADPart(title, parentTree)
	, theModel_(model)
{
	DoAfterConstruct();
}

void ForgBaseLib::NihadVesselPartTreeItem::DoAfterConstruct()
{
	std::vector<std::shared_ptr<AutLib::TModel_Surface>> TModelSurfaces;
	std::vector<std::shared_ptr<AutLib::TModel_Paired>> TModelCurves;
	theModel_->RetrieveFacesTo(TModelSurfaces);
	theModel_->RetrieveSegmentsTo(TModelCurves);

	GetSurfaces() = TModelSurfaces;
	GetCurves() = TModelCurves;

	FrgString ExportPartString = "&Export";
	this->GetContextMenu()->AddItem(ExportPartString);
	QObject::connect
	(
		this->GetContextMenu()->GetItem(ExportPartString.remove('&'))
		, SIGNAL(triggered(bool))
		, this->GetParentTree()
		, SLOT(ExportPartSlot(bool))
	);

	FrgBaseCADPart::DoAfterConstruct();
}