#include <FrgMarine_ShipT01ParamsKeel_TItem.hxx>
#include <FrgMarine_MainWindow.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgMarine_ShipT01Params_TItem.hxx>

#include <LegModel_DispNo1.hxx>

ForgMarineLib::FrgMarine_ShipT01ParamsKeel_TItem::FrgMarine_ShipT01ParamsKeel_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree,
	std::shared_ptr<tnbLib::LegModel_DispNo1> model,
	FrgMarine_ShipT01Params_TItem* parametersTItem
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
	, theModel_(model)
	, theParametersTItem_(parametersTItem)
{
	this->setIcon(0, QIcon(ICONTreeItemPSubIcon));

	double minValue = 0.0, maxValue = 1.0, stepValue = 0.05;
	const char* suffixNonDimensioned = "[-]";

	thePosition_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Position", theModel_->Parameters().Position()->Value(), minValue, maxValue, stepValue, "", suffixNonDimensioned);

	theRisePoint_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Rise Point", theModel_->Parameters().RisePoint()->Value(), minValue, maxValue, stepValue, "", suffixNonDimensioned);

	theRiseSlope_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Rise Slope", theModel_->Parameters().RiseSlope()->Value(), minValue, maxValue, stepValue, "", suffixNonDimensioned);

	theTransomSlope_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Transom Slope", theModel_->Parameters().TransomSlope()->Value(), minValue, maxValue, stepValue, "", suffixNonDimensioned);

	connect(thePosition_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(PositionValueChangedSlot()));
	connect(theRisePoint_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(RisePointValueChangedSlot()));
	connect(theRiseSlope_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(RiseSlopeValueChangedSlot()));
	connect(theTransomSlope_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(TransomSlopeValueChangedSlot()));

	//thePropertiesPanel_ = new ForgBaseLib::FrgBase_PropertiesPanel(GetParentMainWindow(), dynamic_cast<QObject*>(this));
	FormPropertiesPanel();
}

ForgMarineLib::FrgMarine_ShipT01ParamsKeel_TItem::~FrgMarine_ShipT01ParamsKeel_TItem()
{
	FreePointer(thePosition_);
	FreePointer(theRisePoint_);
	FreePointer(theRiseSlope_);
	FreePointer(theTransomSlope_);

	theParametersTItem_ = NullPtr;
}

void ForgMarineLib::FrgMarine_ShipT01ParamsKeel_TItem::PositionValueChangedSlot()
{
	if (theModel_->Parameters().Position()->Value() != thePosition_->GetValue())
	{
		theModel_->Parameters().Position()->Value() = thePosition_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsKeel_TItem::RisePointValueChangedSlot()
{
	if (theModel_->Parameters().RisePoint()->Value() != theRisePoint_->GetValue())
	{
		theModel_->Parameters().RisePoint()->Value() = theRisePoint_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsKeel_TItem::RiseSlopeValueChangedSlot()
{
	if (theModel_->Parameters().RiseSlope()->Value() != theRiseSlope_->GetValue())
	{
		theModel_->Parameters().RiseSlope()->Value() = theRiseSlope_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsKeel_TItem::TransomSlopeValueChangedSlot()
{
	if (theModel_->Parameters().TransomSlope()->Value() != theTransomSlope_->GetValue())
	{
		theModel_->Parameters().TransomSlope()->Value() = theTransomSlope_->GetValue();
		PerformToPreview();
	}
}
void ForgMarineLib::FrgMarine_ShipT01ParamsKeel_TItem::PerformToPreview()
{
	theModel_->PerformToPreview();

	emit theParametersTItem_->ModelPerformedToPreviewSignal();
}