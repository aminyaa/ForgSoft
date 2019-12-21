#include <FrgBaseCADPartFeatures.hxx>
#include <FrgBaseCADPart.hxx>
#include <FrgBase_CADScene_TreeItem.hxx>
#include <FrgBaseCADScene.hxx>

#include <QtCore/QObject>

ForgBaseLib::FrgBaseCADPartFeatureBase::FrgBaseCADPartFeatureBase
(
	const FrgString& title,
	FrgBaseTreeItem* parentItem
)
	: FrgBaseTreeItem(title, parentItem, (parentItem ? parentItem->GetParentTree() : FrgNullPtr), (parentItem ? parentItem->GetParentMainWindow() : FrgNullPtr))
{
	DoAfterConstruct();
}

ForgBaseLib::FrgBaseCADPartFeatureBase::FrgBaseCADPartFeatureBase
(
	const FrgString& title,
	FrgBaseTree* parentTree
)
	: FrgBaseTreeItem(title, FrgNullPtr, parentTree, (parentTree ? parentTree->GetParentMainWindow() : FrgNullPtr))
{
	DoAfterConstruct();
}

ForgBaseLib::FrgBaseCADPartFeatureBase::~FrgBaseCADPartFeatureBase()
{
	for (int i = 0; i < thePointerToScenes_.size(); i++)
		{
			if (thePointerToScenes_[i])
				thePointerToScenes_[i] = FrgNullPtr;
		}
}

void ForgBaseLib::FrgBaseCADPartFeatureBase::DoAfterConstruct()
{
	this->GetContextMenu()->addSeparator();

	FrgString SplitByPatchPartString = "Split By Patch";

	this->GetContextMenu()->AddItem(SplitByPatchPartString);
	QObject::connect
	(
		this->GetContextMenu()->GetItem(SplitByPatchPartString)
		, SIGNAL(triggered(bool))
		, this->GetParentTree()
		, SLOT(SplitByPatchPartSlot(bool))
	);

	FrgString SplitByNonContiguousString = "Split By Non-Contiguous";

	this->GetContextMenu()->AddItem(SplitByNonContiguousString);
	QObject::connect
	(
		this->GetContextMenu()->GetItem(SplitByNonContiguousString)
		, SIGNAL(triggered(bool))
		, this->GetParentTree()
		, SLOT(SplitByNonContiguousPartSlot(bool))
	);

	this->GetContextMenu()->addSeparator();

	FrgString CombineString = "Combine";

	this->GetContextMenu()->AddItem(CombineString);
	QObject::connect
	(
		this->GetContextMenu()->GetItem(CombineString)
		, SIGNAL(triggered(bool))
		, this->GetParentTree()
		, SLOT(CombinePartSlot(bool))
	);
	this->GetContextMenu()->GetItem(CombineString)->setEnabled(FrgFalse);
}

QList<ForgBaseLib::FrgBase_CADScene_TreeItem*> ForgBaseLib::FrgBaseCADPartFeatureBase::GetPointerToCADSceneTreeItems() const
{
	QList<FrgBase_CADScene_TreeItem*> output;

	for (int i = 0; i < thePointerToScenes_.size(); i++)
	{
		output.push_back(thePointerToScenes_[i]->GetParentCADSceneTreeItem());
	}

	return output;
}

QList<ForgBaseLib::FrgBase_CADScene_TreeItem*> ForgBaseLib::FrgBaseCADPartFeatureBase::GetPointerToCADSceneTreeItems()
{
	QList<FrgBase_CADScene_TreeItem*> output;

	for (int i = 0; i < thePointerToScenes_.size(); i++)
	{
		output.push_back(thePointerToScenes_[i]->GetParentCADSceneTreeItem());
	}

	return output;
}

ForgBaseLib::FrgBaseCADPartFeaturesEntity_Base::FrgBaseCADPartFeaturesEntity_Base
(
	const FrgString& title,
	FrgBaseTreeItem* parentItem
)
	: FrgBaseTreeItem(title, parentItem, parentItem->GetParentTree(), parentItem->GetParentMainWindow())
{
	FrgString SelectAllEntitiesString = "Select All " + this->text(0);

	this->GetContextMenu()->AddItem(SelectAllEntitiesString);
	QObject::connect
	(
		this->GetContextMenu()->GetItem(SelectAllEntitiesString)
		, SIGNAL(triggered(bool))
		, this->GetParentTree()
		, SLOT(SelectAllPartFeatureEntities(bool))
	);
}