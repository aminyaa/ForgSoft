#include <FrgBaseCAD_Part.hxx>
#include <FrgBaseTree.hxx>

ForgBaseLib::FrgBaseCAD_Part_Base::FrgBaseCAD_Part_Base
(
	const FrgString& title,
	FrgBaseTreeItem* parent
)
	: FrgBaseTreeItem(title, parent, (parent ? parent->GetParentTree() : FrgNullPtr), (parent ? parent->GetParentMainWindow() : FrgNullPtr))
{

}

ForgBaseLib::FrgBaseCAD_Part_Base::FrgBaseCAD_Part_Base
(
	const FrgString& title,
	FrgBaseTree* parentTree
)
	: FrgBaseTreeItem(title, FrgNullPtr, parentTree, (parentTree ? parentTree->GetParentMainWindow() : FrgNullPtr))
{

}