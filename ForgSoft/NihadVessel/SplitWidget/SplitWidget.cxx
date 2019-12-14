#include <SplitWidget.hxx>
#include <FrgBaseMainWindow.hxx>
#include <SplitTree.hxx>
#include <FrgBaseCADScene.hxx>
#include <CADPartItem.hxx>
#include <NihadTree.hxx>
#include <FrgBaseCADPartFeatures.hxx>

#include <QtWidgets/QDockWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>

ForgBaseLib::SplitWidget::SplitWidget
(
	FrgString name,
	FrgBaseMainWindow* parenMainWindow,
	SurfaceBlockPtr surfaceBlock,
	CurveBlockPtr curveBlock,
	QList<FrgBaseCADScene*> pointerToScenes,
	FrgBaseCADPart_Entity* parentPart
)
	: QWidget(parenMainWindow)
	, theParentMainWindow_(parenMainWindow)
{
	QVBoxLayout* mainLayout = new QVBoxLayout();
	QHBoxLayout* nameLayout = new QHBoxLayout();
	QHBoxLayout* buttonsLayout = new QHBoxLayout();

	theTree_ = FrgNew SplitTree(theParentMainWindow_, surfaceBlock, curveBlock, pointerToScenes, this, parentPart);

	QLabel* nameLabel = new QLabel("Name");
	theNameLineEdit_ = new QLineEdit();
	nameLayout->addWidget(nameLabel);
	nameLayout->addWidget(theNameLineEdit_);

	QPushButton* createButton = new QPushButton("Create");
	QPushButton* closeButton = new QPushButton("Close");
	buttonsLayout->addStretch(1);
	buttonsLayout->addWidget(createButton);
	buttonsLayout->addWidget(closeButton);

	mainLayout->addWidget(theTree_);
	mainLayout->addLayout(nameLayout);
	mainLayout->addLayout(buttonsLayout);
	
	QWidget* mainWidget = new QWidget();
	mainWidget->setLayout(mainLayout);

	theDockWidget_ = new QDockWidget("Split " + name, theParentMainWindow_);
	theDockWidget_->setTitleBarWidget(new QWidget);
	theParentMainWindow_->tabifyDockWidget(theParentMainWindow_->GetTreeWidget()->theDockWidget_, theDockWidget_);
	theParentMainWindow_->tabifiedDockWidgetActivated(theDockWidget_);
	theParentMainWindow_->GetTreeWidget()->theDockWidget_->setEnabled(false);
	theDockWidget_->setWidget(mainWidget);

	theDockWidget_->show();
	theDockWidget_->raise();

	connect(createButton, SIGNAL(clicked()), theTree_, SLOT(CreateButtonClickedSlot()));
	connect(closeButton, SIGNAL(clicked()), this, SLOT(CloseButtonClickedSlot()));
}

void ForgBaseLib::SplitWidget::CloseButtonClickedSlot()
{
	auto part = dynamic_cast<CADPartItem<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>, AutLib::Cad_BlockEntity<AutLib::TModel_Paired>>*>(theTree_->GetParentPart());
	if (!part)
	{
		std::cout << "The part is not type of CADPartItem<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>, AutLib::Cad_BlockEntity<AutLib::TModel_Paired>> in SplitTree::CloseButtonClickedSlot()\n";
		return;
	}

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
	}

	//QList<QTreeWidgetItem*> items;
	//items.push_back(part);
	//dynamic_cast<NihadTree*>(theParentMainWindow_->GetTree())->ObjectsSelectedUpdateInSceneSlot(items, part->GetFeatures()->GetSurfacesEntity()->GetFeatureEntity(0)->GetPointerToScenes());

	part->GetSurfaces() = surfaceBlocks;

	/*for (int iBlock = 0; iBlock < surfaceManager->NbBlocks(); iBlock++)
	{
		part->GetFeatures()->GetSurfacesEntity()->GetFeatureListEntity().push_back(FrgNew FrgBaseCADPartFeatureEntity<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>>(surfaceBlocks[iBlock]->Name().c_str(), part->GetFeatures()->GetSurfacesEntity()));
		part->GetFeatures()->GetSurfacesEntity()->GetFeatureEntity(iBlock)->GetEntity() = surfaceBlocks[iBlock];
		part->GetFeatures()->GetSurfacesEntity()->GetFeatureEntity(iBlock)->setIcon(0, QIcon(FrgICONTreeItemPartSurface));
		part->GetFeatures()->GetSurfacesEntity()->GetFeatureEntity(iBlock)->GetParentPart() = part;
	}*/

	this->deleteLater();
}