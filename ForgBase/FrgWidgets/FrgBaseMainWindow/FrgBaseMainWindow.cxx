#include <FrgMainWindow.hxx>
#include <FrgTree.hxx>
#include <FrgTreeItem.hxx>
#include <FrgFileMenu.hxx>
#include <FrgDlgNewSim.hxx>
#include <FrgDlgLoadSim.hxx>

#include <QtWidgets/QDockWidget>
#include <QtWidgets/QMenu>

#include <QtilitiesLogging/QtilitiesLogging>
#include <QtilitiesLogging/Qtilities>
#include <QtilitiesCore/QtilitiesCore>
#include <QtilitiesCoreGui/QtilitiesCoreGui>
#include <QtilitiesCoreGui/QtilitiesApplication>
#include <QtilitiesCoreGui/WidgetLoggerEngine>

#include <qttreepropertybrowser.h>

#include <fstream>

using namespace QtilitiesLogging;
using namespace Qtilities::CoreGui;
//using namespace boost::archive;

ForgBaseLib::FrgMainWindow::FrgMainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	this->window()->setWindowIcon(QIcon(":/Icons/Forg Logo.png"));

	//theMenus_ = FrgMakeSharedPtr(FrgMenus)(this);
	theFileMenu_ = FrgMakeSharedPtr(FrgFileMenu)(this);

	this->setCentralWidget(FrgNew QWidget);

	CreateConsoleOutput();

	SetMainWindowStyleSheet();

	InitFrgMainWindow();

	for (FrgInt i = 0; i < 200; i++)
	{
		theDoubles_.push_back(sin(i));
	}
}

void ForgBaseLib::FrgMainWindow::FileNewActionSlot()
{
	FrgSharedPtr<FrgDlgNewSim> dlg = FrgMakeSharedPtr(FrgDlgNewSim)(this);

	if (dlg->exec() == QDialog::Accepted)
	{
		ParseInfoToConsole("New was clicked!");

		theFileMenu_->SetEnabledItem("Save", FrgTrue);
		theFileMenu_->SetEnabledItem("Save As...", FrgTrue);

		CreateTree();
		CreateProperties();
	}
}

void ForgBaseLib::FrgMainWindow::FileLoadActionSlot()
{
	FrgSharedPtr<FrgDlgLoadSim> dlg = FrgMakeSharedPtr(FrgDlgLoadSim)(this);

	if (dlg->exec() == QDialog::Accepted)
	{
		std::ifstream file;
		
		file.open(dlg->GetFileName().toStdString().c_str(), std::ios::binary);
		
		if (!file.is_open())
		{
			ParseErrorToConsole("\"" + dlg->GetFileName() + "\" not found!");
			return;
		}

		
		//binary_iarchive ia(file);
		//ia >> *this;
		
		file.close();

		ParseInfoToConsole("\"" + dlg->GetFileName() + "\" was loaded successfully.");
	}
}

void ForgBaseLib::FrgMainWindow::FileSaveActionSlot()
{
	/*FrgString fileName = QFileDialog::getSaveFileName(this, "Save current simulation", "",
		"Frg Files (*.Frg)");

	std::ofstream file;
	if (*theFileFormat_ == Frg_binary)
	{
		file.open(fileName.toStdString().c_str(), std::ios::binary);
		binary_oarchive oa(file);
		oa << *this;
	}
	else if (*theFileFormat_ == Frg_txt)
	{
		file.open(fileName.toStdString().c_str());
		text_oarchive oa(file);
		oa << *this;
	}
	file.close();

	ParseInfoToConsole("Simulation was saved successfully at \"" + fileName + "\"");*/
}

void ForgBaseLib::FrgMainWindow::FileSaveAsActionSlot()
{
	ParseInfoToConsole("Save As... was clicked!");
}

void ForgBaseLib::FrgMainWindow::FileSaveAllActionSlot()
{
	ParseInfoToConsole("SaveAll was clicked!");
}

void ForgBaseLib::FrgMainWindow::FileImportActionSlot()
{
	ParseInfoToConsole("Import was clicked!");
}

void ForgBaseLib::FrgMainWindow::FileExportActionSlot()
{
	ParseInfoToConsole("Export was clicked!");
}

void ForgBaseLib::FrgMainWindow::FileExitActionSlot()
{
	ParseInfoToConsole("Exit was clicked!");
}

void ForgBaseLib::FrgMainWindow::CreateConsoleOutput()
{
	Log->setLoggerSettingsEnabled(false);
	LOG_INITIALIZE();
	Log->setGlobalLogLevel(Logger::Fatal);
	Log->toggleQtMsgEngine(true);
	Log->toggleConsoleEngine(true);
	Log->toggleQtMsgEngine(false);

	theConsoleWidget_ = FrgMakeSharedPtr(ConsoleWidgetStruct)();

	theConsoleWidget_->theEngineName_ = "Output Dock Widget";
	FrgString xml_example = QCoreApplication::applicationDirPath() + "/XML_Log.xml";
	AbstractLoggerEngine* xml_file_engine = Log->newFileEngine("XML File", xml_example);

	theConsoleWidget_->theDockWidget_ = LoggerGui::createLogDockWidget
	(
		&theConsoleWidget_->theEngineName_,
		WidgetLoggerEngine::AllMessagesPlainTextEdit |
		WidgetLoggerEngine::WarningsPlainTextEdit |
		WidgetLoggerEngine::ErrorsPlainTextEdit,
		"",
		true,
		Logger::Info | Logger::Warning | Logger::Error
	);

	this->addDockWidget(Qt::BottomDockWidgetArea, theConsoleWidget_->theDockWidget_);
	this->setCorner(Qt::Corner::BottomLeftCorner, Qt::LeftDockWidgetArea);

	//LOG_FINALIZE();
}

void ForgBaseLib::FrgMainWindow::ParseInfoToConsole(const FrgString& info)
{
	LOG_INFO_E(theConsoleWidget_->theEngineName_, info);
}

void ForgBaseLib::FrgMainWindow::ParseWarningToConsole(const FrgString& info)
{
	LOG_WARNING_E(theConsoleWidget_->theEngineName_, info);
}

void ForgBaseLib::FrgMainWindow::ParseErrorToConsole(const FrgString& info)
{
	LOG_ERROR_E(theConsoleWidget_->theEngineName_, info);
}

void ForgBaseLib::FrgMainWindow::SetMainWindowStyleSheet()
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

void ForgBaseLib::FrgMainWindow::AddMainWindowStyleSheet(const FrgString& styleSheet)
{
	FrgString str = this->styleSheet();

	str += styleSheet;

	this->setStyleSheet(str);
}

void ForgBaseLib::FrgMainWindow::CreateTree()
{
	theTreeWidget_->theTree_ = FrgNew FrgTree(this);
	theTreeWidget_->theTree_->FormTree();
	theTreeWidget_->theDockWidget_->setWidget(theTreeWidget_->theTree_);
}

void ForgBaseLib::FrgMainWindow::CreateProperties()
{
	thePropertyWidget_->theProperty_ = theTreeWidget_->theTree_->GetItems().at(0)->GetProperty();
	thePropertyWidget_->theDockWidget_->setWidget(thePropertyWidget_->theProperty_);
}

void ForgBaseLib::FrgMainWindow::InitFrgMainWindow()
{
	theTreeWidget_ = FrgMakeSharedPtr(TreeWidgetStruct)();
	theTreeWidget_->theDockWidget_ = FrgNew QDockWidget("Simulation Tree", this);
	theTreeWidget_->theDockWidget_->setTitleBarWidget(FrgNew QWidget);

	this->addDockWidget(Qt::LeftDockWidgetArea, theTreeWidget_->theDockWidget_);

	thePropertyWidget_ = FrgMakeSharedPtr(PropertiesWidgetStruct)();
	thePropertyWidget_->theDockWidget_ = FrgNew QDockWidget("Properties Window", this);
	thePropertyWidget_->theDockWidget_->setTitleBarWidget(FrgNew QWidget);

	this->addDockWidget(Qt::LeftDockWidgetArea, thePropertyWidget_->theDockWidget_);

	theTreeWidget_->theDockWidget_->setMinimumWidth(200);
	thePropertyWidget_->theDockWidget_->setMinimumWidth(200);
}