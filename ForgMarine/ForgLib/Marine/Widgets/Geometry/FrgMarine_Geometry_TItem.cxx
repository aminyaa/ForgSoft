#include <FrgMarine_Geometry_TItem.hxx>
#include <FrgMarine_GeomPModels_TItem.hxx>
#include <FrgMarine_GeomParts_TItem.hxx>

ForgMarineLib::FrgMarine_Geometry_TItem::FrgMarine_Geometry_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	theParametricModels_ = new FrgMarine_GeomPModels_TItem("Parametric Models", this, parentTree);
	theParts_ = new FrgMarine_GeomParts_TItem("Parts", this, parentTree);
}

ForgMarineLib::FrgMarine_Geometry_TItem::~FrgMarine_Geometry_TItem()
{
	FreePointer(theParts_);
	FreePointer(theParametricModels_);
}