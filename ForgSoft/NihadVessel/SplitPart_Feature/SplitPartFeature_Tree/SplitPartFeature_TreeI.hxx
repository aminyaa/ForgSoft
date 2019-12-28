#pragma once
#include <FrgBaseCADPart_Features.hxx>
#include <SplitPartFeature_Traits.hxx>
#include <SplitPartFeature_Widget.hxx>

template<class BlockEntity>
inline ForgBaseLib::SplitPartFeature_Tree<BlockEntity>::SplitPartFeature_Tree
(
	FrgBaseMainWindow * parentMainWindow,
	FrgBaseCADPart_Feature<BlockEntity>* partFeature
)
	: SplitPartFeature_Tree_Base(parentMainWindow, partFeature)
	, thePartFeature_(partFeature)
{
	FormTree();
}

template<class BlockEntity>
inline void ForgBaseLib::SplitPartFeature_Tree<BlockEntity>::FormTree()
{
	std::vector<std::shared_ptr<Entity_From_BlockEntity<BlockEntity>::type>> entities;
	thePartFeature_->GetFeatureEntity()->RetrieveEntitiesTo(entities);

	for (int iEntity = 0; iEntity < entities.size(); iEntity++)
	{
		auto item = FrgNew FrgBaseCADPart_Feature<Entity_From_BlockEntity<BlockEntity>::type>
			(QString::number(entities[iEntity]->Index()), this, thePartFeature_->GetParentPart());

		item->GetFeatureEntity() = entities[iEntity];

		item->setIcon(0, QIcon(Entity_From_BlockEntity<BlockEntity>::GetIcon()));
		GetItems().push_back(item);
	}
}

template<class BlockEntity>
inline void ForgBaseLib::SplitPartFeature_Tree<BlockEntity>::CreateButtonClicked()
{
	theParentSplitWidget_->GetNameLineEdit()->setText(theParentSplitWidget_->GetNameLineEdit()->text().simplified());
	auto blockName = theParentSplitWidget_->GetNameLineEdit()->text().toStdString();

	if (blockName == "")
		return;

	auto selected = this->selectedItems();
	auto partManager = theParentSplitWidget_->GetPartManager();

	if (!selected.isEmpty())
	{
		int nbTreeChildren = this->topLevelItemCount();
		partManager->SelectBlockEntity(thePartFeature_->GetFeatureEntity()->Name());

		if (selected.size() != nbTreeChildren)
		{

			for (int iSelected = 0; iSelected < selected.size(); iSelected++)
			{
				auto modelEntity = dynamic_cast<FrgBaseCADPart_Feature<Entity_From_BlockEntity<BlockEntity>::type>*>(selected[iSelected]);
				thePartFeature_->GetFeatureEntity()->SelectEntity(modelEntity->GetFeatureEntity()->Index());

				this->takeTopLevelItem(this->indexOfTopLevelItem(selected[iSelected]));
			}
			partManager->Split(blockName);
		}
		else
		{
			partManager->RenameBlock(thePartFeature_->GetFeatureEntity(), blockName.c_str());
			partManager->UnSelectAll();
			theParentSplitWidget_->CloseButtonClicked();
		}

		partManager->UnSelectAll();
	}

	theParentSplitWidget_->GetNameLineEdit()->setText("");
}