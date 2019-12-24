#pragma once
#include <SplitTree.hxx>
#include <FrgBaseCADPartFeatures.hxx>

template<class Entity>
ForgBaseLib::SplitTree<Entity>::SplitTree
(
	FrgBaseMainWindow* parent,
	FrgBaseCADPartFeatureEntity<Entity> featureEntity,
	QList<FrgBaseCADScene*> pointerToScenes,
	SplitWidget<Entity>* parentSplitWidget,
	FrgBaseCADPart_Entity* parentPart
)
	: SplitTree_Base(parent, pointerToScenes, parentPart)
	, theFeatureEntity_(featureEntity)
	, theParentSplitWidget_(parentSplitWidget)
{

}

template<class Entity>
inline void ForgBaseLib::SplitTree<Entity>::FormTree()
{
	std::vector<std::shared_ptr<AutLib::TModel_Surface>>;
	theFeatureEntity_->GetEntity()
}