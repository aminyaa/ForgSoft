#include <FrgCAD_Scene_TItem.hxx>
#include <FrgCAD_Scene.hxx>

ForgCADLib::FrgCAD_Scene_TItem::FrgCAD_Scene_TItem
(
	const QString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: ForgVisualLib::FrgVisual_Scene_TItem<2>(itemTitle, parentItem, parentTree)
{

}

void ForgCADLib::FrgCAD_Scene_TItem::FormTItem()
{
	theScene_ = new FrgCAD_Scene(GetParentMainWindow());
	dynamic_cast<FrgCAD_Scene*>(theScene_)->Init();

	ForgVisualLib::FrgVisual_Scene_TItem<2>::FormTItem();
}