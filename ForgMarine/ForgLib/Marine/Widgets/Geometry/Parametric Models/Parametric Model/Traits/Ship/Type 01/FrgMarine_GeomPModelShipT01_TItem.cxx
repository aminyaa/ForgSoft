#include <FrgMarine_GeomPModelShipT01_TItem.hxx>
#include <FrgMarine_ShipT01Params_TItem.hxx>
#include <FrgBase_Global_Thread.hxx>

#include <LegModel_DispNo1.hxx>
#include <LegModel_ConstParameter.hxx>
#include <TopoDS_Shape.hxx>
#include <FrgMarine_GeomPModelPView_TItem.hxx>
#include <FrgBase_Tree.hxx>

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

	//theParameters_->setHidden(true);

	connect(theParameters_, SIGNAL(ModelPerformedToPreviewSignal()), this, SIGNAL(ModelPerformedToPreviewSignal()));

	shipModel->PerformToPreview();
}

ForgMarineLib::FrgMarine_GeomPModelShipT01_TItem::~FrgMarine_GeomPModelShipT01_TItem()
{
	FreePointer(theParameters_);
}

void ForgMarineLib::FrgMarine_GeomPModelShipT01_TItem::FormTItem()
{
	FrgMarine_GeomPModelShip_TItem::FormTItem();

	thePreviewTItem_ = new FrgMarine_GeomPModelPView_TItem("Preview", this, GetParentTree(), this->GetModel());
	thePreviewTItem_->FormTItem();

	connect(this, SIGNAL(ModelPerformedToPreviewSignal()), thePreviewTItem_, SLOT(UpdatePreviewSlot()));
}

const TopoDS_Shape& ForgMarineLib::FrgMarine_GeomPModelShipT01_TItem::GetShape() const
{
	ExecuteFunctionInProcess(GetParentMainWindow(), std::dynamic_pointer_cast<tnbLib::LegModel_DispNo1>(theModel_)->Perform(), nullptr, nullptr);
	//std::dynamic_pointer_cast<tnbLib::LegModel_DispNo1>(theModel_)->Perform();
	return theModel_->Entity();
}

DECLARE_SAVE_IMP(ForgMarineLib::FrgMarine_GeomPModelShipT01_TItem)
{
	VOID_CAST_REGISTER(ForgMarineLib::FrgMarine_GeomPModelShipT01_TItem, ForgMarineLib::FrgMarine_GeomPModel_TItem);
	VOID_CAST_REGISTER(ForgMarineLib::FrgMarine_GeomPModelShipT01_TItem, ForgBaseLib::FrgBase_TreeItem);

	ar & thePreviewTItem_;
}

DECLARE_LOAD_IMP(ForgMarineLib::FrgMarine_GeomPModelShipT01_TItem)
{
	VOID_CAST_REGISTER(ForgMarineLib::FrgMarine_GeomPModelShipT01_TItem, ForgMarineLib::FrgMarine_GeomPModel_TItem);
	VOID_CAST_REGISTER(ForgMarineLib::FrgMarine_GeomPModelShipT01_TItem, ForgBaseLib::FrgBase_TreeItem);

	ar & thePreviewTItem_;
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPModelShipT01_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_GeomPModelShipT01_TItem);
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPModelShipT01_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgMarineLib::FrgMarine_GeomPModelShipT01_TItem);
}

BOOST_CLASS_EXPORT_CXX(ForgMarineLib::FrgMarine_GeomPModelShipT01_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgMarineLib::FrgMarine_GeomPModelShipT01_TItem)