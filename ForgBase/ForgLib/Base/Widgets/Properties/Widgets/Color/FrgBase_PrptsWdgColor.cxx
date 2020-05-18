#include <FrgBase_PrptsWdgColor.hxx>
#include <FrgBase_PrptsVrntColor.hxx>
#include <FrgBase_PrptsVrntWdgColor_Label.hxx>

#include <QtWidgets/QColorDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QToolButton>

ForgBaseLib::FrgBase_PrptsWdgColor::FrgBase_PrptsWdgColor
(
	QWidget* parent,
	FrgBase_PrptsVrnt* variant
)
	: FrgBase_PrptsWdgOneValue(parent, variant)
{
	if (variant)
	{
		FormWidget();
	}
}

ForgBaseLib::FrgBase_PrptsWdgColor::~FrgBase_PrptsWdgColor()
{
	FreePointer(thePrefixLabel_);
	FreePointer(theSuffixLabel_);
}

void ForgBaseLib::FrgBase_PrptsWdgColor::FormWidget()
{
	if (!theVariant_)
	{
		std::cout << "theVariant_ is null in ForgBaseLib::FrgBase_PrptsWdgColor::FormWidget()\n";
		return;
	}

	connect(dynamic_cast<FrgBase_PrptsVrntColor*>(theVariant_), SIGNAL(DisplayNameChangedSignal(const char*)), this, SLOT(DisplayNameChangedSlot(const char*)));
	connect(dynamic_cast<FrgBase_PrptsVrntColor*>(theVariant_), SIGNAL(ValueChangedSignal(const QColor&)), this, SLOT(ValueChangedSlot(const QColor&)));
	connect(dynamic_cast<FrgBase_PrptsVrntColor*>(theVariant_), SIGNAL(PrefixChangedSignal(const char*)), this, SLOT(PrefixChangedSlot(const char*)));
	connect(dynamic_cast<FrgBase_PrptsVrntColor*>(theVariant_), SIGNAL(SuffixChangedSignal(const char*)), this, SLOT(SuffixChangedSlot(const char*)));

	QHBoxLayout* myLayout = new QHBoxLayout;
	myLayout->setMargin(0);
	myLayout->setSpacing(0);
	myLayout->setContentsMargins(0, 2, 0, 2);

	if (GetPrefix() != "")
	{
		SetPrefix(GetPrefix());
		myLayout->addWidget(thePrefixLabel_);
	}

	theColorLabel_ = new FrgBase_PrptsVrntWdgColor_Label("");
	SetLabelWidgetColor(dynamic_cast<FrgBase_PrptsVrntColor*>(theVariant_)->GetValue());
	theColorLabel_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	theColorLabel_->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	myLayout->addWidget(theColorLabel_);
	//myLayout->addStretch(1);

	theColorButton_ = new QToolButton;
	theColorButton_->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred));
	theColorButton_->setText(QLatin1String("..."));

	//myLayout->addStretch(1);
	myLayout->addWidget(theColorButton_);

	if (GetSuffix() != "")
	{
		SetSuffix(GetSuffix());
		myLayout->addWidget(theSuffixLabel_);
	}

	this->setLayout(myLayout);

	connect(theColorButton_, SIGNAL(clicked()), this, SLOT(OnColorButtonClickedSlot()));
}

void ForgBaseLib::FrgBase_PrptsWdgColor::SetValue(const QColor & value)
{
	FrgBase_PrptsWdgOneValue::SetValue(value);
}

void ForgBaseLib::FrgBase_PrptsWdgColor::SetPrefix(const char * prefix)
{
	FrgBase_PrptsWdgOneValue::SetPrefix(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgColor::SetSuffix(const char * suffix)
{
	FrgBase_PrptsWdgOneValue::SetSuffix(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgColor::SetVariant(const FrgBase_PrptsVrntOneValue<QColor, false>& variant)
{
	FrgBase_PrptsWdgOneValue::SetVariant(variant);
	this->FormWidget();
}

void ForgBaseLib::FrgBase_PrptsWdgColor::DisplayNameChangedSlot(const char* displayName)
{

}

void ForgBaseLib::FrgBase_PrptsWdgColor::ValueChangedSlot(const QColor & value)
{
	auto myVariant = dynamic_cast<FrgBase_PrptsVrntColor*>(theVariant_);

	if (!myVariant)
	{
		std::cout << "myVariant is null in void ForgBaseLib::FrgBase_PrptsWdgColor::OnColorButtonClickedSlot()\n";
		return;
	}

	SetLabelWidgetColor(myVariant->GetValue());
}

void ForgBaseLib::FrgBase_PrptsWdgColor::PrefixChangedSlot(const char * prefix)
{
	if (!thePrefixLabel_)
		thePrefixLabel_ = new QLabel((std::string(prefix) + std::string(" ")).c_str());
	else
		thePrefixLabel_->setText(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgColor::SuffixChangedSlot(const char * suffix)
{
	if (!theSuffixLabel_)
		theSuffixLabel_ = new QLabel((std::string(" ") + std::string(suffix)).c_str());
	else
		theSuffixLabel_->setText(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgColor::OnColorButtonClickedSlot()
{
	auto myVariant = dynamic_cast<FrgBase_PrptsVrntColor*>(theVariant_);

	if (!myVariant)
	{
		std::cout << "myVariant is null in void ForgBaseLib::FrgBase_PrptsWdgColor::OnColorButtonClickedSlot()\n";
		return;
	}

	std::shared_ptr<QColorDialog> colorDialog = std::make_shared<QColorDialog>(myVariant->GetValue(), this);

	if (colorDialog->exec() == QColorDialog::Accepted)
	{
		myVariant->SetValue(colorDialog->selectedColor());
	}
}

void ForgBaseLib::FrgBase_PrptsWdgColor::SetLabelWidgetColor(const QColor & color)
{
	int red = color.red();
	int green = color.green();
	int blue = color.blue();
	QString colorStr = QString("QLabel { background-color : rgb(%1, %2, %3); }").arg(red).arg(green).arg(blue);
	theColorLabel_->setStyleSheet(colorStr);

	theColorLabel_->setText(QString("(%1, %2, %3)").arg(red).arg(green).arg(blue));

	// http://stackoverflow.com/a/3943023/112731
	QString textColorStr;
	if ((red * 0.299 + green * 0.587 + blue * 0.114) > 186)
		textColorStr = "QLabel { color : black; }";
	else
		textColorStr = "QLabel { color : white; }";

	theColorLabel_->setStyleSheet(theColorLabel_->styleSheet() + textColorStr);
}

void ForgBaseLib::FrgBase_PrptsWdgColor::SetLabelWidgetColor(int red, int green, int blue)
{
	SetLabelWidgetColor(QColor(red, green, blue));
}