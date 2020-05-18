#pragma once
#include <FrgBase_PrptsWdgSelectTItem_Tree.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_Tree.hxx>
#include <FrgBase_MainWindow.hxx>

#include <QtCore/QObject>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QTreeWidgetItemIterator>

template<typename Type>
inline ForgBaseLib::FrgBase_PrptsWdgSelectTItem_Dlg<Type>::FrgBase_PrptsWdgSelectTItem_Dlg
(
	const QString & dialogTitle,
	FrgBase_MainWindow * parentMainWindow,
	QTreeWidgetItem * selectedTItem
)
	: FrgBase_PrptsWdgSelectTItem_Dlg_Base(dialogTitle, parentMainWindow, selectedTItem)
{
	setupLayout();
}

template<typename Type>
inline void ForgBaseLib::FrgBase_PrptsWdgSelectTItem_Dlg<Type>::setupLayout()
{
	theMainLayout_ = new QVBoxLayout;
	theButtonsLayout_ = new QHBoxLayout;

	theOKButton_ = new QPushButton("OK");
	theOKButton_->setEnabled(false);
	theCancelButton_ = new QPushButton("Cancel");
	theButtonsLayout_->addStretch(1);
	theButtonsLayout_->addWidget(theOKButton_);
	theButtonsLayout_->addWidget(theCancelButton_);

	theTree_ = new FrgBase_PrptsWdgSelectTItem_Tree();

	auto myMainWindow = dynamic_cast<FrgBase_MainWindow*>(this->parentWidget());
	auto myTree = myMainWindow->GetTree();
	QTreeWidgetItemIterator it(myTree);
	while (*it)
	{
		auto castedTItem = dynamic_cast<Type*>((*it));

		if (!castedTItem)
		{
			++it;
			continue;
		}
		
		int nTopLevelTItemCount = theTree_->topLevelItemCount();
		bool found = false;
		for (int iTopLevelTItemCount = 0; iTopLevelTItemCount < nTopLevelTItemCount; iTopLevelTItemCount++)
		{
			if (theTree_->topLevelItem(iTopLevelTItemCount) == theMapTreeToSelectionTree_.at((*it)->parent()))
			{
				auto item = new QTreeWidgetItem();
				item->setText(0, (*it)->text(0));
				item->setIcon(0, (*it)->icon(0));

				theTree_->topLevelItem(iTopLevelTItemCount)->addChild(item);

				theMapTreeToSelectionTree_.insert(std::pair<QTreeWidgetItem*, QTreeWidgetItem*>((*it), item));
				theMapSelectionTreeToTree_.insert(std::pair<QTreeWidgetItem*, QTreeWidgetItem*>(item, (*it)));
				found = true;
				break;
			}
		}
		if (!found)
		{
			auto item = new QTreeWidgetItem();
			item->setText(0, (*it)->parent()->text(0));
			item->setIcon(0, (*it)->parent()->icon(0));

			theTree_->addTopLevelItem(item);
			theMapTreeToSelectionTree_.insert(std::pair<QTreeWidgetItem*, QTreeWidgetItem*>((*it)->parent(), item));
			theMapSelectionTreeToTree_.insert(std::pair<QTreeWidgetItem*, QTreeWidgetItem*>(item, (*it)->parent()));

			auto item2 = new QTreeWidgetItem();
			item2->setText(0, (*it)->text(0));
			item2->setIcon(0, (*it)->icon(0));

			item->addChild(item2);

			theMapTreeToSelectionTree_.insert(std::pair<QTreeWidgetItem*, QTreeWidgetItem*>((*it), item2));
			theMapSelectionTreeToTree_.insert(std::pair<QTreeWidgetItem*, QTreeWidgetItem*>(item2, (*it)));

			item->setExpanded(true);
		}

		++it;
	}

	theMainLayout_->addWidget(theTree_);
	theMainLayout_->addLayout(theButtonsLayout_);

	this->setLayout(theMainLayout_);

	QObject::connect(theOKButton_, SIGNAL(clicked()), dynamic_cast<FrgBase_PrptsWdgSelectTItem_Dlg_Base*>(this), SLOT(onOK()));
	QObject::connect(theCancelButton_, SIGNAL(clicked()), dynamic_cast<FrgBase_PrptsWdgSelectTItem_Dlg_Base*>(this), SLOT(reject()));
	QObject::connect(theTree_, SIGNAL(itemClicked(QTreeWidgetItem *, int)), dynamic_cast<FrgBase_PrptsWdgSelectTItem_Dlg_Base*>(this), SLOT(itemClickedSlot(QTreeWidgetItem *, int)));

	theOKButton_->setFocus();
	this->setModal(true);

	this->adjustSize();
}

template<typename Type>
inline void ForgBaseLib::FrgBase_PrptsWdgSelectTItem_Dlg<Type>::TItemIsClicked(QTreeWidgetItem *item, int column)
{
	if (theTree_->selectedItems().size() == 0)
		return;

	auto castedTItem = dynamic_cast<Type*>(theMapSelectionTreeToTree_.at(item));

	if (!castedTItem)
	{
		theTree_->clearSelection();
		theOKButton_->setEnabled(false);
	}

	else
		theOKButton_->setEnabled(true);
}