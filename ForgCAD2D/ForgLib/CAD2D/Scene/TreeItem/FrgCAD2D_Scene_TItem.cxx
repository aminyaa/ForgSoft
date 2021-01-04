#include <FrgCAD2D_Scene_TItem.hxx>
#include <FrgCAD2D_Scene.hxx>

ForgCAD2DLib::FrgCAD2D_Scene_TItem::FrgCAD2D_Scene_TItem
(
	const QString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: ForgVisualLib::FrgVisual_Scene_TItem<2>(itemTitle, parentItem, parentTree)
{

}

void ForgCAD2DLib::FrgCAD2D_Scene_TItem::FormTItem()
{
	theScene_ = new FrgCAD2D_Scene(GetParentMainWindow());
	dynamic_cast<FrgCAD2D_Scene*>(theScene_)->Init();

	ForgVisualLib::FrgVisual_Scene_TItem<2>::FormTItem();
}