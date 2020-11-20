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
	
}

void ForgBaseLib::FrgBase_PrptsWdgString::FormWidget()
{
	if (!theVariant_)
	{
		std::cout << "theVariant_ is null in ForgBaseLib::FrgBase_PrptsWdgString::FormWidget()\n";
		return;
	}

	connect(dynamic_cast<FrgBase_PrptsVrntString*>(theVariant_), SIGNAL(DisplayNameChangedSignal(const QString&)), this, SLOT(DisplayNameChangedSlot(const QString&)));
	connect(dynamic_cast<FrgBase_PrptsVrntString*>(theVariant_), SIGNAL(ValueChangedSignal(const QString&)), this, SLOT(ValueChangedSlot(const QString&)));
	connect(dynamic_cast<FrgBase_PrptsVrntString*>(theVariant_), SIGNAL(PrefixChangedSignal(const QString&)), this, SLOT(PrefixChangedSlot(const QString&)));
	connect(dynamic_cast<FrgBase_PrptsVrntString*>(theVariant_), SIGNAL(SuffixChangedSignal(const QString&)), this, SLOT(SuffixChangedSlot(const QString&)));

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

void ForgBaseLib::FrgBase_PrptsWdgString::SetPrefix(const QString& prefix)
{
	FrgBase_PrptsWdgOneValue<QString, false>::SetPrefix(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgString::SetSuffix(const QString& suffix)
{
	FrgBase_PrptsWdgOneValue<QString, false>::SetSuffix(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgString::SetVariant(const ForgBaseLib::FrgBase_PrptsVrntOneValue<QString, false>& variant)
{
	FrgBase_PrptsWdgOneValue<QString, false>::SetVariant(variant);
}

void ForgBaseLib::FrgBase_PrptsWdgString::DisplayNameChangedSlot(const QString& displayName)
{

}

void ForgBaseLib::FrgBase_PrptsWdgString::ValueChangedSlot(const QString& value)
{
	if(theLineEdit_->text() != value)
		theLineEdit_->setText(value);
}

void ForgBaseLib::FrgBase_PrptsWdgString::PrefixChangedSlot(const QString& prefix)
{
	if (!thePrefixLabel_)
		thePrefixLabel_ = new QLabel(prefix + " ");
	else
		thePrefixLabel_->setText(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgString::SuffixChangedSlot(const QString& suffix)
{
	if (!theSuffixLabel_)
		theSuffixLabel_ = new QLabel(" " + suffix);
	else
		theSuffixLabel_->setText(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgString::WdgValueChangedSlot()
{
	if(theLineEdit_->isModified())
		SetValue(theLineEdit_->text());
}