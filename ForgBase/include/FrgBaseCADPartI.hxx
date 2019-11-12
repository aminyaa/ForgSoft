#pragma once
#include <FrgBaseTree.hxx>
#include <FrgBaseGlobalsICONS.hxx>

template<class SurfaceEntity, class CurveEntity>
inline ForgBaseLib::FrgBaseCADPart<SurfaceEntity, CurveEntity>::FrgBaseCADPart
(
	const FrgString& title,
	FrgBaseTreeItem* parent
)
	: FrgBaseTreeItem(title, parent, parent->GetParentTree(), parent->GetParentMainWindow())
{
}

template<class SurfaceEntity, class CurveEntity>
inline ForgBaseLib::FrgBaseCADPart<SurfaceEntity, CurveEntity>::FrgBaseCADPart
(
	const FrgString& title,
	FrgBaseTree* parentTree
)
	: FrgBaseTreeItem(title, FrgNullPtr, parentTree, parentTree->GetParentMainWindow())
{
}

template<class SurfaceEntity, class CurveEntity>
inline ForgBaseLib::FrgBaseCADPart<SurfaceEntity, CurveEntity>::FrgBaseCADPart
(
	const FrgString& title,
	FrgBaseTreeItem* parent,
	std::vector<std::shared_ptr<SurfaceEntity>> surfaces,
	std::vector<std::shared_ptr<CurveEntity>> curves
)
	: FrgBaseTreeItem(title, parent, parent->GetParentTree(), parent->GetParentMainWindow())
	, theSurfaces_(surfaces)
	, theCurves_(curves)
{
	DoAfterConstruct();
}

template<class SurfaceEntity, class CurveEntity>
inline ForgBaseLib::FrgBaseCADPart<SurfaceEntity, CurveEntity>::FrgBaseCADPart
(
	const FrgString& title,
	FrgBaseTree* parentTree,
	std::vector<std::shared_ptr<SurfaceEntity>> surfaces,
	std::vector<std::shared_ptr<CurveEntity>> curves
)
	: FrgBaseTreeItem(title, FrgNullPtr, parentTree, parentTree->GetParentMainWindow())
	, theSurfaces_(surfaces)
	, theCurves_(curves)
{
	DoAfterConstruct();
}

template<class SurfaceEntity, class CurveEntity>
inline void ForgBaseLib::FrgBaseCADPart<SurfaceEntity, CurveEntity>::DoAfterConstruct()
{
	theFeatures_ = FrgNew FrgBaseCADPartFeatures<SurfaceEntity, CurveEntity>("Features", (FrgBaseTreeItem*)this);

	for (int iSurface = 0; iSurface < theSurfaces_.size(); iSurface++)
	{
		theFeatures_->GetSurfacesEntity()->GetFeatureListEntity().push_back(FrgNew FrgBaseCADPartFeatureEntity<SurfaceEntity>(CorrectName<FrgBaseTreeItem>(theFeatures_->GetSurfacesEntity(), "Surface "), theFeatures_->GetSurfacesEntity()));
		theFeatures_->GetSurfacesEntity()->GetFeatureEntity(iSurface)->GetEntity() = theSurfaces_.at(iSurface);

		theFeatures_->GetSurfacesEntity()->GetFeatureEntity(iSurface)->setIcon(0, QIcon(FrgICONTreeItemPartSurface));
	}

	for (int iCurve = 0; iCurve < theCurves_.size(); iCurve++)
	{
		theFeatures_->GetCurvesEntity()->GetFeatureListEntity().push_back(FrgNew FrgBaseCADPartFeatureEntity<CurveEntity>(CorrectName<FrgBaseTreeItem>(theFeatures_->GetCurvesEntity(), "Curve "), theFeatures_->GetCurvesEntity()));
		theFeatures_->GetCurvesEntity()->GetFeatureEntity(iCurve)->GetEntity() = theCurves_.at(iCurve);

		theFeatures_->GetCurvesEntity()->GetFeatureEntity(iCurve)->setIcon(0, QIcon(FrgICONTreeItemPartCurve));
	}
}