#include <FrgBase_Tools_TItem.hxx>
#include <FrgBase_ToolsParameters_TItem.hxx>

ForgBaseLib::FrgBase_Tools_TItem::FrgBase_Tools_TItem
(
	const QString& itemTitle,
	FrgBase_TreeItem* parentItem,
	FrgBase_Tree* parentTree
)
	: ForgBaseLib::FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{

}

void ForgBaseLib::FrgBase_Tools_TItem::FormTItem()
{
	ForgBaseLib::FrgBase_TreeItem::FormTItem();

	auto parametersTItem = new FrgBase_ToolsParameters_TItem("Parameters", this, GetParentTree());
	parametersTItem->FormTItem();
}