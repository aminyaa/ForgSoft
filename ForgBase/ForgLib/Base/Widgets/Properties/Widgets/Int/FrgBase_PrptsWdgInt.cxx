#include <FrgBase_PrptsWdgInt.hxx>
#include <FrgBase_PrptsVrntInt.hxx>

#include <QtWidgets/QSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QEvent>
#include <QtGui/QKeyEvent>
#include <QLineEdit>

#include <string.h>

ForgBaseLib::FrgBase_PrptsWdgInt::FrgBase_PrptsWdgInt
(
	QWidget* parent,
	FrgBase_PrptsVrnt* variant
)
	: FrgBase_PrptsWdgOneValue(parent, variant)
{
	
}

ForgBaseLib::FrgBase_PrptsWdgInt::~FrgBase_PrptsWdgInt()
{
	FreePointer(thePrefixLabel_);
	FreePointer(theSuffixLabel_);
	FreePointer(theSpinBox_);
}

void ForgBaseLib::FrgBase_PrptsWdgInt::FormWidget()
{
	if (!theVariant_)
	{
		std::cout << "theVariant_ is null in ForgBaseLib::FrgBase_PrptsWdgInt::FormWidget()\n";
		return;
	}

	connect(dynamic_cast<FrgBase_PrptsVrntInt*>(theVariant_), SIGNAL(DisplayNameChangedSignal(const QString&)), this, SLOT(DisplayNameChangedSlot(const QString&)));
	connect(dynamic_cast<FrgBase_PrptsVrntInt*>(theVariant_), SIGNAL(ValueChangedSignal(const int&)), this, SLOT(ValueChangedSlot(const int&)));
	connect(dynamic_cast<FrgBase_PrptsVrntInt*>(theVariant_), SIGNAL(MinimumValueChangedSignal(const int&)), this, SLOT(MinimumValueChangedSlot(const int&)));
	connect(dynamic_cast<FrgBase_PrptsVrntInt*>(theVariant_), SIGNAL(MaximumValueChangedSignal(const int&)), this, SLOT(MaximumValueChangedSlot(const int&)));
	connect(dynamic_cast<FrgBase_PrptsVrntInt*>(theVariant_), SIGNAL(StepValueChangedSignal(const int&)), this, SLOT(StepValueChangedSlot(const int&)));
	connect(dynamic_cast<FrgBase_PrptsVrntInt*>(theVariant_), SIGNAL(PrefixChangedSignal(const QString&)), this, SLOT(PrefixChangedSlot(const QString&)));
	connect(dynamic_cast<FrgBase_PrptsVrntInt*>(theVariant_), SIGNAL(SuffixChangedSignal(const QString&)), this, SLOT(SuffixChangedSlot(const QString&)));

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

	theSpinBox_->setLocale(QLocale(QLocale::Language::English, QLocale::UnitedStates));

	theSpinBox_->setMinimum(GetMinimumValue());
	theSpinBox_->setMaximum(GetMaximumValue());
	theSpinBox_->setSingleStep(GetStepValue());
	theSpinBox_->setValue(GetValue());
	theSpinBox_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	theSpinBox_->setFixedWidth(100);
	theSpinBox_->setKeyboardTracking(false);

	theSpinBox_->installEventFilter(this);

	myLayout->addWidget(theSpinBox_);
	myLayout->addStretch(1);

	if (GetSuffix() != "")
	{
		SetSuffix(GetSuffix());
		myLayout->addWidget(theSuffixLabel_);
	}

	this->setLayout(myLayout);

	connect(theSpinBox_, SIGNAL(valueChanged(int)), this, SLOT(WdgValueChangedSlot()));
	connect(theSpinBox_, SIGNAL(editingFinished()), this, SLOT(WdgValueChangedSlot()));
}

void ForgBaseLib::FrgBase_PrptsWdgInt::SetValue(const int& value)
{
	FrgBase_PrptsWdgOneValue<int>::SetValue(value);
}

const int & ForgBaseLib::FrgBase_PrptsWdgInt::GetMinimumValue() const
{
	return dynamic_cast<FrgBase_PrptsVrntInt*>(theVariant_)->GetMinimumValue();
}

void ForgBaseLib::FrgBase_PrptsWdgInt::SetMinimumValue(const int& value)
{
	dynamic_cast<FrgBase_PrptsVrntInt*>(theVariant_)->SetMinimumValue(value);
}

const int & ForgBaseLib::FrgBase_PrptsWdgInt::GetMaximumValue() const
{
	return dynamic_cast<FrgBase_PrptsVrntInt*>(theVariant_)->GetMaximumValue();
}

void ForgBaseLib::FrgBase_PrptsWdgInt::SetMaxmimumValue(const int& value)
{
	dynamic_cast<FrgBase_PrptsVrntInt*>(theVariant_)->SetMaximumValue(value);
}

const int & ForgBaseLib::FrgBase_PrptsWdgInt::GetStepValue() const
{
	return dynamic_cast<FrgBase_PrptsVrntInt*>(theVariant_)->GetStepValue();
}

void ForgBaseLib::FrgBase_PrptsWdgInt::SetStepValue(const int& stepValue)
{
	dynamic_cast<FrgBase_PrptsVrntInt*>(theVariant_)->SetStepValue(stepValue);
}

void ForgBaseLib::FrgBase_PrptsWdgInt::SetPrefix(const QString& prefix)
{
	FrgBase_PrptsWdgOneValue<int>::SetPrefix(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgInt::SetSuffix(const QString& suffix)
{
	FrgBase_PrptsWdgOneValue<int>::SetSuffix(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgInt::SetVariant(const FrgBase_PrptsVrntOneValue<int> & variant)
{
	FrgBase_PrptsWdgOneValue<int>::SetVariant(variant);
	theSpinBox_->setValue(variant.GetValue());
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
	if (event->type() == QEvent::FocusOut)
	{
		theSpinBox_->clearFocus();
		event->accept();

		return false;
	}

	if (event->type() == QEvent::KeyPress)
	{
		QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

		if (keyEvent)
		{
			if (keyEvent->key() == Qt::Key_Escape)
			{
				theSpinBox_->setValue(GetValue());
				theSpinBox_->clearFocus();
				event->accept();
				return false;
			}
			if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter)
			{
				/*const auto& le = theSpinBox_->findChild<QLineEdit*>();
				if(le)
					le->deselect();*/
				theSpinBox_->clearFocus();
				event->accept();

				return true;
			}
		}
	}
	
	/*std::cout << "From WdgInt() " << obj->metaObject()->className() << std::endl;

	if (event->type() == QEvent::KeyPress)
	{
		QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

		std::cout << obj->metaObject()->className() << " ====> " << keyEvent->key() << std::endl;
	}

	*/

	return FrgBase_PrptsWdgOneValue<int>::eventFilter(obj, event);
}

void ForgBaseLib::FrgBase_PrptsWdgInt::DisplayNameChangedSlot(const QString& displayName)
{

}

void ForgBaseLib::FrgBase_PrptsWdgInt::ValueChangedSlot(const int & value)
{
	if(theSpinBox_->value() != value)
		theSpinBox_->setValue(value);
}

void ForgBaseLib::FrgBase_PrptsWdgInt::MinimumValueChangedSlot(const int & value)
{
	if(theSpinBox_->minimum() != value)
		theSpinBox_->setMinimum(value);
}

void ForgBaseLib::FrgBase_PrptsWdgInt::MaximumValueChangedSlot(const int & value)
{
	if(theSpinBox_->maximum() != value)
		theSpinBox_->setMaximum(value);
}

void ForgBaseLib::FrgBase_PrptsWdgInt::StepValueChangedSlot(const int & stepValue)
{
	if(theSpinBox_->singleStep() != stepValue)
		theSpinBox_->setSingleStep(stepValue);
}

void ForgBaseLib::FrgBase_PrptsWdgInt::PrefixChangedSlot(const QString& prefix)
{
	if (!thePrefixLabel_)
		thePrefixLabel_ = new QLabel(prefix + " ");
	else
		thePrefixLabel_->setText(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgInt::SuffixChangedSlot(const QString& suffix)
{
	if (!theSuffixLabel_)
		theSuffixLabel_ = new QLabel(" " + suffix);
	else
		theSuffixLabel_->setText(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgInt::WdgValueChangedSlot()
{
	if (theSpinBox_->value() != GetValue())
		SetValue(theSpinBox_->value());
}