#pragma once
#ifndef _FrgBaseCADPartFeatures_Header
#define _FrgBaseCADPartFeatures_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTreeItem.hxx>
#include <FrgBaseTree.hxx>
#include <FrgBaseMenu.hxx>

BeginFrgBaseLib

class FrgBaseCADScene;
class FrgBaseCADPart_Entity;

class FORGBASE_EXPORT FrgBaseCADPartFeatureBase : public FrgBaseTreeItem
{

private:

	FrgBaseCADPart_Entity* theParentPart_ = FrgNullPtr;

	QList<FrgBaseCADScene*> thePointerToScenes_;

public:

	FrgBaseCADPartFeatureBase
	(
		const FrgString& title,
		FrgBaseTreeItem* parentItem
	);

	FrgBaseCADPartFeatureBase
	(
		const FrgString& title,
		FrgBaseTree* parentTree
	);

	~FrgBaseCADPartFeatureBase();

	virtual void DoAfterConstruct() override;

	FrgGetMacro(QList<FrgBaseCADScene*>, PointerToScenes, thePointerToScenes_);
	FrgGetMacro(FrgBaseCADPart_Entity*, ParentPart, theParentPart_);
};

template <class Entity>
class FrgBaseCADPartFeatureEntity : public FrgBaseCADPartFeatureBase
{

private:

	FrgSharedPtr<Entity> theEntity_ = FrgNullPtr;

public:

	FrgBaseCADPartFeatureEntity
	(
		const FrgString& title,
		FrgBaseTreeItem* parentItem
	);

	FrgBaseCADPartFeatureEntity
	(
		const FrgString& title,
		FrgBaseTree* parentTree
	);

	FrgGetMacro(FrgSharedPtr<Entity>, Entity, theEntity_);
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

	~FrgBaseCADPartFeaturesEntity();

	const FrgBaseCADPartFeatureEntity<Entity>*& GetFeatureEntity(int index) const { return theFeatureEntities_[index]; }
	FrgBaseCADPartFeatureEntity<Entity>*& GetFeatureEntity(int index) { return theFeatureEntities_[index]; }

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

	~FrgBaseCADPartFeatures();

	FrgGetMacro(FrgBaseCADPartFeaturesEntity<SurfaceEntity>*, SurfacesEntity, theSurfacesEntity_);
	FrgGetMacro(FrgBaseCADPartFeaturesEntity<CurveEntity>*, CurvesEntity, theCurvesEntity_);
};

EndFrgBaseLib

#include <FrgBaseCADPartFeaturesI.hxx>

#endif // !_FrgBaseCADPartFeatures_Header
