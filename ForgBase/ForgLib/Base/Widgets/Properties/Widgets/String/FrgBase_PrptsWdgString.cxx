#include <FrgBase_PrptsWdgString.hxx>
#include <FrgBase_PrptsVrntString.hxx>

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>

#include <string.h>

ForgBaseLib::FrgBase_PrptsWdgString::FrgBase_PrptsWdgString
(
	QWidget* parent /* = nullptr */,
	FrgBase_PrptsVrnt* variant /* = nullptr */
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

	connect(dynamic_cast<FrgBase_PrptsVrntString*>(theVariant_), SIGNAL(DisplayNameChangedSignal(const char*)), this, SLOT(DisplayNameChangedSlot(const char*)));
	connect(dynamic_cast<FrgBase_PrptsVrntString*>(theVariant_), SIGNAL(ValueChangedSignal(const QString&)), this, SLOT(ValueChangedSlot(const QString&)));
	connect(dynamic_cast<FrgBase_PrptsVrntString*>(theVariant_), SIGNAL(PrefixChangedSignal(const char*)), this, SLOT(PrefixChangedSlot(const char*)));
	connect(dynamic_cast<FrgBase_PrptsVrntString*>(theVariant_), SIGNAL(SuffixChangedSignal(const char*)), this, SLOT(SuffixChangedSlot(const char*)));

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

	connect(theLineEdit_, SIGNAL(editingFinished()), this, SLOT(WdgValueChangedSlot()));
}

ForgBaseLib::FrgBase_PrptsWdgString::~FrgBase_PrptsWdgString()
{
	FreePointer(thePrefixLabel_);
	FreePointer(theSuffixLabel_);
	FreePointer(theLineEdit_);
}

void ForgBaseLib::FrgBase_PrptsWdgString::SetValue(const QString & value)
{
	FrgBase_PrptsWdgOneValue<QString, false>::SetValue(value);
}

void ForgBaseLib::FrgBase_PrptsWdgString::SetPrefix(const char * prefix)
{
	FrgBase_PrptsWdgOneValue<QString, false>::SetPrefix(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgString::SetSuffix(const char * suffix)
{
	FrgBase_PrptsWdgOneValue<QString, false>::SetSuffix(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgString::SetVariant(const ForgBaseLib::FrgBase_PrptsVrntOneValue<QString, false>& variant)
{
	FrgBase_PrptsWdgOneValue<QString, false>::SetVariant(variant);
}

void ForgBaseLib::FrgBase_PrptsWdgString::DisplayNameChangedSlot(const char* displayName)
{

}

void ForgBaseLib::FrgBase_PrptsWdgString::ValueChangedSlot(const QString& value)
{
	if(theLineEdit_->text() != value)
		theLineEdit_->setText(value);
}

void ForgBaseLib::FrgBase_PrptsWdgString::PrefixChangedSlot(const char * prefix)
{
	if (!thePrefixLabel_)
		thePrefixLabel_ = new QLabel((std::string(prefix) + std::string(" ")).c_str());
	else
		thePrefixLabel_->setText(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgString::SuffixChangedSlot(const char * suffix)
{
	if (!theSuffixLabel_)
		theSuffixLabel_ = new QLabel((std::string(" ") + std::string(suffix)).c_str());
	else
		theSuffixLabel_->setText(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgString::WdgValueChangedSlot()
{
	if(theLineEdit_->isModified())
		SetValue(theLineEdit_->text());
}