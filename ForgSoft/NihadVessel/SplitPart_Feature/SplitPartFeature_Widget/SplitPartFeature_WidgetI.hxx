#pragma once
#include <SplitPartFeature_Tree.hxx>

#include <QtWidgets/QDockWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>

template<class BlockEntity>
inline ForgBaseLib::SplitPartFeature_Widget<BlockEntity>::SplitPartFeature_Widget
(
	FrgBaseMainWindow* parentMainWindow,
	FrgBaseCADPart_Feature<BlockEntity>* partFeature
)
	: SplitPartFeature_Widget_Base(parentMainWindow)
{
	theWidgetItems_ = new WidgetItemsStruct;

	theWidgetItems_->theMainLayout_ = new QVBoxLayout(this);
	theWidgetItems_->theNameLayout_ = new QHBoxLayout(this);
	theWidgetItems_->theButtonsLayout_ = new QHBoxLayout(this);

	theTree_ = FrgNew SplitPartFeature_Tree<BlockEntity>(theParentMainWindow_,partFeature);
	theTree_->GetParentSplitWidget() = this;

	theWidgetItems_->theNameLabel_ = new QLabel("Name");
	theNameLineEdit_ = new QLineEdit(this);
	theWidgetItems_->theNameLayout_->addWidget(theWidgetItems_->theNameLabel_);
	theWidgetItems_->theNameLayout_->addWidget(theNameLineEdit_);

	theCreateButton_ = new QPushButton("Create", this);
	theCloseButton_ = new QPushButton("Close", this);
	theWidgetItems_->theButtonsLayout_->addStretch(1);
	theWidgetItems_->theButtonsLayout_->addWidget(theCreateButton_);
	theWidgetItems_->theButtonsLayout_->addWidget(theCloseButton_);

	theWidgetItems_->theMainLayout_->addWidget(theTree_);
	theWidgetItems_->theMainLayout_->addLayout(theWidgetItems_->theNameLayout_);
	theWidgetItems_->theMainLayout_->addLayout(theWidgetItems_->theButtonsLayout_);

	theWidgetItems_->theMainWidget_ = new QWidget(this);
	theWidgetItems_->theMainWidget_->setLayout(theWidgetItems_->theMainLayout_);

	theDockWidget_ = new QDockWidget("Split " + partFeature->text(0), theParentMainWindow_);
	theDockWidget_->setTitleBarWidget(new QWidget(this));
	theParentMainWindow_->tabifyDockWidget(theParentMainWindow_->GetTreeWidget()->theDockWidget_, theDockWidget_);
	theParentMainWindow_->tabifiedDockWidgetActivated(theDockWidget_);
	theParentMainWindow_->GetTreeWidget()->theDockWidget_->setEnabled(false);
	theDockWidget_->setWidget(theWidgetItems_->theMainWidget_);

	theDockWidget_->show();
	theDockWidget_->raise();

	QObject::connect(theCreateButton_, SIGNAL(clicked()), theTree_, SLOT(CreateButtonClickedSlot()));
	QObject::connect(theCloseButton_, SIGNAL(clicked()), this, SLOT(CloseButtonClickedSlot()));
}

template<class BlockEntity>
inline void ForgBaseLib::SplitPartFeature_Widget<BlockEntity>::SetManager
(
	std::shared_ptr<typename Entity_From_BlockEntity<BlockEntity>::typeManager> manager
)
{
	thePartManager_ = manager;
}

template<class BlockEntity>
inline void ForgBaseLib::SplitPartFeature_Widget<BlockEntity>::CloseButtonClicked()
{
	auto parentOfFeatures = theTree_->GetPartFeature()->GetParentFeatures();
	parentOfFeatures->RemoveFeature(theTree_->GetPartFeature());

	std::vector<std::shared_ptr<BlockEntity>> blockEntities;
	thePartManager_->RetrieveTo(blockEntities);

	for (int iBlock = 0; iBlock < blockEntities.size(); iBlock++)
	{
		auto feature = parentOfFeatures->AddFeature(blockEntities[iBlock]);
		feature->DoAfterConstruct();
		feature->setIcon(0, QIcon(Entity_From_BlockEntity<BlockEntity>::GetIcon()));
	}

	theParentMainWindow_->GetTreeWidget()->theDockWidget_->setEnabled(true);
	theParentMainWindow_->GetTreeWidget()->theDockWidget_->show();
	theParentMainWindow_->GetTreeWidget()->theDockWidget_->raise();
	theParentMainWindow_->removeDockWidget(theDockWidget_);
}