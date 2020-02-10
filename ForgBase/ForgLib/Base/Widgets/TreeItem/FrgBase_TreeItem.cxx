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
	theTItemName_ = new FrgBase_PrptsVrntString("Name", itemTitle);

	this->setText(0, theTItemName_->GetValue());
	this->setIcon(0, QIcon(ICON_Menu_File_Load));
	this->setObjectName(itemTitle);

	theContextMenu_ = FrgNew FrgBase_Menu(itemTitle, theParentMainWindow_, FrgTrue);
	theContextMenu_->GetToolBar()->setHidden(FrgTrue);

	QObject::connect(this, SIGNAL(TItemNameChanged(const QString&)), theContextMenu_, SLOT(MenuTitleChangedSlot(const QString&)));
	connect(theTItemName_, SIGNAL(ValueChangedSignal(const QString&)), this, SLOT(RenameTItemSlot(const QString&)));

	if (parentItem)
	{
		parentItem->addChild(this);
	}
	else
		if (!parentTree)
		{
			std::cout << "parentTree is null in FrgBase_TreeItem::FrgBase_TreeItem(...)\n";
			return;
		}
		else
			parentTree->addTopLevelItem(this);

	//thePropertiesPanel_ = new FrgBase_PropertiesPanel(GetParentMainWindow(), this);

	/*QObject::connect
	(
		this,
		SIGNAL(objectNameChanged(const QString &)),
		this,
		SLOT(objectNameChangedSlot(const QString &))
	);*/
}

//void ForgBaseLib::FrgBase_TreeItem::UpdateObject()
//{
//
//}

void ForgBaseLib::FrgBase_TreeItem::SetTItemName(const QString& name)
{
	FrgString str = name;
	str = str.simplified();

	if (str == "")
		return;

	if (this->text(0) != str)
	{
		if (QTreeWidgetItem::parent())
		{
			while (IsSameNameTItem(str))
				str += " (Copy)";
		}

		this->setObjectName(str);
		theTItemName_->SetValue(str);
		this->setText(0, str);

		emit TItemNameChanged(theTItemName_->GetValue());
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

	for (int iItem = 0; iItem < listOfItems.size(); iItem++)
	{
		if (listOfItems[iItem]->text(0) == str)
			return listOfItems[iItem];
	}

	return NullPtr;
}

bool ForgBaseLib::FrgBase_TreeItem::IsSameNameTItem(const QString & name)
{
	if (dynamic_cast<FrgBase_TreeItem*>(QTreeWidgetItem::parent())->GetChild(name))
		return true;

	return false;
}

void ForgBaseLib::FrgBase_TreeItem::RenameTItemSlot()
{
	std::shared_ptr<FrgBase_DlgRenameTItem> dlg = std::make_shared<FrgBase_DlgRenameTItem>(this->text(0), theParentMainWindow_);

	if (dlg->exec() == FrgBase_DlgRenameTItem::Accepted)
	{
		SetTItemName(dlg->GetLineEditName());
	}
}

void ForgBaseLib::FrgBase_TreeItem::RenameTItemSlot(const QString & name)
{
	if (sender() == theTItemName_)
		theTItemName_->blockSignals(true);

	SetTItemName(name);

	if (sender() == theTItemName_)
		theTItemName_->blockSignals(false);
}

void ForgBaseLib::FrgBase_TreeItem::AddRenameOptionInContextMenu()
{
	auto action = theContextMenu_->AddItem("Rename", FrgFalse);
	QObject::connect(action, SIGNAL(triggered()), this, SLOT(RenameTItemSlot()));
}