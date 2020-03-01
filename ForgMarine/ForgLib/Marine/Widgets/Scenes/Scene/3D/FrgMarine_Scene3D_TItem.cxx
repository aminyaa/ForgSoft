#include <FrgMarine_Scene3D_TItem.hxx>
#include <FrgVisual_Scene.hxx>
#include <FrgMarine_Tree.hxx>
#include <FrgMarine_Geometry_TItem.hxx>
#include <FrgMarine_GeomParts_TItem.hxx>
#include <FrgBase_PropertiesPanel.hxx>

ForgMarineLib::FrgMarine_Scene3D_TItem::FrgMarine_Scene3D_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgVisual_Scene3D_TItem(itemTitle, parentItem, parentTree)
{
	theScene_->SetLogoText("Tonb");

	theSelectTItems_ = new ForgBaseLib::FrgBase_PrptsVrntSelectTItems
	("Select Parts", dynamic_cast<FrgMarine_Tree*>(GetParentTree())->GetGeometryTItem()->GetPartsTItem());

	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntSelectTItems>(theSelectTItems_);
}