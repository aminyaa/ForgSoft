#include <FrgMarine_CrossCurvesHeel_TItem.hxx>
#include <FrgBase_PropertiesPanel.hxx>

#include <Geo_xDistb.hxx>
#include <MarineBase_Tools.hxx>

ForgMarineLib::FrgMarine_CrossCurvesHeel_TItem::FrgMarine_CrossCurvesHeel_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	theDegree0_ = new ForgBaseLib::FrgBase_PrptsVrntDouble("From:", 0.0, 0.0, 120.0, 0.5, "", "[deg]");
	theDegree1_ = new ForgBaseLib::FrgBase_PrptsVrntDouble("To:", 90.0, 0.0, 120.0, 0.5, "", "[deg]");
	theNbHeels_ = new ForgBaseLib::FrgBase_PrptsVrntInt("Number Of Divisions:", 10, 2, 100);

	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntDouble>(theDegree0_);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntDouble>(theDegree1_);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntInt>(theNbHeels_);

	theHeel_ = tnbLib::MarineBase_Tools::HeelDistb(theDegree0_->GetValue(), theDegree1_->GetValue(), theNbHeels_->GetValue());
}

ForgMarineLib::FrgMarine_CrossCurvesHeel_TItem::~FrgMarine_CrossCurvesHeel_TItem()
{
	FreePointer(theDegree0_);
	FreePointer(theDegree1_);
	FreePointer(theNbHeels_);
}