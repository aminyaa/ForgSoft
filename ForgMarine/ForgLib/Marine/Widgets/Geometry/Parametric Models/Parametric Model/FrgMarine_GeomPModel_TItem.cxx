#include <FrgMarine_GeomPModel_TItem.hxx>
#include <FrgBase_Menu.hxx>

#include <FrgMarine_Tree.hxx>

ForgMarineLib::FrgMarine_GeomPModel_TItem::FrgMarine_GeomPModel_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	this->AddRenameOptionInContextMenu();
	this->AddDeleteOptionInContextMenu();

	GetContextMenu()->addSeparator();
	auto createPartAction = this->GetContextMenu()->AddItem("Create Part From Model", false);
	this->GetContextMenu()->SetToolBarHidden(true);

	connect(createPartAction, SIGNAL(triggered()), this, SLOT(CreatePartFromModelSlot()));
}

ForgMarineLib::FrgMarine_GeomPModel_TItem::~FrgMarine_GeomPModel_TItem()
{

}

void ForgMarineLib::FrgMarine_GeomPModel_TItem::CreatePartFromModelSlot()
{

}

DECLARE_SAVE_IMP(ForgMarineLib::FrgMarine_GeomPModel_TItem)
{

}

DECLARE_LOAD_IMP(ForgMarineLib::FrgMarine_GeomPModel_TItem)
{

}

DECLARE_SAVE_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPModel_TItem)
{
	//SAVE_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_GeomPModel_TItem)
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPModel_TItem)
{
	//LOAD_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_GeomPModel_TItem)
}

BOOST_CLASS_EXPORT_CXX(ForgMarineLib::FrgMarine_GeomPModel_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPModel_TItem)