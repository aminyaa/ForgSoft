#include <FrgBase_Tree.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_DlgDelete.hxx>

#include <FrgBase_Serialization_IO.hxx>

#include <QtWidgets/QHeaderView>
#include <QtGui/QKeyEvent>
#include <QtWidgets/QTreeWidgetItemIterator>

#include <chaiscript.hpp>

ForgBaseLib::FrgBase_Tree::FrgBase_Tree
(
	FrgBase_MainWindow* parentMainWindow
)
	: QTreeWidget(parentMainWindow)
	, theParentMainWindow_(parentMainWindow)
{
	this->setColumnCount(1);
	//this->setHeaderLabel(tr("Simulation"));
	this->setHeaderLabel(tr(""));
	this->header()->setSectionResizeMode(0, QHeaderView::Interactive);
	this->setSelectionMode(QAbstractItemView::ExtendedSelection);

	this->setContextMenuPolicy(Qt::CustomContextMenu);
	this->setFocusPolicy(Qt::StrongFocus);

	QObject::connect(this, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(itemClickedSlot(QTreeWidgetItem*, int)));
	QObject::connect(this, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(itemDoubleClickedSlot(QTreeWidgetItem*, int)));

	connect(this,
		SIGNAL(customContextMenuRequested(const QPoint&)),
		SLOT(onCustomContextMenuRequested(const QPoint&)));

	this->setExpandsOnDoubleClick(false);
}

ForgBaseLib::FrgBase_Tree::~FrgBase_Tree()
{
	theParentMainWindow_ = NullPtr;

	this->deleteLater();
}

void ForgBaseLib::FrgBase_Tree::FormTree()
{

}

void ForgBaseLib::FrgBase_Tree::keyPressEvent
(
	QKeyEvent* event
)
{
	QTreeWidget::keyPressEvent(event);
	switch (event->key())
	{
	case Qt::Key_Up:
	case Qt::Key_Down:
	case Qt::Key_Left:
	case Qt::Key_Right:
	case Qt::Key_Home:
	case Qt::Key_End:
	case Qt::Key_PageUp:
	case Qt::Key_PageDown:
		if (currentItem())
		{
			emit QTreeWidget::itemClicked(currentItem(), 0);
		}
		break;
	case Qt::Key_F2:
		if (this->selectedItems().size() == 1)
		{
			FrgBase_TreeItem* TItem = dynamic_cast<FrgBase_TreeItem*>(this->selectedItems()[0]);
			if (TItem)
			{
				auto rAction =
					TItem->GetRenameAction();

				if (rAction)
				{
					if (rAction->isEnabled())
					{
						if (!TItem->CanRenameUsingLock())
						{
							const QString message =
								"Cannot rename \"" + TItem->text(0) + "\" because it is locked.";

							GetParentMainWindow()->PrintWarningToConsole(message);
						}
						else
							TItem->RenameTItemSlot();
					}
				}
			}
		}
		break;
	case Qt::Key_Return:
	case Qt::Key_Enter:
	case Qt::Key_Space:
		if (this->selectedItems().size() == 1)
		{
			QTreeWidgetItem* TItem = this->selectedItems()[0];
			if (this->isItemExpanded(TItem))
				this->collapseItem(TItem);
			else
				this->expandItem(TItem);

			this->itemDoubleClickedSlot(this->selectedItems()[0], 0);
		}
		break;
	case Qt::Key_Delete:
		if (this->selectedItems().size() == 1)
		{
			FrgBase_TreeItem* TItem = dynamic_cast<FrgBase_TreeItem*>(this->selectedItems()[0]);
			if (TItem)
			{
				auto dAction = TItem->GetDeleteAction();

				if (dAction)
				{
					if (dAction->isEnabled())
					{
						if (!TItem->CanDeleteUsingLock())
						{
							const QString message =
								"Cannot delete \"" + TItem->text(0) + "\" because it is locked.";

							GetParentMainWindow()->PrintWarningToConsole(message);
						}
						else
							DeleteTreeItemSlot(TItem);
					}
				}
			}
		}
		break;
	default:
		QTreeWidget::keyPressEvent(event);
	}
}

void ForgBaseLib::FrgBase_Tree::itemClickedSlot
(
	QTreeWidgetItem* item,
	int column
)
{
	theLastLeftClickedTItem_ = dynamic_cast<FrgBase_TreeItem*>(item);
	if (theLastLeftClickedTItem_)
	{
		auto panel =
			theLastLeftClickedTItem_->GetPropertiesPanel();

		const auto condition =
			theLastLeftClickedTItem_->CanShowPPanelUsingLock();

		panel->setEnabled(condition);

		theParentMainWindow_->SetPropertiesPanel
		(
			panel
		);
	}

	FrgBase_TreeItem* TItem = dynamic_cast<FrgBase_TreeItem*>(item);
	if (TItem)
	{
		QTreeWidgetItemIterator it(this);
		while (*it)
		{
			FrgBase_TreeItem* TItemFromIT = dynamic_cast<FrgBase_TreeItem*>((*it));
			if (TItemFromIT)
			{
				TItemFromIT->TItemNotClickedSlot();
			}
			++it;
		}

		TItem->TItemClickedSlot();
	}
}

void ForgBaseLib::FrgBase_Tree::itemDoubleClickedSlot
(
	QTreeWidgetItem* item,
	int column
)
{
	theLastLeftClickedTItem_ = dynamic_cast<FrgBase_TreeItem*>(item);
	if (theLastLeftClickedTItem_)
		theLastLeftClickedTItem_->TItemDoubleClickedSlot();
}

void ForgBaseLib::FrgBase_Tree::onCustomContextMenuRequested
(
	const QPoint& pos
)
{
	FrgBase_TreeItem* item = dynamic_cast<FrgBase_TreeItem*>(this->itemAt(pos));

	if (item)
	{
		emit itemClicked(item, 0);

		showContextMenu(item, this->viewport()->mapToGlobal(pos));
	}
}

void ForgBaseLib::FrgBase_Tree::showContextMenu
(
	FrgBase_TreeItem* item,
	const QPoint& globalPos
)
{
	if (item)
	{
		theLastRightClickedTItem_ = item;
		if (!item->CanShowContextMenuUsingLock())
		{
			const QString message =
				"\"" + item->text(0) + "\" is locked.";

			GetParentMainWindow()->PrintWarningToConsole(message);
		}
		else if (item->GetContextMenu())
		{
			item->GetContextMenu()->Execute(globalPos);

			/*if (item->GetContextMenu()->HasTitleAsAnAction())
			{
				if (item->GetContextMenu()->actions().size() > 2)
					item->GetContextMenu()->exec(globalPos);
			}
			else
			{
				if (item->GetContextMenu()->actions().size() > 0)
					item->GetContextMenu()->exec(globalPos);
			}*/
		}

	}
}

void ForgBaseLib::FrgBase_Tree::DeleteTreeItemSlot(FrgBase_TreeItem* TItem)
{
	if (TItem)
	{
		if (!TItem->CanDeleteUsingLock())
		{
			const QString message =
				"Cannot delete \"" + TItem->text(0) + "\" because it is locked.";

			GetParentMainWindow()->PrintWarningToConsole(message);
			return;
		}

		std::shared_ptr<FrgBase_DlgDelete> deleteDlg = std::make_shared<FrgBase_DlgDelete>(TItem->text(0), GetParentMainWindow());

		if (deleteDlg->exec() == QDialog::Accepted)
		{
			const auto& parentItem = TItem->GetParentTItem();
			try
			{
				const auto b = TItem->IsDeletable();

				if (!b)
				{
					std::string message =
						"Cannot delete \"" + TItem->text(0).toStdString() + "\"";

					throw std::exception(message.c_str());
				}

				emit TItem->TItemIsGoingToBeDeleted();

				delete TItem;
			}
			catch (const std::exception& myException)
			{
				if (GetParentMainWindow())
					GetParentMainWindow()->PrintErrorToConsole(QString(myException.what()));

				return;
			}

			ChildTItemDeletedSignal(parentItem);

			//ScrollToItem(parentItem);
		}
	}
}

void ForgBaseLib::FrgBase_Tree::DeleteTreeItemSlot()
{
	const auto TItem = dynamic_cast<FrgBase_TreeItem*>(sender());
	DeleteTreeItemSlot(TItem);
}

void ForgBaseLib::FrgBase_Tree::ScrollToItem
(
	FrgBase_TreeItem* item
)
{
	if (item)
	{
		clearSelection();
		scrollToItem(item);
		setItemSelected(item, true);
		this->setCurrentItem(item);

		emit itemClickedSlot(item, 0);

		setFocus();
	}
}

void ForgBaseLib::FrgBase_Tree::ScrollToItems
(
	QList<FrgBase_TreeItem*> items
)
{
	if (items.isEmpty())
		return;

	clearSelection();
	for (int i = 0; i < items.size(); i++)
		setItemSelected(items[i], true);

	scrollToItem(items.last());
	itemClickedSlot(items.last(), 0);

	setFocus();
}

ForgBaseLib::FrgBase_TreeItem* ForgBaseLib::FrgBase_Tree::FindTItemByObjectName(const QString& objectName)
{
	QTreeWidgetItemIterator it(this);
	while (*it)
	{
		const auto myTItem = dynamic_cast<FrgBase_TreeItem*>(*it);

		if (!myTItem)
		{
			std::cout << "myTItem is null in ForgBaseLib::FrgBase_TreeItem * ForgBaseLib::FrgBase_Tree::FindTItemByObjectName(const QString & objectName)\n";
			return nullptr;
		}

		if (myTItem->objectName() == objectName)
			return myTItem;

		++it;
	}

	return nullptr;
}

std::vector<ForgBaseLib::FrgBase_TreeItem*>
ForgBaseLib::FrgBase_Tree::GetAllItems() const
{
	std::vector<FrgBase_TreeItem*> result;
	QTreeWidgetItemIterator it(const_cast<FrgBase_Tree*>(this));
	while (*it)
	{
		const auto myTItem = dynamic_cast<FrgBase_TreeItem*>(*it);

		if (myTItem)
			result.push_back(myTItem);

		++it;
	}

	return result;
}

std::vector<ForgBaseLib::FrgBase_TreeItem*> ForgBaseLib::FrgBase_Tree::GetItemsUsingLevel(int level) const
{
	std::vector<FrgBase_TreeItem*> result;

	auto allItems = GetAllItems();
	for (auto item : allItems)
	{
		if (item && item->GetLevelInTree() == level)
			result.push_back(item);
	}

	return result;
}

void ForgBaseLib::FrgBase_Tree::SetThemeDark
(
	const bool isDark
)
{
	auto items = GetAllItems();
	for (auto item : items)
		item->SetThemeDark(isDark);
}

void ForgBaseLib::FrgBase_Tree::dropEvent(QDropEvent* event)
{
	QModelIndex droppedIndex = indexAt(event->pos());

	if (!droppedIndex.isValid() || theDraggedTItems_.empty())
		return;

	auto droppedItem = dynamic_cast<ForgBaseLib::FrgBase_TreeItem*>(itemFromIndex(droppedIndex));
	if (droppedItem)
	{
		for (auto theDraggedTItem_ : theDraggedTItems_)
		{
			if (theDraggedTItem_->QTreeWidgetItem::parent() == droppedItem)
				continue;

			if (!droppedItem->IsDroppable() || !droppedItem->CanDropTo(theDraggedTItem_))
			{
				theDraggedTItem_ = nullptr;
				continue;
			}

			auto chlds = droppedItem->GetAllChildrenToTheRoot();
			for (auto ch : chlds)
			{
				if (ch->GetTItemName()->GetValue() == theDraggedTItem_->GetTItemName()->GetValue())
				{
					theDraggedTItem_->RenameTItemSlot(CorrectName(droppedItem, theDraggedTItem_->GetTItemName()->GetValue()));
					break;
				}
			}

			theDraggedTItem_->QTreeWidgetItem::parent()->removeChild(theDraggedTItem_);
			droppedItem->insertChild(0, theDraggedTItem_);

			theDraggedTItem_->SetLevelInTree(theDraggedTItem_->GetParentTItem()->GetLevelInTree() + 1);
		}

		droppedItem->setExpanded(true);

		if (droppedItem->IsTItemSortable())
			droppedItem->SortTItem();

		ScrollToItem(theDraggedTItems_[0]);
	}

	//QTreeWidget::dropEvent(event);
}

void ForgBaseLib::FrgBase_Tree::dragEnterEvent(QDragEnterEvent* event)
{
	theDraggedTItems_.clear();

	auto sls = this->selectedItems();
	for (auto sl : sls)
		theDraggedTItems_.push_back(dynamic_cast<ForgBaseLib::FrgBase_TreeItem*>(sl));

	if (!theDraggedTItems_.empty())
	{
		for (auto theDraggedTItem_ : theDraggedTItems_)
		{
			if (theDraggedTItem_)
			{
				if (!theDraggedTItem_->IsDraggable())
				{
					theDraggedTItem_ = nullptr;
					return;
				}
			}
			else
				return;
		}
	}

	QTreeWidget::dragEnterEvent(event);
}

void ForgBaseLib::FrgBase_Tree::dragMoveEvent(QDragMoveEvent* event)
{
	this->setDropIndicatorShown(true);
	QTreeWidget::dragMoveEvent(event);

	if (this->dropIndicatorPosition() == QAbstractItemView::OnItem)
		this->setDropIndicatorShown(true);
	else
		this->setDropIndicatorShown(false);

	this->viewport()->update();
}

void ForgBaseLib::FrgBase_Tree::SetParentMainWindow(FrgBase_MainWindow* parentMainWindow)
{
	if (parentMainWindow == theParentMainWindow_)
		return;

	theParentMainWindow_ = parentMainWindow;

	QTreeWidgetItemIterator it((QTreeWidget*)this);
	while (*it)
	{
		ForgBaseLib::FrgBase_TreeItem* myTItem = dynamic_cast<ForgBaseLib::FrgBase_TreeItem*>(*it);

		if (myTItem)
			myTItem->SetParentMainWindow(theParentMainWindow_);

		++it;
	}
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_Tree)
{

}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_Tree)
{

}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_Tree)