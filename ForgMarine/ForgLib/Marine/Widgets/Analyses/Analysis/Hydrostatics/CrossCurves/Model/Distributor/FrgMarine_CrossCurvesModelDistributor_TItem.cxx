#include <FrgMarine_CrossCurvesModelDistributor_TItem.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_PropertiesPanel.hxx>

#include <Entity3d_Box.hxx>
#include <Marine_SectionDistribution_Uniform.hxx>

ForgMarineLib::FrgMarine_CrossCurvesModelDistributor_TItem::FrgMarine_CrossCurvesModelDistributor_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree,
	tnbLib::Entity3d_Box* box
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
	, theBox_(box)
{
	this->setIcon(0, QIcon(ICONTreeItemCircle));

	std::vector<const char*> items;
	items.push_back("Uniform");
	theDistributorVrnt_ = new ForgBaseLib::FrgBase_PrptsVrntCombo(items, "Distributor", "Uniform");

	theLower_ = new ForgBaseLib::FrgBase_PrptsVrntDouble("Lower", theBox_->P0().X(), -1000.0, 1000.0);
	theUpper_ = new ForgBaseLib::FrgBase_PrptsVrntDouble("Upper", theBox_->P1().X(), -1000.0, 1000.0);
	theNbSections_ = new ForgBaseLib::FrgBase_PrptsVrntInt("Number Of Sections", 30, 2, 300);

	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntCombo>(theDistributorVrnt_);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntDouble>(theLower_);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntDouble>(theUpper_);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntInt>(theNbSections_);

	theDistribution_ = std::make_shared<tnbLib::Marine_SectionDistribution_Uniform>();
	theDistribution_->SetLower(theLower_->GetValue());
	theDistribution_->SetUpper(theUpper_->GetValue());
	std::dynamic_pointer_cast<tnbLib::Marine_SectionDistribution_Uniform>(theDistribution_)->SetNbSections(theNbSections_->GetValue());
	theDistribution_->Perform();
}

ForgMarineLib::FrgMarine_CrossCurvesModelDistributor_TItem::~FrgMarine_CrossCurvesModelDistributor_TItem()
{
	FreePointer(theDistributorVrnt_);
	FreePointer(theLower_);
	FreePointer(theUpper_);
	FreePointer(theNbSections_);

	theBox_ = nullptr;
}