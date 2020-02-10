#include <FrgMarine_Ship01Params_Transom.hxx>
#include <FrgMarine_MainWindow.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgMarine_Ship01_Params.hxx>

#include <LegModel_DispNo1.hxx>

ForgMarineLib::FrgMarine_Ship01Params_Transom::FrgMarine_Ship01Params_Transom
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree,
	std::shared_ptr<tnbLib::LegModel_DispNo1> model,
	FrgMarine_Ship01_Params* parametersTItem
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

	thePropertiesPanel_ = new ForgBaseLib::FrgBase_PropertiesPanel(GetParentMainWindow(), dynamic_cast<QObject*>(this));
}

void ForgMarineLib::FrgMarine_Ship01Params_Transom::RakeValueChangedSlot()
{
	if (theModel_->Parameters().Rake()->Value() != theRake_->GetValue())
	{
		theModel_->Parameters().Rake()->Value() = theRake_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_Ship01Params_Transom::WidthValueChangedSlot()
{
	if (theModel_->Parameters().Width()->Value() != theWidth_->GetValue())
	{
		theModel_->Parameters().Width()->Value() = theWidth_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_Ship01Params_Transom::PerformToPreview()
{
	theModel_->PerformToPreview();

	emit theParametersTItem_->ModelPerformedToPreviewSignal();
}