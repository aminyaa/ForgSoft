#include <FrgVisual_Scene3D_TItem.hxx>
#include <FrgVisual_Scene3D.hxx>

#include <FrgBase_Tree.hxx>

ForgVisualLib::FrgVisual_Scene3D_TItem::FrgVisual_Scene3D_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgVisual_Scene_TItem(itemTitle, parentItem, parentTree)
{
	theScene_ = new FrgVisual_Scene3D(GetParentMainWindow());
	dynamic_cast<FrgVisual_Scene3D*>(theScene_)->Init();
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Scene3D_TItem)
{
	ar & theScene_;
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Scene3D_TItem)
{
	ar & theScene_;
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Scene3D_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Scene3D_TItem)
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Scene3D_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Scene3D_TItem)
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Scene3D_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_Scene3D_TItem)