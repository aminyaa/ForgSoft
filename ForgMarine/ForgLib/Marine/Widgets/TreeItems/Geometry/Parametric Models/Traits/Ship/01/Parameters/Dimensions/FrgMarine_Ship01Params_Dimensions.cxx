#include <FrgMarine_Ship01Params_Dimensions.hxx>
#include <FrgMarine_MainWindow.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_Global_Icons.hxx>

#include <LegModel_DispNo1.hxx>

ForgMarineLib::FrgMarine_Ship01Params_Dimensions::FrgMarine_Ship01Params_Dimensions
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree,
	std::shared_ptr<tnbLib::LegModel_DispNo1> model
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
	, theModel_(model)
{
	this->setIcon(0, QIcon(ICONTreeItemPSubIcon));

	double minValue = 0.1, maxValue = 100.0, stepValue = 0.05;
	const char* suffixDimensioned = "[m]";
	const char* suffixNonDimensioned = "[-]";

	theDraft_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Draft", theModel_->Parameters().Draft()->Value(), minValue, maxValue, stepValue, "", suffixDimensioned);
	
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

	connect(theDraft_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(DraftValueChangedSlot()));
	connect(theTransomHeight_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(TransomHeightValueChangedSlot()));
	connect(theDepthAtBow_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(DepthAtBowValueChangedSlot()));
	connect(theDepthAtTransom_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(DepthAtTransomValueChangedSlot()));
	connect(theBeamOnDeck_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(BeamOnDeckValueChangedSlot()));
	connect(theLengthOnDeck_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(LengthOnDeckValueChangedSlot()));
	connect(theNbNetRows_, SIGNAL(ValueChangedSignal(const int&)), this, SLOT(NbNetRowsValueChangedSlot()));
	connect(theNbNetColumns_, SIGNAL(ValueChangedSignal(const int&)), this, SLOT(NbNetColumnsValueChangedSlot()));

	thePropertiesPanel_ = new ForgBaseLib::FrgBase_PropertiesPanel(GetParentMainWindow(), dynamic_cast<QObject*>(this));
}

void ForgMarineLib::FrgMarine_Ship01Params_Dimensions::DraftValueChangedSlot()
{
	theModel_->Parameters().Draft()->Value() = theDraft_->GetValue();
	PerformToPreview();
}

void ForgMarineLib::FrgMarine_Ship01Params_Dimensions::TransomHeightValueChangedSlot()
{
	theModel_->Parameters().TransomHeight()->Value() = theTransomHeight_->GetValue();
	PerformToPreview();
}

void ForgMarineLib::FrgMarine_Ship01Params_Dimensions::DepthAtBowValueChangedSlot()
{
	theModel_->Parameters().DepthAtBow()->Value() = theDepthAtBow_->GetValue();
	PerformToPreview();
}

void ForgMarineLib::FrgMarine_Ship01Params_Dimensions::DepthAtTransomValueChangedSlot()
{
	theModel_->Parameters().DepthAtTransom()->Value() = theDepthAtTransom_->GetValue();
	PerformToPreview();
}

void ForgMarineLib::FrgMarine_Ship01Params_Dimensions::BeamOnDeckValueChangedSlot()
{
	theModel_->Parameters().BeamOnDeck()->Value() = theBeamOnDeck_->GetValue();
	PerformToPreview();
}

void ForgMarineLib::FrgMarine_Ship01Params_Dimensions::LengthOnDeckValueChangedSlot()
{
	theModel_->Parameters().LengthOnDeck()->Value() = theLengthOnDeck_->GetValue();
	PerformToPreview();
}

void ForgMarineLib::FrgMarine_Ship01Params_Dimensions::NbNetRowsValueChangedSlot()
{
	theModel_->Parameters().NbNetRows() = theNbNetRows_->GetValue();
	PerformToPreview();
}

void ForgMarineLib::FrgMarine_Ship01Params_Dimensions::NbNetColumnsValueChangedSlot()
{
	theModel_->Parameters().NbNetColumns() = theNbNetColumns_->GetValue();
	PerformToPreview();
}

void ForgMarineLib::FrgMarine_Ship01Params_Dimensions::PerformToPreview()
{
	theModel_->PerformToPreview();
}