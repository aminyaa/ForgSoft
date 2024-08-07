#include <FrgMarine_ShipT01ParamsTransom_TItem.hxx>
#include <FrgMarine_MainWindow.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgMarine_ShipT01Params_TItem.hxx>

#include <LegModel_DispNo1.hxx>

ForgMarineLib::FrgMarine_ShipT01ParamsTransom_TItem::FrgMarine_ShipT01ParamsTransom_TItem
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

	double minValue = 0.1, maxValue = 1.0, stepValue = 0.05;
	const char* suffixDimensioned = "[deg]";
	const char* suffixNonDimensioned = "[-]";

	theRake_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Rake", theModel_->Parameters().Rake()->Value(), -30.0, 30.0, 1.0, "", suffixDimensioned);

	theWidth_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Width", theModel_->Parameters().Width()->Value(), minValue, maxValue, stepValue, "", suffixNonDimensioned);

	connect(theRake_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(RakeValueChangedSlot()));
	connect(theWidth_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(WidthValueChangedSlot()));

	thePropertiesPanel_->AddRow(theRake_);
	thePropertiesPanel_->AddRow(theWidth_);
}

ForgMarineLib::FrgMarine_ShipT01ParamsTransom_TItem::~FrgMarine_ShipT01ParamsTransom_TItem()
{
	FreePointer(theRake_);
	FreePointer(theWidth_);

	theParametersTItem_ = NullPtr;
}

void ForgMarineLib::FrgMarine_ShipT01ParamsTransom_TItem::RakeValueChangedSlot()
{
	if (theModel_->Parameters().Rake()->Value() != theRake_->GetValue())
	{
		theModel_->Parameters().Rake()->Value() = theRake_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsTransom_TItem::WidthValueChangedSlot()
{
	if (theModel_->Parameters().Width()->Value() != theWidth_->GetValue())
	{
		theModel_->Parameters().Width()->Value() = theWidth_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsTransom_TItem::PerformToPreview()
{
	theModel_->PerformToPreview();

	emit theParametersTItem_->ModelPerformedToPreviewSignal();
}