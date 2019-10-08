#include <FrgTree.hxx>
#include <FrgTreeItem.hxx>
#include <FrgMainWindow.hxx>

#include <QtWidgets/QHeaderView>
#include <QtWidgets/QDockWidget>
#include <QKeyEvent>

#include <qttreepropertybrowser.h>

ForgBaseLib::FrgTree::FrgTree(FrgMainWindow* parent)
	: QTreeWidget(parent)
	, theParentMainWindow_(parent)
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

	connect(this, SIGNAL(itemClicked(QTreeWidgetItem*, FrgInt)), this, SLOT(itemClickedSlot(QTreeWidgetItem*, FrgInt)));
}

void ForgBaseLib::FrgTree::FormTree()
{
	theItems_.push_back(FrgNew FrgTreeItem("Geometry", FrgNullPtr, this, theParentMainWindow_));

	FrgNew FrgTreeItem("3D-CAD Models", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Parts", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Contacts", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	theItems_.push_back(FrgNew FrgTreeItem("Continua", FrgNullPtr, this, theParentMainWindow_));

	theItems_.push_back(FrgNew FrgTreeItem("Regions", FrgNullPtr, this, theParentMainWindow_));

	theItems_.push_back(FrgNew FrgTreeItem("Stopping Criteria", FrgNullPtr, this, theParentMainWindow_));

	theItems_.push_back(FrgNew FrgTreeItem("Solution Histories", FrgNullPtr, this, theParentMainWindow_));

	theItems_.push_back(FrgNew FrgTreeItem("Solution Views", FrgNullPtr, this, theParentMainWindow_));

	FrgNew FrgTreeItem("Current Solution", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	theItems_.push_back(FrgNew FrgTreeItem("Monitors", FrgNullPtr, this, theParentMainWindow_));

	FrgNew FrgTreeItem("Physical Time", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);
	theItems_.at(theItems_.size() - 1)->child(theItems_.at(theItems_.size() - 1)->childCount() - 1)->setIcon(0, QIcon(":/Icons/TreeStyle/Eye.png"));

	theItems_.push_back(FrgNew FrgTreeItem("Plots", FrgNullPtr, this, theParentMainWindow_));

	theItems_.push_back(FrgNew FrgTreeItem("Summaries", FrgNullPtr, this, theParentMainWindow_));

	theItems_.push_back(FrgNew FrgTreeItem("Tools", FrgNullPtr, this, theParentMainWindow_));

	FrgNew FrgTreeItem("Annotations", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Colormaps", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Coordinate Systems", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Custom Trees", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Data Focus", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Data Set Functions", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Environment Maps", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Field Functions", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Filters", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Layouts", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Parameters", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Rendering Materials", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Tables", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Tags", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Transforms", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Units", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Update Events", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("User Code", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Views", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgTreeItem("Volume Shapes", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);
}

void ForgBaseLib::FrgTree::ClearTree()
{
	this->clear();
}

void  ForgBaseLib::FrgTree::keyPressEvent(QKeyEvent* event)
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

void ForgBaseLib::FrgTree::itemClickedSlot(QTreeWidgetItem* item, FrgInt column)
{
	if (theParentMainWindow_->GetPropertyWidget())
	{
		theParentMainWindow_->GetPropertyWidget()->theProperty_ = ((FrgTreeItem*)item)->GetProperty();
		theParentMainWindow_->GetPropertyWidget()->theDockWidget_->setWidget(((FrgTreeItem*)item)->GetProperty());
	}
}