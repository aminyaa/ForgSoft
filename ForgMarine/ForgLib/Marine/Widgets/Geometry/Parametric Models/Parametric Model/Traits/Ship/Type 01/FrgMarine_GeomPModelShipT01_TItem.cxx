#include <FrgMarine_GeomPModelShipT01_TItem.hxx>
#include <FrgMarine_ShipT01Params_TItem.hxx>

#include <LegModel_DispNo1.hxx>
#include <LegModel_ConstParameter.hxx>

ForgMarineLib::FrgMarine_GeomPModelShipT01_TItem::FrgMarine_GeomPModelShipT01_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgMarine_GeomPModelShip_TItem(itemTitle, parentItem, parentTree)
{
	theModel_ = std::make_shared<tnbLib::LegModel_DispNo1>();
	auto shipModel = std::dynamic_pointer_cast<tnbLib::LegModel_DispNo1>(theModel_);

	//shipModel->Parameters().Draft() = std::make_shared<tnbLib::LegModel_ConstParameter>(1110, "Draft", 1.0);

	theParameters_ = new FrgMarine_ShipT01Params_TItem("Parameters", this, parentTree, shipModel);

	connect(theParameters_, SIGNAL(ModelPerformedToPreviewSignal()), this, SIGNAL(ModelPerformedToPreviewSignal()));

	shipModel->PerformToPreview();
}