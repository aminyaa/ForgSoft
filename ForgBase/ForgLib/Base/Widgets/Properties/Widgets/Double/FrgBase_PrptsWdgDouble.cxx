#include <FrgBase_PrptsWdgDouble.hxx>
#include <FrgBase_PrptsVrntDouble.hxx>

#include <QtWidgets/QSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>

#include <string.h>

ForgBaseLib::FrgBase_PrptsWdgDouble::FrgBase_PrptsWdgDouble
(
	QWidget* parent /* = nullptr */,
	FrgBase_PrptsVrnt* variant /* = nullptr */
)
	: FrgBase_PrptsWdgOneValue(parent, variant)
{
	
}

ForgBaseLib::FrgBase_PrptsWdgDouble::~FrgBase_PrptsWdgDouble()
{
	FreePointer(thePrefixLabel_);
	FreePointer(theSuffixLabel_);
	FreePointer(theSpinBox_);
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::FormWidget()
{
	if (!theVariant_)
	{
		std::cout << "theVariant_ is null inForgBaseLib::FrgBase_PrptsWdgDouble::FormWidget()\n";
		return;
	}

	connect(dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_), SIGNAL(DisplayNameChangedSignal(const QString&)), this, SLOT(DisplayNameChangedSlot(const QString&)));
	connect(dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_), SIGNAL(ValueChangedSignal(const double&)), this, SLOT(ValueChangedSlot(const double&)));
	connect(dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_), SIGNAL(MinimumValueChangedSignal(const double&)), this, SLOT(MinimumValueChangedSlot(const double&)));
	connect(dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_), SIGNAL(MaximumValueChangedSignal(const double&)), this, SLOT(MaximumValueChangedSlot(const double&)));
	connect(dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_), SIGNAL(StepValueChangedSignal(const double&)), this, SLOT(StepValueChangedSlot(const double&)));
	connect(dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_), SIGNAL(PrefixChangedSignal(const QString&)), this, SLOT(PrefixChangedSlot(const QString&)));
	connect(dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_), SIGNAL(SuffixChangedSignal(const QString&)), this, SLOT(SuffixChangedSlot(const QString&)));

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
	return dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_)->GetMinimumValue();
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::SetMinimumValue(const double & value)
{
	dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_)->SetMinimumValue(value);
}

const double & ForgBaseLib::FrgBase_PrptsWdgDouble::GetMaximumValue() const
{
	return dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_)->GetMaximumValue();
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::SetMaxmimumValue(const double & value)
{
	dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_)->SetMaximumValue(value);
}

const double & ForgBaseLib::FrgBase_PrptsWdgDouble::GetStepValue() const
{
	return dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_)->GetStepValue();
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::SetStepValue(const double & stepValue)
{
	dynamic_cast<FrgBase_PrptsVrntDouble*>(theVariant_)->SetStepValue(stepValue);
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::SetPrefix(const QString& prefix)
{
	FrgBase_PrptsWdgOneValue<double>::SetPrefix(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::SetSuffix(const QString& suffix)
{
	FrgBase_PrptsWdgOneValue<double>::SetSuffix(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::SetVariant(const ForgBaseLib::FrgBase_PrptsVrntOneValue<double>& variant)
{
	FrgBase_PrptsWdgOneValue<double>::SetVariant(variant);
	theSpinBox_->setValue(variant.GetValue());
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::DisplayNameChangedSlot(const QString& displayName)
{

}

void ForgBaseLib::FrgBase_PrptsWdgDouble::ValueChangedSlot(const double & value)
{
	if(theSpinBox_->value() != value)
		theSpinBox_->setValue(value);
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::MinimumValueChangedSlot(const double & value)
{
	if(theSpinBox_->minimum() != value)
		theSpinBox_->setMinimum(value);
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::MaximumValueChangedSlot(const double & value)
{
	if(theSpinBox_->maximum() != value)
		theSpinBox_->setMaximum(value);
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::StepValueChangedSlot(const double & stepValue)
{
	if(theSpinBox_->singleStep() != stepValue)
		theSpinBox_->setSingleStep(stepValue);
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::PrefixChangedSlot(const QString& prefix)
{
	if (!thePrefixLabel_)
		thePrefixLabel_ = new QLabel(prefix + " ");
	else
		thePrefixLabel_->setText(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::SuffixChangedSlot(const QString& suffix)
{
	if (!theSuffixLabel_)
		theSuffixLabel_ = new QLabel(" " + suffix);
	else
		theSuffixLabel_->setText(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgDouble::WdgValueChangedSlot()
{
	SetValue(theSpinBox_->value());
}