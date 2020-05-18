#include <FrgMarine_MainWindow.hxx>
#include <FrgMarine_Tree.hxx>
#include <FrgBase_ProgressBar.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_TabWidget.hxx>

#include <FrgMarine_Serialization_Global.hxx>

#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFileDialog>

#include <iostream>
#include <fstream>

ForgMarineLib::FrgMarine_MainWindow::FrgMarine_MainWindow(QWidget* parent)
	: FrgBase_MainWindow(parent)
{
	this->setMinimumSize(QSize(1366, 768));

	InitMainWindow();
}

void ForgMarineLib::FrgMarine_MainWindow::InitMainWindow()
{
	FormMenus();
	SetMainWindowStyleSheet();

	theTree_ = new FrgMarine_Tree(this);
	theTree_->FormTree();
	theProgressBar_ = new ForgBaseLib::FrgBase_ProgressBar(this);
	thePropertiesPanel_ = new ForgBaseLib::FrgBase_PropertiesPanel(this, nullptr);

	theTreeDockWidget_ = new QDockWidget("Tree", this);
	theTreeDockWidget_->setWidget(theTree_);
	theTreeDockWidget_->setTitleBarWidget(new QWidget);
	this->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, theTreeDockWidget_);

	theProgressBarDockWidget_ = new QDockWidget("Progress Bar", this);
	theProgressBarDockWidget_->setWidget(theProgressBar_);
	theProgressBarDockWidget_->setTitleBarWidget(new QWidget);
	this->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, theProgressBarDockWidget_);

	thePropertiesPanelDockWidget_ = new QDockWidget("Properties", this);
	thePropertiesPanelDockWidget_->setWidget(thePropertiesPanel_);
	thePropertiesPanelDockWidget_->setTitleBarWidget(new QWidget);
	this->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, thePropertiesPanelDockWidget_);

	CreateConsoleOutput();
}

void ForgMarineLib::FrgMarine_MainWindow::FileLoadActionSlot()
{
	QString* ext;
	QString fileName = QFileDialog::getOpenFileName(this, "Load File", "", "Tonb (*.tnb)");

	if (fileName.isEmpty())
		return;


	std::ifstream myFile(fileName.toStdString());
	boost::archive::polymorphic_binary_iarchive ia(myFile);

	FrgMarine_Tree* myTree;

	ia >> myTree;

	myFile.close();

	delete theTree_;
	theTree_ = myTree;
	theTree_->SetParentMainWindow(this);

	theTreeDockWidget_->setWidget(theTree_);
}

void ForgMarineLib::FrgMarine_MainWindow::FileSaveActionSlot()
{
	QString* ext;
	QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Tonb (*.tnb)");

	if (fileName.isEmpty())
		return;


	std::ofstream myFile(fileName.toStdString());
	//boost::archive::text_oarchive oa(myFile);
	boost::archive::polymorphic_binary_oarchive oa(myFile);

	/*oa.template register_type<ForgBaseLib::FrgBase_Tree>();
	oa.template register_type<ForgMarineLib::FrgMarine_Tree>();*/

	auto myTree = dynamic_cast<FrgMarine_Tree*>(theTree_);
	oa << myTree;

	myFile.close();
}