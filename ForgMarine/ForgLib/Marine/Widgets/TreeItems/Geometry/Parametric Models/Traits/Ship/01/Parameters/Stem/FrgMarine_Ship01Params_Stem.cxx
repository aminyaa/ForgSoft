#include <FrgMarine_Ship01Params_Stem.hxx>
#include <FrgMarine_MainWindow.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_Global_Icons.hxx>

#include <LegModel_DispNo1.hxx>

ForgMarineLib::FrgMarine_Ship01Params_Stem::FrgMarine_Ship01Params_Stem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree,
	std::shared_ptr<tnbLib::LegModel_DispNo1> model
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
	, theModel(model)
{
	this->setIcon(0, QIcon(ICONTreeItemPSubIcon));

	double minValue = 0.1, maxValue = 1.0, stepValue = 0.05;
	const char* suffixDimensioned = "[deg]";
	const char* suffixNonDimensioned = "[-]";

	theBowRounding_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Bow Rounding", theModel->Parameters().BowRounding()->Value(), minValue, maxValue, stepValue, "", suffixNonDimensioned);

	theStemRake_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Stem Rake", theModel->Parameters().StemRake()->Value(), -45.0, 45.0, 1.0, "", suffixDimensioned);

	theForeFootShape_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Fore Foot Shape", theModel->Parameters().ForeFootShape()->Value(), minValue, maxValue, stepValue, "", suffixNonDimensioned);

	connect(theBowRounding_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(BowRoundingValueChangedSlot()));
	connect(theStemRake_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(StemRakeValueChangedSlot()));
	connect(theForeFootShape_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(ForeFootShapeValueChangedSlot()));

	thePropertiesPanel_ = new ForgBaseLib::FrgBase_PropertiesPanel(GetParentMainWindow(), dynamic_cast<QObject*>(this));
}

void ForgMarineLib::FrgMarine_Ship01Params_Stem::BowRoundingValueChangedSlot()
{
	theModel->Parameters().BowRounding()->Value() = theBowRounding_->GetValue();
	PerformToPreview();
}

void ForgMarineLib::FrgMarine_Ship01Params_Stem::StemRakeValueChangedSlot()
{
	theModel->Parameters().StemRake()->Value() = theStemRake_->GetValue();
	PerformToPreview();
}

void ForgMarineLib::FrgMarine_Ship01Params_Stem::ForeFootShapeValueChangedSlot()
{
	theModel->Parameters().ForeFootShape()->Value() = theForeFootShape_->GetValue();
	PerformToPreview();
}

void ForgMarineLib::FrgMarine_Ship01Params_Stem::PerformToPreview()
{
	theModel->PerformToPreview();
}