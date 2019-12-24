#pragma once
#include <SplitWidget.hxx>

template<class Entity>
ForgBaseLib::SplitWidget<Entity>::SplitWidget
(
	FrgString name,
	FrgBaseMainWindow* parentMainWindow,
	QList<FrgBaseCADScene*> pointerToScenes,
	FrgBaseCADPart_Entity* parentPart
)
	: SplitWidget_Base(name, parentMainWindow, pointerToScenes, parentPart)
{
	theWidgetItems_ = new WidgetItemsStruct;

	theWidgetItems_->theMainLayout_ = new QVBoxLayout(this);
	theWidgetItems_->theNameLayout_ = new QHBoxLayout(this);
	theWidgetItems_->theButtonsLayout_ = new QHBoxLayout(this);

	theTree_ = FrgNew SplitTree(theParentMainWindow_, surfaceBlock, curveBlock, pointerToScenes, this, parentPart);

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
	QObject::connect(theCloseButton_, SIGNAL(clicked()), dynamic_cast<SplitWidget_Base*>(this), SLOT(CloseButtonClickedSlot()));
}

template<class Entity>
inline void ForgBaseLib::SplitWidget<Entity>::CloseButtonClicked()
{
	auto part = dynamic_cast<CADPartItem<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>, AutLib::Cad_BlockEntity<AutLib::TModel_Paired>>*>(theTree_->GetParentPart());
	if (!part)
	{
		std::cout << "The part is not type of CADPartItem<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>, AutLib::Cad_BlockEntity<AutLib::TModel_Paired>> in SplitTree::CloseButtonClickedForSurfaces()\n";
		return;
	}

	QList<QTreeWidgetItem*> items;
	items.push_back(part);
	auto scenes = part->GetFeatures()->GetSurfacesEntity()->GetFeatureEntity(0)->GetPointerToCADSceneTreeItems();

	theParentMainWindow_->GetTreeWidget()->theDockWidget_->setEnabled(true);
	theParentMainWindow_->GetTreeWidget()->theDockWidget_->show();
	theParentMainWindow_->GetTreeWidget()->theDockWidget_->raise();
	theParentMainWindow_->removeDockWidget(theDockWidget_);

	auto listOfSurfaces = part->GetFeatures()->GetSurfacesEntity()->GetFeatureListEntity();
	for (int iSurface = 0; iSurface < listOfSurfaces.size(); iSurface++)
	{
		theParentMainWindow_->GetTree()->GetItems().removeOne(listOfSurfaces[iSurface]);
		part->GetFeatures()->GetSurfacesEntity()->removeChild(listOfSurfaces[iSurface]);
	}
	part->GetFeatures()->GetSurfacesEntity()->GetFeatureListEntity().clear();

	std::vector<std::shared_ptr<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>>> surfaceBlocks;
	auto surfaceManager = part->GetModel()->Faces();
	surfaceManager->RetrieveTo(surfaceBlocks);

	for (int iBlock = 0; iBlock < surfaceManager->NbBlocks(); iBlock++)
	{
		auto surfaceFeature = FrgNew FrgBaseCADPartFeatureEntity<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>>(surfaceBlocks[iBlock]->Name().c_str(), part->GetFeatures()->GetSurfacesEntity());
		theParentMainWindow_->GetTree()->GetItems().push_back(surfaceFeature);
		part->GetFeatures()->GetSurfacesEntity()->GetFeatureListEntity().push_back(surfaceFeature);

		surfaceFeature->GetEntity() = surfaceBlocks[iBlock];
		surfaceFeature->setIcon(0, QIcon(FrgICONTreeItemPartSurface));

		surfaceFeature->GetParentPart() = part;

		surfaceManager->UnSelectAll();
		surfaceManager->RenameBlock(surfaceBlocks[iBlock], surfaceFeature->text(0).toStdString().c_str());
	}

	part->GetSurfaces() = surfaceBlocks;

	part->GetModel()->Faces()->UnSelectAll();



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