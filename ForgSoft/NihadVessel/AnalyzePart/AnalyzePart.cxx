#include <AnalyzePart.hxx>
#include <FrgBaseMainWindow.hxx>

#include <QtWidgets/QLabel>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QDockWidget>

ForgBaseLib::AnalyzePart::AnalyzePart
(
	FrgString name,
	FrgBaseMainWindow* parentMainWindow,
	FrgBaseCADPart_Entity* parentPart
)
	: QWidget(parentMainWindow)
	, theParentMainWindow_(parentMainWindow)
{
	theMainLayout_ = FrgNew QVBoxLayout;
	theTitle_ = FrgNew QLabel("Analyze Part");
	theContainerLayout_ = FrgNew QGridLayout;
	theButtonLayout_ = FrgNew QHBoxLayout;
	theContainerItems_ = FrgNew ContainerItems_Struct;
	theAnalyzeButton_ = FrgNew QPushButton("Analyze");
	theButtonItems_ = FrgNew ButtonItems_Struct;

	theContainerItems_->theNbCommonSingularitiesLabel_ = FrgNew QLabel("Number of Common Singularities");
	theContainerItems_->theNbDefectsLabel_ = FrgNew QLabel("Number of Defects");
	theContainerItems_->theNbDeepSingularitiesLabel_ = FrgNew QLabel("Number of Deep Singularities");
	theContainerItems_->theNbRegularsLabel_ = FrgNew QLabel("Number of Regulars");

	theContainerItems_->theNbCommonSingularitiesValue_ = FrgNew QPushButton("");
	theContainerItems_->theNbCommonSingularitiesValue_->setMinimumWidth(75);
	theContainerItems_->theNbDefectsValue_ = FrgNew QPushButton("");
	theContainerItems_->theNbDefectsValue_->setMinimumWidth(75);
	theContainerItems_->theNbDeepSingularitiesValue_ = FrgNew QPushButton("");
	theContainerItems_->theNbDeepSingularitiesValue_->setMinimumWidth(75);
	theContainerItems_->theNbRegularsValue_ = FrgNew QPushButton("");
	theContainerItems_->theNbRegularsValue_->setMinimumWidth(75);

	theButtonItems_->theRepairButton_ = FrgNew QPushButton("Repair");
	theButtonItems_->theCloseButton_ = FrgNew QPushButton("Close");

	QHBoxLayout* hLayout = FrgNew QHBoxLayout;

	theContainerLayout_->addWidget(theContainerItems_->theNbCommonSingularitiesLabel_, 0, 0);
	theContainerLayout_->addWidget(theContainerItems_->theNbCommonSingularitiesValue_, 0, 1);
	theContainerLayout_->addWidget(theContainerItems_->theNbDefectsLabel_, 1, 0);
	theContainerLayout_->addWidget(theContainerItems_->theNbDefectsValue_, 1, 1);
	theContainerLayout_->addWidget(theContainerItems_->theNbDeepSingularitiesLabel_, 2, 0);
	theContainerLayout_->addWidget(theContainerItems_->theNbDeepSingularitiesValue_, 2, 1);
	theContainerLayout_->addWidget(theContainerItems_->theNbRegularsLabel_, 3, 0);
	theContainerLayout_->addWidget(theContainerItems_->theNbRegularsValue_, 3, 1);
	theContainerLayout_->addWidget(theAnalyzeButton_, 4, 0);
	hLayout->addLayout(theContainerLayout_);
	hLayout->addStretch(1);

	theButtonLayout_->addWidget(theButtonItems_->theRepairButton_);
	theButtonLayout_->addWidget(theButtonItems_->theCloseButton_);
	theButtonLayout_->addStretch(1);

	theMainLayout_->addWidget(theTitle_);
	theMainLayout_->addLayout(hLayout);
	theMainLayout_->addStretch(1);
	theMainLayout_->addLayout(theButtonLayout_);

	this->setLayout(theMainLayout_);

	QDockWidget* dockWidget = new QDockWidget("Analyze " + name, theParentMainWindow_);
	dockWidget->setTitleBarWidget(new QWidget);
	theParentMainWindow_->tabifyDockWidget(theParentMainWindow_->GetTreeWidget()->theDockWidget_, dockWidget);
	theParentMainWindow_->tabifiedDockWidgetActivated(dockWidget);
	theParentMainWindow_->GetTreeWidget()->theDockWidget_->setEnabled(false);
	dockWidget->setWidget(this);

	dockWidget->show();
	dockWidget->raise();

	SetNbCommonSingularities(5);
	SetNbDefects(1);
	SetNbDeepSingularities(3);
	SetNbRegulars(10);
}

void ForgBaseLib::AnalyzePart::SetNbCommonSingularities(int number)
{
	// Yellow
	theContainerItems_->theNbCommonSingularitiesValue_->setText(QString::number(number));

	/*theContainerItems_->theNbCommonSingularitiesValue_->setStyleSheet
	(
		"background-color: qlineargradient(spread : pad, x1 : 0, y1 : 0, x2 : 0, y2 : 1, stop : 0 rgba(60, 186, 162, 255), stop : 1 rgba(98, 211, 162, 255))"
	);*/

	theContainerItems_->theNbCommonSingularitiesValue_->setStyleSheet
	(
		"background-color: qlineargradient(spread : pad, x1 : 0, y1 : 0, x2 : 0, y2 : 1, stop : 0 rgba(247, 220, 111, 255), stop : 1 rgba(241, 196, 15, 255))"
	);
}

void ForgBaseLib::AnalyzePart::SetNbDefects(int number)
{
	// Red
	theContainerItems_->theNbDefectsValue_->setText(QString::number(number));

	theContainerItems_->theNbDefectsValue_->setStyleSheet
	(
		"background-color: qlineargradient(spread : pad, x1 : 0, y1 : 0, x2 : 0, y2 : 1, stop : 0 rgba(236, 112, 99, 255), stop : 1 rgba(231, 76, 60, 255))"
	);
}

void ForgBaseLib::AnalyzePart::SetNbDeepSingularities(int number)
{
	// Purple
	theContainerItems_->theNbDeepSingularitiesValue_->setText(QString::number(number));

	theContainerItems_->theNbDeepSingularitiesValue_->setStyleSheet
	(
		"background-color: qlineargradient(spread : pad, x1 : 0, y1 : 0, x2 : 0, y2 : 1, stop : 0 rgba(165, 105, 189, 255), stop : 1 rgba(142, 68, 173, 255))"
	);
}

void ForgBaseLib::AnalyzePart::SetNbRegulars(int number)
{
	// Blue
	theContainerItems_->theNbRegularsValue_->setText(QString::number(number));

	theContainerItems_->theNbRegularsValue_->setStyleSheet
	(
		"background-color: qlineargradient(spread : pad, x1 : 0, y1 : 0, x2 : 0, y2 : 1, stop : 0 rgba(52, 152, 219, 255), stop : 1 rgba(46, 134, 193, 255))"
	);
}