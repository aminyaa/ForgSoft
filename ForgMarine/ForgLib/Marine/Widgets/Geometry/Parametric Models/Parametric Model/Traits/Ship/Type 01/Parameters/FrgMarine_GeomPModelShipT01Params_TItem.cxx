#include <FrgMarine_GeomPModelShipT01Params_TItem.hxx>
#include <FrgMarine_GeomPModelShipT01Params_Dimensions_TItem.hxx>
#include <FrgMarine_GeomPModelShipT01Params_Hull_TItem.hxx>
#include <FrgMarine_GeomPModelShipT01Params_Keel_TItem.hxx>
#include <FrgMarine_GeomPModelShipT01Params_Stem_TItem.hxx>
#include <FrgMarine_GeomPModelShipT01Params_Transom_TItem.hxx>

#include <FrgBase_Global_Icons.hxx>

ForgMarineLib::FrgMarine_GeomPModelShipT01Params_TItem::FrgMarine_GeomPModelShipT01Params_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree,
	std::shared_ptr<tnbLib::LegModel_DispNo1> model
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
	, theModel(model)
{
	this->setIcon(0, QIcon(ICONTreeItemPIcon));

	theDimension_ = new FrgMarine_GeomPModelShipT01Params_Dimensions_TItem("Dimensions", this, parentTree, model, this);
	theHull_ = new FrgMarine_GeomPModelShipT01Params_Hull_TItem("Hull", this, parentTree, model, this);
	theKeel_ = new FrgMarine_GeomPModelShipT01Params_Keel_TItem("Keel", this, parentTree, model, this);
	theStem_ = new FrgMarine_GeomPModelShipT01Params_Stem_TItem("Stem", this, parentTree, model, this);
	theTransom_ = new FrgMarine_GeomPModelShipT01Params_Transom_TItem("Transom", this, parentTree, model, this);
}