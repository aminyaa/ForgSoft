#pragma once
#include <FrgBaseTree.hxx>
#include <FrgBaseMenu.hxx>

template<class Entity>
inline ForgBaseLib::FrgBaseCADGeometry<Entity>::FrgBaseCADGeometry
(
	const FrgString& title,
	FrgBaseTreeItem* parent
)
	: FrgBaseTreeItem(title, parent, parent->GetParentTree(), parent->GetParentMainWindow())
{
	DoAfterConstruct();
}

template<class Entity>
inline ForgBaseLib::FrgBaseCADGeometry<Entity>::FrgBaseCADGeometry
(
	const FrgString& title,
	FrgBaseTree* parentTree
)
	: FrgBaseTreeItem(title, FrgNullPtr, parentTree, parentTree->GetParentMainWindow())
{
	DoAfterConstruct();
}

template<class Entity>
inline void ForgBaseLib::FrgBaseCADGeometry<Entity>::DoAfterConstruct()
{
	this->GetContextMenu()->AddItem("Delete");

	QObject::connect(this->GetContextMenu()->GetItem("Delete"), SIGNAL(triggered(bool)), GetParentTree(), SLOT(DeleteTreeItemSlot(bool)));
	this->GetContextMenu()->GetItem("Delete")->setEnabled(FrgFalse);
}