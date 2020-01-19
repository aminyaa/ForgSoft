#include <FrgBase_PrptsEditorInt.hxx>

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QSpinBox>
#include <QtGui/QKeyEvent>

ForgBaseLib::FrgBase_PrptsEditorInt::FrgBase_PrptsEditorInt(QWidget* parent /* = nullptr */)
	: FrgBase_PrptsEditorBase(parent)
{
	//QLayout* layout = new QVBoxLayout();
	theSpinBox_ = new QSpinBox(this);
	//this->setGeometry(parent->rect());
	theSpinBox_->setGeometry(this->rect());
	//layout->addWidget(theSpinBox_);

	//this->setContentsMargins(0, 0, 0, 0);

	//connect(theSpinBox_, SIGNAL(valueChanged(int)), this, SIGNAL(editingFinished()));
}

int ForgBaseLib::FrgBase_PrptsEditorInt::GetMaximumValue() const
{
	return theSpinBox_->maximum();
}

void ForgBaseLib::FrgBase_PrptsEditorInt::SetMaximumValue(int value)
{
	theSpinBox_->setMaximum(value);
}

int ForgBaseLib::FrgBase_PrptsEditorInt::GetMinimumValue() const
{
	return theSpinBox_->minimum();
}

void ForgBaseLib::FrgBase_PrptsEditorInt::SetMinimumValue(int value)
{
	theSpinBox_->setMinimum(value);
}

int ForgBaseLib::FrgBase_PrptsEditorInt::GetValue() const
{
	return theSpinBox_->value();
}

void ForgBaseLib::FrgBase_PrptsEditorInt::SetValue(int value)
{
	theSpinBox_->setValue(value);
}

int ForgBaseLib::FrgBase_PrptsEditorInt::GetStep() const
{
	return theSpinBox_->singleStep();
}

void ForgBaseLib::FrgBase_PrptsEditorInt::SetStep(int step)
{
	theSpinBox_->setSingleStep(step);
}

QString ForgBaseLib::FrgBase_PrptsEditorInt::GetSuffix() const
{
	return theSpinBox_->suffix();
}

void ForgBaseLib::FrgBase_PrptsEditorInt::SetSuffix(const QString & text)
{
	theSpinBox_->setSuffix(text);
}

void ForgBaseLib::FrgBase_PrptsEditorInt::mouseReleaseEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton || event->button() == Qt::RightButton)
	{
		emit editingFinished();
		event->accept();
	}
	FrgBase_PrptsEditorBase::mouseReleaseEvent(event);
}

void ForgBaseLib::FrgBase_PrptsEditorInt::keyReleaseEvent(QKeyEvent * event)
{
	if (event->key() == QKeyEvent::Enter)
	{
		emit editingFinished();
		event->accept();
	}
	FrgBase_PrptsEditorBase::keyReleaseEvent(event);
}