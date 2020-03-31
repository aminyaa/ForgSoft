#include <FrgBase_PrptsWdgPnt3d.hxx>
#include <FrgBase_PrptsVrntPnt3d.hxx>

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

ForgBaseLib::FrgBase_PrptsWdgPnt3d::FrgBase_PrptsWdgPnt3d
(
	QWidget* parent,
	FrgBase_PrptsVrnt* variant
)
	: FrgBase_PrptsWdgOneValue<Pnt3d_Data*, false>(parent, variant)
{
	if (variant)
	{
		FormWidget();
	}
}

void ForgBaseLib::FrgBase_PrptsWdgPnt3d::FormWidget()
{
	if (!theVariant_)
	{
		std::cout << "theVariant_ is null in ForgBaseLib::FrgBase_PrptsWdgPnt2d::FormWidget()\n";
		return;
	}

	connect(dynamic_cast<FrgBase_PrptsVrntPnt3d*>(theVariant_), SIGNAL(DisplayNameChangedSignal(const char*)), this, SLOT(DisplayNameChangedSlot(const char*)));
	connect(dynamic_cast<FrgBase_PrptsVrntPnt3d*>(theVariant_), SIGNAL(ValueChangedSignal(Pnt3d_Data*)), this, SLOT(ValueChangedSlot(Pnt3d_Data*)));
	connect(dynamic_cast<FrgBase_PrptsVrntPnt3d*>(theVariant_), SIGNAL(PrefixChangedSignal(const char*)), this, SLOT(PrefixChangedSlot(const char*)));
	connect(dynamic_cast<FrgBase_PrptsVrntPnt3d*>(theVariant_), SIGNAL(SuffixChangedSignal(const char*)), this, SLOT(SuffixChangedSlot(const char*)));

	QHBoxLayout* myHLayout = new QHBoxLayout;

	QHBoxLayout* myXHLayout = new QHBoxLayout;
	myXHLayout->setMargin(0);
	myXHLayout->setSpacing(0);
	myXHLayout->setContentsMargins(0, 2, 0, 2);

	QHBoxLayout* myYHLayout = new QHBoxLayout;
	myYHLayout->setMargin(0);
	myYHLayout->setSpacing(0);
	myYHLayout->setContentsMargins(0, 2, 0, 2);

	QHBoxLayout* myZHLayout = new QHBoxLayout;
	myZHLayout->setMargin(0);
	myZHLayout->setSpacing(0);
	myZHLayout->setContentsMargins(0, 2, 0, 2);

	if (GetPrefix() != "")
	{
		SetPrefix(GetPrefix());
	}

	theXLineEdit_ = new QLineEdit;
	theXLineEdit_->setText(std::to_string(GetValue()->theX_).c_str());
	theXLineEdit_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	theXLineEdit_->setMinimumWidth(70);

	myXHLayout->addWidget(new QLabel("X:  "));
	myXHLayout->addWidget(theXLineEdit_);

	theYLineEdit_ = new QLineEdit;
	theYLineEdit_->setText(std::to_string(GetValue()->theY_).c_str());
	theYLineEdit_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	theYLineEdit_->setMinimumWidth(70);

	myYHLayout->addWidget(new QLabel("Y:  "));
	myYHLayout->addWidget(theYLineEdit_);

	theZLineEdit_ = new QLineEdit;
	theZLineEdit_->setText(std::to_string(GetValue()->theZ_).c_str());
	theZLineEdit_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	theZLineEdit_->setMinimumWidth(70);

	myZHLayout->addWidget(new QLabel("Z:  "));
	myZHLayout->addWidget(theZLineEdit_);

	if (GetSuffix() != "")
	{
		SetSuffix(GetSuffix());
	}

	QVBoxLayout* myLayout = new QVBoxLayout;
	myLayout->addLayout(myXHLayout);
	myLayout->addLayout(myYHLayout);
	myLayout->addLayout(myZHLayout);

	myHLayout->addLayout(myLayout);

	this->setLayout(myHLayout);

	connect(theXLineEdit_, SIGNAL(editingFinished()), this, SLOT(WdgXValueChangedSlot()));
	connect(theYLineEdit_, SIGNAL(editingFinished()), this, SLOT(WdgYValueChangedSlot()));
	connect(theZLineEdit_, SIGNAL(editingFinished()), this, SLOT(WdgZValueChangedSlot()));
}

ForgBaseLib::FrgBase_PrptsWdgPnt3d::~FrgBase_PrptsWdgPnt3d()
{
	FreePointer(thePrefixLabel_);
	FreePointer(theSuffixLabel_);
	FreePointer(theXLineEdit_);
	FreePointer(theYLineEdit_);
	FreePointer(theZLineEdit_);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt3d::SetValue(Pnt3d_Data* const &value)
{
	FrgBase_PrptsWdgOneValue::SetValue(value);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt3d::SetPrefix(const char * prefix)
{
	FrgBase_PrptsWdgOneValue::SetPrefix(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt3d::SetSuffix(const char * suffix)
{
	FrgBase_PrptsWdgOneValue::SetSuffix(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt3d::SetVariant(const ForgBaseLib::FrgBase_PrptsVrntOneValue<Pnt3d_Data*, false>& variant)
{
	FrgBase_PrptsWdgOneValue::SetVariant(variant);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt3d::DisplayNameChangedSlot(const char* displayName)
{

}

void ForgBaseLib::FrgBase_PrptsWdgPnt3d::ValueChangedSlot(Pnt3d_Data* value)
{
	if (theXLineEdit_->text().toDouble() != value->theX_)
		theXLineEdit_->setText(std::to_string(value->theX_).c_str());
	if (theYLineEdit_->text().toDouble() != value->theY_)
		theYLineEdit_->setText(std::to_string(value->theY_).c_str());
}

void ForgBaseLib::FrgBase_PrptsWdgPnt3d::PrefixChangedSlot(const char * prefix)
{
	if (!thePrefixLabel_)
		thePrefixLabel_ = new QLabel((std::string(prefix) + std::string(" ")).c_str());
	else
		thePrefixLabel_->setText(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt3d::SuffixChangedSlot(const char * suffix)
{
	if (!theSuffixLabel_)
		theSuffixLabel_ = new QLabel((std::string(" ") + std::string(suffix)).c_str());
	else
		theSuffixLabel_->setText(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt3d::WdgXValueChangedSlot()
{
	if (theXLineEdit_->isModified())
		dynamic_cast<FrgBase_PrptsVrntPnt3d*>(theVariant_)->SetXValue(theXLineEdit_->text().toDouble());
}

void ForgBaseLib::FrgBase_PrptsWdgPnt3d::WdgYValueChangedSlot()
{
	if (theYLineEdit_->isModified())
		dynamic_cast<FrgBase_PrptsVrntPnt3d*>(theVariant_)->SetYValue(theYLineEdit_->text().toDouble());
}

void ForgBaseLib::FrgBase_PrptsWdgPnt3d::WdgZValueChangedSlot()
{
	if (theZLineEdit_->isModified())
		dynamic_cast<FrgBase_PrptsVrntPnt3d*>(theVariant_)->SetZValue(theZLineEdit_->text().toDouble());
}