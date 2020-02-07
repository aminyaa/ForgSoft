#include <FrgBase_PrptsWdgInt.hxx>
#include <FrgBase_PrptsVrntInt.hxx>

#include <QtWidgets/QSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QEvent>
#include <QtGui/QKeyEvent>

#include <string.h>

ForgBaseLib::FrgBase_PrptsWdgInt::FrgBase_PrptsWdgInt
(
	QWidget* parent,
	FrgBase_PrptsVrntInt* variant
)
	: FrgBase_PrptsWdgOneValue(parent, variant)
{
	if (variant)
	{
		FormWidget();
	}
}

void ForgBaseLib::FrgBase_PrptsWdgInt::FormWidget()
{
	if (!theVariant_)
	{
		std::cout << "theVariant_ is null in ForgBaseLib::FrgBase_PrptsWdgInt::FormWidget()\n";
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
	
	theSpinBox_ = new QSpinBox(this);
	theSpinBox_->setValue(GetValue());
	theSpinBox_->setMinimum(GetMinimumValue());
	theSpinBox_->setMaximum(GetMaximumValue());
	theSpinBox_->setSingleStep(GetStepValue());
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

	connect(theSpinBox_, SIGNAL(valueChanged(int)), this, SIGNAL(valueChanged(int)));
	connect(theSpinBox_, SIGNAL(editingFinished()), this, SLOT(editingFinished()));
}

void ForgBaseLib::FrgBase_PrptsWdgInt::SetValue(const int& value)
{
	FrgBase_PrptsWdgOneValue<int>::SetValue(value);
	theSpinBox_->setValue(value);
}

const int & ForgBaseLib::FrgBase_PrptsWdgInt::GetMinimumValue() const
{
	return theVariant_->GetMinimumValue();
}

void ForgBaseLib::FrgBase_PrptsWdgInt::SetMinimumValue(const int& value)
{
	theVariant_->SetMinimumValue(value);
	theSpinBox_->setMinimum(value);
}

const int & ForgBaseLib::FrgBase_PrptsWdgInt::GetMaximumValue() const
{
	return theVariant_->GetMaximumValue();
}

void ForgBaseLib::FrgBase_PrptsWdgInt::SetMaxmimumValue(const int& value)
{
	theVariant_->SetMaximumValue(value);
	theSpinBox_->setMaximum(value);
}

const int & ForgBaseLib::FrgBase_PrptsWdgInt::GetStepValue() const
{
	return theVariant_->GetStepValue();
}

void ForgBaseLib::FrgBase_PrptsWdgInt::SetStepValue(const int& stepValue)
{
	theVariant_->SetStepValue(stepValue);
	theSpinBox_->setSingleStep(stepValue);
}

void ForgBaseLib::FrgBase_PrptsWdgInt::SetPrefix(const char * prefix)
{
	FrgBase_PrptsWdgOneValue<int>::SetPrefix(prefix);

	if (!thePrefixLabel_)
		thePrefixLabel_ = new QLabel((std::string(prefix) + std::string(" ")).c_str());
	else
		thePrefixLabel_->setText(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgInt::SetSuffix(const char * suffix)
{
	FrgBase_PrptsWdgOneValue<int>::SetSuffix(suffix);

	if (!theSuffixLabel_)
		theSuffixLabel_ = new QLabel((std::string(" ") + std::string(suffix)).c_str());
	else
		theSuffixLabel_->setText(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgInt::SetVariant(const FrgBase_PrptsVrntOneValue<int> & variant)
{
	FrgBase_PrptsWdgOneValue<int>::SetVariant(variant);
	theSpinBox_->setValue(variant.GetValue());
}

void ForgBaseLib::FrgBase_PrptsWdgInt::editingFinished()
{
	//std::cout << "Editing Finished\n";
}

bool ForgBaseLib::FrgBase_PrptsWdgInt::event(QEvent * event)
{
	//std::cout << "From WdgInt() " << event->type() << std::endl;
	if (event->type() == QEvent::KeyPress)
	{
		QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

		
	}

	return FrgBase_PrptsWdgOneValue<int>::event(event);
}

bool ForgBaseLib::FrgBase_PrptsWdgInt::eventFilter(QObject * obj, QEvent * event)
{
	/*std::cout << "From WdgInt() " << obj->metaObject()->className() << std::endl;

	if (event->type() == QEvent::KeyPress)
	{
		QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

		std::cout << obj->metaObject()->className() << " ====> " << keyEvent->key() << std::endl;
	}

	*/return FrgBase_PrptsWdgOneValue<int>::eventFilter(obj, event);
}