#include <FrgMarine_Scenes_TItem.hxx>

ForgMarineLib::FrgMarine_Scenes_TItem::FrgMarine_Scenes_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{

}

DECLARE_SAVE_IMP(ForgMarineLib::FrgMarine_Scenes_TItem)
{

}

DECLARE_LOAD_IMP(ForgMarineLib::FrgMarine_Scenes_TItem)
{

}

DECLARE_SAVE_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_Scenes_TItem)
{

}

DECLARE_LOAD_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_Scenes_TItem)
{

}

BOOST_CLASS_EXPORT_CXX(ForgMarineLib::FrgMarine_Scenes_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgMarineLib::FrgMarine_Scenes_TItem)