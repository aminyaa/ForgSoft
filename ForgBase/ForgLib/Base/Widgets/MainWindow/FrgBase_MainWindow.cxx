#include <FrgBase_MainWindow.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_MenuFile.hxx>
#include <FrgBase_MenuEdit.hxx>
#include <FrgBase_MenuTools.hxx>
#include <FrgBase_MenuWindow.hxx>
#include <FrgBase_MenuHelp.hxx>
#include <FrgBase_Tree.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_TabWidget.hxx>

#include <QtWidgets/QDockWidget>

#include <QtilitiesLogging/QtilitiesLogging>
#include <QtilitiesLogging/Qtilities>
#include <QtilitiesCore/QtilitiesCore>
#include <QtilitiesCoreGui/QtilitiesCoreGui>
#include <QtilitiesCoreGui/QtilitiesApplication>
#include <QtilitiesCoreGui/WidgetLoggerEngine>

using namespace QtilitiesLogging;
using namespace Qtilities::CoreGui;

ForgBaseLib::FrgBase_MainWindow::FrgBase_MainWindow
(
	QWidget* parent
)
	: QMainWindow(parent)
{
	this->window()->setWindowIcon(QIcon(ICONLogo));

	theTabWidget_ = new FrgBase_TabWidget(this);
	this->setCentralWidget(theTabWidget_);
}

ForgBaseLib::FrgBase_MainWindow::~FrgBase_MainWindow()
{
	FreePointer(theTree_);
	FreePointer(theTreeDockWidget_);
	thePropertiesPanel_ = NullPtr;
	FreePointer(thePropertiesPanelDockWidget_);
	FreePointer(theTabWidget_);
}

ForgBaseLib::FrgBase_MainWindow::MainWindowMenus_Struct::~MainWindowMenus_Struct()
{
	FreePointer(theFileMenu_);
	FreePointer(theEditMenu_);
	FreePointer(theToolsMenu_);
	FreePointer(theWindowMenu_);
	FreePointer(theHelpMenu_);
}

void ForgBaseLib::FrgBase_MainWindow::InitMainWindow()
{
	FormMenus();
	SetMainWindowStyleSheet();

	theTree_ = new FrgBase_Tree(this);
	thePropertiesPanel_ = new FrgBase_PropertiesPanel(this, nullptr);

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

void ForgBaseLib::FrgBase_MainWindow::FormMenus()
{
	theMainWindowMenus_ = new MainWindowMenus_Struct;

	theMainWindowMenus_->theFileMenu_ = new FrgBase_MenuFile(this);
	theMainWindowMenus_->theEditMenu_ = new FrgBase_MenuEdit(this);
	/*theMainWindowMenus_->theToolsMenu_ = new FrgBase_MenuTools;
	theMainWindowMenus_->theWindowMenu_ = new FrgBase_MenuWindow;*/
	theMainWindowMenus_->theHelpMenu_ = new FrgBase_MenuHelp(this);
}

void ForgBaseLib::FrgBase_MainWindow::SetMainWindowStyleSheet()
{
	FrgString seperatorStyle = "QMainWindow::separator {"
		"  height: 5px;"
		"  width:  5px;"
		"}"
		"QMainWindow::separator:hover{"
		"  background : #c2c2c2;"
		"}"
		"QMainWindow::separator:horizontal{"
		"  border-top: 1px solid #6b9cb8;"
		"  border-bottom: 1px solid #6b9cb8;"
		"}"
		"QMainWindow::separator:vertical{"
		"  border-left: 1px solid #6b9cb8;"
		"  border-right: 1px solid #6b9cb8;"
		"}";
	AddMainWindowStyleSheet(seperatorStyle);

	FrgString statusBarStyle = "QStatusBar {"
		"		border-top: 1px solid #6b9cb8;"
		"}";
	AddMainWindowStyleSheet(statusBarStyle);
}

void ForgBaseLib::FrgBase_MainWindow::AddMainWindowStyleSheet(const QString& styleSheet)
{
	QString str = this->styleSheet();
	str += styleSheet;
	this->setStyleSheet(str);
}

void ForgBaseLib::FrgBase_MainWindow::CreateConsoleOutput()
{
	Log->setLoggerSettingsEnabled(true);
	LOG_INITIALIZE();
	Log->setGlobalLogLevel(Logger::Fatal);
	Log->toggleQtMsgEngine(true);
	Log->toggleConsoleEngine(true);
	Log->toggleQtMsgEngine(false);

	theConsoleEngineName_ = "Console Output";

	auto consoleDockWidget = LoggerGui::createLogDockWidget
	(
		&theConsoleEngineName_,
		WidgetLoggerEngine::AllMessagesPlainTextEdit |
		WidgetLoggerEngine::WarningsPlainTextEdit |
		WidgetLoggerEngine::ErrorsPlainTextEdit,
		"",
		true,
		Logger::Info | Logger::Warning | Logger::Error
	);
	consoleDockWidget->setTitleBarWidget(new QWidget);

	this->addDockWidget(Qt::BottomDockWidgetArea, consoleDockWidget);
	this->setCorner(Qt::Corner::BottomLeftCorner, Qt::LeftDockWidgetArea);
}

void ForgBaseLib::FrgBase_MainWindow::PrintInfoToConsole(const FrgString & info)
{
	LOG_INFO_E(theConsoleEngineName_, info);
}

void ForgBaseLib::FrgBase_MainWindow::PrintWarningToConsole(const FrgString & warning)
{
	LOG_WARNING_E(theConsoleEngineName_, warning);
}

void ForgBaseLib::FrgBase_MainWindow::PrintErrorToConsole(const FrgString & error)
{
	LOG_ERROR_E(theConsoleEngineName_, error);
}

void ForgBaseLib::FrgBase_MainWindow::SetPropertiesPanel(FrgBase_PropertiesPanel * propertiesPanel)
{
	thePropertiesPanel_ = propertiesPanel;

	thePropertiesPanelDockWidget_->setWidget(thePropertiesPanel_);
}

void ForgBaseLib::FrgBase_MainWindow::ShowTabWidget(QWidget * widget, const QString& title)
{
	theTabWidget_->ShowTabWidget(widget, title);
}

void ForgBaseLib::FrgBase_MainWindow::SetTabText(QWidget * widget, const QString & title)
{
	int index = theTabWidget_->indexOf(widget);

	SetTabText(index, title);
}

void ForgBaseLib::FrgBase_MainWindow::SetTabText(int index, const QString & title)
{
	theTabWidget_->setTabText(index, title);
}