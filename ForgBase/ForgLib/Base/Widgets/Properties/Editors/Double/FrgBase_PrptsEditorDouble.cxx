#include <FrgBase_PrptsEditorDouble.hxx>

#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QVBoxLayout>

ForgBaseLib::FrgBase_PrptsEditorDouble::FrgBase_PrptsEditorDouble(QWidget* parent /* = nullptr */)
	: FrgBase_PrptsEditorBase(parent)
{
	QLayout* layout = new QVBoxLayout(this);
	theSpinBox_ = new QDoubleSpinBox(this);
	layout->addWidget(theSpinBox_);

	this->setLayout(layout);

	connect(theSpinBox_, SIGNAL(valueChanged(double)), this, SIGNAL(editingFinished()));
}

double ForgBaseLib::FrgBase_PrptsEditorDouble::GetMaximumValue() const
{
	return theSpinBox_->maximum();
}

void ForgBaseLib::FrgBase_PrptsEditorDouble::SetMaximumValue(double value)
{
	theSpinBox_->setMaximum(value);
}

double ForgBaseLib::FrgBase_PrptsEditorDouble::GetMinimumValue() const
{
	return theSpinBox_->minimum();
}

void ForgBaseLib::FrgBase_PrptsEditorDouble::SetMinimumValue(double value)
{
	theSpinBox_->setMinimum(value);
}

double ForgBaseLib::FrgBase_PrptsEditorDouble::GetValue() const
{
	return theSpinBox_->value();
}

void ForgBaseLib::FrgBase_PrptsEditorDouble::SetValue(double value)
{
	theSpinBox_->setValue(value);
}

double ForgBaseLib::FrgBase_PrptsEditorDouble::GetStep() const
{
	return theSpinBox_->singleStep();
}

void ForgBaseLib::FrgBase_PrptsEditorDouble::SetStep(double step)
{
	theSpinBox_->setSingleStep(step);
}

QString ForgBaseLib::FrgBase_PrptsEditorDouble::GetSuffix() const
{
	return theSpinBox_->suffix();
}

void ForgBaseLib::FrgBase_PrptsEditorDouble::SetSuffix(const QString & text)
{
	theSpinBox_->setSuffix(text);
}