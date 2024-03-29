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
	FrgBase_PrptsVrnt * variant
)
	: FrgBase_PrptsWdgOneValue(parent, variant)
{
	
}

ForgBaseLib::FrgBase_PrptsWdgBool::~FrgBase_PrptsWdgBool()
{
	FreePointer(thePrefixLabel_);
	FreePointer(theSuffixLabel_);
	FreePointer(theCheckBox_);
}

void ForgBaseLib::FrgBase_PrptsWdgBool::FormWidget()
{
	if (!theVariant_)
	{
		std::cout << "theVariant_ is null in ForgBaseLib::FrgBase_PrptsWdgBool::FormWidget()\n";
		return;
	}

	connect(dynamic_cast<FrgBase_PrptsVrntBool*>(theVariant_), SIGNAL(DisplayNameChangedSignal(const QString&)), this, SLOT(DisplayNameChangedSlot(const QString&)));
	connect(dynamic_cast<FrgBase_PrptsVrntBool*>(theVariant_), SIGNAL(ValueChangedSignal(const bool&)), this, SLOT(ValueChangedSlot(const bool&)));
	connect(dynamic_cast<FrgBase_PrptsVrntBool*>(theVariant_), SIGNAL(PrefixChangedSignal(const QString&)), this, SLOT(PrefixChangedSlot(const QString&)));
	connect(dynamic_cast<FrgBase_PrptsVrntBool*>(theVariant_), SIGNAL(SuffixChangedSignal(const QString&)), this, SLOT(SuffixChangedSlot(const QString&)));

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

	connect(theCheckBox_, SIGNAL(toggled(bool)), this, SLOT(WdgValueChangedSlot(bool)));

	theCheckBox_->installEventFilter(this);
}

void ForgBaseLib::FrgBase_PrptsWdgBool::SetValue(const bool & value)
{
	FrgBase_PrptsWdgOneValue<bool, false>::SetValue(value);
}

void ForgBaseLib::FrgBase_PrptsWdgBool::SetPrefix(const QString& prefix)
{
	FrgBase_PrptsWdgOneValue<bool, false>::SetPrefix(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgBool::SetSuffix(const QString& suffix)
{
	FrgBase_PrptsWdgOneValue<bool, false>::SetSuffix(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgBool::SetVariant(const FrgBase_PrptsVrntOneValue<bool, false>& variant)
{
	FrgBase_PrptsWdgOneValue<bool, false>::SetVariant(variant);
	theCheckBox_->setChecked(variant.GetValue());
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

void ForgBaseLib::FrgBase_PrptsWdgBool::DisplayNameChangedSlot(const QString& displayName)
{

}

void ForgBaseLib::FrgBase_PrptsWdgBool::ValueChangedSlot(const bool& value)
{
	if(theCheckBox_->isChecked() != value)
		theCheckBox_->setChecked(value);
}

void ForgBaseLib::FrgBase_PrptsWdgBool::PrefixChangedSlot(const QString& prefix)
{
	if (!thePrefixLabel_)
		thePrefixLabel_ = new QLabel(prefix + " ");
	else
		thePrefixLabel_->setText(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgBool::SuffixChangedSlot(const QString& suffix)
{
	if (!theSuffixLabel_)
		theSuffixLabel_ = new QLabel(" " + suffix);
	else
		theSuffixLabel_->setText(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgBool::WdgValueChangedSlot(bool checked)
{
	SetValue(checked);

	/*QEvent* event = new QEvent(QEvent::MouseButtonRelease);

	if(theParentPropertiesPanel_)
		theParentPropertiesPanel_->eventFilter(this, event);*/
}