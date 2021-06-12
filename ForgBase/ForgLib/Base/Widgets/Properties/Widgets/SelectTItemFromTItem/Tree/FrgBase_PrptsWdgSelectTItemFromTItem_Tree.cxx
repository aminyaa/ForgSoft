#include <FrgBase_PrptsWdgSelectTItemFromTItem_Tree.hxx>

#include <QtWidgets/QHeaderView>
#include <QtGui/QKeyEvent>

ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Tree::FrgBase_PrptsWdgSelectTItemFromTItem_Tree()
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
}

ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Tree::~FrgBase_PrptsWdgSelectTItemFromTItem_Tree()
{

}