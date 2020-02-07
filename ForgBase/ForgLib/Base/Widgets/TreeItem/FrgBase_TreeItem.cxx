#include <FrgBase_TreeItem.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgBase_Tree.hxx>
#include <FrgBase_DlgRenameTItem.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgBase_Global_Icons.hxx>

#include <QtWidgets/QToolBar>
#include <QtCore/QMetaProperty>

ForgBaseLib::FrgBase_TreeItem::FrgBase_TreeItem
(
	const FrgString & itemTitle,
	FrgBase_TreeItem * parentItem,
	FrgBase_Tree * parentTree
)
	: QTreeWidgetItem(parentItem)
	, theParentTree_(parentTree)
	, theParentMainWindow_(theParentTree_->GetParentMainWindow())
{
	this->setText(0, itemTitle);
	this->setIcon(0, QIcon(ICON_Menu_File_Load));
	this->setObjectName(itemTitle);

	theContextMenu_ = FrgNew FrgBase_Menu(itemTitle, theParentMainWindow_, FrgTrue);
	theContextMenu_->GetToolBar()->setHidden(FrgTrue);

	if (parentItem)
	{
		parentItem->addChild(this);
		auto action = theContextMenu_->AddItem("Rename", FrgFalse);
		//action->setEnabled(FrgFalse);

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

	thePropertiesPanel_ = new FrgBase_PropertiesPanel(GetParentMainWindow(), this);
}

//void ForgBaseLib::FrgBase_TreeItem::UpdateObject()
//{
//
//}

QString ForgBaseLib::FrgBase_TreeItem::GetTItemName() const
{
	return objectName();
}

void ForgBaseLib::FrgBase_TreeItem::SetTItemName(const QString& name)
{
	FrgString str = name;
	str = str.simplified();

	if (objectName() != str)
	{
		if (QTreeWidgetItem::parent())
		{
			while (GetChild(str))
				str += " (Copy)";
		}

		this->setObjectName(str);
		this->setText(0, objectName());

		emit TItemNameChanged(objectName());
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