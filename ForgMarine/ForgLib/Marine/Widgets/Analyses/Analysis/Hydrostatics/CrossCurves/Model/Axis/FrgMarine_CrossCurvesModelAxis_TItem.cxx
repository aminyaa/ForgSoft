#include <FrgMarine_CrossCurvesModelAxis_TItem.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_PropertiesPanel.hxx>

#include <Entity3d_Box.hxx>

ForgMarineLib::FrgMarine_CrossCurvesModelAxis_TItem::FrgMarine_CrossCurvesModelAxis_TItem
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
	items.push_back("XOY");
	items.push_back("ZOX");
	items.push_back("YOZ");
	thePlane_ = new ForgBaseLib::FrgBase_PrptsVrntCombo(items, "Plane", "XOY");

	const auto ym = 0.5*(theBox_->P0().Y() + theBox_->P1().Y());
	theLocation_ = new ForgBaseLib::FrgBase_PrptsVrntPnt3d ("Location", new ForgBaseLib::Pnt3d_Data(theBox_->P0().X(), ym, theBox_->P0().Z()));
	const auto& pt = theLocation_->GetValue();

	theAxis_ = gp::XOY();
	theAxis_.SetLocation(tnbLib::Pnt3d(pt->theX_, pt->theY_, pt->theZ_));

	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntCombo>(thePlane_);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntPnt3d>(theLocation_);
}

ForgMarineLib::FrgMarine_CrossCurvesModelAxis_TItem::~FrgMarine_CrossCurvesModelAxis_TItem()
{
	FreePointer(thePlane_);
	FreePointer(theLocation_);

	theBox_ = nullptr;
}