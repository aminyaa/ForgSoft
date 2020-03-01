#include <FrgBase_PrptsWdgSelectTItems_Dlg.hxx>
#include <FrgBase_TreeItem.hxx>

#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtGui/QKeyEvent>
#include <QtWidgets/QHeaderView>

ForgBaseLib::FrgBase_PrptsWdgSelectTItems_Dlg::FrgBase_PrptsWdgSelectTItems_Dlg
(
	const QString & dialogTitle,
	FrgBase_MainWindow * parentMainWindow,
	FrgBase_TreeItem* parentTItem
)
	: FrgBase_Dlg(parentMainWindow)
	, theParentTItem_(parentTItem)
{
	this->setWindowTitle(dialogTitle);

	setupLayout();
}

ForgBaseLib::FrgBase_PrptsWdgSelectTItems_Dlg::~FrgBase_PrptsWdgSelectTItems_Dlg()
{
	theTree_ = NullPtr;

	FreePointer(theOKButton_);
	FreePointer(theCancelButton_);
	FreePointer(theButtonsLayout_);
	FreePointer(theMainLayout_);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItems_Dlg::setupLayout()
{
	theMainLayout_ = new QVBoxLayout;
	theButtonsLayout_ = new QHBoxLayout;

	theOKButton_ = new QPushButton("OK");
	theCancelButton_ = new QPushButton("Cancel");
	theButtonsLayout_->addStretch(1);
	theButtonsLayout_->addWidget(theOKButton_);
	theButtonsLayout_->addWidget(theCancelButton_);

	theTree_ = new QTreeWidget();
	theTree_->header()->setSectionResizeMode(0, QHeaderView::Interactive);
	theTree_->setSelectionMode(QAbstractItemView::ExtendedSelection);
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

	theTree_->setStyleSheet(style);

	theMapTreeToSelectionTree_.clear();

	QTreeWidgetItemIterator it(theParentTItem_);
	while (*it)
	{
		auto item = new QTreeWidgetItem();
		item->setText(0, (*it)->text(0));
		item->setIcon(0, (*it)->icon(0));

		theMapTreeToSelectionTree_.insert(std::pair<QTreeWidgetItem*, QTreeWidgetItem*>((*it), item));
		theMapSelectionTreeToTree_.insert(std::pair<QTreeWidgetItem*, QTreeWidgetItem*>(item, (*it)));
		if ((*it)->parent() == theParentTItem_)
			theTree_->addTopLevelItem(item);
		else
		{
			auto parentOfIT = theMapTreeToSelectionTree_.find((*it)->parent());
			if (parentOfIT != theMapTreeToSelectionTree_.end())
				theMapTreeToSelectionTree_.at((*it)->parent())->addChild(item);
		}

		++it;
	}

	theMainLayout_->addWidget(theTree_);
	theMainLayout_->addLayout(theButtonsLayout_);

	this->setLayout(theMainLayout_);

	QObject::connect(theOKButton_, SIGNAL(clicked()), this, SLOT(onOK()));
	QObject::connect(theCancelButton_, SIGNAL(clicked()), this, SLOT(reject()));

	theOKButton_->setFocus();
	this->setModal(true);

	this->adjustSize();
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItems_Dlg::onOK()
{
	theListOfSelectedTItems_.clear();

	auto listOfTItems = theTree_->selectedItems();
	for (int i = 0; i < listOfTItems.size(); i++)
		theListOfSelectedTItems_.push_back(theMapSelectionTreeToTree_.at(listOfTItems[i]));
	
	accept();
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItems_Dlg::keyPressEvent(QKeyEvent * event)
{
	switch (event->key())
	{
	case Qt::Key_Escape:
		reject();
		break;
	}
}