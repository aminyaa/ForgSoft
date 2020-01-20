#include <FrgBase_PrptsWdgString.hxx>
#include <FrgBase_PrptsVrntString.hxx>

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>

#include <string.h>

ForgBaseLib::FrgBase_PrptsWdgString::FrgBase_PrptsWdgString
(
	QWidget* parent /* = nullptr */,
	FrgBase_PrptsVrntString* variant /* = nullptr */
)
	: FrgBase_PrptsWdgOneValue(parent, variant)
{
	if (variant)
	{
		FormWidget();
	}
}

void ForgBaseLib::FrgBase_PrptsWdgString::FormWidget()
{
	if (!theVariant_)
	{
		std::cout << "theVariant_ is null in ForgBaseLib::FrgBase_PrptsWdgString::FormWidget()\n";
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

	theLineEdit_ = new QLineEdit;
	theLineEdit_->setText(GetValue());
	theLineEdit_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	theLineEdit_->setMinimumWidth(70);
	myLayout->addWidget(theLineEdit_);

	if (GetSuffix() != "")
	{
		SetSuffix(GetSuffix());
		myLayout->addWidget(theSuffixLabel_);
	}

	this->setLayout(myLayout);

	connect(theLineEdit_, SIGNAL(textChanged(const QString&)), this, SIGNAL(valueChanged(const QString&)));
}

void ForgBaseLib::FrgBase_PrptsWdgString::SetValue(const QString & value)
{
	FrgBase_PrptsWdgOneValue<QString, false>::SetValue(value);
	theLineEdit_->setText(value);
}

void ForgBaseLib::FrgBase_PrptsWdgString::SetPrefix(const char * prefix)
{
	FrgBase_PrptsWdgOneValue<QString, false>::SetPrefix(prefix);

	if (!thePrefixLabel_)
		thePrefixLabel_ = new QLabel((std::string(prefix) + std::string(" ")).c_str());
	else
		thePrefixLabel_->setText(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgString::SetSuffix(const char * suffix)
{
	FrgBase_PrptsWdgOneValue<QString, false>::SetSuffix(suffix);

	if (!theSuffixLabel_)
		theSuffixLabel_ = new QLabel((std::string(" ") + std::string(suffix)).c_str());
	else
		theSuffixLabel_->setText(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgString::SetVariant(const ForgBaseLib::FrgBase_PrptsVrntOneValue<QString, false>& variant)
{
	FrgBase_PrptsWdgOneValue<QString, false>::SetVariant(variant);
	theLineEdit_->setText(variant.GetValue());
}