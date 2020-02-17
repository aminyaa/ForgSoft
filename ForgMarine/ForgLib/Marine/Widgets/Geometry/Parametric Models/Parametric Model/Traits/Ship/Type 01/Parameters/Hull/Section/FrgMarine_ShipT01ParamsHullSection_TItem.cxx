#include <FrgMarine_ShipT01ParamsHullSection_TItem.hxx>
#include <FrgMarine_MainWindow.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgMarine_ShipT01Params_TItem.hxx>

#include <LegModel_DispNo1.hxx>

ForgMarineLib::FrgMarine_ShipT01ParamsHullSection_TItem::FrgMarine_ShipT01ParamsHullSection_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree,
	std::shared_ptr<tnbLib::LegModel_DispNo1> model,
	tnbLib::LegModel_DispNo1_SectionParamsBase* modelSection,
	FrgMarine_ShipT01Params_TItem* parametersTItem
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
	, theModel_(model)
	, theModelSection_(modelSection)
	, theParametersTItem_(parametersTItem)
{
	this->setIcon(0, QIcon(ICONTreeItemPSubIcon));

	double minValue = 0.0, maxValue = 1.0, stepValue = 0.05;
	const char* suffixNonDimensioned = "[-]";

	theTightness_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Tightness", theModelSection_->Tightness()->Value(), minValue, maxValue, stepValue, "", suffixNonDimensioned);

	theDeadrise_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Deadrise", theModelSection_->Deadrise()->Value(), minValue, maxValue, stepValue, "", suffixNonDimensioned);

	theSideSlope_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Side Slope", theModelSection_->SideSlope()->Value(), minValue, maxValue, stepValue, "", suffixNonDimensioned);

	theFlare_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Flare", theModelSection_->Flare()->Value(), minValue, maxValue, stepValue, "", suffixNonDimensioned);

	connect(theTightness_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(TightnessValueChangedSlot()));
	connect(theDeadrise_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(DeadriseValueChangedSlot()));
	connect(theSideSlope_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(SideSlopeValueChangedSlot()));
	connect(theFlare_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(FlareValueChangedSlot()));

	//thePropertiesPanel_ = new ForgBaseLib::FrgBase_PropertiesPanel(GetParentMainWindow(), dynamic_cast<QObject*>(this));
	FormPropertiesPanel();
}

ForgMarineLib::FrgMarine_ShipT01ParamsHullSection_TItem::~FrgMarine_ShipT01ParamsHullSection_TItem()
{
	FreePointer(theTightness_);
	FreePointer(theDeadrise_);
	FreePointer(theSideSlope_);
	FreePointer(theFlare_);

	theModelSection_ = NullPtr;
	theParametersTItem_ = NullPtr;
}

void ForgMarineLib::FrgMarine_ShipT01ParamsHullSection_TItem::TightnessValueChangedSlot()
{
	if (theModelSection_->Tightness()->Value() != theTightness_->GetValue())
	{
		theModelSection_->Tightness()->Value() = theTightness_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsHullSection_TItem::DeadriseValueChangedSlot()
{
	if (theModelSection_->Deadrise()->Value() != theDeadrise_->GetValue())
	{
		theModelSection_->Deadrise()->Value() = theDeadrise_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsHullSection_TItem::SideSlopeValueChangedSlot()
{
	if (theModelSection_->SideSlope()->Value() != theSideSlope_->GetValue())
	{
		theModelSection_->SideSlope()->Value() = theSideSlope_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsHullSection_TItem::FlareValueChangedSlot()
{
	if (theModelSection_->Flare()->Value() != theFlare_->GetValue())
	{
		theModelSection_->Flare()->Value() = theFlare_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsHullSection_TItem::PerformToPreview()
{
	theModel_->PerformToPreview();

	emit theParametersTItem_->ModelPerformedToPreviewSignal();
}