#include <FrgBaseMainWindow.hxx>
#include <FrgBaseTree.hxx>
#include <FrgBaseTreeItem.hxx>
#include <FrgBaseMenuFile.hxx>
#include <FrgBaseDlgNewSim.hxx>
#include <FrgBaseDlgLoadSim.hxx>
#include <FrgBaseTreeItemProperties.hxx>
//#include <FrgBaseSceneTreeItem.hxx>
#include <FrgBaseTabWidget.hxx>

#include <QtWidgets/QDockWidget>
#include <QtWidgets/QMenu>

#include <QtilitiesLogging/QtilitiesLogging>
#include <QtilitiesLogging/Qtilities>
#include <QtilitiesCore/QtilitiesCore>
#include <QtilitiesCoreGui/QtilitiesCoreGui>
#include <QtilitiesCoreGui/QtilitiesApplication>
#include <QtilitiesCoreGui/WidgetLoggerEngine>

#include <fstream>

using namespace QtilitiesLogging;
using namespace Qtilities::CoreGui;
//using namespace boost::archive;

ForgBaseLib::FrgBaseMainWindow::FrgBaseMainWindow(QWidget* parent)
	: QMainWindow(parent)
{

	this->window()->setWindowIcon(QIcon(":/Icons/Forg Logo.png"));

	//theMenus_ = FrgMakeSharedPtr(FrgMenus)(this);
	theFileMenu_ = FrgNew FrgBaseMenuFile(this);

	this->setCentralWidget(FrgNew QWidget);

	CreateConsoleOutput();

	SetMainWindowStyleSheet();

	InitFrgMainWindow();

	FrgBaseMenu* EditMenu = new FrgBaseMenu("Edit", this);
	EditMenu->GetToolBar()->setHidden(true);
	FrgBaseMenu* ToolsMenu = new FrgBaseMenu("Tools", this);
	ToolsMenu->GetToolBar()->setHidden(true);
	FrgBaseMenu* ModelsMenu = new FrgBaseMenu("Models", this);
	ModelsMenu->GetToolBar()->setHidden(true);
	FrgBaseMenu* WindowMenu = new FrgBaseMenu("Window", this);
	WindowMenu->GetToolBar()->setHidden(true);
	FrgBaseMenu* HelpMenu = new FrgBaseMenu("Help", this);
	HelpMenu->GetToolBar()->setHidden(true);

	this->menuBar()->addMenu(EditMenu);
	this->menuBar()->addMenu(ToolsMenu);
	this->menuBar()->addMenu(ModelsMenu);
	this->menuBar()->addMenu(WindowMenu);
	this->menuBar()->addMenu(HelpMenu);

	QAction* copyAction = new QAction(QIcon(":/Icons/Menus/File/Copy.png"), "Copy");
	QAction* pasteAction = new QAction(QIcon(":/Icons/Menus/File/Paste.png"), "Paste");

	QAction* shipAction = new QAction(QIcon(":/Icons/Models/Ship.png"), "New Ship");
	QAction* propellerAction = new QAction(QIcon(":/Icons/Models/Propeller.png"), "New Propeller");
	QAction* ductAction = new QAction(QIcon(":/Icons/Models/Duct.png"), "New Duct");

	QAction* initializeSolutionAction = new QAction(QIcon(":/Icons/Menus/Solution/Initialize Solution.png"), "Initialize Solution");
	QAction* runAction = new QAction(QIcon(":/Icons/Menus/Solution/Run.png"), "Run");
	QAction* stepAction = new QAction(QIcon(":/Icons/Menus/Solution/Step.png"), "Step");
	QAction* stopAction = new QAction(QIcon(":/Icons/Menus/Solution/Stop.png"), "Stop");

	QAction* genSrfMeshAction = new QAction(QIcon(":/Icons/Menus/Mesh/Generate Surface Mesh.png"), "Generate Surface Mesh");
	QAction* genVlmMeshAction = new QAction(QIcon(":/Icons/Menus/Mesh/Generate Volume Mesh.png"), "Generate Volume Mesh");
	QAction* clcGenMeshAction = new QAction(QIcon(":/Icons/Menus/Mesh/Clear Generated Mesh.png"), "Clear Generated Mesh");
	QAction* initializeMeshAction = new QAction(QIcon(":/Icons/Menus/Mesh/Initialize Meshing.png"), "Initialize Meshing");

	QAction* CursorSceneAction = new QAction(QIcon(":/Icons/Menus/Scene/Cursor.png"), "Cursor");
	QAction* MoveSceneAction = new QAction(QIcon(":/Icons/Menus/Scene/Move.png"), "Move");
	QAction* RotateXSceneAction = new QAction(QIcon(":/Icons/Menus/Scene/RotateX.png"), "RotateX");
	QAction* RotateYSceneAction = new QAction(QIcon(":/Icons/Menus/Scene/RotateY.png"), "RotateY");
	QAction* RotateZSceneAction = new QAction(QIcon(":/Icons/Menus/Scene/RotateZ.png"), "RotateZ");
	QAction* RotateXYZSceneAction = new QAction(QIcon(":/Icons/Menus/Scene/RotateXYZ.png"), "RotateXYZ");

	QToolBar* EditToolbar = new QToolBar("Edit");
	EditToolbar->addAction(copyAction);
	EditToolbar->addAction(pasteAction);

	QToolBar* ModelsToolbar = new QToolBar("Models");
	ModelsToolbar->addAction(shipAction);
	ModelsToolbar->addAction(propellerAction);
	ModelsToolbar->addAction(ductAction);

	QToolBar* SolutionToolbar = new QToolBar("Solution");
	SolutionToolbar->addAction(initializeSolutionAction);
	SolutionToolbar->addAction(runAction);
	SolutionToolbar->addAction(stepAction);
	SolutionToolbar->addAction(stopAction);

	QToolBar* MeshToolbar = new QToolBar("Mesh");
	MeshToolbar->addAction(genSrfMeshAction);
	MeshToolbar->addAction(genVlmMeshAction);
	MeshToolbar->addAction(clcGenMeshAction);
	MeshToolbar->addAction(initializeMeshAction);

	QToolBar* SceneToolbar = new QToolBar("Scene");
	SceneToolbar->addAction(CursorSceneAction);
	SceneToolbar->addAction(MoveSceneAction);
	SceneToolbar->addAction(RotateXSceneAction);
	SceneToolbar->addAction(RotateYSceneAction);
	SceneToolbar->addAction(RotateZSceneAction);
	SceneToolbar->addAction(RotateXYZSceneAction);

	this->addToolBar(EditToolbar);
	this->addToolBar(ModelsToolbar);
	this->addToolBar(MeshToolbar);
	this->addToolBar(SolutionToolbar);
	this->addToolBar(SceneToolbar);
}

ForgBaseLib::FrgBaseMainWindow::~FrgBaseMainWindow()
{
	FreePointer(theTreeWidget_);
	FreePointer(theFileMenu_);
	FreePointer(theConsoleWidget_);
	FreePointer(thePropertyWidget_);
	FreePointer(theTabWidget_);
}

void ForgBaseLib::FrgBaseMainWindow::FileNewActionSlot()
{
	FrgSharedPtr<FrgBaseDlgNewSim> dlg = FrgMakeSharedPtr(FrgBaseDlgNewSim)(this);

	if (dlg->exec() == QDialog::Accepted)
	{
		theFileMenu_->SetEnabledItem("Save", FrgTrue);
		theFileMenu_->SetEnabledItem("Save As...", FrgTrue);

		CreateTree();
		theTreeWidget_->theTree_->FormTree();
		theTreeWidget_->theDockWidget_->setWidget(theTreeWidget_->theTree_);
		CreateProperties();

		//FrgBaseSceneTreeItem sc1("scene1", theTreeWidget_->theTree_->GetItems().at(0), theTreeWidget_->theTree_, this);
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

	theConsoleWidget_ = FrgNew ConsoleWidgetStruct();

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
}

void ForgBaseLib::FrgBaseMainWindow::CreateProperties()
{
	thePropertyWidget_->theProperty_ = theTreeWidget_->theTree_->GetItems().at(0)->GetProperties()->GetPropertyBrowser();
	thePropertyWidget_->theDockWidget_->setWidget(thePropertyWidget_->theProperty_);
}

void ForgBaseLib::FrgBaseMainWindow::InitFrgMainWindow()
{
	theTreeWidget_ = FrgNew TreeWidgetStruct();
	theTreeWidget_->theDockWidget_ = FrgNew QDockWidget("Simulation Tree", this);
	theTreeWidget_->theDockWidget_->setTitleBarWidget(FrgNew QWidget);

	this->addDockWidget(Qt::LeftDockWidgetArea, theTreeWidget_->theDockWidget_);

	thePropertyWidget_ = FrgNew PropertiesWidgetStruct();
	thePropertyWidget_->theDockWidget_ = FrgNew QDockWidget("Properties Window", this);
	thePropertyWidget_->theDockWidget_->setTitleBarWidget(FrgNew QWidget);

	this->addDockWidget(Qt::LeftDockWidgetArea, thePropertyWidget_->theDockWidget_);

	theTreeWidget_->theDockWidget_->setMinimumWidth(200);
	thePropertyWidget_->theDockWidget_->setMinimumWidth(200);

	theTabWidget_ = FrgNew FrgBaseTabWidget(this);
	this->setCentralWidget(theTabWidget_);
}