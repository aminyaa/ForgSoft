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
#include <CADPartItem.hxx>

#include <vtkActor.h>
#include <vtkRenderWindow.h>

#include <QtGui/QIcon>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QDockWidget>

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
	, theParentPart_(parentPart)
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

	if (theCurveBlock_)
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
			if (!scene) continue;

			scene->CreateActor(surfaces[iSurface], item);
			scene->GetParentTree() = this;
		}

		//auto item = FrgNew FrgBaseTreeItem(QString::number(surfaces[iSurface]->Index()), FrgNullPtr, this, theParentMainWindow_);
		item->setIcon(0, QIcon(FrgICONTreeItemPartSurface));
		GetItems().push_back(item);
	}

	for (int iCurve = 0; iCurve < curves.size(); iCurve++)
	{
		auto item = FrgNew FrgBaseCADPartFeatureEntity<AutLib::TModel_Paired>(QString::number(curves[iCurve]->Index()), this);
		item->GetEntity() = curves[iCurve];
		item->GetPointerToScenes() = thePointerToScenes_;

		for (int iScene = 0; iScene < thePointerToScenes_.size(); iScene++)
		{
			auto scene = dynamic_cast<CADScene*>(thePointerToScenes_[iScene]);
			if (!scene) continue;

			scene->CreateActor(curves[iCurve], item);
			scene->GetParentTree() = this;
		}

		//auto item = FrgNew FrgBaseTreeItem(QString::number(surfaces[iSurface]->Index()), FrgNullPtr, this, theParentMainWindow_);
		item->setIcon(0, QIcon(FrgICONTreeItemPartCurve));
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
	theParentSplitWidget_->GetNameLineEdit()->setText(theParentSplitWidget_->GetNameLineEdit()->text().simplified());
	auto blockName = theParentSplitWidget_->GetNameLineEdit()->text().toStdString();

	if (blockName == "")
		return;

	auto selected = this->selectedItems();

	if (!selected.isEmpty())
	{
		int nbTreeChildren = this->topLevelItemCount();
		auto part = dynamic_cast<CADPartItem<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>, AutLib::Cad_BlockEntity<AutLib::TModel_Paired>>*>(theParentPart_);
		if (!part)
		{
			std::cout << "The part is not type of CADPartItem<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>, AutLib::Cad_BlockEntity<AutLib::TModel_Paired>> in SplitTree::CreateButtonClickedSlot()\n";
			return;
		}

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

		if (theSurfaceBlock_)
		{
			if (selected.size() == nbTreeChildren)
			{
				part->GetModel()->Faces()->RenameBlock(CorrectName<FrgBaseTreeItem>(part->GetFeatures()->GetSurfacesEntity(), blockName.c_str()).toStdString().c_str());
				theParentSplitWidget_->CloseButtonClickedSlot();
			}
			else
			{
				part->GetModel()->Faces()->Split(CorrectName<FrgBaseTreeItem>(part->GetFeatures()->GetSurfacesEntity(), blockName.c_str()).toStdString().c_str());
				part->GetModel()->Faces()->SelectBlockEntity(theSurfaceBlock_->Name());
			}
		}
		else if (theCurveBlock_)
		{
			if (selected.size() == nbTreeChildren)
			{
				part->GetModel()->Segments()->RenameBlock(CorrectName<FrgBaseTreeItem>(part->GetFeatures()->GetCurvesEntity(), blockName.c_str()).toStdString().c_str());
				theParentSplitWidget_->CloseButtonClickedSlot();
			}
			else
			{
				part->GetModel()->Segments()->Split(CorrectName<FrgBaseTreeItem>(part->GetFeatures()->GetCurvesEntity(), blockName.c_str()).toStdString().c_str());
				part->GetModel()->Segments()->SelectBlockEntity(theCurveBlock_->Name());
			}
		}
	}

	/*the*/

	theParentSplitWidget_->GetNameLineEdit()->setText("");
}