#include <FrgBase_PrptsWdgTextEdit.hxx>
#include <FrgBase_PrptsVrntTextEdit.hxx>

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QLabel>
#include <QtCore/QEvent>
#include <QtGui/QMouseEvent>
#include <QtWidgets/QApplication>
#include <FrgBase_PropertiesPanel.hxx>

ForgBaseLib::FrgBase_PrptsWdgTextEdit::FrgBase_PrptsWdgTextEdit
(
	QWidget* parent,
	FrgBase_PrptsVrnt* variant
)
	: FrgBase_PrptsWdgOneValue(parent, variant)
{

}

ForgBaseLib::FrgBase_PrptsWdgTextEdit::~FrgBase_PrptsWdgTextEdit()
{
	FreePointer(thePrefixLabel_);
	FreePointer(theSuffixLabel_);
	FreePointer(theTextEdit_);
}

void ForgBaseLib::FrgBase_PrptsWdgTextEdit::FormWidget()
{
	if (!theVariant_)
	{
		std::cout << "theVariant_ is null in ForgBaseLib::FrgBase_PrptsWdgTextEdit::FormWidget()\n";
		return;
	}

	const auto& myVariant = dynamic_cast<FrgBase_PrptsVrntTextEdit*>(theVariant_);
	if (myVariant)
	{
		connect(myVariant, SIGNAL(DisplayNameChangedSignal(const QString&)), this, SLOT(DisplayNameChangedSlot(const QString&)));
		connect(myVariant, SIGNAL(ValueChangedSignal(const QString&)), this, SLOT(ValueChangedSlot(const QString&)));
		connect(myVariant, SIGNAL(PrefixChangedSignal(const QString&)), this, SLOT(PrefixChangedSlot(const QString&)));
		connect(myVariant, SIGNAL(SuffixChangedSignal(const QString&)), this, SLOT(SuffixChangedSlot(const QString&)));
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

	theTextEdit_ = new QTextEdit(this);
	theTextEdit_->setText(GetValue());
	myLayout->addWidget(theTextEdit_);
	myLayout->addStretch(1);

	if (GetSuffix() != "")
	{
		SetSuffix(GetSuffix());
		myLayout->addWidget(theSuffixLabel_);
	}

	this->setLayout(myLayout);

	connect(theTextEdit_, &QTextEdit::textChanged, this, &FrgBase_PrptsWdgTextEdit::WdgValueChangedSlot);

	theTextEdit_->installEventFilter(this);
}

void ForgBaseLib::FrgBase_PrptsWdgTextEdit::SetValue(const QString& value)
{
	FrgBase_PrptsWdgOneValue<QString, false>::SetValue(value);
}

void ForgBaseLib::FrgBase_PrptsWdgTextEdit::SetPrefix(const QString& prefix)
{
	FrgBase_PrptsWdgOneValue<QString, false>::SetPrefix(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgTextEdit::SetSuffix(const QString& suffix)
{
	FrgBase_PrptsWdgOneValue<QString, false>::SetSuffix(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgTextEdit::SetVariant(const FrgBase_PrptsVrntOneValue<QString, false>& variant)
{
	FrgBase_PrptsWdgOneValue<QString, false>::SetVariant(variant);
	theTextEdit_->setText(variant.GetValue());
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

void ForgBaseLib::FrgBase_PrptsWdgTextEdit::DisplayNameChangedSlot(const QString& displayName)
{

}

void ForgBaseLib::FrgBase_PrptsWdgTextEdit::ValueChangedSlot(const QString& value)
{
	if (theTextEdit_->toPlainText() != value)
		theTextEdit_->setText(value);
}

void ForgBaseLib::FrgBase_PrptsWdgTextEdit::PrefixChangedSlot(const QString& prefix)
{
	if (!thePrefixLabel_)
		thePrefixLabel_ = new QLabel(prefix + " ");
	else
		thePrefixLabel_->setText(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgTextEdit::SuffixChangedSlot(const QString& suffix)
{
	if (!theSuffixLabel_)
		theSuffixLabel_ = new QLabel(" " + suffix);
	else
		theSuffixLabel_->setText(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgTextEdit::WdgValueChangedSlot()
{
	SetValue(theTextEdit_->toPlainText());

	/*QEvent* event = new QEvent(QEvent::MouseButtonRelease);

	if(theParentPropertiesPanel_)
		theParentPropertiesPanel_->eventFilter(this, event);*/
}