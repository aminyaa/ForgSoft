#pragma once
#ifndef _FrgBase_FieldTreeWidget_Header
#define _FrgBase_FieldTreeWidget_Header

#include <FrgBase_Global.hxx>

#include <QTreeWidget>

class QVBoxLayout;
class QHBoxLayout;
class QTreeWidget;
class QPushButton;

BeginForgBaseLib

class FrgBase_SymbolTable;
class FrgBase_FieldTreeItemWidget;

class FORGBASE_EXPORT FrgBase_FieldTreeWidget
	: public QTreeWidget
{

	Q_OBJECT

public:

	FrgBase_FieldTreeWidget
	(
		const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& tables,
		QWidget* parent = nullptr
	);

	Q_SIGNAL void ItemDoubleClickedSignal(const QString& name);

protected:

	void AddTableToTree
	(
		const std::shared_ptr<FrgBase_SymbolTable>& table
	);

	bool ContainsTable
	(
		const std::shared_ptr<FrgBase_SymbolTable>& table
	) const;

	void ConnectSignals();
	void DisconnectSignals();

	void SetItemsSelected(const bool condition);

	void UpdateColumns();

	void SortItems();
	void SortItem(QTreeWidgetItem* item);

protected slots:

	void ItemExpandedSlot(QTreeWidgetItem* item);
	void ItemCollapsedSlot(QTreeWidgetItem* item);
	void ItemClickedSlot();
	void ItemDoubleClickedSlot(QTreeWidgetItem* item, int column);

protected:

	std::vector<std::shared_ptr<FrgBase_SymbolTable>> theTables_;

	std::map<std::shared_ptr<FrgBase_SymbolTable>, FrgBase_FieldTreeItemWidget*> theMap_;
};
EndForgBaseLib

#endif // !_FrgBase_FieldTreeWidget_Header
