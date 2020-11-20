#include <FrgBase_PrptsWdgCombo.hxx>
#include <FrgBase_PrptsVrntCombo.hxx>

#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>

ForgBaseLib::FrgBase_PrptsWdgCombo::FrgBase_PrptsWdgCombo
(
	QWidget* parent,
	FrgBase_PrptsVrnt* variant
)
	: FrgBase_PrptsWdgOneValue(parent, variant)
{
	
}

ForgBaseLib::FrgBase_PrptsWdgCombo::~FrgBase_PrptsWdgCombo()
{
	FreePointer(thePrefixLabel_);
	FreePointer(theSuffixLabel_);
	FreePointer(theComboBox_);
}

void ForgBaseLib::FrgBase_PrptsWdgCombo::FormWidget()
{
	if (!theVariant_)
	{
		std::cout << "theVariant_ is null in ForgBaseLib::FrgBase_PrptsWdgCombo::FormWidget()\n";
		return;
	}

	connect(dynamic_cast<FrgBase_PrptsVrntCombo*>(theVariant_), SIGNAL(DisplayNameChangedSignal(const QString&)), this, SLOT(DisplayNameChangedSlot(const QString&)));
	connect(dynamic_cast<FrgBase_PrptsVrntCombo*>(theVariant_), SIGNAL(ValueChangedSignal(const QString&)), this, SLOT(ValueChangedSlot(const QString&)));
	connect(dynamic_cast<FrgBase_PrptsVrntCombo*>(theVariant_), SIGNAL(PrefixChangedSignal(const QString&)), this, SLOT(PrefixChangedSlot(const QString&)));
	connect(dynamic_cast<FrgBase_PrptsVrntCombo*>(theVariant_), SIGNAL(SuffixChangedSignal(const QString&)), this, SLOT(SuffixChangedSlot(const QString&)));

	QHBoxLayout* myLayout = new QHBoxLayout;
	myLayout->setMargin(0);
	myLayout->setSpacing(0);
	myLayout->setContentsMargins(0, 2, 0, 2);

	if (GetPrefix() != "")
	{
		SetPrefix(GetPrefix());
		myLayout->addWidget(thePrefixLabel_);
	}

	theComboBox_ = new QComboBox(this);

	auto items = dynamic_cast<FrgBase_PrptsVrntCombo*>(theVariant_)->GetItems();
	for (auto item : items)
	{
		theComboBox_->addItem(item);
	}
	theComboBox_->setCurrentText(dynamic_cast<FrgBase_PrptsVrntCombo*>(theVariant_)->GetValue());
	theComboBox_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	myLayout->addWidget(theComboBox_);
	//myLayout->addStretch(1);

	if (GetSuffix() != "")
	{
		SetSuffix(GetSuffix());
		myLayout->addWidget(theSuffixLabel_);
	}

	this->setLayout(myLayout);

	connect(theComboBox_, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(WdgValueChangedSlot(const QString&)));
}

void ForgBaseLib::FrgBase_PrptsWdgCombo::SetValue(const QString& value)
{
	FrgBase_PrptsWdgOneValue::SetValue(value);
}

void ForgBaseLib::FrgBase_PrptsWdgCombo::SetPrefix(const QString& prefix)
{
	FrgBase_PrptsWdgOneValue::SetPrefix(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgCombo::SetSuffix(const QString& suffix)
{
	FrgBase_PrptsWdgOneValue::SetSuffix(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgCombo::SetVariant(const FrgBase_PrptsVrntOneValue<QString, false>& variant)
{
	FrgBase_PrptsWdgOneValue::SetVariant(variant);
	this->FormWidget();
}

void ForgBaseLib::FrgBase_PrptsWdgCombo::DisplayNameChangedSlot(const QString& displayName)
{

}

void ForgBaseLib::FrgBase_PrptsWdgCombo::ValueChangedSlot(const QString& value)
{
	if(theComboBox_->currentText() != value)
		theComboBox_->setCurrentText(value);
}

void ForgBaseLib::FrgBase_PrptsWdgCombo::PrefixChangedSlot(const QString& prefix)
{
	if (!thePrefixLabel_)
		thePrefixLabel_ = new QLabel(prefix + " ");
	else
		thePrefixLabel_->setText(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgCombo::SuffixChangedSlot(const QString& suffix)
{
	if (!theSuffixLabel_)
		theSuffixLabel_ = new QLabel(" " + suffix);
	else
		theSuffixLabel_->setText(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgCombo::WdgValueChangedSlot(const QString& value)
{
	SetValue(value);
}