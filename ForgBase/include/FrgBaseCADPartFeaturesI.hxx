#pragma once
//#include <FrgBaseCADPartFeatures.hxx>

//ForgBaseLib::CADPartFeatureBase::CADPartFeatureBase
//(
//	const FrgString& title,
//	FrgBaseTreeItem* parentItem
//)
//	: FrgBaseTreeItem(title, parentItem, parentItem->GetParentTree(), parentItem->GetParentMainWindow())
//{
//
//}

template<class Entity>
inline ForgBaseLib::FrgBaseCADPartFeatureEntity<Entity>::FrgBaseCADPartFeatureEntity
(
	const FrgString& title,
	FrgBaseTreeItem* parentItem
)
	: FrgBaseCADPartFeatureBase(title, parentItem)
{

}

template<class Entity>
inline ForgBaseLib::FrgBaseCADPartFeaturesEntity<Entity>::FrgBaseCADPartFeaturesEntity
(
	const FrgString& title,
	FrgBaseTreeItem* parentItem
)
	: FrgBaseTreeItem(title, parentItem, parentItem->GetParentTree(), parentItem->GetParentMainWindow())
{

}

template<class Entity>
inline ForgBaseLib::FrgBaseCADPartFeaturesEntity<Entity>::~FrgBaseCADPartFeaturesEntity()
{
	FreeVectorOfPointers(theFeatureEntities_);
}

template<class SurfaceEntity, class CurveEntity>
inline ForgBaseLib::FrgBaseCADPartFeatures<SurfaceEntity, CurveEntity>::FrgBaseCADPartFeatures
(
	const FrgString& title,
	FrgBaseTreeItem* parentItem
)
{
	theSurfacesEntity_ = FrgNew FrgBaseCADPartFeaturesEntity<SurfaceEntity>("Surfaces", parentItem);
	theCurvesEntity_ = FrgNew FrgBaseCADPartFeaturesEntity<CurveEntity>("Curves", parentItem);
}

template<class SurfaceEntity, class CurveEntity>
inline ForgBaseLib::FrgBaseCADPartFeatures<SurfaceEntity, CurveEntity>::~FrgBaseCADPartFeatures()
{
	FreePointer(theSurfacesEntity_);
	FreePointer(theCurvesEntity_);
}