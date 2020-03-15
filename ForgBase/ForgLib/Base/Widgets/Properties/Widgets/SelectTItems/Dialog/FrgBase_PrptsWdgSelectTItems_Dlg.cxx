#include <FrgBase_PrptsWdgSelectTItems_Dlg.hxx>
#include <FrgBase_PrptsWdgSelectTItems_Tree.hxx>
#include <FrgBase_TreeItem.hxx>

#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtGui/QKeyEvent>

ForgBaseLib::FrgBase_PrptsWdgSelectTItems_Dlg::FrgBase_PrptsWdgSelectTItems_Dlg
(
	const QString & dialogTitle,
	FrgBase_MainWindow * parentMainWindow,
	FrgBase_TreeItem* parentTItem,
	std::vector<QTreeWidgetItem*> selectedTItems
)
	: FrgBase_Dlg(parentMainWindow)
	, theParentTItem_(parentTItem)
	, theListOfSelectedTItems_(selectedTItems)
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
	FreePointer(theTree_);

	theMapTreeToSelectionTree_.clear();
	theMapSelectionTreeToTree_.clear();
	theListOfSelectedTItems_.clear();
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItems_Dlg::setupLayout()
{
	theMainLayout_ = new QVBoxLayout;
	theButtonsLayout_ = new QHBoxLayout;

	theOKButton_ = new QPushButton("OK");
	theOKButton_->setEnabled(false);
	theCancelButton_ = new QPushButton("Cancel");
	theButtonsLayout_->addStretch(1);
	theButtonsLayout_->addWidget(theOKButton_);
	theButtonsLayout_->addWidget(theCancelButton_);

	theTree_ = new FrgBase_PrptsWdgSelectTItems_Tree();

	QTreeWidgetItemIterator it(theParentTItem_);
	while (*it)
	{
		auto item = new QTreeWidgetItem();
		item->setText(0, (*it)->text(0));
		item->setIcon(0, (*it)->icon(0));
		item->setCheckState(0, Qt::Unchecked);

		theMapTreeToSelectionTree_.insert(std::pair<QTreeWidgetItem*, QTreeWidgetItem*>((*it), item));
		theMapSelectionTreeToTree_.insert(std::pair<QTreeWidgetItem*, QTreeWidgetItem*>(item, (*it)));
		if ((*it)->parent() == theParentTItem_)
			theTree_->addTopLevelItem(item);
		else
		{
			auto parentOfIT = theMapTreeToSelectionTree_.find((*it)->parent());
			if (parentOfIT != theMapTreeToSelectionTree_.end())
				theMapTreeToSelectionTree_.at((*it)->parent())->addChild(item);
			else
			{
				theMapTreeToSelectionTree_.erase((*it));
				theMapSelectionTreeToTree_.erase(item);
				delete item;
				item = nullptr;
			}
		}

		for (int iSelectedTItem = 0; iSelectedTItem < theListOfSelectedTItems_.size(); iSelectedTItem++)
		{
			if (theListOfSelectedTItems_[iSelectedTItem] == (*it))
			{
				theTree_->SetCheckState(item, Qt::Checked);
				break;
			}
		}

		if(item)
			theTree_->SetCheckState(item, item->checkState(0));

		++it;
	}

	theMainLayout_->addWidget(theTree_);
	theMainLayout_->addLayout(theButtonsLayout_);

	this->setLayout(theMainLayout_);

	QObject::connect(theOKButton_, SIGNAL(clicked()), this, SLOT(onOK()));
	QObject::connect(theCancelButton_, SIGNAL(clicked()), this, SLOT(reject()));
	QObject::connect(theTree_, SIGNAL(itemSelectionChanged()), this, SLOT(ItemSelectionChangedSlot()));

	theOKButton_->setFocus();
	this->setModal(true);

	this->adjustSize();
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItems_Dlg::onOK()
{
	auto listOfTItems = theTree_->GetSelectedItems();

	if (listOfTItems.size() == 0 && theListOfSelectedTItems_.size() == 0)
	{
		reject();
		return;
	}
	else if (theListOfSelectedTItems_.size() > 0 && listOfTItems.size() == 0)
	{
		theListOfSelectedTItems_.clear();
		accept();
		return;
	}
	else
	{
		theListOfSelectedTItems_.clear();

		for (int i = 0; i < listOfTItems.size(); i++)
			theListOfSelectedTItems_.push_back(theMapSelectionTreeToTree_.at(listOfTItems[i]));

		accept();
	}
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

void ForgBaseLib::FrgBase_PrptsWdgSelectTItems_Dlg::ItemSelectionChangedSlot()
{
	theOKButton_->setEnabled(true);
}