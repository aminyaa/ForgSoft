#include <FrgBaseDlgNewSim.hxx>
#include <FrgBaseMainWindow.hxx>

#include <QtWidgets/QGroupBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QPushButton>
#include <QtGui/QKeyEvent>

ForgBaseLib::FrgBaseDlgNewSim::FrgBaseDlgNewSim(FrgBaseMainWindow* parent)
	: QDialog(parent)
{
	this->setMinimumSize(QSize(450, 600));
	this->setModal(true);
	this->setWindowTitle(QMainWindow::tr("Create a New Simulation"));

	setWindowIcon(QIcon(":/Icons/Menus/File/New.png"));

	setupLayout();
}

void ForgBaseLib::FrgBaseDlgNewSim::setupLayout()
{
	theMPI_GroupBox_ = FrgNew QGroupBox(QMainWindow::tr("Process Options"));
	the_Layout_NewSim_ = FrgNew QVBoxLayout;
	theLayout_MPI_Group_ = FrgNew QVBoxLayout;

	theRadioBtn1_ = FrgNew QRadioButton(QMainWindow::tr("Serial"));
	theRadioBtn1_->setChecked(true);

	theRadioBtn2_ = FrgNew QRadioButton(QMainWindow::tr("Parallel"));

	theLayout_MPI_Group_->addWidget(theRadioBtn1_);
	theLayout_MPI_Group_->addWidget(theRadioBtn2_);

	theParallelLabel_ = FrgNew QLabel(QMainWindow::tr("Compute Processes:"));
	theParallelSpin_ = FrgNew QSpinBox();
	theParallelSpin_->setValue(2);
	theParallelLayout_ = FrgNew QHBoxLayout();
	theParallelLayout_->addWidget(theParallelLabel_);
	theParallelLayout_->addWidget(theParallelSpin_);
	theLayout_MPI_Group_->addLayout(theParallelLayout_);
	theParallelLabel_->setVisible(false);
	theParallelSpin_->setVisible(false);

	theMPI_GroupBox_->setLayout(theLayout_MPI_Group_);

	the_Layout_NewSim_->addSpacing(10);
	the_Layout_NewSim_->addWidget(theMPI_GroupBox_);
	the_Layout_NewSim_->addStretch(1);

	theBtnOK_ = FrgNew QPushButton(QMainWindow::tr("OK"));
	theBtnCancel_ = FrgNew QPushButton(QMainWindow::tr("Cancel"));
	theBtnLayout_ = FrgNew QHBoxLayout();
	theBtnLayout_->addStretch(1);
	theBtnLayout_->addWidget(theBtnOK_);
	theBtnLayout_->addWidget(theBtnCancel_);

	the_Layout_NewSim_->addLayout(theBtnLayout_);

	this->setLayout(the_Layout_NewSim_);

	connect(theParallelSpin_, SIGNAL(editingFinished()), this, SLOT(ShowParallelOptions()));

	connect(theRadioBtn1_, SIGNAL(clicked()), this, SLOT(ShowParallelOptions()));
	connect(theRadioBtn2_, SIGNAL(clicked()), this, SLOT(ShowParallelOptions()));

	connect(this->theBtnOK_, SIGNAL(clicked()), this, SLOT(onOK()));
	connect(this->theBtnCancel_, SIGNAL(clicked()), this, SLOT(reject()));

	this->theBtnOK_->setFocus();
}

void ForgBaseLib::FrgBaseDlgNewSim::onOK()
{
	accept();
}

void ForgBaseLib::FrgBaseDlgNewSim::ShowParallelOptions()
{
	bool b = theRadioBtn2_->isChecked();
	this->theParallelLabel_->setVisible(b);
	this->theParallelSpin_->setVisible(b);
	this->theBtnOK_->setFocus();
}

void ForgBaseLib::FrgBaseDlgNewSim::keyPressEvent(QKeyEvent* event)
{
	switch (event->key())
	{
	case Qt::Key_Escape:
	{
		done(0);
		break;
	}
	case Qt::Key_Return:
	case Qt::Key_Enter:
	{
		QDialog::accept();

		break;
	}
	default:
		event->ignore();
	}
}