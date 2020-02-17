#include <FrgMarine_ShipT01ParamsStem_TItem.hxx>
#include <FrgMarine_MainWindow.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgMarine_ShipT01Params_TItem.hxx>

#include <LegModel_DispNo1.hxx>

ForgMarineLib::FrgMarine_ShipT01ParamsStem_TItem::FrgMarine_ShipT01ParamsStem_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree,
	std::shared_ptr<tnbLib::LegModel_DispNo1> model,
	FrgMarine_ShipT01Params_TItem* parametersTItem
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
	, theModel(model)
	, theParametersTItem_(parametersTItem)
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

	//thePropertiesPanel_ = new ForgBaseLib::FrgBase_PropertiesPanel(GetParentMainWindow(), dynamic_cast<QObject*>(this));
	FormPropertiesPanel();
}

ForgMarineLib::FrgMarine_ShipT01ParamsStem_TItem::~FrgMarine_ShipT01ParamsStem_TItem()
{
	FreePointer(theBowRounding_);
	FreePointer(theStemRake_);
	FreePointer(theForeFootShape_);

	theParametersTItem_ = NullPtr;
}

void ForgMarineLib::FrgMarine_ShipT01ParamsStem_TItem::BowRoundingValueChangedSlot()
{
	if (theModel->Parameters().BowRounding()->Value() != theBowRounding_->GetValue())
	{
		theModel->Parameters().BowRounding()->Value() = theBowRounding_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsStem_TItem::StemRakeValueChangedSlot()
{
	if (theModel->Parameters().StemRake()->Value() != theStemRake_->GetValue())
	{
		theModel->Parameters().StemRake()->Value() = theStemRake_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsStem_TItem::ForeFootShapeValueChangedSlot()
{
	if (theModel->Parameters().ForeFootShape()->Value() != theForeFootShape_->GetValue())
	{
		theModel->Parameters().ForeFootShape()->Value() = theForeFootShape_->GetValue();
		PerformToPreview();
	}
}

void ForgMarineLib::FrgMarine_ShipT01ParamsStem_TItem::PerformToPreview()
{
	theModel->PerformToPreview();

	emit theParametersTItem_->ModelPerformedToPreviewSignal();
}