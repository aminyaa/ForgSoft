#include <FrgMarine_TItem_Geom.hxx>
#include <FrgMarine_TItemGeom_ParMdls.hxx>

ForgMarineLib::FrgMarine_TItem_Geom::FrgMarine_TItem_Geom
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	theParametricModels_ = new FrgMarine_TItemGeom_ParMdls("Parametric Models", this, parentTree);
}