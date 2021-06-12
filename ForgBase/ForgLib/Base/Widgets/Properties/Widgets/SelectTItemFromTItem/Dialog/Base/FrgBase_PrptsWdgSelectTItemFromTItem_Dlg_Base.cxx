#include <FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgBase_Tree.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_PrptsWdgSelectTItemFromTItem_Tree.hxx>
#include <FrgBase_PrptsVrntSelectTItemFromTItem_Base.hxx>

#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtGui/QKeyEvent>

ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base::FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base
(
	const QString& dialogTitle,
	FrgBase_MainWindow* parentMainWindow,
	FrgBase_PrptsVrnt* myVariant
)
	: QDialog(parentMainWindow)
	, theVariant_(myVariant)
{
	auto myCastedVariant = dynamic_cast<FrgBase_PrptsVrntSelectTItemFromTItem_Base*>(theVariant_);
	theSelectedTItem_ = myCastedVariant->GetValue();

	this->setWindowTitle(dialogTitle);

	//setupLayout();
}

//void ForgBaseLib::FrgBase_PrptsWdgSelectTItem_Dlg_Base::setupLayout()
//{
//	theMainLayout_ = new QVBoxLayout;
//	theButtonsLayout_ = new QHBoxLayout;
//
//	theOKButton_ = new QPushButton("OK");
//	theOKButton_->setEnabled(false);
//	theCancelButton_ = new QPushButton("Cancel");
//	theButtonsLayout_->addStretch(1);
//	theButtonsLayout_->addWidget(theOKButton_);
//	theButtonsLayout_->addWidget(theCancelButton_);
//
//	theTree_ = new FrgBase_PrptsWdgSelectTItem_Tree();
//
//	QTreeWidgetItemIterator it(theParentTItem_);
//	while (*it)
//	{
//		auto item = new QTreeWidgetItem();
//		item->setText(0, (*it)->text(0));
//		item->setIcon(0, (*it)->icon(0));
//		item->setCheckState(0, Qt::Unchecked);
//
//		theMapTreeToSelectionTree_.insert(std::pair<QTreeWidgetItem*, QTreeWidgetItem*>((*it), item));
//		theMapSelectionTreeToTree_.insert(std::pair<QTreeWidgetItem*, QTreeWidgetItem*>(item, (*it)));
//		if ((*it)->parent() == theParentTItem_)
//			theTree_->addTopLevelItem(item);
//		else
//		{
//			auto parentOfIT = theMapTreeToSelectionTree_.find((*it)->parent());
//			if (parentOfIT != theMapTreeToSelectionTree_.end())
//				theMapTreeToSelectionTree_.at((*it)->parent())->addChild(item);
//			else
//			{
//				theMapTreeToSelectionTree_.erase((*it));
//				theMapSelectionTreeToTree_.erase(item);
//				delete item;
//				item = nullptr;
//			}
//		}
//	}
//
//	theMainLayout_->addWidget(theTree_);
//	theMainLayout_->addLayout(theButtonsLayout_);
//
//	this->setLayout(theMainLayout_);
//
//	QObject::connect(theOKButton_, SIGNAL(clicked()), this, SLOT(onOK()));
//	QObject::connect(theCancelButton_, SIGNAL(clicked()), this, SLOT(reject()));
//	QObject::connect(theTree_, SIGNAL(itemSelectionChanged()), this, SLOT(ItemSelectionChangedSlot()));
//
//	theOKButton_->setFocus();
//	this->setModal(true);
//
//	this->adjustSize();
//}

ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base::~FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base()
{

}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base::keyPressEvent(QKeyEvent* event)
{
	switch (event->key())
	{
	case Qt::Key_Escape:
		reject();
		break;
	}
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base::onOK()
{
	auto selectedTItem = theTree_->selectedItems()[0];

	if (theMapSelectionTreeToTree_.at(selectedTItem) == theSelectedTItem_)
	{
		reject();
		return;
	}

	theSelectedTItem_ = theMapSelectionTreeToTree_.at(selectedTItem);
	accept();
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base::itemClickedSlot(QTreeWidgetItem* item, int column)
{
	TItemIsClicked(item, column);

	auto iter = theMapSelectionTreeToTree_.find(item);
	if (iter == theMapSelectionTreeToTree_.end())
		return;

	auto myMainWindow = dynamic_cast<FrgBase_MainWindow*>(this->parentWidget());
	auto myTree = myMainWindow->GetTree();

	emit myTree->itemClicked(theMapSelectionTreeToTree_.at(item), column);
}