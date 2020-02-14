#include <FrgMarine_ShipT01ParamsDim_TItem.hxx>
#include <FrgMarine_MainWindow.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgMarine_ShipT01Params_TItem.hxx>

#include <LegModel_DispNo1.hxx>

ForgMarineLib::FrgMarine_ShipT01ParamsDim_TItem::FrgMarine_ShipT01ParamsDim_TItem
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

	double minValue = 0.1, maxValue = 500.0, stepValue = 0.5;
	const char* suffixDimensioned = "[m]";
	const char* suffixNonDimensioned = "[-]";

	/*theDraft_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Draft", theModel_->Parameters().Draft()->Value(), minValue, maxValue, stepValue, "", suffixDimensioned);*/
	
	theTransomHeight_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Transom Height", theModel_->Parameters().TransomHeight()->Value(), minValue, maxValue, stepValue, "", suffixDimensioned);

	theDepthAtBow_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Depth At Bow", theModel_->Parameters().DepthAtBow()->Value(), minValue, maxValue, stepValue, "", suffixDimensioned);

	theDepthAtTransom_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Depth At Transom", theModel_->Parameters().DepthAtTransom()->Value(), minValue, maxValue, stepValue, "", suffixDimensioned);

	theBeamOnDeck_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Beam On Deck", theModel_->Parameters().BeamOnDeck()->Value(), minValue, maxValue, stepValue, "", suffixDimensioned);

	theLengthOnDeck_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Length On Deck", theModel_->Parameters().LengthOnDeck()->Value(), minValue, maxValue, stepValue, "", suffixDimensioned);

	theNbNetRows_ = new ForgBaseLib::FrgBase_PrptsVrntInt
	("Number of Net Rows", theModel_->Parameters().NbNetRows(), 5, 90, 1, "", suffixNonDimensioned);

	theNbNetColumns_ = new ForgBaseLib::FrgBase_PrptsVrntInt
	("Number of Net Columns", theModel_->Parameters().NbNetColumns(), 5, 90, 1, "", suffixNonDimensioned);

	//connect(theDraft_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(DraftValueChangedSlot()));
	connect(theTransomHeight_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(TransomHeightValueChangedSlot()));
	connect(theDepthAtBow_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(DepthAtBowValueChangedSlot()));
	connect(theDepthAtTransom_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(DepthAtTransomValueChangedSlot()));
	connect(theBeamOnDeck_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(BeamOnDeckValueChangedSlot()));
	connect(theLengthOnDeck_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(LengthOnDeckValueChangedSlot()));
	connect(theNbNetRows_, SIGNAL(ValueChangedSignal(const int&)), this, SLOT(NbNetRowsValueChangedSlot()));
	connect(theNbNetColumns_, SIGNAL(ValueChangedSignal(const int&)), this, SLOT(NbNetColumnsValueChangedSlot()));

	//thePropertiesPanel_ = new ForgBaseLib::FrgBase_PropertiesPanel(GetParentMainWindow(), dynamic_cast<QObject*>(this));
	FormPropertiesPanel();
}

//void ForgMarineLib::FrgMarine_Ship01Params_Dimensions::DraftValueChangedSlot()
//{
//	theModel_->Parameters().Draft()->Value() = theDraft_->GetValue();
//	PerformToPreview();
//}

void ForgMarineLib::FrgMarine_ShipT01ParamsDim_TItem::TransomHeightValueChangedSlot()
{
	if (theModel_->Parameters().TransomHeight()->Value() != theTransomHeight_->GetValue())
	{
		theModel_->Parameters().TransomHeight()->Value() = theTransomHeight_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsDim_TItem::DepthAtBowValueChangedSlot()
{
	if (theModel_->Parameters().DepthAtBow()->Value() != theDepthAtBow_->GetValue())
	{
		theModel_->Parameters().DepthAtBow()->Value() = theDepthAtBow_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsDim_TItem::DepthAtTransomValueChangedSlot()
{
	if (theModel_->Parameters().DepthAtTransom()->Value() != theDepthAtTransom_->GetValue())
	{
		theModel_->Parameters().DepthAtTransom()->Value() = theDepthAtTransom_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsDim_TItem::BeamOnDeckValueChangedSlot()
{
	if (theModel_->Parameters().BeamOnDeck()->Value() != theBeamOnDeck_->GetValue())
	{
		theModel_->Parameters().BeamOnDeck()->Value() = theBeamOnDeck_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsDim_TItem::LengthOnDeckValueChangedSlot()
{
	if (theModel_->Parameters().LengthOnDeck()->Value() != theLengthOnDeck_->GetValue())
	{
		theModel_->Parameters().LengthOnDeck()->Value() = theLengthOnDeck_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsDim_TItem::NbNetRowsValueChangedSlot()
{
	if (theModel_->Parameters().NbNetRows() != theNbNetRows_->GetValue())
	{
		theModel_->Parameters().NbNetRows() = theNbNetRows_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsDim_TItem::NbNetColumnsValueChangedSlot()
{
	if (theModel_->Parameters().NbNetColumns() != theNbNetColumns_->GetValue())
	{
		theModel_->Parameters().NbNetColumns() = theNbNetColumns_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsDim_TItem::PerformToPreview()
{
	theModel_->PerformToPreview();

	emit theParametersTItem_->ModelPerformedToPreviewSignal();
}