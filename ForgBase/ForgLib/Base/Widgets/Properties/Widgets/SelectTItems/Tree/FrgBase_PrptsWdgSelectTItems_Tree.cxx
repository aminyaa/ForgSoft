#include <FrgBase_PrptsWdgSelectTItems_Tree.hxx>

#include <QtWidgets/QHeaderView>
#include <QtGui/QKeyEvent>

ForgBaseLib::FrgBase_PrptsWdgSelectTItems_Tree::FrgBase_PrptsWdgSelectTItems_Tree()
	: QTreeWidget(nullptr)
{
	this->setColumnCount(1);
	this->setHeaderLabel(tr(""));

	this->header()->setSectionResizeMode(0, QHeaderView::Interactive);
	this->setSelectionMode(QAbstractItemView::SingleSelection);

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
}

ForgBaseLib::FrgBase_PrptsWdgSelectTItems_Tree::~FrgBase_PrptsWdgSelectTItems_Tree()
{
	
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItems_Tree::itemClickedSlot
(
	QTreeWidgetItem* TItem,
	int column
)
{
	if (!TItem)
		return;

	if (TItem->checkState(column) == Qt::Unchecked)
		SetCheckState(TItem, Qt::Checked);
	else if (TItem->checkState(column) == Qt::Checked)
		SetCheckState(TItem, Qt::Unchecked);
	else if (TItem->checkState(column) == Qt::PartiallyChecked)
		SetCheckState(TItem, Qt::Unchecked);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItems_Tree::SetCheckState(QTreeWidgetItem * TItem, Qt::CheckState state)
{
	for (int i = 0; i < TItem->childCount(); i++)
		SetCheckState(TItem->child(i), state);

	TItem->setCheckState(0, state);

	SetParentsCheckState(TItem);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItems_Tree::SetParentsCheckState(QTreeWidgetItem * TItem)
{
	auto parentOfTItem = TItem->parent();
	if (parentOfTItem)
	{
		bool is_Same = true;
		auto check_0 = parentOfTItem->child(0)->checkState(0);
		for (int i = 1; i < parentOfTItem->childCount(); i++)
			if (check_0 != parentOfTItem->child(i)->checkState(0))
			{
				is_Same = false;
				break;
			}
		if (is_Same && parentOfTItem->child(0)->checkState(0) == Qt::Checked)
			parentOfTItem->setCheckState(0, Qt::Checked);
		else if (is_Same && parentOfTItem->child(0)->checkState(0) == Qt::Unchecked)
			parentOfTItem->setCheckState(0, Qt::Unchecked);
		else if (is_Same && parentOfTItem->child(0)->checkState(0) == Qt::PartiallyChecked)
			parentOfTItem->setCheckState(0, Qt::PartiallyChecked);
		else
			parentOfTItem->setCheckState(0, Qt::PartiallyChecked);

		SetParentsCheckState(parentOfTItem);
	}
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItems_Tree::keyPressEvent
(
	QKeyEvent* event
)
{
	switch (event->key())
	{
	case Qt::Key_Space:
		itemClickedSlot(this->currentItem(), 0);
		event->accept();
		break;
	default:
		QTreeWidget::keyPressEvent(event);
	}
}

std::vector<QTreeWidgetItem*> ForgBaseLib::FrgBase_PrptsWdgSelectTItems_Tree::GetSelectedItems()
{
	std::vector<QTreeWidgetItem*> output;

	QTreeWidgetItemIterator it(this);
	while (*it)
	{
		if ((*it)->checkState(0) == Qt::Checked)
			output.push_back((*it));
		++it;
	}

	return output;
}