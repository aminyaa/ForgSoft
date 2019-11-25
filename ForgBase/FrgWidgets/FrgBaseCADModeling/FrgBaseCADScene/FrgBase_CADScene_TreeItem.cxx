#include <FrgBase_CADScene_TreeItem.hxx>
#include <FrgBaseTreeItemProperties.hxx>
#include <FrgBaseCADScene.hxx>

ForgBaseLib::FrgBase_CADScene_TreeItem::FrgBase_CADScene_TreeItem
(
	const FrgString & title,
	FrgBaseTreeItem * parent
)
	: FrgBaseTreeItem(title, parent, parent->GetParentTree(), parent->GetParentMainWindow())
{
	setIcon(0, QIcon(":/Icons/Scenes/Geometry_Scene_Icon.png"));

	GetProperties()->SetEnabled("Name", FrgTrue);
}