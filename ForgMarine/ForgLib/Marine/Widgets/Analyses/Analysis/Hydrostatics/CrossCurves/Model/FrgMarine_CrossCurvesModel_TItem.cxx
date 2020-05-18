#include <FrgMarine_CrossCurvesModel_TItem.hxx>
#include <FrgMarine_CrossCurvesModelAxis_TItem.hxx>
#include <FrgMarine_CrossCurvesModelDistributor_TItem.hxx>
#include <FrgMarine_Tree.hxx>
#include <FrgMarine_Geometry_TItem.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_Global_Thread.hxx>

#include <Entity3d_Box.hxx>
#include <CrossSection_xShapeStation.hxx>
#include <TopoDS_Shape.hxx>

ForgMarineLib::FrgMarine_CrossCurvesModel_TItem::FrgMarine_CrossCurvesModel_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree,
	TopoDS_Shape* shape,
	tnbLib::Entity3d_Box* box
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	theAxisTItem_ = new FrgMarine_CrossCurvesModelAxis_TItem("Axis", this, GetParentTree(), box);
	theDistributorTItem_ = new FrgMarine_CrossCurvesModelDistributor_TItem("Distributor", this, GetParentTree(), box);

	theModel_ = std::make_shared<tnbLib::CrossSection_xShapeStation>(theAxisTItem_->GetAxis());
	theModel_->LoadShape(*shape);
	theModel_->LoadDistributor(theDistributorTItem_->GetDistribution());

	ExecuteFunctionInProcess(GetParentMainWindow(), theModel_->Perform(), nullptr, nullptr);
	//theModel_->Perform();
}

ForgMarineLib::FrgMarine_CrossCurvesModel_TItem::~FrgMarine_CrossCurvesModel_TItem()
{
	FreePointer(theAxisTItem_);
	FreePointer(theDistributorTItem_);
}