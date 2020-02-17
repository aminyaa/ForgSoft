#include <FrgBase_DlgDelete.hxx>
#include <FrgBase_MainWindow.hxx>

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtGui/QKeyEvent>
#include <QtGui/QShowEvent>

ForgBaseLib::FrgBase_DlgDelete::FrgBase_DlgDelete
(
	const QString & currentName,
	FrgBase_MainWindow * parentMainWindow
)
	: FrgBase_Dlg(parentMainWindow)
	, theCurrentName_(currentName.simplified())
{
	this->setWindowTitle("Delete Item");

	setupLayout();
}

ForgBaseLib::FrgBase_DlgDelete::~FrgBase_DlgDelete()
{
	FreePointer(theNoButton_);
	FreePointer(theYesButton_);
	FreePointer(theMessage_);
	FreePointer(theButtonsLayout_);
	FreePointer(theMainLayout_);
}

void ForgBaseLib::FrgBase_DlgDelete::setupLayout()
{
	theMainLayout_ = new QVBoxLayout;
	theButtonsLayout_ = new QHBoxLayout;

	theMessage_ = new QLabel("Are you sure you want to delete " + theCurrentName_ + "?");

	theYesButton_ = new QPushButton("Yes");
	theNoButton_ = new QPushButton("No");
	theButtonsLayout_->addStretch(1);
	theButtonsLayout_->addWidget(theYesButton_);
	theButtonsLayout_->addWidget(theNoButton_);

	theMainLayout_->addWidget(theMessage_);
	theMainLayout_->addLayout(theButtonsLayout_);

	this->setLayout(theMainLayout_);

	QObject::connect(theYesButton_, SIGNAL(clicked()), this, SLOT(onOK()));
	QObject::connect(theNoButton_, SIGNAL(clicked()), this, SLOT(reject()));

	theYesButton_->setFocus();
	this->setModal(FrgTrue);

	this->adjustSize();
}

void ForgBaseLib::FrgBase_DlgDelete::keyPressEvent(QKeyEvent * event)
{
	switch (event->key())
	{
	case Qt::Key_Escape:
		reject();
		break;
	}
}

void ForgBaseLib::FrgBase_DlgDelete::onOK()
{
	accept();
}