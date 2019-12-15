#pragma once
#include <FrgBaseMenu.hxx>
#include <FrgBaseTree.hxx>
#include <FrgBaseCADPartFeatures.hxx>

#include <Cad3d_TModel.hxx>

template<class SurfaceEntity, class CurveEntity>
inline ForgBaseLib::CADPartItem<SurfaceEntity, CurveEntity>::CADPartItem
(
	const FrgString& title,
	FrgBaseTreeItem* parent,
	FrgSharedPtr<AutLib::Cad3d_TModel> model
) : FrgBaseCADPart(title, parent)
, theModel_(model)
{
	DoAfterConstruct();
}

template<class SurfaceEntity, class CurveEntity>
inline ForgBaseLib::CADPartItem<SurfaceEntity, CurveEntity>::CADPartItem
(
	const FrgString& title,
	FrgBaseTree* parentTree,
	FrgSharedPtr<AutLib::Cad3d_TModel> model
) : FrgBaseCADPart(title, parentTree)
, theModel_(model)
{
	DoAfterConstruct();
}

template<class SurfaceEntity, class CurveEntity>
inline void ForgBaseLib::CADPartItem<SurfaceEntity, CurveEntity>::DoAfterConstruct()
{
	//std::vector<std::shared_ptr<SurfaceEntity>> surfaceVector;
	//std::vector<std::shared_ptr<CurveEntity>> curveVector;

	std::vector<std::shared_ptr<SurfaceEntity>> blocksForSurfaces;
	std::vector<std::shared_ptr<CurveEntity>> blocksForCurves;
	theModel_->Faces()->RetrieveTo(blocksForSurfaces);
	theModel_->Segments()->RetrieveTo(blocksForCurves);

	//surfaceVector.push_back(blocksForSurfaces);
	//curveVector.push_back(blocksForCurves);
	/*for (int iSurface = 0; iSurface < blocksForSurfaces.size(); iSurface++)
		GetSurfaces().push_back(std::dynamic_pointer_cast<SurfaceEntity>(blocksForSurfaces[iSurface]));
	for (int iCurve = 0; iCurve < blocksForCurves.size(); iCurve++)
		GetCurves().push_back(std::dynamic_pointer_cast<CurveEntity>(blocksForCurves[iCurve]));*/

	GetSurfaces() = blocksForSurfaces;
	GetCurves() = blocksForCurves;

	FrgBaseCADPart::DoAfterConstruct();

	FrgString ExportPartString = "&Export";
	this->GetContextMenu()->AddItem(ExportPartString);
	QObject::connect
	(
		this->GetContextMenu()->GetItem(ExportPartString.remove('&'))
		, SIGNAL(triggered(bool))
		, this->GetParentTree()
		, SLOT(ExportPartSlot(bool))
	);

	/*auto& surfacesList = this->GetFeatures()->GetSurfacesEntity()->GetFeatureListEntity();

	for (int i = 0; i < surfacesList.size(); i++)
	{
		FrgString SplitByPatchPartString = "&Split By Patch";

		auto& surfacesEntity = this->GetFeatures()->GetSurfacesEntity()->GetFeatureEntity(i);
		surfacesEntity->GetContextMenu()->AddItem(SplitByPatchPartString);
		QObject::connect
		(
			surfacesEntity->GetContextMenu()->GetItem(SplitByPatchPartString.remove('&'))
			, SIGNAL(triggered(bool))
			, this->GetParentTree()
			, SLOT(SplitByPatchPartSlot(bool))
		);
	}*/
}

//template<class SurfaceEntity, class CurveEntity>
//inline void ForgBaseLib::CADPartItem<SurfaceEntity, CurveEntity>::SplitByPatchPartSlot(bool)
//{
//	/*auto surfaceItem = dynamic_cast<FrgBaseCADPartFeatureEntity<SurfaceEntity>*>(theLastRightClicked_);
//	auto curveItem = dynamic_cast<FrgBaseCADPartFeatureEntity<CurveEntity>*>(theLastRightClicked_);
//
//	SplitWidget* splitWidget = FrgNew SplitWidget
//	(
//		theLastRightClicked_->text(0),
//		GetParentMainWindow(), (surfaceItem ? surfaceItem->GetEntity() : FrgNullPtr),
//		(curveItem ? curveItem->GetEntity() : FrgNullPtr),
//		(surfaceItem ? surfaceItem->GetPointerToScenes() : curveItem->GetPointerToScenes()),
//		dynamic_cast<FrgBaseCADPartFeatureBase*>(theLastRightClicked_)->GetParentPart()
//	);
//
//	if (surfaceItem)
//		part->GetModel()->Faces()->SelectBlockEntity(surfaceItem->GetEntity()->Name());
//	else if (curveItem)
//		part->GetModel()->Segments()->SelectBlockEntity(curveItem->GetEntity()->Name());*/
//
//	std::cout << "It is connected!\n";
//}