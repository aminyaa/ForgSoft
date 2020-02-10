#include <FrgMarine_MainWindow.hxx>
#include <FrgMarine_Tree.hxx>
#include <FrgBase_PropertiesPanel.hxx>

#include <QtWidgets/QDockWidget>

ForgMarineLib::FrgMarine_MainWindow::FrgMarine_MainWindow(QWidget* parent)
	: FrgBase_MainWindow(parent)
{
	InitMainWindow();
}

void ForgMarineLib::FrgMarine_MainWindow::InitMainWindow()
{
	FormMenus();
	SetMainWindowStyleSheet();

	theTree_ = new FrgMarine_Tree(this);
	thePropertiesPanel_ = new ForgBaseLib::FrgBase_PropertiesPanel(this, nullptr);

	theTreeDockWidget_ = new QDockWidget("Tree", this);
	theTreeDockWidget_->setWidget(theTree_);
	theTreeDockWidget_->setTitleBarWidget(new QWidget);
	this->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, theTreeDockWidget_);

	thePropertiesPanelDockWidget_ = new QDockWidget("Properties", this);
	thePropertiesPanelDockWidget_->setWidget(thePropertiesPanel_);
	thePropertiesPanelDockWidget_->setTitleBarWidget(new QWidget);
	this->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, thePropertiesPanelDockWidget_);

	CreateConsoleOutput();
}