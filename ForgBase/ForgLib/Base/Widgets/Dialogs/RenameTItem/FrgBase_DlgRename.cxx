#include <FrgBase_DlgRename.hxx>
#include <FrgBase_MainWindow.hxx>

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtGui/QKeyEvent>
#include <QtGui/QShowEvent>

ForgBaseLib::FrgBase_DlgRename::FrgBase_DlgRename
(
	const QString& currentName,
	FrgBase_MainWindow* parentMainWindow
)
	: FrgBase_Dlg(parentMainWindow)
	, theCurrentName_(currentName.simplified())
{
	this->setWindowTitle("Rename Item");

	setupLayout();
}

ForgBaseLib::FrgBase_DlgRename::~FrgBase_DlgRename()
{
	FreePointer(theCloseButton_);
	FreePointer(theOKButton_);
	FreePointer(theNameLineEdit_);
	FreePointer(theNameLabel_);
	FreePointer(theNameLayout_);
	FreePointer(theButtonsLayout_);
	FreePointer(theMainLayout_);
}

void ForgBaseLib::FrgBase_DlgRename::setupLayout()
{
	theMainLayout_ = new QVBoxLayout;
	theButtonsLayout_ = new QHBoxLayout;
	theNameLayout_ = new QHBoxLayout;

	theNameLabel_ = new QLabel("Name:");
	theNameLineEdit_ = new QLineEdit(theCurrentName_);
	theNameLayout_->addWidget(theNameLabel_);
	theNameLayout_->addWidget(theNameLineEdit_);

	theOKButton_ = new QPushButton("OK");
	theCloseButton_ = new QPushButton("Close");
	theButtonsLayout_->addWidget(theOKButton_);
	theButtonsLayout_->addWidget(theCloseButton_);

	theMainLayout_->addLayout(theNameLayout_);
	theMainLayout_->addLayout(theButtonsLayout_);

	this->setLayout(theMainLayout_);

	QObject::connect(theOKButton_, SIGNAL(clicked()), this, SLOT(onOK()));
	QObject::connect(theCloseButton_, SIGNAL(clicked()), this, SLOT(reject()));
	QObject::connect(theNameLineEdit_, SIGNAL(returnPressed()), this, SLOT(onOK()));

	theOKButton_->setFocus();
	theNameLineEdit_->setFocus();
	this->setModal(FrgTrue);

	this->adjustSize();
}

void ForgBaseLib::FrgBase_DlgRename::keyPressEvent(QKeyEvent* event)
{
	switch (event->key())
	{
	case Qt::Key_Escape:
		reject();
		break;
	}
}

QString ForgBaseLib::FrgBase_DlgRename::GetLineEditName() const
{
	return theNameLineEdit_->text();
}

void ForgBaseLib::FrgBase_DlgRename::onOK()
{
	if (theNameLineEdit_->text().simplified() == "")
		return;

	accept();
}