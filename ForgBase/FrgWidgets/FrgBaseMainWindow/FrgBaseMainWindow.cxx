#include <FrgBaseMainWindow.hxx>
#include <FrgBaseTree.hxx>
#include <FrgBaseTreeItem.hxx>
#include <FrgBaseMenuFile.hxx>
#include <FrgBaseDlgNewSim.hxx>
#include <FrgBaseDlgLoadSim.hxx>
#include <FrgBaseTreeItemProperty.hxx>
#include <FrgBaseSceneTreeItem.hxx>

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

ForgBaseLib::FrgBaseMainWindow::FrgBaseMainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	this->window()->setWindowIcon(QIcon(":/Icons/Forg Logo.png"));

	//theMenus_ = FrgMakeSharedPtr(FrgMenus)(this);
	theFileMenu_ = FrgMakeSharedPtr(FrgBaseMenuFile)(this);

	this->setCentralWidget(FrgNew QWidget);

	CreateConsoleOutput();

	SetMainWindowStyleSheet();

	InitFrgMainWindow();

	for (FrgInt i = 0; i < 200; i++)
	{
		theDoubles_.push_back(sin(i));
	}
}

void ForgBaseLib::FrgBaseMainWindow::FileNewActionSlot()
{
	FrgSharedPtr<FrgBaseDlgNewSim> dlg = FrgMakeSharedPtr(FrgBaseDlgNewSim)(this);

	if (dlg->exec() == QDialog::Accepted)
	{
		ParseInfoToConsole("New was clicked!");

		theFileMenu_->SetEnabledItem("Save", FrgTrue);
		theFileMenu_->SetEnabledItem("Save As...", FrgTrue);

		CreateTree();
		CreateProperties();

		FrgBaseSceneTreeItem sc1("scene1", theTreeWidget_->theTree_->GetItems().at(0), theTreeWidget_->theTree_, this);
	}
}

void ForgBaseLib::FrgBaseMainWindow::FileLoadActionSlot()
{
	FrgSharedPtr<FrgBaseDlgLoadSim> dlg = FrgMakeSharedPtr(FrgBaseDlgLoadSim)(this);

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

void ForgBaseLib::FrgBaseMainWindow::FileSaveActionSlot()
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

void ForgBaseLib::FrgBaseMainWindow::FileSaveAsActionSlot()
{
	ParseInfoToConsole("Save As... was clicked!");
}

void ForgBaseLib::FrgBaseMainWindow::FileSaveAllActionSlot()
{
	ParseInfoToConsole("SaveAll was clicked!");
}

void ForgBaseLib::FrgBaseMainWindow::FileImportActionSlot()
{
	ParseInfoToConsole("Import was clicked!");
}

void ForgBaseLib::FrgBaseMainWindow::FileExportActionSlot()
{
	ParseInfoToConsole("Export was clicked!");
}

void ForgBaseLib::FrgBaseMainWindow::FileExitActionSlot()
{
	ParseInfoToConsole("Exit was clicked!");
}

void ForgBaseLib::FrgBaseMainWindow::CreateConsoleOutput()
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

void ForgBaseLib::FrgBaseMainWindow::ParseInfoToConsole(const FrgString& info)
{
	LOG_INFO_E(theConsoleWidget_->theEngineName_, info);
}

void ForgBaseLib::FrgBaseMainWindow::ParseWarningToConsole(const FrgString& info)
{
	LOG_WARNING_E(theConsoleWidget_->theEngineName_, info);
}

void ForgBaseLib::FrgBaseMainWindow::ParseErrorToConsole(const FrgString& info)
{
	LOG_ERROR_E(theConsoleWidget_->theEngineName_, info);
}

void ForgBaseLib::FrgBaseMainWindow::SetMainWindowStyleSheet()
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

void ForgBaseLib::FrgBaseMainWindow::AddMainWindowStyleSheet(const FrgString& styleSheet)
{
	FrgString str = this->styleSheet();

	str += styleSheet;

	this->setStyleSheet(str);
}

void ForgBaseLib::FrgBaseMainWindow::CreateTree()
{
	theTreeWidget_->theTree_ = FrgNew FrgBaseTree(this);
	theTreeWidget_->theTree_->FormTree();
	theTreeWidget_->theDockWidget_->setWidget(theTreeWidget_->theTree_);
}

void ForgBaseLib::FrgBaseMainWindow::CreateProperties()
{
	thePropertyWidget_->theProperty_ = theTreeWidget_->theTree_->GetItems().at(0)->GetProperty()->GetPropertyBrowser();
	thePropertyWidget_->theDockWidget_->setWidget(thePropertyWidget_->theProperty_);
}

void ForgBaseLib::FrgBaseMainWindow::InitFrgMainWindow()
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