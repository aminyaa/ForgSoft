#include <ForgGuiLoadSimDlg.hxx>

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QFileDialog>

ForgGuiLib::ForgGuiLoadSimDlg::ForgGuiLoadSimDlg(ForgGuiMainWindow* parent)
	: ForgGuiNewSimDlg(parent)
{
	this->setWindowTitle(QMainWindow::tr("Load Simulation"));

	setWindowIcon(QIcon(":/Icons/Menus/File/Load.png"));

	theBrowseLabel_ = new QLabel(QMainWindow::tr("File"));
	theBrowseBtn_ = new QPushButton(QMainWindow::tr("Browse"));
	theBrowseLineEdit_ = new QLineEdit;
	theBrowseLayout_ = new QHBoxLayout;

	theBrowseLayout_->addWidget(theBrowseLabel_);
	theBrowseLayout_->addWidget(theBrowseLineEdit_);
	theBrowseLayout_->addWidget(theBrowseBtn_);

	this->GetWindowLayout()->insertLayout(this->GetWindowLayout()->count() - 2, theBrowseLayout_);

	connect(theBrowseLineEdit_, SIGNAL(returnPressed()), this, SLOT(ShowParallelOptions()));
	connect(theBrowseBtn_, SIGNAL(clicked()), this, SLOT(ShowBrowseDialog()));
}

void ForgGuiLib::ForgGuiLoadSimDlg::ShowBrowseDialog()
{
	QString fileName = QFileDialog::getOpenFileName(this, "Open a simulation", "",
		"Forg Files (*.frg)");

	theBrowseLineEdit_->setText(fileName);
}