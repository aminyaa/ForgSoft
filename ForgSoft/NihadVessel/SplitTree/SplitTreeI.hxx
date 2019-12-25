#pragma once
#include <SplitTree.hxx>
#include <FrgBaseCADPartFeatures.hxx>
#include <SplitTree_Traits.hxx>

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

template<class BlockEntity>
ForgBaseLib::SplitTree<BlockEntity>::SplitTree
(
	FrgBaseMainWindow* parent,
	FrgBaseCADPartFeatureEntity<BlockEntity>* featureEntity,
	std::shared_ptr<typename Entity_From_BlockEntity<BlockEntity>::typeManager> manager,
	QList<FrgBaseCADScene*> pointerToScenes,
	SplitWidget<BlockEntity>* parentSplitWidget,
	FrgBaseCADPart_Entity* parentPart
)
	: SplitTree_Base(parent, pointerToScenes, parentPart)
	, theFeatureEntity_(featureEntity)
	, theParentSplitWidget_(parentSplitWidget)
	, theEntityManager_(manager)
{
	connect(this, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(itemInSplitTreeClickedSlot(QTreeWidgetItem*, int)));

	FormTree();
}

template<class BlockEntity>
inline void ForgBaseLib::SplitTree<BlockEntity>::FormTree()
{
	std::vector<std::shared_ptr<Entity_From_BlockEntity<BlockEntity>::type>> entities;

	theFeatureEntity_->GetEntity()->RetrieveEntitiesTo(entities);

	for (int iScene = 0; iScene < thePointerToScenes_.size(); iScene++)
		if (!(thePointerToScenes_[iScene]->GetActors().isEmpty()))
			for (int i = 0; i < thePointerToScenes_[iScene]->GetActors().size(); i++)
				thePointerToScenes_[iScene]->GetActors()[i]->SetVisibility(false);

	for (int iEntity = 0; iEntity < entities.size(); iEntity++)
	{
		auto item = FrgNew FrgBaseCADPartFeatureEntity<Entity_From_BlockEntity<BlockEntity>::type>(QString::number(entities[iEntity]->Index()), this);
		item->GetEntity() = entities[iEntity];
		item->GetPointerToScenes() = thePointerToScenes_;

		for (int iScene = 0; iScene < thePointerToScenes_.size(); iScene++)
		{
			auto scene = dynamic_cast<CADScene*>(thePointerToScenes_[iScene]);
			if (!scene) continue;

			scene->CreateActor(entities[iEntity], item);
			scene->GetParentTree() = this;
		}

		//auto item = FrgNew FrgBaseTreeItem(QString::number(surfaces[iSurface]->Index()), FrgNullPtr, this, theParentMainWindow_);
		item->setIcon(0, QIcon(Entity_From_BlockEntity<BlockEntity>::GetIcon()));
		GetItems().push_back(item);
	}
}

template<class BlockEntity>
inline void ForgBaseLib::SplitTree<BlockEntity>::CreateButtonClicked()
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

		if (theFeatureEntity_)
		{
			for (int iItem = 0; iItem < selected.size(); iItem++)
			{
				auto item = dynamic_cast<FrgBaseCADPartFeatureBase*>(selected[iItem]);
				if (!item)
					continue;

				theFeatureEntity_->GetEntity()->SelectEntity(std::stoi(selected[iItem]->text(0).toStdString().c_str()));
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

		if (theFeatureEntity_)
		{
			if (selected.size() == nbTreeChildren)
			{
				theEntityManager_->RenameBlock(blockName);
				theParentSplitWidget_->CloseButtonClickedSlot();
			}
			else
			{
				theEntityManager_->Split(blockName);
				theEntityManager_->SelectBlockEntity(theFeatureEntity_->GetEntity()->Name());
			}
		}
	}

	/*the*/

	theParentSplitWidget_->GetNameLineEdit()->setText("");
}