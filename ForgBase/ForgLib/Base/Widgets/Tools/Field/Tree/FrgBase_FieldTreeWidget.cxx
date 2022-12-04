#include "FrgBase_FieldTreeWidget.hxx"

#include <FrgBase_FieldTreeItemWidget.hxx>
#include <FrgBase_SymbolTable.hxx>
#include <FrgBase_Field.hxx>
#include <FrgBase_FieldTools.hxx>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTreeWidget>
#include <QPushButton>
#include <QMessageBox>

ForgBaseLib::FrgBase_FieldTreeWidget::FrgBase_FieldTreeWidget
(
	const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& tables,
	QWidget* parent
)
	: QTreeWidget(parent)
	, theTables_(tables)
{
	this->setWindowTitle("Tables With Their Fields");

	this->setSelectionMode(QAbstractItemView::SingleSelection);
	this->setIconSize(QSize(24, 24));
	this->setColumnCount(3);
	this->setHeaderLabels({ "Item", "Type", "Is Selectable?" });

	for (const auto& table : theTables_)
		AddTableToTree(table);

	SortItems();

	UpdateColumns();

	ConnectSignals();
}

void ForgBaseLib::FrgBase_FieldTreeWidget::AddTableToTree
(
	const std::shared_ptr<FrgBase_SymbolTable>& table
)
{
	if (!table)
		return;

	auto parent =
		table->GetParentSymbolTable();

	if (parent)
		AddTableToTree(parent);

	if (ContainsTable(table))
		return;

	auto item =
		new FrgBase_FieldTreeItemWidget;

	item->setText
	(
		0,
		QString::fromStdString(table->GetPresentationName())
	);

	if (!parent)
		this->addTopLevelItem(item);
	else
		theMap_[parent]->addChild(item);

	item->SetType("Table");
	item->SetSelectable(false);


	theMap_[table] = item;

	for (const auto& field : table->GetFields())
	{
		auto fieldItem =
			new FrgBase_FieldTreeItemWidget;

		fieldItem->setText
		(
			0,
			QString::fromStdString(field->GetPresentationName())
		);

		fieldItem->SetType(field->GetTypeAsString());
		fieldItem->SetSelectable(true);
		fieldItem->SetFieldFullPresentationName
		(
			QString::fromStdString
			(
				field->GetFullPresentationName()
			)
		);

		item->addChild(fieldItem);
	}
}

bool ForgBaseLib::FrgBase_FieldTreeWidget::ContainsTable
(
	const std::shared_ptr<FrgBase_SymbolTable>& table
) const
{
	auto iter = theMap_.find(table);
	if (iter != theMap_.end())
		return true;

	return false;
}

void ForgBaseLib::FrgBase_FieldTreeWidget::ConnectSignals()
{
	connect
	(
		this,
		&QTreeWidget::itemExpanded,
		this,
		&FrgBase_FieldTreeWidget::ItemExpandedSlot
	);

	connect
	(
		this,
		&QTreeWidget::itemCollapsed,
		this,
		&FrgBase_FieldTreeWidget::ItemCollapsedSlot
	);

	connect
	(
		this,
		&QTreeWidget::itemSelectionChanged,
		this,
		&FrgBase_FieldTreeWidget::ItemClickedSlot
	);

	connect
	(
		this,
		&QTreeWidget::itemDoubleClicked,
		this,
		&FrgBase_FieldTreeWidget::ItemDoubleClickedSlot
	);
}



void ForgBaseLib::FrgBase_FieldTreeWidget::DisconnectSignals()
{
	disconnect
	(
		this,
		&QTreeWidget::itemExpanded,
		this,
		&FrgBase_FieldTreeWidget::ItemExpandedSlot
	);

	disconnect
	(
		this,
		&QTreeWidget::itemCollapsed,
		this,
		&FrgBase_FieldTreeWidget::ItemCollapsedSlot
	);

	disconnect
	(
		this,
		&QTreeWidget::itemSelectionChanged,
		this,
		&FrgBase_FieldTreeWidget::ItemClickedSlot
	);

	disconnect
	(
		this,
		&QTreeWidget::itemDoubleClicked,
		this,
		&FrgBase_FieldTreeWidget::ItemDoubleClickedSlot
	);
}

void ForgBaseLib::FrgBase_FieldTreeWidget::ItemExpandedSlot
(
	QTreeWidgetItem* item
)
{
	UpdateColumns();
}

void ForgBaseLib::FrgBase_FieldTreeWidget::ItemCollapsedSlot
(
	QTreeWidgetItem* item
)
{
	//UpdateColumns();
}

void ForgBaseLib::FrgBase_FieldTreeWidget::ItemClickedSlot()
{
	auto sis = this->selectedItems();

	if (sis.empty())
		return;

	if (sis.size() > 1)
	{
		SetItemsSelected(false);

		return;
	}

	auto item =
		dynamic_cast<FrgBase_FieldTreeItemWidget*>(sis[0]);

	if (item)
	{
		if (!item->IsSelectable())
			SetItemsSelected(false);
	}
}

void ForgBaseLib::FrgBase_FieldTreeWidget::ItemDoubleClickedSlot
(
	QTreeWidgetItem* item,
	int column
)
{
	auto myItem =
		dynamic_cast<FrgBase_FieldTreeItemWidget*>(item);

	if (myItem && myItem->IsSelectable())
	{
		/*QMessageBox::information
		(
			this,
			"Field Name",
			myItem->GetFieldFullPresentationName()
		);*/

		auto name =
			FrgBase_FieldTools::AddDecoratorAndBracketToString
			(
				myItem->GetFieldFullPresentationName().toStdString()
			);

		emit ItemDoubleClickedSignal
		(
			QString::fromStdString(name)
		);
	}
}

void ForgBaseLib::FrgBase_FieldTreeWidget::SetItemsSelected
(
	const bool condition
)
{
	DisconnectSignals();

	QTreeWidgetItemIterator it(this);
	while (*it)
	{
		this->setItemSelected(*it, condition);

		++it;
	}

	ConnectSignals();
}

void ForgBaseLib::FrgBase_FieldTreeWidget::UpdateColumns()
{
	for (int i = 0; i < this->columnCount(); i++)
	{
		auto cw = this->columnWidth(i);
		this->resizeColumnToContents(i);

		if (cw > this->columnWidth(i))
			this->setColumnWidth(i, cw);
	}
}

void ForgBaseLib::FrgBase_FieldTreeWidget::SortItems()
{
	auto count = this->topLevelItemCount();
	for (int i = 0; i < count; i++)
	{
		auto item =
			this->topLevelItem(i);
		
		SortItem(item);
	}
}

void ForgBaseLib::FrgBase_FieldTreeWidget::SortItem
(
	QTreeWidgetItem* item
)
{
	if (!item)
		return;

	auto childCount = item->childCount();

	for (int j = childCount - 1; j >= 0; j--)
	{
		auto it =
			dynamic_cast<FrgBase_FieldTreeItemWidget*>(item->child(j));

		if (it && !it->IsSelectable())
			SortItem(it);
	}

	auto p = item->parent();
	if (p)
	{
		p->removeChild(item);

		p->insertChild
		(
			0,
			item
		);
	}
}