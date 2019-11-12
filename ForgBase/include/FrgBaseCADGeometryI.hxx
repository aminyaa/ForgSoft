#pragma once
#include <FrgBaseTree.hxx>

template<class Entity>
inline ForgBaseLib::FrgBaseCADGeometry<Entity>::FrgBaseCADGeometry
(
	const FrgString& title,
	FrgBaseTreeItem* parent
)
	: FrgBaseTreeItem(title, parent, parent->GetParentTree(), parent->GetParentMainWindow())
{

}

template<class Entity>
inline ForgBaseLib::FrgBaseCADGeometry<Entity>::FrgBaseCADGeometry
(
	const FrgString& title,
	FrgBaseTree* parentTree
)
	: FrgBaseTreeItem(title, FrgNullPtr, parentTree, parentTree->GetParentMainWindow())
{
}