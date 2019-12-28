#pragma once
#include <SplitWidget.hxx>
#include <FrgBaseMainWindow.hxx>
#include <SplitTree.hxx>
#include <FrgBaseCADScene.hxx>
#include <CADPartItem.hxx>
#include <NihadTree.hxx>
#include <FrgBaseCADPartFeatures.hxx>
#include <FrgBase_CADScene_TreeItem.hxx>
#include <FrgBaseCADScene.hxx>
#include <FrgBaseCADPart.hxx>
#include <FrgBaseTreeItem.hxx>

#include <QtWidgets/QDockWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>

template<class BlockEntity>
ForgBaseLib::SplitWidget<BlockEntity>::SplitWidget
(
	FrgString name,
	FrgBaseMainWindow* parentMainWindow,
	FrgBaseCADPartFeatureEntity<BlockEntity>* featureEntity,
	std::shared_ptr<typename Entity_From_BlockEntity<BlockEntity>::typeManager> manager,
	QList<FrgBaseCADScene*> pointerToScenes,
	FrgBaseCADPart_Entity* parentPart
)
	: SplitWidget_Base(name, parentMainWindow, pointerToScenes, parentPart)
{
	theWidgetItems_ = new WidgetItemsStruct;

	theWidgetItems_->theMainLayout_ = new QVBoxLayout(this);
	theWidgetItems_->theNameLayout_ = new QHBoxLayout(this);
	theWidgetItems_->theButtonsLayout_ = new QHBoxLayout(this);

	theTree_ = FrgNew SplitTree<BlockEntity>(theParentMainWindow_, featureEntity, manager, pointerToScenes, this, parentPart);

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

	theDockWidget_ = new QDockWidget("Split " + name, theParentMainWindow_);
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
inline void ForgBaseLib::SplitWidget<BlockEntity>::CloseButtonClicked()
{
	/*auto part = dynamic_cast<CADPartItem<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>, AutLib::Cad_BlockEntity<AutLib::TModel_Paired>>*>(theTree_->GetParentPart());
	if (!part)
	{
		std::cout << "The part is not type of CADPartItem<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>, AutLib::Cad_BlockEntity<AutLib::TModel_Paired>> in SplitTree::CloseButtonClickedForSurfaces()\n";
		return;
	}*/

	QList<QTreeWidgetItem*> items;
	items.push_back(theTree_->GetParentPart());
	auto scenes = theTree_->GetFeatureEntity()->GetPointerToCADSceneTreeItems();

	theParentMainWindow_->GetTreeWidget()->theDockWidget_->setEnabled(true);
	theParentMainWindow_->GetTreeWidget()->theDockWidget_->show();
	theParentMainWindow_->GetTreeWidget()->theDockWidget_->raise();
	theParentMainWindow_->removeDockWidget(theDockWidget_);

	auto listOfEntities = theTree_->GetFeatureEntity()->GetParentEntities()->GetFeatureListEntity();
	for (int iEntity = 0; iEntity < listOfEntities.size(); iEntity++)
	{
		theParentMainWindow_->GetTree()->GetItems().removeOne(listOfEntities[iEntity]);
		theTree_->GetFeatureEntity()->GetParentEntities()->removeChild(listOfEntities[iEntity]);
		std::cout << "iEntity = " << iEntity << std::endl;
	}
	listOfEntities.clear();

	std::vector<std::shared_ptr<BlockEntity>> entityBlocks;
	theTree_->GetEntityManager()->RetrieveTo(entityBlocks);

	for (int iBlock = 0; iBlock < theTree_->GetEntityManager()->NbBlocks(); iBlock++)
	{
		auto entityFeature = FrgNew FrgBaseCADPartFeatureEntity<BlockEntity>(entityBlocks[iBlock]->Name().c_str(), theTree_->GetFeatureEntity()->GetParentEntities());
		theParentMainWindow_->GetTree()->GetItems().push_back(entityFeature);
		listOfEntities.push_back(entityFeature);

		entityFeature->GetEntity() = entityBlocks[iBlock];
		entityFeature->setIcon(0, QIcon(Entity_From_BlockEntity<BlockEntity>::GetIcon()));

		entityFeature->GetParentPart() = theTree_->GetParentPart();
		entityFeature->GetParentEntities() = theTree_->GetFeatureEntity()->GetParentEntities();
		entityFeature->GetPointerToScenes() = thePointerToScenes_;

		theTree_->GetEntityManager()->UnSelectAll();
		theTree_->GetEntityManager()->RenameBlock(entityBlocks[iBlock], entityFeature->text(0).toStdString().c_str());
	}

	theTree_->GetFeatureEntity()->GetParentEntities()->GetParentEntitiesStored() = entityBlocks;
	//listOfEntities->Get part->GetSurfaces() = entityBlocks;

	theTree_->GetEntityManager()->UnSelectAll();



	auto tree = dynamic_cast<NihadTree*>(theParentMainWindow_->GetTree());

	if (!tree)
	{
		std::cout << "tree is null in SplitWidget::CloseButtonClickedForSurfaces()\n";
		return;
	}

	tree->ObjectsSelectedUpdateInSceneSlot
	(
		items,
		scenes,
		FrgFalse
	);

	for (int i = 0; i < theTree_->GetPointerToScenes().size(); i++)
		theTree_->GetPointerToScenes()[i]->GetParentTree() = theParentMainWindow_->GetTree();
}