#include <SplitTree.hxx>
#include <FrgBaseCADPart.hxx>
#include <Cad_BlockEntity.hxx>
#include <TModel_Surface.hxx>
#include <TModel_Paired.hxx>
#include <FrgBaseMainWindow.hxx>
#include <FrgBaseGlobalsICONS.hxx>
#include <FrgBaseCADScene.hxx>
#include <CADScene.hxx>
#include <NihadTree.hxx>
#include <SplitWidget.hxx>
#include <FrgBaseCADPart.hxx>

#include <vtkActor.h>
#include <vtkRenderWindow.h>

#include <QtGui/QIcon>
#include <QtWidgets/QLineEdit>

ForgBaseLib::SplitTree::SplitTree
(
	FrgBaseMainWindow* parent,
	SurfaceBlockPtr surfaceBlock,
	CurveBlockPtr curveBlock,
	QList<FrgBaseCADScene*> pointerToScenes,
	SplitWidget* parentSplitWidget,
	FrgBaseCADPart_Entity* parentPart
)
	: FrgBaseTree(parent)
	, theSurfaceBlock_(surfaceBlock)
	, theCurveBlock_(curveBlock)
	, theParentMainWindow_(parent)
	, thePointerToScenes_(pointerToScenes)
	, theParentSplitWidget_(parentSplitWidget)
{
	connect(this, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(itemInSplitTreeClickedSlot(QTreeWidgetItem*, int)));

	FormTree();
}

void ForgBaseLib::SplitTree::FormTree()
{
	std::vector<std::shared_ptr<AutLib::TModel_Surface>> surfaces;
	std::vector<std::shared_ptr<AutLib::TModel_Paired>> curves;

	if (theSurfaceBlock_)
		theSurfaceBlock_->RetrieveEntitiesTo(surfaces);

	if(theCurveBlock_)
		theCurveBlock_->RetrieveEntitiesTo(curves);

	for (int iScene = 0; iScene < thePointerToScenes_.size(); iScene++)
		if (!(thePointerToScenes_[iScene]->GetActors().isEmpty()))
			for (int i = 0; i < thePointerToScenes_[iScene]->GetActors().size(); i++)
				thePointerToScenes_[iScene]->GetActors()[i]->SetVisibility(false);

	for (int iSurface = 0; iSurface < surfaces.size(); iSurface++)
	{
		auto item = FrgNew FrgBaseCADPartFeatureEntity<AutLib::TModel_Surface>(QString::number(surfaces[iSurface]->Index()), this);
		item->GetEntity() = surfaces[iSurface];
		item->GetPointerToScenes() = thePointerToScenes_;

		for (int iScene = 0; iScene < thePointerToScenes_.size(); iScene++)
		{
			auto scene = dynamic_cast<CADScene*>(thePointerToScenes_[iScene]);
			if(!scene) continue;

			scene->CreateActor(surfaces[iSurface], item);
		}

		//auto item = FrgNew FrgBaseTreeItem(QString::number(surfaces[iSurface]->Index()), FrgNullPtr, this, theParentMainWindow_);
		item->setIcon(0, QIcon(FrgICONTreeItemPartSurface));
		GetItems().push_back(item);
	}
}

void ForgBaseLib::SplitTree::itemInSplitTreeClickedSlot(QTreeWidgetItem* item, int column)
{
	FrgBaseTree::itemClickedSlot(item, column);

	auto tree = dynamic_cast<NihadTree*>(theParentMainWindow_->GetTree());

	if (!tree)
		return;

	tree->itemInSplitTreeClickedSlot(this, item, column);
}

void ForgBaseLib::SplitTree::CreateButtonClickedSlot()
{
	if (theParentSplitWidget_->GetNameLineEdit()->text().simplified() == "")
		return;

	auto selected = this->selectedItems();

	/*if(!selected.isEmpty())
		part = selected[0]*/

	if (theSurfaceBlock_)
	{
		for (int iItem = 0; iItem < selected.size(); iItem++)
		{
			auto item = dynamic_cast<FrgBaseCADPartFeatureBase*>(selected[iItem]);
			if (!item)
				continue;

			theSurfaceBlock_->SelectEntity(std::stoi(selected[iItem]->text(0).toStdString().c_str()));
			GetItems().removeOne(item);
			this->takeTopLevelItem(this->indexOfTopLevelItem(item));
			//this->removeItemWidget(selected[iItem], 0);
		}
	}

	else if (theCurveBlock_)
	{
		for (int iItem = 0; iItem < selected.size(); iItem++)
		{
			auto item = dynamic_cast<FrgBaseCADPartFeatureBase*>(selected[iItem]);
			if (!item)
				continue;

			theCurveBlock_->SelectEntity(std::stoi(selected[iItem]->text(0).toStdString().c_str()));
			GetItems().removeOne(item);
			this->takeTopLevelItem(this->indexOfTopLevelItem(item));
			//this->removeItemWidget(selected[iItem], 0);
		}
	}

	for (int iScene = 0; iScene < thePointerToScenes_.size(); iScene++)
	{
		for (int iItem = 0; iItem < selected.size(); iItem++)
		{
			auto item = dynamic_cast<FrgBaseCADPartFeatureBase*>(selected[iItem]);
			if (!item)
				continue;

			auto scene = dynamic_cast<CADScene*>(thePointerToScenes_[iScene]);
			if (!scene)
				continue;

			scene->RemoveActor(scene->GetPartFeatureToActor().value(item));
			scene->GetRenderWindow()->Render();
		}
	}

	/*the*/

	theParentSplitWidget_->GetNameLineEdit()->setText("");
}