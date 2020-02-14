#include <FrgMarine_ShipT01Params_TItem.hxx>
#include <FrgMarine_ShipT01ParamsDim_TItem.hxx>
#include <FrgMarine_ShipT01ParamsHull_TItem.hxx>
#include <FrgMarine_ShipT01ParamsKeel_TItem.hxx>
#include <FrgMarine_ShipT01ParamsStem_TItem.hxx>
#include <FrgMarine_ShipT01ParamsTransom_TItem.hxx>

#include <FrgBase_Global_Icons.hxx>

ForgMarineLib::FrgMarine_ShipT01Params_TItem::FrgMarine_ShipT01Params_TItem
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

	theDimension_ = new FrgMarine_ShipT01ParamsDim_TItem("Dimensions", this, parentTree, model, this);
	theHull_ = new FrgMarine_ShipT01ParamsHull_TItem("Hull", this, parentTree, model, this);
	theKeel_ = new FrgMarine_ShipT01ParamsKeel_TItem("Keel", this, parentTree, model, this);
	theStem_ = new FrgMarine_ShipT01ParamsStem_TItem("Stem", this, parentTree, model, this);
	theTransom_ = new FrgMarine_ShipT01ParamsTransom_TItem("Transom", this, parentTree, model, this);
}