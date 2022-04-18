#pragma once

#include <FrgBase_PrptsWdgSelectTItemFromTItem_Tree.hxx>
#include <FrgBase_PrptsVrntSelectTItemFromTItem_Base.hxx>
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
inline ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Dlg<Type>::FrgBase_PrptsWdgSelectTItemFromTItem_Dlg
(
	const QString& dialogTitle,
	FrgBase_MainWindow* parentMainWindow,
	FrgBase_PrptsVrnt* myVariant
)
	: FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base(dialogTitle, parentMainWindow, myVariant)
{
	setupLayout();
}

template<typename Type>
inline void ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Dlg<Type>::setupLayout()
{
	theMainLayout_ = new QVBoxLayout;
	theButtonsLayout_ = new QHBoxLayout;

	theOKButton_ = new QPushButton("OK");
	theOKButton_->setEnabled(false);
	theCancelButton_ = new QPushButton("Cancel");
	theButtonsLayout_->addStretch(1);
	theButtonsLayout_->addWidget(theOKButton_);
	theButtonsLayout_->addWidget(theCancelButton_);

	theTree_ = new FrgBase_PrptsWdgSelectTItemFromTItem_Tree();

	connect(theTree_, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(itemClickedSlot(QTreeWidgetItem*, int)));

	auto myMainWindow = dynamic_cast<FrgBase_MainWindow*>(this->parentWidget());
	auto myTree = myMainWindow->GetTree();

	auto myCastedVariant = dynamic_cast<FrgBase_PrptsVrntSelectTItemFromTItem_Base*>(theVariant_);
	auto parentTItems = myCastedVariant->GetParentTItems();
	if (!parentTItems.empty())
	{
		std::vector<Type*> myTypes;
		for (auto parentTItem : parentTItems)
		{
			auto item = new QTreeWidgetItem;
			item->setText(0, parentTItem->text(0));
			item->setIcon(0, parentTItem->icon(0));
			theTree_->addTopLevelItem(item);

			theMapTreeToSelectionTree_.insert(std::pair<QTreeWidgetItem*, QTreeWidgetItem*>(parentTItem, item));
			theMapSelectionTreeToTree_.insert(std::pair<QTreeWidgetItem*, QTreeWidgetItem*>(item, parentTItem));

			auto myChildren = parentTItem->GetAllChildrenToTheRootByType<FrgBase_TreeItem>();
			for (auto myChild : myChildren)
			{
				if (myChild->GetIndex() == -1)
					continue;

				auto myChildType = dynamic_cast<Type*>(myChild);
				if (myChildType)
					myTypes.push_back(myChildType);
				else
				{
					for (auto x : myTypes)
					{
						if (myChild->IsMyParent(x))
							continue;
					}
				}

				auto item = new QTreeWidgetItem;
				item->setText(0, myChild->text(0));
				item->setIcon(0, myChild->icon(0));

				//auto& myP = theMapTreeToSelectionTree_.at(myChild->QTreeWidgetItem::parent());
				const auto& myP = theMapTreeToSelectionTree_.find(myChild->QTreeWidgetItem::parent());
				if (myP != theMapTreeToSelectionTree_.end())
				{
					myP->second->addChild(item);

					theMapTreeToSelectionTree_.insert(std::pair<QTreeWidgetItem*, QTreeWidgetItem*>(myChild, item));
					theMapSelectionTreeToTree_.insert(std::pair<QTreeWidgetItem*, QTreeWidgetItem*>(item, myChild));
				}
			}
		}
	}

	//theTree_->expandAll();

	theMainLayout_->addWidget(theTree_);
	theMainLayout_->addLayout(theButtonsLayout_);

	this->setLayout(theMainLayout_);

	QObject::connect(theOKButton_, SIGNAL(clicked()), dynamic_cast<FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base*>(this), SLOT(onOK()));
	QObject::connect(theCancelButton_, SIGNAL(clicked()), dynamic_cast<FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base*>(this), SLOT(reject()));
	QObject::connect(theTree_, SIGNAL(itemClicked(QTreeWidgetItem*, int)), dynamic_cast<FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base*>(this), SLOT(itemClickedSlot(QTreeWidgetItem*, int)));

	theOKButton_->setFocus();
	this->setModal(true);

	this->adjustSize();
}

template<typename Type>
inline void ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Dlg<Type>::TItemIsClicked(QTreeWidgetItem* item, int column)
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