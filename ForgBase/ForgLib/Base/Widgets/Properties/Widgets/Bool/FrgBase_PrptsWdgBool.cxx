#include <FrgBase_PrptsWdgBool.hxx>
#include <FrgBase_PrptsVrntBool.hxx>

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtCore/QEvent>
#include <QtGui/QMouseEvent>
#include <QtWidgets/QApplication>
#include <FrgBase_PropertiesPanel.hxx>

ForgBaseLib::FrgBase_PrptsWdgBool::FrgBase_PrptsWdgBool
(
	QWidget * parent,
	FrgBase_PrptsVrntBool * variant
)
	: FrgBase_PrptsWdgOneValue(parent, variant)
	, theParentPropertiesPanel_(dynamic_cast<FrgBase_PropertiesPanel*>(parent))
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

	theCheckBox_ = new QCheckBox(this);
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
	connect(theCheckBox_, SIGNAL(toggled(bool)), this, SLOT(valueChangedSlot(bool)));

	theCheckBox_->installEventFilter(this);
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

void ForgBaseLib::FrgBase_PrptsWdgBool::valueChangedSlot(bool checked)
{
	theVariant_->SetValue(checked);

	/*QEvent* event = new QEvent(QEvent::MouseButtonRelease);

	if(theParentPropertiesPanel_)
		theParentPropertiesPanel_->eventFilter(this, event);*/
}

//void ForgBaseLib::FrgBase_PrptsWdgBool::mouseReleaseEvent(QMouseEvent * event)
//{
//	std::cout << "event->button() = " << event->button() << std::endl;
//	if (event->button() == Qt::MouseButton::LeftButton)
//	{
//		theCheckBox_->click();
//	}
//}

//bool ForgBaseLib::FrgBase_PrptsWdgBool::eventFilter(QObject * obj, QEvent * event)
//{
//	//std::cout << "theCheckBox_ = " << theCheckBox_ << ", obj = " << obj << std::endl;
//	////std::cout << "object = " << obj->metaObject()->className() << ", event = " << event->type() << std::endl;
//	//if (obj == theCheckBox_ && event->type() == QEvent::MouseButtonRelease)
//	//{
//	//	theCheckBox_->setChecked(!theCheckBox_->isChecked());
//	//	//return true;
//	//}
//	return FrgBase_PrptsWdgOneValue<bool, false>::eventFilter(obj, event);
//}