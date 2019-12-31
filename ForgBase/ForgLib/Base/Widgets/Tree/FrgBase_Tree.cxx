#include <FrgBase_Tree.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_Menu.hxx>

#include <QtWidgets/QHeaderView>
#include <QtGui/QKeyEvent>

ForgBaseLib::FrgBase_Tree::FrgBase_Tree
(
	FrgBase_MainWindow* parentMainWindow
)
	: QTreeWidget(parentMainWindow)
{
	this->setColumnCount(1);
	this->setHeaderLabel(tr("Simulation"));
	this->header()->setSectionResizeMode(0, QHeaderView::Interactive);
	this->setSelectionMode(QAbstractItemView::ExtendedSelection);

	this->setContextMenuPolicy(Qt::CustomContextMenu);

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
	case Qt::Key_Home:
	case Qt::Key_End:
	case Qt::Key_PageUp:
	case Qt::Key_PageDown:
		if (currentItem())
		{
			emit QTreeWidget::itemClicked(currentItem(), 0);
		}
	}
}

void ForgBaseLib::FrgBase_Tree::itemClickedSlot
(
	QTreeWidgetItem* item,
	int column
)
{
	theLastLeftClickedTItem_ = dynamic_cast<FrgBase_TreeItem*>(item);
}

void ForgBaseLib::FrgBase_Tree::itemDoubleClickedSlot
(
	QTreeWidgetItem* item,
	int column
)
{
	theLastLeftClickedTItem_ = dynamic_cast<FrgBase_TreeItem*>(item);
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
			item->GetContextMenu()->exec(globalPos);
	}
}

void ForgBaseLib::FrgBase_Tree::ScrollToItem
(
	FrgBase_TreeItem* item
)
{
	clearSelection();
	scrollToItem(item);
	setItemSelected(item, true);
	this->setCurrentItem(item);

	emit itemClickedSlot(item, 0);

	setFocus();
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