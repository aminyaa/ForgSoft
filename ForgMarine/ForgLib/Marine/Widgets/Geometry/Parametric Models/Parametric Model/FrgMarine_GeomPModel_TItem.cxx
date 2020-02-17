#include <FrgMarine_GeomPModel_TItem.hxx>
#include <FrgBase_Menu.hxx>

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

void ForgMarineLib::FrgMarine_GeomPModel_TItem::CreatePartFromModelSlot()
{

}