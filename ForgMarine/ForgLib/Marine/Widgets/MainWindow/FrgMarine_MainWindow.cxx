#include <FrgMarine_MainWindow.hxx>
#include <FrgMarine_Tree.hxx>
#include <FrgBase_ProgressBar.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_TabWidget.hxx>

#include <FrgMarine_Serialization_Global.hxx>
#include <FrgBase_Global_Thread.hxx>

#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>

#include <iostream>
#include <fstream>
#include <filesystem>

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

	SetWindowTitle("Tonb");
	ProgramModifiedSlot(false);
}

void ForgMarineLib::FrgMarine_MainWindow::FileLoadActionSlot()
{
	if (theProgramIsModified_)
	{
		auto myMessageOutput = QMessageBox::information(this, "Save project?", "This project is not saved. Do you want to save your project?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

		if (myMessageOutput == QMessageBox::Yes)
		{
			FileSaveActionSlot();
			return;
		}
		else if (myMessageOutput == QMessageBox::Cancel)
			return;
	}

	QString* ext;
	QString fileName = QFileDialog::getOpenFileName(this, "Load File", "", "Tonb (*.tnb)");

	if (fileName.isEmpty())
		return;


	std::ifstream myFile;
	//myFile.open(fileName.toStdString(), std::ios::binary);
	myFile.open(fileName.toStdString());

	if (!myFile.is_open())
	{
		PrintInfoToConsole("\"" + fileName + "\" cannot open!");
		return;
	}

	FrgMarine_Tree* myTree;

	{
		//boost::archive::polymorphic_binary_iarchive ia(myFile);
		boost::archive::polymorphic_text_iarchive ia(myFile);
		ia >> myTree;
	}

	myFile.close();

	delete theTree_;
	theTree_ = myTree;
	theTree_->SetParentMainWindow(this);

	theTreeDockWidget_->setWidget(theTree_);

	ProgramModifiedSlot(false);

	PrintInfoToConsole("The project was successfully loaded from \"" + fileName + "\".");
}

void ForgMarineLib::FrgMarine_MainWindow::FileSaveActionSlot()
{
	if (!theProgramIsModified_)
		return;

	QString* ext;
	QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Tonb (*.tnb)");

	if (fileName.isEmpty())
		return;

	bool exist = std::filesystem::exists(fileName.toStdString().c_str());
	if (exist)
	{
		QString bakFileName = fileName + "bak";

		bool existBak = std::filesystem::exists(bakFileName.toStdString().c_str());
		if (existBak)
			std::remove(bakFileName.toStdString().c_str());

		std::rename(fileName.toStdString().c_str(), bakFileName.toStdString().c_str());
	}

	std::ofstream myFile;
	//myFile.open(fileName.toStdString(), std::ios::binary);
	myFile.open(fileName.toStdString());
	
	{
		//boost::archive::polymorphic_binary_oarchive oa(myFile);
		boost::archive::polymorphic_text_oarchive oa(myFile);
		auto myTree = dynamic_cast<FrgMarine_Tree*>(theTree_);
		oa << myTree;
	}

	myFile.close();

	ProgramModifiedSlot(false);

	PrintInfoToConsole("The project was successfully saved in \"" + fileName + "\".");
}