#include <FrgMarine_ShipT01ParamsHull_TItem.hxx>
#include <FrgMarine_MainWindow.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgMarine_ShipT01ParamsHullSection_TItem.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgMarine_ShipT01Params_TItem.hxx>

#include <LegModel_DispNo1.hxx>

ForgMarineLib::FrgMarine_ShipT01ParamsHull_TItem::FrgMarine_ShipT01ParamsHull_TItem
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
	this->setIcon(0, QIcon(ICONTreeItemPIcon));

	theAftSection_ = new FrgMarine_ShipT01ParamsHullSection_TItem("Aft Section", this, parentTree, model, &model->AftSection(), theParametersTItem_);
	theMidSection_ = new FrgMarine_ShipT01ParamsHullSection_TItem("Mid Section", this, parentTree, model, &model->MidSection(), theParametersTItem_);
	theFwdSection_ = new FrgMarine_ShipT01ParamsHullSection_TItem("Fwd Section", this, parentTree, model, &model->FwdSection(), theParametersTItem_);

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

	thePropertiesPanel_->AddRow(theMaxAreaLocation_);
	thePropertiesPanel_->AddRow(theFwdFullness_);
	thePropertiesPanel_->AddRow(theAftFullness_);
}

ForgMarineLib::FrgMarine_ShipT01ParamsHull_TItem::~FrgMarine_ShipT01ParamsHull_TItem()
{
	FreePointer(theAftSection_);
	FreePointer(theMidSection_);
	FreePointer(theFwdSection_);

	FreePointer(theMaxAreaLocation_);
	FreePointer(theFwdFullness_);
	FreePointer(theAftFullness_);

	theParametersTItem_ = NullPtr;
}

void ForgMarineLib::FrgMarine_ShipT01ParamsHull_TItem::MaxAreaLocationValueChangedSlot()
{
	if (theModel_->Parameters().MaxAreaLocation()->Value() != theMaxAreaLocation_->GetValue())
	{
		theModel_->Parameters().MaxAreaLocation()->Value() = theMaxAreaLocation_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsHull_TItem::FwdFullnessValueChangedSlot()
{
	if (theModel_->Parameters().FwdFullness()->Value() != theFwdFullness_->GetValue())
	{
		theModel_->Parameters().FwdFullness()->Value() = theFwdFullness_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsHull_TItem::AftFullnessValueChangedSlot()
{
	if (theModel_->Parameters().AftFullness()->Value() != theAftFullness_->GetValue())
	{
		theModel_->Parameters().AftFullness()->Value() = theAftFullness_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsHull_TItem::PerformToPreview()
{
	theModel_->PerformToPreview();

	emit theParametersTItem_->ModelPerformedToPreviewSignal();
}