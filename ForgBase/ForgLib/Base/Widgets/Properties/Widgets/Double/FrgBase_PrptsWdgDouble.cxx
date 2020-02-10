#include <FrgBase_PrptsWdgDouble.hxx>
#include <FrgBase_PrptsVrntDouble.hxx>

#include <QtWidgets/QSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>

#include <string.h>

ForgBaseLib::FrgBase_PrptsWdgDouble::FrgBase_PrptsWdgDouble
(
	QWidget* parent /* = nullptr */,
	FrgBase_PrptsVrntDouble* variant /* = nullptr */
)
	: FrgBase_PrptsWdgOneValue(parent, variant)
{
	if (variant)
	{
		FormWidget();
	}
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::FormWidget()
{
	if (!theVariant_)
	{
		std::cout << "theVariant_ is null inForgBaseLib::FrgBase_PrptsWdgDouble::FormWidget()\n";
		return;
	}

	connect(dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_), SIGNAL(DisplayNameChangedSignal(const char*)), this, SLOT(DisplayNameChangedSlot(const char*)));
	connect(dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_), SIGNAL(ValueChangedSignal(const double&)), this, SLOT(ValueChangedSlot(const double&)));
	connect(dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_), SIGNAL(MinimumValueChangedSignal(const double&)), this, SLOT(MinimumValueChangedSlot(const double&)));
	connect(dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_), SIGNAL(MaximumValueChangedSignal(const double&)), this, SLOT(MaximumValueChangedSlot(const double&)));
	connect(dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_), SIGNAL(StepValueChangedSignal(const double&)), this, SLOT(StepValueChangedSlot(const double&)));
	connect(dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_), SIGNAL(PrefixChangedSignal(const char*)), this, SLOT(PrefixChangedSlot(const char*)));
	connect(dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_), SIGNAL(SuffixChangedSignal(const char*)), this, SLOT(SuffixChangedSlot(const char*)));

	QHBoxLayout* myLayout = new QHBoxLayout;
	myLayout->setMargin(0);
	myLayout->setSpacing(0);
	myLayout->setContentsMargins(0, 2, 0, 2);

	if (GetPrefix() != "")
	{
		SetPrefix(GetPrefix());
		myLayout->addWidget(thePrefixLabel_);
	}

	theSpinBox_ = new QDoubleSpinBox;
	theSpinBox_->setMinimum(GetMinimumValue());
	theSpinBox_->setMaximum(GetMaximumValue());
	theSpinBox_->setSingleStep(GetStepValue());
	theSpinBox_->setValue(GetValue());
	theSpinBox_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	theSpinBox_->setFixedWidth(100);
	theSpinBox_->setKeyboardTracking(false);
	myLayout->addWidget(theSpinBox_);
	myLayout->addStretch(1);

	if (GetSuffix() != "")
	{
		SetSuffix(GetSuffix());
		myLayout->addWidget(theSuffixLabel_);
	}

	this->setLayout(myLayout);

	connect(theSpinBox_, SIGNAL(valueChanged(double)), this, SLOT(WdgValueChangedSlot()));
	connect(theSpinBox_, SIGNAL(editingFinished()), this, SLOT(WdgValueChangedSlot()));
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::SetValue(const double & value)
{
	FrgBase_PrptsWdgOneValue<double>::SetValue(value);
}

const double & ForgBaseLib::FrgBase_PrptsWdgDouble::GetMinimumValue() const
{
	return theVariant_->GetMinimumValue();
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::SetMinimumValue(const double & value)
{
	theVariant_->SetMinimumValue(value);
}

const double & ForgBaseLib::FrgBase_PrptsWdgDouble::GetMaximumValue() const
{
	return theVariant_->GetMaximumValue();
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::SetMaxmimumValue(const double & value)
{
	theVariant_->SetMaximumValue(value);
}

const double & ForgBaseLib::FrgBase_PrptsWdgDouble::GetStepValue() const
{
	return theVariant_->GetStepValue();
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::SetStepValue(const double & stepValue)
{
	theVariant_->SetStepValue(stepValue);
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::SetPrefix(const char * prefix)
{
	FrgBase_PrptsWdgOneValue<double>::SetPrefix(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::SetSuffix(const char * suffix)
{
	FrgBase_PrptsWdgOneValue<double>::SetSuffix(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::SetVariant(const ForgBaseLib::FrgBase_PrptsVrntOneValue<double>& variant)
{
	FrgBase_PrptsWdgOneValue<double>::SetVariant(variant);
	theSpinBox_->setValue(variant.GetValue());
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::DisplayNameChangedSlot(const char* displayName)
{

}

void ForgBaseLib::FrgBase_PrptsWdgDouble::ValueChangedSlot(const double & value)
{
	theSpinBox_->setValue(value);
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::MinimumValueChangedSlot(const double & value)
{
	theSpinBox_->setMinimum(value);
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::MaximumValueChangedSlot(const double & value)
{
	theSpinBox_->setMaximum(value);
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::StepValueChangedSlot(const double & stepValue)
{
	theSpinBox_->setSingleStep(stepValue);
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::PrefixChangedSlot(const char * prefix)
{
	if (!thePrefixLabel_)
		thePrefixLabel_ = new QLabel((std::string(prefix) + std::string(" ")).c_str());
	else
		thePrefixLabel_->setText(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::SuffixChangedSlot(const char * suffix)
{
	if (!theSuffixLabel_)
		theSuffixLabel_ = new QLabel((std::string(" ") + std::string(suffix)).c_str());
	else
		theSuffixLabel_->setText(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::WdgValueChangedSlot()
{
	SetValue(theSpinBox_->value());
}