#include <FrgVisual_Plot2DAxisEntity_TItem.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgVisual_Plot2DAxisTitle_TItem.hxx>

ForgVisualLib::FrgVisual_Plot2DAxisEntity_TItem::FrgVisual_Plot2DAxisEntity_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	theVisible_ = new ForgBaseLib::FrgBase_PrptsVrntBool("Visible", true);
	theLogarithmic_ = new ForgBaseLib::FrgBase_PrptsVrntBool("Logarithmic", false);

	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntBool>(theVisible_);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntBool>(theLogarithmic_);

	theTitleTItem_ = new FrgVisual_Plot2DAxisTitle_TItem("Title", this, parentTree);
}