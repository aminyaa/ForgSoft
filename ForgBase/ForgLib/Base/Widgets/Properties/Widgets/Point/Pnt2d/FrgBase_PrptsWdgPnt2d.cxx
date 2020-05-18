#include <FrgBase_PrptsWdgPnt2d.hxx>
#include <FrgBase_PrptsVrntPnt2d.hxx>
#include <FrgBase_Pnt2d.hxx>

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

ForgBaseLib::FrgBase_PrptsWdgPnt2d::FrgBase_PrptsWdgPnt2d
(
	QWidget* parent,
	FrgBase_PrptsVrnt* variant
)
	: FrgBase_PrptsWdgOneValue<FrgBase_Pnt2d*, false>(parent, variant)
{
	if (variant)
	{
		FormWidget();
	}
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::FormWidget()
{
	if (!theVariant_)
	{
		std::cout << "theVariant_ is null in ForgBaseLib::FrgBase_PrptsWdgPnt2d::FormWidget()\n";
		return;
	}

	connect(dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_), SIGNAL(DisplayNameChangedSignal(const char*)), this, SLOT(DisplayNameChangedSlot(const char*)));
	connect(dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_), SIGNAL(ValueChangedSignal(FrgBase_Pnt2d*)), this, SLOT(ValueChangedSlot(FrgBase_Pnt2d*)));
	connect(dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_), SIGNAL(PrefixChangedSignal(const char*)), this, SLOT(PrefixChangedSlot(const char*)));
	connect(dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_), SIGNAL(SuffixChangedSignal(const char*)), this, SLOT(SuffixChangedSlot(const char*)));

	QHBoxLayout* myHLayout = new QHBoxLayout;

	QHBoxLayout* myXHLayout = new QHBoxLayout;
	myXHLayout->setMargin(0);
	myXHLayout->setSpacing(0);
	myXHLayout->setContentsMargins(0, 2, 0, 2);

	QHBoxLayout* myYHLayout = new QHBoxLayout;
	myYHLayout->setMargin(0);
	myYHLayout->setSpacing(0);
	myYHLayout->setContentsMargins(0, 2, 0, 2);

	if (GetPrefix() != "")
	{
		SetPrefix(GetPrefix());
	}

	theXLineEdit_ = new QLineEdit;
	theXLineEdit_->setText(std::to_string(GetValue()->X()).c_str());
	theXLineEdit_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	theXLineEdit_->setMinimumWidth(70);

	myXHLayout->addWidget(new QLabel("X:  "));
	myXHLayout->addWidget(theXLineEdit_);

	theYLineEdit_ = new QLineEdit;
	theYLineEdit_->setText(std::to_string(GetValue()->Y()).c_str());
	theYLineEdit_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	theYLineEdit_->setMinimumWidth(70);

	myYHLayout->addWidget(new QLabel("Y:  "));
	myYHLayout->addWidget(theYLineEdit_);

	if (GetSuffix() != "")
	{
		SetSuffix(GetSuffix());
	}

	QVBoxLayout* myLayout = new QVBoxLayout;
	myLayout->addLayout(myXHLayout);
	myLayout->addLayout(myYHLayout);

	myHLayout->addLayout(myLayout);

	this->setLayout(myHLayout);

	connect(theXLineEdit_, SIGNAL(editingFinished()), this, SLOT(WdgXValueChangedSlot()));
	connect(theYLineEdit_, SIGNAL(editingFinished()), this, SLOT(WdgYValueChangedSlot()));
}

ForgBaseLib::FrgBase_PrptsWdgPnt2d::~FrgBase_PrptsWdgPnt2d()
{
	FreePointer(thePrefixLabel_);
	FreePointer(theSuffixLabel_);
	FreePointer(theXLineEdit_);
	FreePointer(theYLineEdit_);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::SetValue(FrgBase_Pnt2d* const &value)
{
	FrgBase_PrptsWdgOneValue::SetValue(value);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::SetPrefix(const char * prefix)
{
	FrgBase_PrptsWdgOneValue::SetPrefix(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::SetSuffix(const char * suffix)
{
	FrgBase_PrptsWdgOneValue::SetSuffix(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::SetVariant(const ForgBaseLib::FrgBase_PrptsVrntOneValue<FrgBase_Pnt2d*, false>& variant)
{
	FrgBase_PrptsWdgOneValue::SetVariant(variant);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::DisplayNameChangedSlot(const char* displayName)
{

}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::ValueChangedSlot(FrgBase_Pnt2d* value)
{
	if (theXLineEdit_->text().toDouble() != value->X())
		theXLineEdit_->setText(std::to_string(value->X()).c_str());
	if (theYLineEdit_->text().toDouble() != value->Y())
		theYLineEdit_->setText(std::to_string(value->Y()).c_str());
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::PrefixChangedSlot(const char * prefix)
{
	if (!thePrefixLabel_)
		thePrefixLabel_ = new QLabel((std::string(prefix) + std::string(" ")).c_str());
	else
		thePrefixLabel_->setText(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::SuffixChangedSlot(const char * suffix)
{
	if (!theSuffixLabel_)
		theSuffixLabel_ = new QLabel((std::string(" ") + std::string(suffix)).c_str());
	else
		theSuffixLabel_->setText(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::WdgXValueChangedSlot()
{
	if (theXLineEdit_->isModified())
		dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_)->SetXValue(theXLineEdit_->text().toDouble());
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::WdgYValueChangedSlot()
{
	if (theYLineEdit_->isModified())
		dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_)->SetYValue(theYLineEdit_->text().toDouble());
}