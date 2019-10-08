#include <FrgDlgLoadSim.hxx>
#include <FrgMainWindow.hxx>

#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QFileDialog>

ForgBaseLib::FrgDlgLoadSim::FrgDlgLoadSim(FrgMainWindow* parent)
	: FrgDlgNewSim(parent)
{
	this->setWindowTitle(QMainWindow::tr("Load Simulation"));

	setWindowIcon(QIcon(":/Icons/Menus/File/Load.png"));

	theBrowseLabel_ = FrgNew QLabel(QMainWindow::tr("File"));
	theBrowseBtn_ = FrgNew QPushButton(QMainWindow::tr("Browse"));
	theBrowseLineEdit_ = FrgNew QLineEdit;
	theBrowseLayout_ = FrgNew QHBoxLayout;

	theBrowseLayout_->addWidget(theBrowseLabel_);
	theBrowseLayout_->addWidget(theBrowseLineEdit_);
	theBrowseLayout_->addWidget(theBrowseBtn_);

	this->GetWindowLayout()->insertLayout(this->GetWindowLayout()->count() - 2, theBrowseLayout_);

	connect(theBrowseLineEdit_, SIGNAL(returnPressed()), this, SLOT(ShowParallelOptions()));
	connect(theBrowseBtn_, SIGNAL(clicked()), this, SLOT(ShowBrowseDialog()));
}

void ForgBaseLib::FrgDlgLoadSim::ShowBrowseDialog()
{
	QString fileName = QFileDialog::getOpenFileName(this, "Open a simulation", "",
		"frg Files (*.frg)");

	theBrowseLineEdit_->setText(fileName);
}