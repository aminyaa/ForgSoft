#include <FrgMarine_GeomPModelShip_TItem.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_Tree.hxx>

ForgMarineLib::FrgMarine_GeomPModelShip_TItem::FrgMarine_GeomPModelShip_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgMarine_GeomPModel_TItem(itemTitle, parentItem, parentTree)
{
	this->setIcon(0, QIcon(ICON_Menu_Models_Ship));
}

void ForgMarineLib::FrgMarine_GeomPModelShip_TItem::FormTItem()
{
	ForgMarineLib::FrgMarine_GeomPModel_TItem::FormTItem();
}

DECLARE_SAVE_IMP(ForgMarineLib::FrgMarine_GeomPModelShip_TItem)
{

}

DECLARE_LOAD_IMP(ForgMarineLib::FrgMarine_GeomPModelShip_TItem)
{

}

DECLARE_SAVE_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPModelShip_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_GeomPModelShip_TItem);
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPModelShip_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_GeomPModelShip_TItem);
}

BOOST_CLASS_EXPORT_CXX(ForgMarineLib::FrgMarine_GeomPModelShip_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPModelShip_TItem)