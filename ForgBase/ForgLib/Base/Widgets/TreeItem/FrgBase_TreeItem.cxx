#include <FrgBase_TreeItem.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgBase_MenuAction.hxx>
#include <FrgBase_Tree.hxx>
#include <FrgBase_DlgRename.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_Icon.hxx>
#include <FrgBase_Tree.hxx>

#include <QtCore/QMetaProperty>
#include <QtCore/QObject>
#include <QtCore/QCollator>

#include <nlohmann/json.hpp>

ForgBaseLib::FrgBase_TreeItem::FrgBase_TreeItem
(
	const FrgString& itemTitle,
	FrgBase_TreeItem* parentItem,
	FrgBase_Tree* parentTree
)
	: QTreeWidgetItem(parentItem)
{
	ConstructTItem(itemTitle, parentItem, parentTree);

	/*if (parentTree)
		if (parentTree->GetParentMainWindow())
			parentTree->GetParentMainWindow()->ProgramModifiedSlot(true);*/

	theTItemIsSortable_ = false;
	theTItemIsDeletable_ = true;
	theTItemIsDraggable_ = false;
	theTItemIsDroppable_ = false;

	theRenameAction_ = theContextMenu_->AddItem("Rename", false);
	theDeleteAction_ = theContextMenu_->AddItem(QIcon(ICON_Menu_Edit_Delete), "Delete", false);

	connect
	(
		theRenameAction_,
		SIGNAL(ClickedSignal()),
		this,
		SLOT(RenameTItemSlot())
	);

	connect
	(
		theDeleteAction_,
		&FrgBase_MenuAction::ClickedSignal,
		this,
		&FrgBase_TreeItem::DeleteTItemCalled
	);

	theRenameAction_->SetHidden(true);
	theDeleteAction_->SetHidden(true);
}

ForgBaseLib::FrgBase_TreeItem::~FrgBase_TreeItem()
{
	theParentTree_ = NullPtr;
	theParentMainWindow_ = NullPtr;

	theContextMenu_->deleteLater();
	FreePointer(thePropertiesPanel_);
	//FreePointer(theTItemName_);
}

void ForgBaseLib::FrgBase_TreeItem::SetParentMainWindow
(
	ForgBaseLib::FrgBase_MainWindow* parentMainWindow
)
{
	theParentMainWindow_ = parentMainWindow;

	thePropertiesPanel_->SetParentWidget(parentMainWindow);
	thePropertiesPanel_->SetParentObject(this);
}

void ForgBaseLib::FrgBase_TreeItem::SetParentTree
(
	FrgBase_Tree* parentTree
)
{
	theParentTree_ = parentTree;

	const auto& children = GetChildren();
	for (const auto& child : children)
		child->SetParentTree(theParentTree_);
}

void ForgBaseLib::FrgBase_TreeItem::SetParentTItem
(
	FrgBase_TreeItem* parentTItem,
	bool renameTItem
)
{
	if (!parentTItem)
		return;

	const auto& myParentTItem = GetParentTItem();
	if (myParentTItem)
		myParentTItem->removeChild(this);

	this->SetParentMainWindow(parentTItem->GetParentMainWindow());
	parentTItem->addChild(this);
	SetParentTree(parentTItem->GetParentTree());
	this->setParent(parentTItem);
	this->SetLevelInTree(parentTItem->GetLevelInTree() + 1);

	if (renameTItem)
	{
		QString n = text(0);
		this->RenameTItemSlot("___tmp" + n + "tmp___");
		this->RenameTItemSlot(n);
	}

	parentTItem->SortTItem();

	const auto& childrenItems = GetAllChildrenToTheRoot();
	for (const auto& childItem : childrenItems)
		childItem->SetParentMainWindow(theParentMainWindow_);
}

bool ForgBaseLib::FrgBase_TreeItem::IsThemeDark() const
{
	if (theParentMainWindow_)
		return theParentMainWindow_->IsThemeDark();

	return false;
}

ForgBaseLib::FrgBase_TreeItem*
ForgBaseLib::FrgBase_TreeItem::GetParentTItem() const
{
	return dynamic_cast<FrgBase_TreeItem*>(this->QTreeWidgetItem::parent());
}

void ForgBaseLib::FrgBase_TreeItem::ConstructTItem
(
	const FrgString& itemTitle,
	FrgBase_TreeItem* parentItem,
	FrgBase_Tree* parentTree
)
{
	theParentTree_ = parentTree;
	if(parentTree)
		theParentMainWindow_ = parentTree->GetParentMainWindow();

	//this->setIcon(0, QIcon(ICON_Menu_File_Load));
	this->SetIcon(0, FrgBase_Icon(ICON_Menu_File_Load, true));

	theTItemName_ = new FrgBase_PrptsVrntString("Name", "");
	RenameTItemSlot(itemTitle);

	theContextMenu_ = FrgNew FrgBase_Menu(theTItemName_->GetValue(), theParentMainWindow_, false);
	theContextMenu_->SetToolBarHidden(true);

	connect
	(
		this,
		SIGNAL(TItemNameChanged(const QString&)),
		theContextMenu_,
		SLOT(MenuTitleChangedSlot(const QString&))
	);

	connect
	(
		theTItemName_,
		SIGNAL(ValueChangedSignal(const QString&)),
		this,
		SLOT(RenameTItemSlot(const QString&))
	);

	connect
	(
		this,
		SIGNAL(DeleteTItemCalled()),
		GetParentTree(),
		SLOT(DeleteTreeItemSlot())
	);

	if (parentItem)
	{
		parentItem->addChild(this);

		this->setObjectName(parentItem->objectName() + "_" + itemTitle);

		theLevelInTree_ = parentItem->GetLevelInTree() + 1;
	}
	else
		if (!parentTree)
		{
			std::cout << "parentTree is null in FrgBase_TreeItem::FrgBase_TreeItem(...)\n";
			return;
		}
		else
		{
			parentTree->addTopLevelItem(this);
			this->setObjectName(itemTitle);

			theLevelInTree_ = 0;
		}

	FormPropertiesPanel();
	thePropertiesPanel_->AddRow<FrgBase_PrptsVrntString>(theTItemName_);
}

void ForgBaseLib::FrgBase_TreeItem::FormTItem()
{
	auto myParent = dynamic_cast<FrgBase_TreeItem*>(QTreeWidgetItem::parent());
	if (myParent)
	{
		if (myParent->IsTItemSortable())
			myParent->SortTItem();
	}
}

bool ForgBaseLib::FrgBase_TreeItem::IsMyParent
(
	FrgBase_TreeItem* p,
	bool recursive
) const
{
	FrgBase_TreeItem* par =
		dynamic_cast<FrgBase_TreeItem*>(QTreeWidgetItem::parent());

	if (par)
	{
		if (recursive)
		{
			while (par)
			{
				if (par == p)
					return true;

				par = dynamic_cast<FrgBase_TreeItem*>(par->QTreeWidgetItem::parent());
			}
		}
		else
		{
			if (par == p)
				return true;
		}
	}

	return false;
}

void ForgBaseLib::FrgBase_TreeItem::SetIcon
(
	int column,
	const FrgBase_Icon& icon
)
{
	this->setIcon(column, icon);

	FreePointer(theIcon_);

	theIcon_ = new FrgBase_Icon(icon);
}

bool ForgBaseLib::FrgBase_TreeItem::CanRenameUsingLock() const
{
	auto condition =
		theLockType_ == LockType::Rename ||
		theLockType_ == LockType::RenameAndDelete ||
		theLockType_ == LockType::RenameAndPPanel ||
		theLockType_ == LockType::RenameAndDeleteAndPPanel ||
		theLockType_ == LockType::ContextMenuAndRename ||
		theLockType_ == LockType::ContextMenuAndRenameAndDelete ||
		theLockType_ == LockType::ContextMenuAndRenameAndPPanel ||
		theLockType_ == LockType::ContextMenuAndRenameAndDeleteAndPPanel ||
		theLockType_ == LockType::Full;

	return !condition;
}

bool ForgBaseLib::FrgBase_TreeItem::CanDeleteUsingLock() const
{
	auto condition =
		theLockType_ == LockType::Delete ||
		theLockType_ == LockType::DeleteAndPPanel ||
		theLockType_ == LockType::RenameAndDelete ||
		theLockType_ == LockType::RenameAndDeleteAndPPanel ||
		theLockType_ == LockType::ContextMenuAndDelete ||
		theLockType_ == LockType::ContextMenuAndRenameAndDelete ||
		theLockType_ == LockType::ContextMenuAndDeleteAndPPanel ||
		theLockType_ == LockType::ContextMenuAndRenameAndDeleteAndPPanel ||
		theLockType_ == LockType::Full;

	return !condition;
}

bool ForgBaseLib::FrgBase_TreeItem::CanShowPPanelUsingLock() const
{
	auto condition =
		theLockType_ == LockType::PPanel ||
		theLockType_ == LockType::RenameAndPPanel ||
		theLockType_ == LockType::DeleteAndPPanel ||
		theLockType_ == LockType::RenameAndDeleteAndPPanel ||
		theLockType_ == LockType::ContextMenuAndPPanel ||
		theLockType_ == LockType::ContextMenuAndRenameAndPPanel ||
		theLockType_ == LockType::ContextMenuAndDeleteAndPPanel ||
		theLockType_ == LockType::ContextMenuAndRenameAndDeleteAndPPanel ||
		theLockType_ == LockType::Full;

	return !condition;
}

bool ForgBaseLib::FrgBase_TreeItem::CanShowContextMenuUsingLock() const
{
	auto condition =
		theLockType_ == LockType::ContextMenu ||
		theLockType_ == LockType::ContextMenuAndRename ||
		theLockType_ == LockType::ContextMenuAndDelete ||
		theLockType_ == LockType::ContextMenuAndRenameAndDelete ||
		theLockType_ == LockType::ContextMenuAndPPanel ||
		theLockType_ == LockType::ContextMenuAndRenameAndPPanel ||
		theLockType_ == LockType::ContextMenuAndDeleteAndPPanel ||
		theLockType_ == LockType::ContextMenuAndRenameAndDeleteAndPPanel ||
		theLockType_ == LockType::Full;

	return !condition;
}

bool ForgBaseLib::FrgBase_TreeItem::HasParentTItemNullTree() const
{
	if (GetParentTItem())
	{
		if (!GetParentTItem()->GetParentTree())
			return true;

		return false;
	}

	return false;
}

nlohmann::json ForgBaseLib::FrgBase_TreeItem::ToJSON() const
{
	nlohmann::json j;

	j["Index"] = GetIndex();
	j["Name"] = GetName();
	j["TItemIsClickable"] = theTItemIsClickable_;
	j["TItemIsSortable"] = theTItemIsSortable_;
	j["TItemIsDraggable"] = theTItemIsDraggable_;
	j["TItemIsDroppable"] = theTItemIsDroppable_;
	j["LockType"] = theLockType_;
	j["LevelInTree"] = theLevelInTree_;
	j["Icon"] = theIcon_ ? theIcon_->GetFileAddress().toStdString() : nullptr;

	return j;
}

void ForgBaseLib::FrgBase_TreeItem::SortTItem
(
	Qt::SortOrder sortOrder_
)
{
	if (theTItemIsSortable_)
	{
		this->sortChildren(0, sortOrder_);
	}
}

void ForgBaseLib::FrgBase_TreeItem::SetTItemName
(
	const QString& name,
	bool sortParentTItem
)
{
	FrgString str = name;
	str = str.simplified();

	if (str == "")
		return;

	if (this->text(0) != str)
	{
		if (QTreeWidgetItem::parent())
		{
			this->setText(0, "___tempName___");
			str = CorrectName(QTreeWidgetItem::parent(), name);
		}

		/*if (QTreeWidgetItem::parent())
		{
			while (IsSameNameTItem(str))
				str += " (Copy)";
		}*/

		this->setObjectName(str);
		theTItemName_->SetValue(str);
		this->setText(0, str);

		emit TItemNameChanged(theTItemName_->GetValue());

		if (sortParentTItem)
		{
			auto myParent =
				dynamic_cast<FrgBase_TreeItem*>(QTreeWidgetItem::parent());

			if (myParent)
			{
				if (myParent->IsTItemSortable())
					myParent->SortTItem();
			}
		}
	}
}

bool ForgBaseLib::FrgBase_TreeItem::operator<
	(
		const QTreeWidgetItem& other
		) const
{
	QCollator collator;
	collator.setNumericMode(true);
	return collator.compare(text(0), other.text(0)) < 0;
}

QList<ForgBaseLib::FrgBase_TreeItem*>
ForgBaseLib::FrgBase_TreeItem::GetChildren() const
{
	QList<FrgBase_TreeItem*> listOfItems;
	int nbIems = this->childCount();

	for (int iItem = 0; iItem < nbIems; iItem++)
	{
		listOfItems.push_back(dynamic_cast<FrgBase_TreeItem*>(this->child(iItem)));
	}

	return listOfItems;
}

ForgBaseLib::FrgBase_TreeItem*
ForgBaseLib::FrgBase_TreeItem::GetChild
(
	const QString& name
)
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

std::vector<ForgBaseLib::FrgBase_TreeItem*>
ForgBaseLib::FrgBase_TreeItem::GetAllChildrenToTheRoot() const
{
	std::vector<FrgBase_TreeItem*> results;

	int i = 0;
	QTreeWidgetItemIterator it((QTreeWidgetItem*)(this));
	while (*it)
	{
		bool founded = false;
		QTreeWidgetItem* itParent = (*it)->parent();
		while (itParent)
		{
			if (itParent == this)
			{
				founded = true;
				break;
			}

			itParent = itParent->parent();
		}

		if (!founded && i == 0)
		{
			++it;
			continue;
		}

		if (!founded)
			break;

		auto myTItem =
			dynamic_cast<FrgBase_TreeItem*>(*it);

		if (myTItem)
			results.push_back(myTItem);

		++it;
		i++;
	}

	return results;
}

bool ForgBaseLib::FrgBase_TreeItem::IsSameNameTItem
(
	const QString& name
)
{
	auto item =
		dynamic_cast<FrgBase_TreeItem*>(QTreeWidgetItem::parent())->GetChild(name);

	if (item)
		return true;

	return false;
}

void ForgBaseLib::FrgBase_TreeItem::RenameTItemSlot
(
	bool sortParentTItem
)
{
	if (!CanRenameUsingLock())
	{
		const QString message =
			"Cannot rename \"" + this->text(0) + "\" because it is locked.";

		GetParentMainWindow()->PrintWarningToConsole(message);
		return;
	}

	auto dlg =
		std::make_shared<FrgBase_DlgRename>
		(
			this->text(0),
			theParentMainWindow_
		);

	if (dlg->exec() == FrgBase_DlgRename::Accepted)
	{
		SetTItemName(dlg->GetLineEditName(), sortParentTItem);
	}
}

void ForgBaseLib::FrgBase_TreeItem::RenameTItemSlot
(
	const QString& name,
	bool sortParentTItem
)
{
	if (sender() == theTItemName_)
		theTItemName_->blockSignals(true);

	SetTItemName(name, sortParentTItem);

	if (sender() == theTItemName_)
		theTItemName_->blockSignals(false);
}

void ForgBaseLib::FrgBase_TreeItem::AddRenameOptionInContextMenu()
{
	theRenameAction_->SetHidden(false);
}

void ForgBaseLib::FrgBase_TreeItem::RemoveRenameOptionInContextMenu()
{
	theRenameAction_->SetHidden(true);
}

void ForgBaseLib::FrgBase_TreeItem::AddDeleteOptionInContextMenu()
{
	theDeleteAction_->SetHidden(false);
}

void ForgBaseLib::FrgBase_TreeItem::RemoveDeleteOptionInContextMenu()
{
	theDeleteAction_->SetHidden(true);
}

void ForgBaseLib::FrgBase_TreeItem::FormPropertiesPanel()
{
	if (thePropertiesPanel_)
	{
		delete thePropertiesPanel_;
		thePropertiesPanel_ = NullPtr;
	}

	thePropertiesPanel_ =
		new FrgBase_PropertiesPanel(theParentMainWindow_, this);
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_TreeItem)
{
	ar& boost::serialization::base_object<FrgBase_Object>(*this);

	ar& theTItemIsClickable_;
	ar& theTItemIsSortable_;
	ar& theTItemIsDeletable_;
	ar& theTItemIsDraggable_;
	ar& theTItemIsDroppable_;
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_TreeItem)
{
	ar& boost::serialization::base_object<FrgBase_Object>(*this);

	ar& theTItemIsClickable_;
	ar& theTItemIsSortable_;
	ar& theTItemIsDeletable_;
	ar& theTItemIsDraggable_;
	ar& theTItemIsDroppable_;
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgBaseLib::FrgBase_TreeItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgBaseLib::FrgBase_TreeItem)
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgBaseLib::FrgBase_TreeItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgBaseLib::FrgBase_TreeItem)
}

BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgBaseLib::FrgBase_TreeItem)