#include <FrgBase_TreeItem.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgBase_Tree.hxx>
#include <FrgBase_DlgRenameTItem.hxx>

#include <QtWidgets/QToolBar>
#include <QtCore/QMetaProperty>

ForgBaseLib::FrgBase_TreeItem::FrgBase_TreeItem
(
	const FrgString & itemTitle, FrgBase_TreeItem * parentItem, FrgBase_Tree * parentTree
)
	: QTreeWidgetItem(parentItem)
	, theParentTree_(parentTree)
{
	theContextMenu_ = FrgNew FrgBase_Menu(itemTitle, theParentMainWindow_, FrgTrue);
	theContextMenu_->GetToolBar()->setHidden(FrgTrue);

	if (parentItem)
	{
		parentItem->addChild(this);
		auto action = theContextMenu_->AddItem("Rename", FrgFalse);
		action->setEnabled(FrgFalse);

		QObject::connect(action, SIGNAL(triggered()), this, SLOT(RenameTItemSlot()));
	}
	else
		if (!parentTree)
		{
			std::cout << "parentTree is null in FrgBase_TreeItem::FrgBase_TreeItem(...)\n";
			return;
		}
		else
			parentTree->addTopLevelItem(this);
}

//void ForgBaseLib::FrgBase_TreeItem::UpdateObject()
//{
//
//}

QString ForgBaseLib::FrgBase_TreeItem::GetTItemName() const
{
	return theTItemName_;
}

void ForgBaseLib::FrgBase_TreeItem::SetTItemName(const QString& name)
{
	FrgString str = name;
	str = str.simplified();

	if (theTItemName_ != str)
	{
		if (QTreeWidgetItem::parent())
		{
			while (GetChild(str))
				str += " (Copy)";}

		theTItemName_ = str;
		this->setText(0, str);

		emit TItemNameChanged(theTItemName_);
	}
}

QList<ForgBaseLib::FrgBase_TreeItem*> ForgBaseLib::FrgBase_TreeItem::GetChildren()
{
	QList<FrgBase_TreeItem*> listOfItems;
	int nbIems = this->childCount();

	for (int iItem = 0; iItem < nbIems; iItem++)
	{
		listOfItems.push_back(dynamic_cast<FrgBase_TreeItem*>(this->child(iItem)));
	}

	return listOfItems;
}

ForgBaseLib::FrgBase_TreeItem* ForgBaseLib::FrgBase_TreeItem::GetChild(const QString& name)
{
	auto listOfItems = GetChildren();

	FrgString str = name;
	str = str.simplified();
	str.replace(" ", "");

	for (int iItem = 0; iItem < listOfItems.size(); iItem++)
	{
		if (listOfItems[iItem]->text(0) == str)
			return listOfItems[iItem];
	}

	return NullPtr;
}

void ForgBaseLib::FrgBase_TreeItem::RenameTItemSlot()
{
	std::shared_ptr<FrgBase_DlgRenameTItem> dlg = std::make_shared<FrgBase_DlgRenameTItem>(this->text(0), theParentMainWindow_);

	if (dlg->exec() == FrgBase_DlgRenameTItem::Accepted)
	{
		SetTItemName(dlg->GetLineEditName());
	}
}