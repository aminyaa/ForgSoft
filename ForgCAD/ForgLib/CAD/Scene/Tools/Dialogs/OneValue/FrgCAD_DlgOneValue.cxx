#include <FrgCAD_DlgOneValue.hxx>

#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtGui/QDoubleValidator>

ForgCADLib::FrgCAD_DlgOneValue::FrgCAD_DlgOneValue(const QString& label, QWidget* parent /* = nullptr */)
	: ForgCADLib::FrgCAD_DlgEntity(parent)
{
	theLabel_ = new QLabel(label);
	FormDlg();
}

void ForgCADLib::FrgCAD_DlgOneValue::SetFocused(bool condition)
{
	if (theValueLineEdit_)
	{
		if (condition)
		{
			theValueLineEdit_->setFocus();
			theValueLineEdit_->selectAll();
		}
		else
		{
			theValueLineEdit_->editingFinished();
			parentWidget()->setFocus();
		}
	}
}

void ForgCADLib::FrgCAD_DlgOneValue::SetValue(std::vector<double> values)
{
	if (values.empty() && values.size() != 1)
		return;

	if(theValueLineEdit_)
		theValueLineEdit_->setText(QString::number(values[0], 'f').leftJustified(6, '0'));
}

void ForgCADLib::FrgCAD_DlgOneValue::FormDlg()
{
	auto lay = new QHBoxLayout;
	lay->setContentsMargins(0, 0, 0, 0);
	theValueLineEdit_ = new QLineEdit;
	theValueLineEdit_->setValidator(new QDoubleValidator);
	theValueLineEdit_->setMinimumWidth(100);

	lay->addWidget(theLabel_);
	lay->addWidget(theValueLineEdit_);

	theLayout_->addLayout(lay);
	this->setLayout(theLayout_);

	connect(theValueLineEdit_, &QLineEdit::textChanged, [this](const QString& text)
		{
			emit ValueChangedSignal(text.toDouble());
		});

	this->show();

	FrgCAD_DlgEntity::FormDlg();
}