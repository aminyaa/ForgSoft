#include <FrgVisual_Plot2DAxisTitle_TItem.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_PropertiesPanel.hxx>

ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem::FrgVisual_Plot2DAxisTitle_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	this->setIcon(0, QIcon(ICONTreeItemCircle));

	theVisible_ = new ForgBaseLib::FrgBase_PrptsVrntBool("Visible", true);
	theTitle_ = new ForgBaseLib::FrgBase_PrptsVrntString("Title", "X Axis");
	std::vector<const char*> items;
	items.push_back("0 degrees");
	items.push_back("90 degrees");
	items.push_back("180 degrees");
	items.push_back("270 degrees");
	theRotation_ = new ForgBaseLib::FrgBase_PrptsVrntCombo(items, "Rotation", "0 degrees");

	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntBool>(theVisible_);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntString>(theTitle_);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntCombo>(theRotation_);
}