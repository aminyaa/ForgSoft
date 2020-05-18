#include <FrgMarine_GeomPModelShipT01_TItem.hxx>
#include <FrgMarine_ShipT01Params_TItem.hxx>
#include <FrgBase_Global_Thread.hxx>

#include <LegModel_DispNo1.hxx>
#include <LegModel_ConstParameter.hxx>
#include <TopoDS_Shape.hxx>
#include <FrgMarine_GeomPModelPView_TItem.hxx>

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

	thePreviewTItem_ = new FrgMarine_GeomPModelPView_TItem("Preview", this, GetParentTree(), this->GetModel());

	connect(this, SIGNAL(ModelPerformedToPreviewSignal()), thePreviewTItem_, SLOT(UpdatePreviewSlot()));
}

ForgMarineLib::FrgMarine_GeomPModelShipT01_TItem::~FrgMarine_GeomPModelShipT01_TItem()
{
	FreePointer(theParameters_);
}

const TopoDS_Shape& ForgMarineLib::FrgMarine_GeomPModelShipT01_TItem::GetShape() const
{
	ExecuteFunctionInProcess(GetParentMainWindow(), std::dynamic_pointer_cast<tnbLib::LegModel_DispNo1>(theModel_)->Perform(), nullptr, nullptr);
	//std::dynamic_pointer_cast<tnbLib::LegModel_DispNo1>(theModel_)->Perform();
	return theModel_->Entity();
}