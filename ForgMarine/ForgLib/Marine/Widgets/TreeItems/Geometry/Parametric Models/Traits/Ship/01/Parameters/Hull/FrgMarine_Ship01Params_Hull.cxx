#include <FrgMarine_Ship01Params_Hull.hxx>
#include <FrgMarine_MainWindow.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgMarine_Ship01ParamsHull_Section.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgMarine_Ship01_Params.hxx>

#include <LegModel_DispNo1.hxx>

ForgMarineLib::FrgMarine_Ship01Params_Hull::FrgMarine_Ship01Params_Hull
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
	this->setIcon(0, QIcon(ICONTreeItemPIcon));

	theAftSection_ = new FrgMarine_Ship01ParamsHull_Section("Aft Section", this, parentTree, model, &model->AftSection(), theParametersTItem_);
	theMidSection_ = new FrgMarine_Ship01ParamsHull_Section("Mid Section", this, parentTree, model, &model->MidSection(), theParametersTItem_);
	theFwdSection_ = new FrgMarine_Ship01ParamsHull_Section("Fwd Section", this, parentTree, model, &model->FwdSection(), theParametersTItem_);

	double minValue = 0.0, maxValue = 1.0, stepValue = 0.05;
	const char* suffixNonDimensioned = "[-]";

	theMaxAreaLocation_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Max Area Location", theModel_->Parameters().MaxAreaLocation()->Value(), minValue, maxValue, stepValue, "", suffixNonDimensioned);

	theFwdFullness_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Fwd Fullness", theModel_->Parameters().FwdFullness()->Value(), minValue, maxValue, stepValue, "", suffixNonDimensioned);

	theAftFullness_ = new ForgBaseLib::FrgBase_PrptsVrntDouble
	("Aft Fullness", theModel_->Parameters().AftFullness()->Value(), minValue, maxValue, stepValue, "", suffixNonDimensioned);

	connect(theMaxAreaLocation_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(MaxAreaLocationValueChangedSlot()));
	connect(theFwdFullness_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(FwdFullnessValueChangedSlot()));
	connect(theAftFullness_, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(AftFullnessValueChangedSlot()));

	thePropertiesPanel_ = new ForgBaseLib::FrgBase_PropertiesPanel(GetParentMainWindow(), dynamic_cast<QObject*>(this));
}

void ForgMarineLib::FrgMarine_Ship01Params_Hull::MaxAreaLocationValueChangedSlot()
{
	if (theModel_->Parameters().MaxAreaLocation()->Value() != theMaxAreaLocation_->GetValue())
	{
		theModel_->Parameters().MaxAreaLocation()->Value() = theMaxAreaLocation_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_Ship01Params_Hull::FwdFullnessValueChangedSlot()
{
	if (theModel_->Parameters().FwdFullness()->Value() != theFwdFullness_->GetValue())
	{
		theModel_->Parameters().FwdFullness()->Value() = theFwdFullness_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_Ship01Params_Hull::AftFullnessValueChangedSlot()
{
	if (theModel_->Parameters().AftFullness()->Value() != theAftFullness_->GetValue())
	{
		theModel_->Parameters().AftFullness()->Value() = theAftFullness_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_Ship01Params_Hull::PerformToPreview()
{
	theModel_->PerformToPreview();

	emit theParametersTItem_->ModelPerformedToPreviewSignal();
}