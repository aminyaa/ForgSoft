#include <FrgBaseCADPart_Features.hxx>

ForgBaseLib::FrgBaseCADPart_Feature_Base::FrgBaseCADPart_Feature_Base
(
	const FrgString& title,
	FrgBaseTreeItem* parentItem,
	FrgBaseCAD_Part_Base* parentPart
)
	: FrgBaseTreeItem(title, parentItem, (parentItem ? parentItem->GetParentTree() : FrgNullPtr), (parentItem ? parentItem->GetParentMainWindow() : FrgNullPtr))
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

}