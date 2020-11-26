#pragma once
#ifndef _FrgBase_PrptsWdgSelectTItems_Tree_Header
#define _FrgBase_PrptsWdgSelectTItems_Tree_Header

#include <FrgBase_Global.hxx>
#include <QtWidgets/QTreeWidget>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsWdgSelectTItems_Tree
	: public QTreeWidget
{
	Q_OBJECT

public:

	FrgBase_PrptsWdgSelectTItems_Tree();

	~FrgBase_PrptsWdgSelectTItems_Tree();

	std::vector<QTreeWidgetItem*> GetSelectedItems();

	void SetCheckState(QTreeWidgetItem* TItem, Qt::CheckState state);

private slots:

	void itemClickedSlot(QTreeWidgetItem* TItem, int column);

private:

	void keyPressEvent(QKeyEvent* event) override;
	void SetParentsCheckState(QTreeWidgetItem* TItem);
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgSelectTItems_Tree_Header
