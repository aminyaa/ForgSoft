#include <FrgMarine_MainWindow.hxx>
#include <FrgMarine_Tree.hxx>
#include <FrgBase_ProgressBar.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_TabWidget.hxx>

#include <FrgMarine_Serialization_Global.hxx>
#include <FrgBase_Global_Thread.hxx>
#include <FrgBase_Menu.hxx>

#include <FrgBase_Pnt.hxx>
#include <FrgVisual_Scene2D_TItem.hxx>
#include <FrgVisual_Scene.hxx>

#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QMenuBar>

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

void ForgMarineLib::FrgMarine_MainWindow::InitMainWindow()
{
	ForgBaseLib::FrgBase_MainWindow::InitMainWindow();

	ForgBaseLib::FrgBase_Menu* toolsMenu = new ForgBaseLib::FrgBase_Menu("Tools", this, false);
	toolsMenu->SetToolBarHidden(true);
	ForgBaseLib::FrgBase_Menu* themeMenu = new ForgBaseLib::FrgBase_Menu("Change Theme", this, false);
	themeMenu->SetToolBarHidden(true);
	auto defaultAction = themeMenu->AddItem("Default Mode", false);
	auto darkAction = themeMenu->AddItem("Dark Mode", false);

	auto* projectionModeGroup = new QActionGroup(this);
	projectionModeGroup->addAction(defaultAction);
	projectionModeGroup->addAction(darkAction);
	projectionModeGroup->setExclusive(true);
	defaultAction->setCheckable(true);
	darkAction->setCheckable(true);
	darkAction->setChecked(true);
	
	toolsMenu->addMenu(themeMenu);

	this->menuBar()->addMenu(toolsMenu);

	connect(defaultAction, &QAction::triggered, [this]() {this->SetThemeDark(false); });
	connect(darkAction, &QAction::triggered, [&]() {this->SetThemeDark(true); });
}

void ForgMarineLib::FrgMarine_MainWindow::InitTree()
{
	theTree_ = new FrgMarine_Tree(this);
	theTree_->FormTree();
}