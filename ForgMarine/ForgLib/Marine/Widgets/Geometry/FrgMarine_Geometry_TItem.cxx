#include <FrgMarine_Geometry_TItem.hxx>
#include <FrgMarine_GeomPModels_TItem.hxx>
#include <FrgMarine_GeomParts_TItem.hxx>

#include <FrgMarine_Tree.hxx>

ForgMarineLib::FrgMarine_Geometry_TItem::FrgMarine_Geometry_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	
}

ForgMarineLib::FrgMarine_Geometry_TItem::~FrgMarine_Geometry_TItem()
{
// 	FreePointer(theParts_);
// 	FreePointer(theParametricModels_);
}

void ForgMarineLib::FrgMarine_Geometry_TItem::FormTItem()
{
	theParametricModels_ = new FrgMarine_GeomPModels_TItem("Parametric Models", this, GetParentTree());
	theParametricModels_->FormTItem();

	theParts_ = new FrgMarine_GeomParts_TItem("Parts", this, GetParentTree());
	theParts_->FormTItem();
}

DECLARE_SAVE_IMP(ForgMarineLib::FrgMarine_Geometry_TItem)
{
	VOID_CAST_REGISTER(ForgMarineLib::FrgMarine_Geometry_TItem, ForgBaseLib::FrgBase_TreeItem)

	ar & theParametricModels_;
	ar & theParts_;
}

DECLARE_LOAD_IMP(ForgMarineLib::FrgMarine_Geometry_TItem)
{
	VOID_CAST_REGISTER(ForgMarineLib::FrgMarine_Geometry_TItem, ForgBaseLib::FrgBase_TreeItem)
	
	ar & theParametricModels_;
	ar & theParts_;
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_Geometry_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_Geometry_TItem)
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_Geometry_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_Geometry_TItem)
}

BOOST_CLASS_EXPORT_CXX(ForgMarineLib::FrgMarine_Geometry_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgMarineLib::FrgMarine_Geometry_TItem)