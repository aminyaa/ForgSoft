#include <FrgMarine_HStaticsCrossCurvesPView_TItem.hxx>
#include <FrgBase_Global_Icons.hxx>

ForgMarineLib::FrgMarine_HStaticsCrossCurvesPView_TItem::FrgMarine_HStaticsCrossCurvesPView_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgMarine_Scene3D_TItem(itemTitle, parentItem, parentTree)
{
	this->setIcon(0, QIcon(ICONTreeItemEye));

	this->RemoveRenameOptionInContextMenu();
	this->RemoveDeleteOptionInContextMenu();
}