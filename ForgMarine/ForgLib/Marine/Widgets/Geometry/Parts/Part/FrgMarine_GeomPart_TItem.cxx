#include <FrgMarine_GeomPart_TItem.hxx>
#include <FrgMarine_Tree.hxx>

ForgMarineLib::FrgMarine_GeomPart_TItem::FrgMarine_GeomPart_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	this->AddRenameOptionInContextMenu();
	this->AddDeleteOptionInContextMenu();
}

void ForgMarineLib::FrgMarine_GeomPart_TItem::FormTItem()
{
	ForgBaseLib::FrgBase_TreeItem::FormTItem();
}

DECLARE_SAVE_IMP(ForgMarineLib::FrgMarine_GeomPart_TItem)
{

}

DECLARE_LOAD_IMP(ForgMarineLib::FrgMarine_GeomPart_TItem)
{

}

DECLARE_SAVE_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPart_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_GeomPart_TItem);
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPart_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_GeomPart_TItem);
}

BOOST_CLASS_EXPORT_CXX(ForgMarineLib::FrgMarine_GeomPart_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPart_TItem)