#include <SplitWidget.hxx>
#include <FrgBaseMainWindow.hxx>
#include <SplitTree.hxx>
#include <FrgBaseCADScene.hxx>

#include <QtWidgets/QDockWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>

ForgBaseLib::SplitWidget::SplitWidget
(
	FrgString name,
	FrgBaseMainWindow* parenMainWindow,
	SurfaceBlockPtr surfaceBlock,
	CurveBlockPtr curveBlock,
	QList<FrgBaseCADScene*> pointerToScenes
)
	: QWidget(parenMainWindow)
	, theParentMainWindow_(parenMainWindow)
{
	QVBoxLayout* mainLayout = new QVBoxLayout();
	QHBoxLayout* nameLayout = new QHBoxLayout();
	QHBoxLayout* buttonsLayout = new QHBoxLayout();

	theTree_ = FrgNew SplitTree(theParentMainWindow_, surfaceBlock, curveBlock, pointerToScenes);

	QLabel* nameLabel = new QLabel("Name");
	QLineEdit* nameLineEdit = new QLineEdit();
	nameLayout->addWidget(nameLabel);
	nameLayout->addWidget(nameLineEdit);

	QPushButton* createButton = new QPushButton("Create");
	QPushButton* cancelButton = new QPushButton("Cancel");
	buttonsLayout->addStretch(1);
	buttonsLayout->addWidget(createButton);
	buttonsLayout->addWidget(cancelButton);

	mainLayout->addWidget(theTree_);
	mainLayout->addLayout(nameLayout);
	mainLayout->addLayout(buttonsLayout);
	
	QWidget* mainWidget = new QWidget();
	mainWidget->setLayout(mainLayout);

	QDockWidget* splitWidget = new QDockWidget("Split " + name, theParentMainWindow_);
	splitWidget->setTitleBarWidget(new QWidget);
	theParentMainWindow_->tabifyDockWidget(theParentMainWindow_->GetTreeWidget()->theDockWidget_, splitWidget);
	theParentMainWindow_->tabifiedDockWidgetActivated(splitWidget);
	theParentMainWindow_->GetTreeWidget()->theDockWidget_->setEnabled(false);
	splitWidget->setWidget(mainWidget);

	splitWidget->show();
	splitWidget->raise();

}