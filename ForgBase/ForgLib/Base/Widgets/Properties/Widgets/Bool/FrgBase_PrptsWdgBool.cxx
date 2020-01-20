#include <FrgBase_PrptsWdgBool.hxx>
#include <FrgBase_PrptsVrntBool.hxx>

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>

ForgBaseLib::FrgBase_PrptsWdgBool::FrgBase_PrptsWdgBool
(
	QWidget * parent,
	FrgBase_PrptsVrntBool * variant
)
	: FrgBase_PrptsWdgOneValue(parent, variant)
{
	if (variant)
	{
		FormWidget();
	}
}

void ForgBaseLib::FrgBase_PrptsWdgBool::FormWidget()
{
	if (!theVariant_)
	{
		std::cout << "theVariant_ is null in ForgBaseLib::FrgBase_PrptsWdgBool::FormWidget()\n";
		return;
	}

	QHBoxLayout* myLayout = new QHBoxLayout;
	myLayout->setMargin(0);
	myLayout->setSpacing(0);
	myLayout->setContentsMargins(0, 2, 0, 2);

	if (GetPrefix() != "")
	{
		SetPrefix(GetPrefix());
		myLayout->addWidget(thePrefixLabel_);
	}

	theCheckBox_ = new QCheckBox;
	theCheckBox_->setChecked(GetValue());
	myLayout->addWidget(theCheckBox_);
	myLayout->addStretch(1);

	if (GetSuffix() != "")
	{
		SetSuffix(GetSuffix());
		myLayout->addWidget(theSuffixLabel_);
	}

	this->setLayout(myLayout);

	connect(theCheckBox_, SIGNAL(toggled(bool)), this, SIGNAL(valueChanged(bool)));
}

void ForgBaseLib::FrgBase_PrptsWdgBool::SetValue(const bool & value)
{
	FrgBase_PrptsWdgOneValue<bool, false>::SetValue(value);
	theCheckBox_->setChecked(value);
}

void ForgBaseLib::FrgBase_PrptsWdgBool::SetPrefix(const char * prefix)
{
	FrgBase_PrptsWdgOneValue<bool, false>::SetPrefix(prefix);

	if (!thePrefixLabel_)
		thePrefixLabel_ = new QLabel((std::string(prefix) + std::string(" ")).c_str());
	else
		thePrefixLabel_->setText(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgBool::SetSuffix(const char * suffix)
{
	FrgBase_PrptsWdgOneValue<bool, false>::SetSuffix(suffix);

	if (!theSuffixLabel_)
		theSuffixLabel_ = new QLabel((std::string(" ") + std::string(suffix)).c_str());
	else
		theSuffixLabel_->setText(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgBool::SetVariant(const FrgBase_PrptsVrntOneValue<bool, false>& variant)
{
	FrgBase_PrptsWdgOneValue<bool, false>::SetVariant(variant);
	theCheckBox_->setChecked(variant.GetValue());
}