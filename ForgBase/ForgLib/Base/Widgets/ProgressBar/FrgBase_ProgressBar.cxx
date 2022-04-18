#include <FrgBase_ProgressBar.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgBase_FramelessWindow.hxx>

#include <QtWidgets/QProgressBar>
#include <QtWidgets/QLabel>
#include <QtCore/QLocale>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QStyle>

ForgBaseLib::FrgBase_ProgressBar::FrgBase_ProgressBar(FrgBase_MainWindow* parentMainWindow)
	: QWidget(parentMainWindow)
{
	theProgressBar_ = new QProgressBar(this);
	theLabel_ = new QLabel;
	
	theProgressBar_->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

	theProgressBar_->setFixedHeight(12);
	theProgressBar_->setMaximumWidth(350);
	theProgressBar_->setMinimumWidth(350);
	theProgressBar_->setRange(0, 1);

	QHBoxLayout* layout = new QHBoxLayout;
	layout->addWidget(theProgressBar_, 1);
	layout->addWidget(theLabel_);

	layout->setContentsMargins(0, 0, 0, 0);
	this->setLayout(layout);
	this->setContentsMargins(0, 0, 5, 0);
	this->adjustSize();

	SetLabelHidden();

	connect(this, &FrgBase_ProgressBar::SetProgressBarBusy, this, &FrgBase_ProgressBar::SetProgressBarBusySlot);

	SetProgressBarBusy(false);
}

void ForgBaseLib::FrgBase_ProgressBar::SetProgressBarBusySlot(bool condition)
{
	
	if (condition)
	{
		theProgressBar_->setRange(0, 0);
		this->setHidden(false);
	}
	else
	{
		theProgressBar_->setRange(0, 1);
		this->setHidden(true);
	}
}

QString ForgBaseLib::FrgBase_ProgressBar::GetLabel() const
{
	return theLabel_->text();
}

void ForgBaseLib::FrgBase_ProgressBar::SetLabel(const QString& label) const
{
	theLabel_->setText(label);
}

void ForgBaseLib::FrgBase_ProgressBar::SetLabelHidden(bool condition) const
{
	theLabel_->setHidden(condition);
}