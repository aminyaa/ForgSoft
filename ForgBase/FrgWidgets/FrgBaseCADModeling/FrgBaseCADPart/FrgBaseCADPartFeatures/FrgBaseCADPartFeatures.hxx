#pragma once
#ifndef _FrgBaseCADPartFeatures_Header
#define _FrgBaseCADPartFeatures_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTreeItem.hxx>

BeginFrgBaseLib

class FrgBaseCADScene;

template <class Entity>
class FrgBaseCADPartFeatureEntity : public FrgBaseTreeItem
{

private:

	FrgSharedPtr<Entity> theEntity_ = FrgNullPtr;

	FrgBaseCADScene* thePointerToScene_ = FrgNullPtr;

public:

	FrgBaseCADPartFeatureEntity
	(
		const FrgString& title,
		FrgBaseTreeItem* parentItem
	);

	FrgGetMacro(FrgSharedPtr<Entity>, Entity, theEntity_);
	FrgGetMacro(FrgBaseCADScene*, PointerToScene, thePointerToScene_);
};

template<class Entity>
class FrgBaseCADPartFeaturesEntity : public FrgBaseTreeItem
{

private:

	QList<FrgBaseCADPartFeatureEntity<Entity>*> theFeatureEntities_;

public:

	FrgBaseCADPartFeaturesEntity
	(
		const FrgString& title,
		FrgBaseTreeItem* parentItem
	);

	const FrgBaseCADPartFeatureEntity<Entity>*& GetFeatureEntity(int index) const { return theFeatureEntities_.at(index); }
	FrgBaseCADPartFeatureEntity<Entity>* GetFeatureEntity(int index) { return theFeatureEntities_.at(index); }

	FrgGetMacro(QList<FrgBaseCADPartFeatureEntity<Entity>*>, FeatureListEntity, theFeatureEntities_);
};

template <class SurfaceEntity, class CurveEntity>
class FrgBaseCADPartFeatures
{

private:

	FrgBaseCADPartFeaturesEntity<SurfaceEntity>* theSurfacesEntity_ = FrgNullPtr;
	FrgBaseCADPartFeaturesEntity<CurveEntity>* theCurvesEntity_ = FrgNullPtr;

public:

	FrgBaseCADPartFeatures
	(
		const FrgString& title,
		FrgBaseTreeItem* parentItem
	);

	FrgGetMacro(FrgBaseCADPartFeaturesEntity<SurfaceEntity>*, SurfacesEntity, theSurfacesEntity_);
	FrgGetMacro(FrgBaseCADPartFeaturesEntity<CurveEntity>*, CurvesEntity, theCurvesEntity_);
};

EndFrgBaseLib

#include <FrgBaseCADPartFeaturesI.hxx>

#endif // !_FrgBaseCADPartFeatures_Header
