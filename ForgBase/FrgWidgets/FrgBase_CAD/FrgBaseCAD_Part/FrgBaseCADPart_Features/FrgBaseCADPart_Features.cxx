#include <FrgBaseCADPart_Features.hxx>
#include <FrgBaseMenu.hxx>
#include <FrgBaseTree.hxx>

ForgBaseLib::FrgBaseCADPart_Feature_Base::FrgBaseCADPart_Feature_Base
(
	const FrgString& title,
	FrgBaseTreeItem* parentItem,
	FrgBaseCAD_Part_Base* parentPart
)
	: FrgBaseTreeItem(title, parentItem, (parentItem ? parentItem->GetParentTree() : FrgNullPtr), (parentItem ? parentItem->GetParentMainWindow() : FrgNullPtr))
{

}

ForgBaseLib::FrgBaseCADPart_Feature_Base::FrgBaseCADPart_Feature_Base
(
	const FrgString & title,
	FrgBaseTree * parentTree,
	FrgBaseCAD_Part_Base * parentPart
)
	: FrgBaseTreeItem(title, FrgNullPtr, (parentTree ? parentTree : FrgNullPtr), (parentTree ? parentTree->GetParentMainWindow() : FrgNullPtr))
{

}

ForgBaseLib::FrgBaseCADPart_Features_Base::FrgBaseCADPart_Features_Base
(
	const FrgString& title,
	FrgBaseTreeItem* parentItem,
	FrgBaseCAD_Part_Base* parentPart
)
	: FrgBaseTreeItem(title, parentItem, (parentItem ? parentItem->GetParentTree() : FrgNullPtr), (parentItem ? parentItem->GetParentMainWindow() : FrgNullPtr))
{
	DoAfterConstruct();
}

void ForgBaseLib::FrgBaseCADPart_Feature_Base::DoAfterConstruct()
{
	if (!this->GetContextMenu()->GetItems().isEmpty())
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

void ForgBaseLib::FrgBaseCADPart_Features_Base::DoAfterConstruct()
{
	if (!this->GetContextMenu()->GetItems().isEmpty())
		this->GetContextMenu()->addSeparator();

	FrgString SelectAllEntitiesString = "Select All " + this->text(0);

	this->GetContextMenu()->AddItem(SelectAllEntitiesString);
	QObject::connect
	(
		this->GetContextMenu()->GetItem(SelectAllEntitiesString)
		, SIGNAL(triggered(bool))
		, this
		, SLOT(SelectAllFeaturesSlot(bool))
	);
}

void ForgBaseLib::FrgBaseCADPart_Features_Base::SelectAllFeaturesSlot(bool)
{
	SelectAllFeatures();
}