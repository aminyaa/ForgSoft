#include <FrgBase_DlgRenameTItem.hxx>
#include <FrgBase_MainWindow.hxx>

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtGui/QKeyEvent>
#include <QtGui/QShowEvent>

ForgBaseLib::FrgBase_DlgRenameTItem::FrgBase_DlgRenameTItem
(
	const QString& currentName,
	FrgBase_MainWindow* parentMainWindow
)
	: FrgBase_Dlg(parentMainWindow)
	, theCurrentName_(currentName.simplified())
{

}

void ForgBaseLib::FrgBase_DlgRenameTItem::setupLayout()
{
	/*theMainLayout_ = new QVBoxLayout;
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
	QObject::connect(theNameLineEdit_, SIGNAL(editingFinished()), this, SLOT(onOK()));
	QObject::connect(theCloseButton_, SIGNAL(clicked()), this, SLOT(reject()));

	theOKButton_->setFocus();
	this->setModal(FrgTrue);*/
}

void ForgBaseLib::FrgBase_DlgRenameTItem::keyPressEvent(QKeyEvent* event)
{
}

void ForgBaseLib::FrgBase_DlgRenameTItem::showEvent(QShowEvent*)
{
	//move(x() - (GetParentMainWindow()->geometry().center().x()), y() - (GetParentMainWindow()->geometry().center().y()));
}

QString ForgBaseLib::FrgBase_DlgRenameTItem::GetLineEditName() const
{
	//return theNameLineEdit_->text();
	return "";
}