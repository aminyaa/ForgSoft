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
#include <FrgBase_TreeItem.hxx>

//BOOST_CLASS_EXPORT_GUID(ForgBaseLib::FrgBase_Tree, "ForgBaseLib::FrgBase_Tree")
//BOOST_CLASS_EXPORT(ForgBaseLib::FrgBase_Tree)

ForgBaseLib::FrgBase_Tree::FrgBase_Tree
(
	FrgBase_MainWindow* parentMainWindow
)
	: QTreeWidget(parentMainWindow)
	, theParentMainWindow_(parentMainWindow)
{
	this->setColumnCount(1);
	this->setHeaderLabel(tr("Simulation"));
	this->header()->setSectionResizeMode(0, QHeaderView::Interactive);
	this->setSelectionMode(QAbstractItemView::ExtendedSelection);

	this->setContextMenuPolicy(Qt::CustomContextMenu);
	this->setFocusPolicy(Qt::StrongFocus);

	QString style = "QTreeView::branch:has-siblings:!adjoins-item {"
		"border-image:url(:/Icons/TreeStyle/stylesheet-vline.png)0;"
		"}"

		"QTreeView::branch:has-siblings:adjoins-item {"
		"    border-image: url(:/Icons/TreeStyle/stylesheet-branch-more.png) 0;"
		"}"

		"QTreeView::branch:!has-children:!has-siblings:adjoins-item {"
		"    border-image: url(:/Icons/TreeStyle/stylesheet-branch-end.png) 0;"
		"}"

		"QTreeView::branch:has-children:!has-siblings:closed,"
		"QTreeView::branch:closed:has-children:has-siblings {"
		"        border-image: none;"
		"        image: url(:/Icons/TreeStyle/User-Interface-Plus-icon.png);"
		"}"

		"QTreeView::branch:open:has-children:!has-siblings,"
		"QTreeView::branch:open:has-children:has-siblings  {"
		"        border-image: none;"
		"        image: url(:/Icons/TreeStyle/User-Interface-Minus-icon.png);"
		"}";

	this->setStyleSheet(style);

	QObject::connect(this, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(itemClickedSlot(QTreeWidgetItem*, int)));
	QObject::connect(this, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(itemDoubleClickedSlot(QTreeWidgetItem*, int)));

	connect(this,
		SIGNAL(customContextMenuRequested(const QPoint&)),
		SLOT(onCustomContextMenuRequested(const QPoint&)));
}

ForgBaseLib::FrgBase_Tree::~FrgBase_Tree()
{
	theParentMainWindow_ = NullPtr;

	this->deleteLater();
}

void ForgBaseLib::FrgBase_Tree::FormTree()
{
	auto geometryTItem = new FrgBase_TreeItem("Geometry", nullptr, this);
	new FrgBase_TreeItem("Parts", geometryTItem, this);
	new FrgBase_TreeItem("Continua", nullptr, this);
	new FrgBase_TreeItem("Regions", nullptr, this);
	new FrgBase_TreeItem("Plots", nullptr, this);
	new FrgBase_TreeItem("Scenes", nullptr, this);
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
			auto TItem = dynamic_cast<FrgBase_TreeItem*>(this->selectedItems()[0]);
			if (TItem->GetContextMenu()->GetItem("Rename"))
				if (TItem->GetContextMenu()->GetItem("Rename")->isEnabled())
					TItem->RenameTItemSlot();
		}
		break;
	case Qt::Key_Return:
	case Qt::Key_Enter:
	case Qt::Key_Space:
		if (this->selectedItems().size() == 1)
		{
			auto TItem = this->selectedItems()[0];
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
			auto TItem = dynamic_cast<FrgBase_TreeItem*>(this->selectedItems()[0]);
			if(TItem->GetContextMenu()->GetItem("Delete"))
				if(TItem->GetContextMenu()->GetItem("Delete")->isEnabled())
					DeleteTreeItemSlot(TItem);
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
		theParentMainWindow_->SetPropertiesPanel(theLastLeftClickedTItem_->GetPropertiesPanel());

	auto TItem = dynamic_cast<FrgBase_TreeItem*>(item);
	if (TItem)
	{
		QTreeWidgetItemIterator it(this);
		while (*it)
		{
			auto TItemFromIT = dynamic_cast<FrgBase_TreeItem*>((*it));
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
		if (item->GetContextMenu())
			if (item->GetContextMenu()->actions().size() > 2)
				item->GetContextMenu()->exec(globalPos);
	}
}

void ForgBaseLib::FrgBase_Tree::DeleteTreeItemSlot(FrgBase_TreeItem * TItem)
{
	if (TItem)
	{
		std::shared_ptr<FrgBase_DlgDelete> deleteDlg = std::make_shared<FrgBase_DlgDelete>(TItem->text(0), GetParentMainWindow());

		if (deleteDlg->exec() == QDialog::Accepted)
		{
			auto parentItem = dynamic_cast<FrgBase_TreeItem*>
				(dynamic_cast<QTreeWidgetItem*>(TItem) ? dynamic_cast<QTreeWidgetItem*>(TItem)->parent() : NullPtr);

			delete TItem;

			ScrollToItem(parentItem);
		}
	}
}

void ForgBaseLib::FrgBase_Tree::DeleteTreeItemSlot()
{
	auto TItem = dynamic_cast<FrgBase_TreeItem*>(sender());
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

ForgBaseLib::FrgBase_TreeItem * ForgBaseLib::FrgBase_Tree::FindTItemByObjectName(const QString & objectName)
{
	QTreeWidgetItemIterator it(this);
	while (*it)
	{
		auto myTItem = dynamic_cast<FrgBase_TreeItem*>(*it);

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

void ForgBaseLib::FrgBase_Tree::SetParentMainWindow(FrgBase_MainWindow* parentMainWindow)
{
	if (parentMainWindow == theParentMainWindow_)
		return;

	theParentMainWindow_ = parentMainWindow;

	QTreeWidgetItemIterator it((QTreeWidget*)this);
	while (*it)
	{
		auto myTItem = dynamic_cast<ForgBaseLib::FrgBase_TreeItem*>(*it);

		if (myTItem)
			myTItem->SetParentMainWindow(theParentMainWindow_);

		++it;
	}
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_Tree)
{
	/*std::list<ForgBaseLib::FrgBase_TreeItem*> myItems;

	QTreeWidgetItemIterator it((QTreeWidget*)this);
	while (*it)
	{
		myItems.push_back(dynamic_cast<ForgBaseLib::FrgBase_TreeItem*>(*it));

		++it;
	}

	ar & myItems;*/
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_Tree)
{
	/*std::list<FrgBase_TreeItem*> myItems;

	ar & myItems;*/
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_Tree)