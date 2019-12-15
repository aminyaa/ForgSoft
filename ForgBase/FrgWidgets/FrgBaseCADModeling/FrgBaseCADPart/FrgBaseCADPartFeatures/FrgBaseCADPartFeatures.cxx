#include <FrgBaseCADPartFeatures.hxx>
#include <FrgBaseCADPart.hxx>

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
	FrgString SplitByPatchPartString = "&Split By Patch";

	this->GetContextMenu()->AddItem(SplitByPatchPartString);
	QObject::connect
	(
		this->GetContextMenu()->GetItem(SplitByPatchPartString.remove('&'))
		, SIGNAL(triggered(bool))
		, this->GetParentTree()
		, SLOT(SplitByPatchPartSlot(bool))
	);

	FrgString SplitByNonContiguousString = "&Split By Non-Contiguous";

	this->GetContextMenu()->AddItem(SplitByNonContiguousString);
	QObject::connect
	(
		this->GetContextMenu()->GetItem(SplitByNonContiguousString.remove('&'))
		, SIGNAL(triggered(bool))
		, this->GetParentTree()
		, SLOT(SplitByNonContiguousPartSlot(bool))
	);
}