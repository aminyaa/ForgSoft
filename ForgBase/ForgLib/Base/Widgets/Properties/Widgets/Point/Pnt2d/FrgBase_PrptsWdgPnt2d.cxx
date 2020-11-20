#include <FrgBase_PrptsWdgPnt2d.hxx>
#include <FrgBase_PrptsVrntPnt2d.hxx>
#include <FrgBase_Pnt2d.hxx>

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtGui/QRegExpValidator>
#include <QtCore/QEvent>
#include <QtGui/QKeyEvent>
#include <QtCore/QTimer>

ForgBaseLib::FrgBase_PrptsWdgPnt2d::FrgBase_PrptsWdgPnt2d
(
	QWidget* parent,
	FrgBase_PrptsVrnt* variant
)
	: FrgBase_PrptsWdgOneValue<FrgBase_Pnt2d*, false>(parent, variant)
{
	
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::FormWidget()
{
	if (!theVariant_)
	{
		std::cout << "theVariant_ is null in ForgBaseLib::FrgBase_PrptsWdgPnt2d::FormWidget()\n";
		return;
	}

	connect(dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_), SIGNAL(DisplayNameChangedSignal(const QString&)), this, SLOT(DisplayNameChangedSlot(const QString&)));
	connect(dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_), SIGNAL(ValueChangedSignal(FrgBase_Pnt2d*)), this, SLOT(ValueChangedSlot(FrgBase_Pnt2d*)));
	connect(dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_), SIGNAL(PrefixChangedSignal(const QString&)), this, SLOT(PrefixChangedSlot(const QString&)));
	connect(dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_), SIGNAL(SuffixChangedSignal(const QString&)), this, SLOT(SuffixChangedSlot(const QString&)));

	connect(dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_), SIGNAL(XPrefixLabelChangedSignal(const QString&)), this, SLOT(XPrefixLabelChangedSlot(const QString&)));
	connect(dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_), SIGNAL(YPrefixLabelChangedSignal(const QString&)), this, SLOT(YPrefixLabelChangedSlot(const QString&)));

	connect(dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_), SIGNAL(XSuffixLabelChangedSignal(const QString&)), this, SLOT(XSuffixLabelChangedSlot(const QString&)));
	connect(dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_), SIGNAL(YSuffixLabelChangedSignal(const QString&)), this, SLOT(YSuffixLabelChangedSlot(const QString&)));

	QVBoxLayout* myLineEditsLayout = new QVBoxLayout;
	myLineEditsLayout->setMargin(0);
	myLineEditsLayout->setSpacing(5);
	myLineEditsLayout->setContentsMargins(0, 0, 0, 0);

	QVBoxLayout* myLabelsLayout = new QVBoxLayout;
	myLabelsLayout->setMargin(0);
	myLabelsLayout->setSpacing(5);
	myLabelsLayout->setContentsMargins(0, 0, 0, 0);

	QVBoxLayout* myLabels2Layout = new QVBoxLayout;
	myLabels2Layout->setMargin(0);
	myLabels2Layout->setSpacing(5);
	myLabels2Layout->setContentsMargins(0, 0, 0, 0);

	if (GetPrefix() != "")
	{
		SetPrefix(GetPrefix());
	}

	theXLineEdit_ = new QLineEdit;
	theXLineEdit_->setText(QString::number(GetValue()->X(), 'G'));
	theXLineEdit_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	theXLineEdit_->setMinimumWidth(70);

	theXPrefixLabel_ = new QLabel(dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_)->GetXPrefixLabel() + ":  ");
	theXSuffixLabel_ = new QLabel("  " + dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_)->GetXSuffixLabel());
	myLabelsLayout->addWidget(theXPrefixLabel_);
	myLabels2Layout->addWidget(theXSuffixLabel_);
	myLineEditsLayout->addWidget(theXLineEdit_);

	theYLineEdit_ = new QLineEdit;
	theYLineEdit_->setText(QString::number(GetValue()->Y(), 'G'));
	theYLineEdit_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	theYLineEdit_->setMinimumWidth(70);

	theYPrefixLabel_ = new QLabel(dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_)->GetYPrefixLabel() + ":  ");
	theYSuffixLabel_ = new QLabel("  " + dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_)->GetYSuffixLabel());
	myLabelsLayout->addWidget(theYPrefixLabel_);
	myLabels2Layout->addWidget(theYSuffixLabel_);
	myLineEditsLayout->addWidget(theYLineEdit_);

	QHBoxLayout* myLayout = new QHBoxLayout;
	myLayout->addLayout(myLabelsLayout);
	myLayout->addLayout(myLineEditsLayout);
	myLayout->addLayout(myLabels2Layout);

	if (GetSuffix() != "")
	{
		SetSuffix(GetSuffix());
		myLayout->addWidget(theSuffixLabel_);
	}

	this->setLayout(myLayout);

	connect(theXLineEdit_, SIGNAL(editingFinished()), this, SLOT(WdgXValueChangedSlot()));
	connect(theYLineEdit_, SIGNAL(editingFinished()), this, SLOT(WdgYValueChangedSlot()));

	theXLineEdit_->setValidator(new QDoubleValidator(theXLineEdit_));
	theYLineEdit_->setValidator(new QDoubleValidator(theYLineEdit_));

	theXLineEdit_->installEventFilter(this);
	theYLineEdit_->installEventFilter(this);

	theXLineEdit_->setTabletTracking(true);
	theYLineEdit_->setTabletTracking(true);
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

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::SetPrefix(const QString& prefix)
{
	FrgBase_PrptsWdgOneValue::SetPrefix(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::SetSuffix(const QString& suffix)
{
	FrgBase_PrptsWdgOneValue::SetSuffix(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::SetVariant(const ForgBaseLib::FrgBase_PrptsVrntOneValue<FrgBase_Pnt2d*, false>& variant)
{
	FrgBase_PrptsWdgOneValue::SetVariant(variant);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::DisplayNameChangedSlot(const QString& displayName)
{

}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::ValueChangedSlot(FrgBase_Pnt2d* value)
{
	if (theXLineEdit_->text().toDouble() != value->X())
		theXLineEdit_->setText(std::to_string(value->X()).c_str());
	if (theYLineEdit_->text().toDouble() != value->Y())
		theYLineEdit_->setText(std::to_string(value->Y()).c_str());
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::PrefixChangedSlot(const QString& prefix)
{
	if (!thePrefixLabel_)
		thePrefixLabel_ = new QLabel(prefix + " ");
	else
		thePrefixLabel_->setText(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::SuffixChangedSlot(const QString& suffix)
{
	if (!theSuffixLabel_)
		theSuffixLabel_ = new QLabel(" " + suffix);
	else
		theSuffixLabel_->setText(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::XPrefixLabelChangedSlot(const QString& xPrefixLabel)
{
	theXPrefixLabel_->setText(xPrefixLabel + ":  ");
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::YPrefixLabelChangedSlot(const QString& yPrefixLabel)
{
	theYPrefixLabel_->setText(yPrefixLabel + ":  ");
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::XSuffixLabelChangedSlot(const QString& xSuffixLabel)
{
	theXSuffixLabel_->setText("  " + xSuffixLabel);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::YSuffixLabelChangedSlot(const QString& ySuffixLabel)
{
	theYSuffixLabel_->setText("  " + ySuffixLabel);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::WdgXValueChangedSlot()
{
	if (theXLineEdit_->text() == QString::number(dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_)->GetValue()->X(), 'G'))
	{
		theXLineEdit_->blockSignals(true);
		theXLineEdit_->clearFocus();
		theXLineEdit_->blockSignals(false);
		return;
	}

	theXLineEdit_->blockSignals(true);

	dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_)->SetXValue(theXLineEdit_->text().toDouble());

	theXLineEdit_->setText(QString::number(theXLineEdit_->text().toDouble(), 'G'));
	theXLineEdit_->clearFocus();
	theXLineEdit_->blockSignals(false);
}

void ForgBaseLib::FrgBase_PrptsWdgPnt2d::WdgYValueChangedSlot()
{
	if (theYLineEdit_->text() == QString::number(dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_)->GetValue()->Y(), 'G'))
	{
		theYLineEdit_->blockSignals(true);
		theYLineEdit_->clearFocus();
		theYLineEdit_->blockSignals(false);
		return;
	}

	theYLineEdit_->blockSignals(true);

	dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_)->SetYValue(theYLineEdit_->text().toDouble());

	theYLineEdit_->setText(QString::number(theYLineEdit_->text().toDouble(), 'G'));
	theYLineEdit_->clearFocus();
	theYLineEdit_->blockSignals(false);
}

bool ForgBaseLib::FrgBase_PrptsWdgPnt2d::eventFilter(QObject* watched, QEvent* event)
{
	if (event->type() == QEvent::FocusIn)
	{
		if (watched == theXLineEdit_)
			QTimer::singleShot(0, theXLineEdit_, &QLineEdit::selectAll);
		else if (watched == theYLineEdit_)
			QTimer::singleShot(0, theYLineEdit_, &QLineEdit::selectAll);
		else
			return false;
	}
	if (event->type() == QEvent::KeyPress)
	{
		QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

		if (keyEvent)
		{
			if (keyEvent->key() == Qt::Key_Tab)
			{
				if (watched == theXLineEdit_)
				{
					emit theXLineEdit_->editingFinished();
					theYLineEdit_->setFocus(Qt::TabFocusReason);
					return true;
				}
				else if (watched == theYLineEdit_)
				{
					emit theYLineEdit_->editingFinished();
					theXLineEdit_->setFocus(Qt::TabFocusReason);
					return true;
				}
			}
			if (keyEvent->key() == Qt::Key_Backtab)
			{
				if (watched == theXLineEdit_)
				{
					emit theXLineEdit_->editingFinished();
					theYLineEdit_->setFocus(Qt::BacktabFocusReason);
					return true;
				}
				else if (watched == theYLineEdit_)
				{
					emit theYLineEdit_->editingFinished();
					theXLineEdit_->setFocus(Qt::BacktabFocusReason);
					return true;
				}
			}
			if (keyEvent->key() == Qt::Key_Escape)
			{
				if (watched == theXLineEdit_)
				{
					theXLineEdit_->setText(QString::number(dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_)->GetValue()->X(), 'G'));
					emit theXLineEdit_->editingFinished();
					return true;
				}
				else if (watched == theYLineEdit_)
				{
					theYLineEdit_->setText(QString::number(dynamic_cast<FrgBase_PrptsVrntPnt2d*>(theVariant_)->GetValue()->Y(), 'G'));
					emit theYLineEdit_->editingFinished();
					return true;
				}
			}
		}
	}

	return FrgBase_PrptsWdgOneValue::eventFilter(watched, event);
}