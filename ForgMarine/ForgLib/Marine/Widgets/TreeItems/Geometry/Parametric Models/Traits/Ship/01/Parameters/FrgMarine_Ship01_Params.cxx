#include <FrgMarine_Ship01_Params.hxx>
#include <FrgMarine_Ship01Params_Dimensions.hxx>
#include <FrgMarine_Ship01Params_Hull.hxx>
#include <FrgMarine_Ship01Params_Keel.hxx>
#include <FrgMarine_Ship01Params_Stem.hxx>
#include <FrgMarine_Ship01Params_Transom.hxx>

#include <FrgBase_Global_Icons.hxx>

ForgMarineLib::FrgMarine_Ship01_Params::FrgMarine_Ship01_Params
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

	theDimension_ = new FrgMarine_Ship01Params_Dimensions("Dimensions", this, parentTree, model, this);
	theHull_ = new FrgMarine_Ship01Params_Hull("Hull", this, parentTree, model, this);
	theKeel_ = new FrgMarine_Ship01Params_Keel("Keel", this, parentTree, model, this);
	theStem_ = new FrgMarine_Ship01Params_Stem("Stem", this, parentTree, model, this);
	theTransom_ = new FrgMarine_Ship01Params_Transom("Transom", this, parentTree, model, this);
}