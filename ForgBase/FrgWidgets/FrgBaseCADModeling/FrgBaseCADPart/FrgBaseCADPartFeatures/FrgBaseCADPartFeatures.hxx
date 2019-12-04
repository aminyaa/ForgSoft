#pragma once
#ifndef _FrgBaseCADPartFeatures_Header
#define _FrgBaseCADPartFeatures_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTreeItem.hxx>
#include <FrgBaseTree.hxx>

BeginFrgBaseLib

class FrgBaseCADScene;

class FrgBaseCADPartFeatureBase : public FrgBaseTreeItem
{

private:

	QList<FrgBaseCADScene*> thePointerToScenes_;

public:

	FrgBaseCADPartFeatureBase
	(
		const FrgString& title,
		FrgBaseTreeItem* parentItem
	)
		: FrgBaseTreeItem(title, parentItem, (parentItem ? parentItem->GetParentTree() : FrgNullPtr), (parentItem ? parentItem->GetParentMainWindow() : FrgNullPtr))
	{}

	FrgBaseCADPartFeatureBase
	(
		const FrgString& title,
		FrgBaseTree* parentTree
	)
		: FrgBaseTreeItem(title, FrgNullPtr, parentTree, (parentTree ? parentTree->GetParentMainWindow() : FrgNullPtr))
	{}

	~FrgBaseCADPartFeatureBase()
	{
		for (int i = 0; i < thePointerToScenes_.size(); i++)
		{
			if (thePointerToScenes_[i])
				thePointerToScenes_[i] = FrgNullPtr;
		}
	}

	FrgGetMacro(QList<FrgBaseCADScene*>, PointerToScenes, thePointerToScenes_);
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
