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

	SetWindowTitle("Tonb");
	ProgramModifiedSlot(false);

	this->theProjectExtension_ = "Tonb (*.tnb)";
}

void ForgMarineLib::FrgMarine_MainWindow::InitTree()
{
	theTree_ = new FrgMarine_Tree(this);
	theTree_->FormTree();
}