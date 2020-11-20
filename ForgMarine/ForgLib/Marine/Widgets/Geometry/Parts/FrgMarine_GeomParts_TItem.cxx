#include <FrgMarine_GeomParts_TItem.hxx>
#include <FrgMarine_GeomPart_TItem.hxx>
#include <FrgMarine_Tree.hxx>

#include <QtWidgets/QTreeWidgetItemIterator>

ForgMarineLib::FrgMarine_GeomParts_TItem::FrgMarine_GeomParts_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{

}

void ForgMarineLib::FrgMarine_GeomParts_TItem::FormTItem()
{
	ForgBaseLib::FrgBase_TreeItem::FormTItem();
}

DECLARE_SAVE_IMP(ForgMarineLib::FrgMarine_GeomParts_TItem)
{
	QTreeWidgetItemIterator it((QTreeWidgetItem*)this);

	std::vector<FrgMarine_GeomPart_TItem*> myTItems;
	while (*it)
	{
		auto myTItem = dynamic_cast<FrgMarine_GeomPart_TItem*>(*it);
		if (myTItem)
			myTItems.push_back(myTItem);

		++it;
	}

	ar& myTItems;
}

DECLARE_LOAD_IMP(ForgMarineLib::FrgMarine_GeomParts_TItem)
{
	std::vector<FrgMarine_GeomPart_TItem*> myTItems;

	ar& myTItems;
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_GeomParts_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_GeomParts_TItem);
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_GeomParts_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_GeomParts_TItem);
}

BOOST_CLASS_EXPORT_CXX(ForgMarineLib::FrgMarine_GeomParts_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgMarineLib::FrgMarine_GeomParts_TItem)