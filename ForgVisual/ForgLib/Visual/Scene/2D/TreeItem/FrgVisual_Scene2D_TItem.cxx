#include <FrgVisual_Scene2D_TItem.hxx>
#include <FrgVisual_Scene2D.hxx>

#include <FrgBase_Tree.hxx>

ForgVisualLib::FrgVisual_Scene2D_TItem::FrgVisual_Scene2D_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgVisual_Scene_TItem(itemTitle, parentItem, parentTree)
{
	
}

void ForgVisualLib::FrgVisual_Scene2D_TItem::FormTItem()
{
	theScene_ = new FrgVisual_Scene2D(GetParentMainWindow());
	dynamic_cast<FrgVisual_Scene2D*>(theScene_)->Init();

	FrgVisual_Scene_TItem::FormTItem();
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Scene2D_TItem)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_Scene_TItem<2>>(*this);

	/*FrgVisual_Scene2D* myScene = dynamic_cast<FrgVisual_Scene2D*>(theScene_);
	ar & myScene;*/
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Scene2D_TItem)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_Scene_TItem<2>>(*this);

	/*FrgVisual_Scene2D* myScene;

	ar & myScene;

	theScene_ = myScene;*/
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Scene2D_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Scene2D_TItem)
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Scene2D_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Scene2D_TItem)
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Scene2D_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_Scene2D_TItem)