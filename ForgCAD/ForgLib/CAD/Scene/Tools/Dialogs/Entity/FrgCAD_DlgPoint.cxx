#include <FrgCAD_DlgPoint.hxx>

#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtGui/QDoubleValidator>

ForgCADLib::FrgCAD_DlgPoint::FrgCAD_DlgPoint(QWidget* parent /* = nullptr */)
	: FrgCAD_DlgEntity(parent)
{
	FormDlg();
}

void ForgCADLib::FrgCAD_DlgPoint::SetValue(std::vector<double> values)
{
	if (values.empty() && values.size() != 2)
		return;

	SetXValue(values[0]);
	SetYValue(values[1]);
}

void ForgCADLib::FrgCAD_DlgPoint::SetXValue(double value)
{
	if (theXData_)
	{
		theXData_->theLineEdit_->blockSignals(true);
		theXData_->theLineEdit_->setText(QString::number(value, 'f').leftJustified(6, '0'));
		theXData_->theLineEdit_->blockSignals(false);
	}
}

void ForgCADLib::FrgCAD_DlgPoint::SetYValue(double value)
{
	if (theYData_)
	{
		theYData_->theLineEdit_->blockSignals(true);
		theYData_->theLineEdit_->setText(QString::number(value, 'f').leftJustified(6, '0'));
		theYData_->theLineEdit_->blockSignals(false);
	}
}

double ForgCADLib::FrgCAD_DlgPoint::FrgCAD_DlgPoint::GetXValue() const
{
	if (theXData_)
		return theXData_->theLineEdit_->text().toDouble();

	return 0.0;
}

double ForgCADLib::FrgCAD_DlgPoint::FrgCAD_DlgPoint::GetYValue() const
{
	if (theYData_)
		return theYData_->theLineEdit_->text().toDouble();

	return 0.0;
}

void ForgCADLib::FrgCAD_DlgPoint::SetFocused(bool condition)
{
	if (theXData_)
	{
		if (condition)
		{
			theXData_->theLineEdit_->setFocus();
			theXData_->theLineEdit_->selectAll();
		}
		else
		{
			theXData_->theLineEdit_->editingFinished();
			parentWidget()->setFocus();
		}
	}
}

void ForgCADLib::FrgCAD_DlgPoint::FormDlg()
{
	theXData_ = new Data;
	theYData_ = new Data;

	theXData_->theLabel_ = new QLabel("X");
	theYData_->theLabel_ = new QLabel("Y");
	theXData_->theLineEdit_ = new QLineEdit;
	theYData_->theLineEdit_ = new QLineEdit;

	theXData_->theLineEdit_->setValidator(new QDoubleValidator);
	theYData_->theLineEdit_->setValidator(new QDoubleValidator);

	QHBoxLayout* theXLayout = new QHBoxLayout;
	QHBoxLayout* theYLayout = new QHBoxLayout;

	theXLayout->addWidget(theXData_->theLabel_);
	theXLayout->addWidget(theXData_->theLineEdit_);
	theYLayout->addWidget(theYData_->theLabel_);
	theYLayout->addWidget(theYData_->theLineEdit_);

	theLayout_->addLayout(theXLayout);
	theLayout_->addLayout(theYLayout);

	connect(theXData_->theLineEdit_, &QLineEdit::textChanged, [this](const QString& text)
		{
			theIsInEditing_ = true;
			emit XValueChangedSignal(text.toDouble());
			emit IsInEditingSignal(true);
		}
	);
	connect(theYData_->theLineEdit_, &QLineEdit::textChanged, [this](const QString& text)
		{
			theIsInEditing_ = true;
			emit YValueChangedSignal(text.toDouble());
			emit IsInEditingSignal(true);
		}
	);

	connect(theXData_->theLineEdit_, &QLineEdit::returnPressed, [this]()
		{
			theIsInEditing_ = false;

			emit theXData_->theLineEdit_->editingFinished();
			theOKButton_->click();
		}
	);
	connect(theYData_->theLineEdit_, &QLineEdit::returnPressed, [this]()
		{
			theIsInEditing_ = false;

			emit theXData_->theLineEdit_->editingFinished();
			theOKButton_->click();
		}
	);

	FrgCAD_DlgEntity::FormDlg();
}