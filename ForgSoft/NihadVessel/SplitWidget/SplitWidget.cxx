#include <SplitWidget.hxx>
#include <FrgBaseMainWindow.hxx>
#include <SplitTree.hxx>
#include <FrgBaseCADScene.hxx>
#include <CADPartItem.hxx>
#include <NihadTree.hxx>
#include <FrgBaseCADPartFeatures.hxx>
#include <FrgBase_CADScene_TreeItem.hxx>
#include <FrgBaseTreeItem.hxx>

#include <QtWidgets/QDockWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>

ForgBaseLib::SplitWidget_Base::SplitWidget_Base
(
	FrgString name,
	FrgBaseMainWindow* parentMainWindow,
	QList<FrgBaseCADScene*> pointerToScenes,
	FrgBaseCADPart_Entity* parentPart
)
	: QWidget(theParentMainWindow_)
{
}

//ForgBaseLib::SplitWidget::SplitWidget
//(
//	FrgString name,
//	FrgBaseMainWindow* parentMainWindow,
//	SurfaceBlockPtr surfaceBlock,
//	CurveBlockPtr curveBlock,
//	QList<FrgBaseCADScene*> pointerToScenes,
//	FrgBaseCADPart_Entity* parentPart
//)
//	: QWidget(parentMainWindow)
//	, theParentMainWindow_(parentMainWindow)
//{
//	theWidgetItems_ = new WidgetItemsStruct;
//
//	theWidgetItems_->theMainLayout_ = new QVBoxLayout(this);
//	theWidgetItems_->theNameLayout_ = new QHBoxLayout(this);
//	theWidgetItems_->theButtonsLayout_ = new QHBoxLayout(this);
//
//	theTree_ = FrgNew SplitTree(theParentMainWindow_, surfaceBlock, curveBlock, pointerToScenes, this, parentPart);
//
//	theWidgetItems_->theNameLabel_ = new QLabel("Name");
//	theNameLineEdit_ = new QLineEdit(this);
//	theWidgetItems_->theNameLayout_->addWidget(theWidgetItems_->theNameLabel_);
//	theWidgetItems_->theNameLayout_->addWidget(theNameLineEdit_);
//
//	theCreateButton_ = new QPushButton("Create", this);
//	theCloseButton_ = new QPushButton("Close", this);
//	theWidgetItems_->theButtonsLayout_->addStretch(1);
//	theWidgetItems_->theButtonsLayout_->addWidget(theCreateButton_);
//	theWidgetItems_->theButtonsLayout_->addWidget(theCloseButton_);
//
//	theWidgetItems_->theMainLayout_->addWidget(theTree_);
//	theWidgetItems_->theMainLayout_->addLayout(theWidgetItems_->theNameLayout_);
//	theWidgetItems_->theMainLayout_->addLayout(theWidgetItems_->theButtonsLayout_);
//
//	theWidgetItems_->theMainWidget_ = new QWidget(this);
//	theWidgetItems_->theMainWidget_->setLayout(theWidgetItems_->theMainLayout_);
//
//	theDockWidget_ = new QDockWidget("Split " + name, theParentMainWindow_);
//	theDockWidget_->setTitleBarWidget(new QWidget(this));
//	theParentMainWindow_->tabifyDockWidget(theParentMainWindow_->GetTreeWidget()->theDockWidget_, theDockWidget_);
//	theParentMainWindow_->tabifiedDockWidgetActivated(theDockWidget_);
//	theParentMainWindow_->GetTreeWidget()->theDockWidget_->setEnabled(false);
//	theDockWidget_->setWidget(theWidgetItems_->theMainWidget_);
//
//	theDockWidget_->show();
//	theDockWidget_->raise();
//
//	connect(theCreateButton_, SIGNAL(clicked()), theTree_, SLOT(CreateButtonClickedSlot()));
//	connect(theCloseButton_, SIGNAL(clicked()), this, SLOT(CloseButtonClickedSlot()));
//}

//ForgBaseLib::SplitWidget::~SplitWidget()
//{
//	this->deleteLater();
//}

void ForgBaseLib::SplitWidget_Base::CloseButtonClickedSlot()
{
	CloseButtonClicked();

	/*if (theTree_->GetSurfaceBlock())
		CloseButtonClickedForSurfaces();
	if (theTree_->GetCurveBlock())
		CloseButtonClickedForCurves();*/
}

void ForgBaseLib::SplitWidget::CloseButtonClickedForSurfaces()
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

void ForgBaseLib::SplitWidget::CloseButtonClickedForCurves()
{
	auto part = dynamic_cast<CADPartItem<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>, AutLib::Cad_BlockEntity<AutLib::TModel_Paired>>*>(theTree_->GetParentPart());
	if (!part)
	{
		std::cout << "The part is not type of CADPartItem<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>, AutLib::Cad_BlockEntity<AutLib::TModel_Paired>> in SplitTree::CloseButtonClickedForCurves()\n";
		return;
	}

	QList<QTreeWidgetItem*> items;
	items.push_back(part);
	auto scenes = part->GetFeatures()->GetCurvesEntity()->GetFeatureEntity(0)->GetPointerToCADSceneTreeItems();

	theParentMainWindow_->GetTreeWidget()->theDockWidget_->setEnabled(true);
	theParentMainWindow_->GetTreeWidget()->theDockWidget_->show();
	theParentMainWindow_->GetTreeWidget()->theDockWidget_->raise();
	theParentMainWindow_->removeDockWidget(theDockWidget_);

	auto listOfCurves = part->GetFeatures()->GetCurvesEntity()->GetFeatureListEntity();
	for (int iCurve = 0; iCurve < listOfCurves.size(); iCurve++)
	{
		theParentMainWindow_->GetTree()->GetItems().removeOne(listOfCurves[iCurve]);
		part->GetFeatures()->GetCurvesEntity()->removeChild(listOfCurves[iCurve]);
	}
	part->GetFeatures()->GetCurvesEntity()->GetFeatureListEntity().clear();

	std::vector<std::shared_ptr<AutLib::Cad_BlockEntity<AutLib::TModel_Paired>>> curveBlocks;
	auto curveManager = part->GetModel()->Segments();
	curveManager->RetrieveTo(curveBlocks);

	for (int iBlock = 0; iBlock < curveManager->NbBlocks(); iBlock++)
	{
		auto curveFeature = FrgNew FrgBaseCADPartFeatureEntity<AutLib::Cad_BlockEntity<AutLib::TModel_Paired>>(curveBlocks[iBlock]->Name().c_str(), part->GetFeatures()->GetCurvesEntity());
		theParentMainWindow_->GetTree()->GetItems().push_back(curveFeature);
		part->GetFeatures()->GetCurvesEntity()->GetFeatureListEntity().push_back(curveFeature);

		curveFeature->GetEntity() = curveBlocks[iBlock];
		curveFeature->setIcon(0, QIcon(FrgICONTreeItemPartCurve));

		curveFeature->GetParentPart() = part;

		curveManager->UnSelectAll();
		curveManager->RenameBlock(curveBlocks[iBlock], curveFeature->text(0).toStdString().c_str());
	}

	part->GetCurves() = curveBlocks;

	part->GetModel()->Segments()->UnSelectAll();

	auto tree = dynamic_cast<NihadTree*>(theParentMainWindow_->GetTree());
	
	if (!tree)
	{
		std::cout << "tree is null in SplitWidget::CloseButtonClickedForCurves()\n";
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