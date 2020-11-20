#include <FrgBase_MainWindow.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_MenuFile.hxx>
#include <FrgBase_MenuEdit.hxx>
#include <FrgBase_MenuWindow.hxx>
#include <FrgBase_MenuHelp.hxx>
#include <FrgBase_Tree.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_TabWidget.hxx>
#include <FrgBase_StylesDarkStyle.hxx>
#include <FrgBase_FramelessWindow.hxx>
#include <FrgBase_ProgressBar.hxx>

#include <FrgBase_Serialization_Global.hxx>

#include <QtilitiesLogging/QtilitiesLogging>
#include <QtilitiesLogging/Qtilities>
#include <QtilitiesCore/QtilitiesCore>
#include <QtilitiesCoreGui/QtilitiesCoreGui>
#include <QtilitiesCoreGui/QtilitiesApplication>

#include <fstream>

#include <chaiscript.hpp>

using namespace QtilitiesLogging;
using namespace Qtilities::CoreGui;

ForgBaseLib::FrgBase_MainWindow::FrgBase_MainWindow
(
	QWidget* parent
)
	: QMainWindow(parent)
{
	theDefaultStyle_ = QApplication::style();
	
	this->window()->setWindowIcon(QIcon(ICONLogo));

	theTabWidget_ = new FrgBase_TabWidget(this);
	this->setCentralWidget(theTabWidget_);

	SetWindowTitle("Forg Soft");

	theProjectExtension_ = "Forg (*.Forg)";

	theChaiScript_ = std::make_shared<chaiscript::ChaiScript>();
}

ForgBaseLib::FrgBase_MainWindow::~FrgBase_MainWindow()
{
	FreePointer(theTree_);
	FreePointer(theTreeDockWidget_);
	thePropertiesPanel_ = nullptr;
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

	InitTree();
	
	thePropertiesPanel_ = new FrgBase_PropertiesPanel(this, nullptr);

	theTreeDockWidget_ = new QDockWidget("Tree", this);
	theTreeDockWidget_->setWidget(theTree_);
	theTreeDockWidget_->setTitleBarWidget(new QWidget);
	this->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, theTreeDockWidget_);

	thePropertiesPanelDockWidget_ = new QDockWidget("Properties", this);
	thePropertiesPanelDockWidget_->setWidget(thePropertiesPanel_);
	thePropertiesPanelDockWidget_->setTitleBarWidget(new QWidget);
	this->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, thePropertiesPanelDockWidget_);

	InitProgressBar();

	InitConsoleOutput();
}

void ForgBaseLib::FrgBase_MainWindow::InitTree()
{
	theTree_ = new FrgBase_Tree(this);
	theTree_->FormTree();
}

void ForgBaseLib::FrgBase_MainWindow::InitProgressBar()
{
	theProgressBar_ = new ForgBaseLib::FrgBase_ProgressBar(this);

	this->statusBar()->addWidget(new QWidget, 1);
	this->statusBar()->addWidget(theProgressBar_, 0);
	this->statusBar()->adjustSize();
	this->statusBar()->setContentsMargins(0, 0, 0, 0);
}

void ForgBaseLib::FrgBase_MainWindow::FormMenus()
{
	theMainWindowMenus_ = new MainWindowMenus_Struct;

	theMainWindowMenus_->theFileMenu_ = new FrgBase_MenuFile(this);
	theMainWindowMenus_->theEditMenu_ = new FrgBase_MenuEdit(this);
	/*theMainWindowMenus_->theToolsMenu_ = new FrgBase_MenuTools;
	theMainWindowMenus_->theWindowMenu_ = new FrgBase_MenuWindow;*/
	theMainWindowMenus_->theHelpMenu_ = new FrgBase_MenuHelp(this);

	auto saveAction = theMainWindowMenus_->theFileMenu_->GetItem("&Save");
	const auto loadAction = theMainWindowMenus_->theFileMenu_->GetItem("&Load");
	saveAction->setEnabled(true);

	connect(saveAction, SIGNAL(triggered()), this, SLOT(FileSaveActionSlot()));
	connect(loadAction, SIGNAL(triggered()), this, SLOT(FileLoadActionSlot()));
}

void ForgBaseLib::FrgBase_MainWindow::InitConsoleOutput()
{
	Log->setLoggerSettingsEnabled(true);
	LOG_INITIALIZE();
	Log->setGlobalLogLevel(Logger::Fatal);
	Log->toggleQtMsgEngine(true);
	Log->toggleConsoleEngine(true);
	Log->toggleQtMsgEngine(false);

	theConsoleEngineName_ = "Console Output";

	theConsoleOutputDockWidget_ = LoggerGui::createLogDockWidget
	(
		&theConsoleEngineName_,
		WidgetLoggerEngine::AllMessagesPlainTextEdit |
		WidgetLoggerEngine::WarningsPlainTextEdit |
		WidgetLoggerEngine::ErrorsPlainTextEdit,
		"",
		true,
		Logger::Info | Logger::Warning | Logger::Error
	);
	theConsoleOutputDockWidget_->setTitleBarWidget(new QWidget);

	this->addDockWidget(Qt::BottomDockWidgetArea, theConsoleOutputDockWidget_);
	this->setCorner(Qt::Corner::BottomLeftCorner, Qt::LeftDockWidgetArea);
}

void ForgBaseLib::FrgBase_MainWindow::CorrectConsoleOutput()
{
	const auto& engine = dynamic_cast<WidgetLoggerEngine*>(Log->loggerEngineReference(theConsoleEngineName_));
	const auto editor = engine->plainTextEdit(WidgetLoggerEngine::AllMessagesPlainTextEdit);

	const auto text = editor->toPlainText();
	editor->setPlainText(text);

	editor->verticalScrollBar()->setValue(editor->verticalScrollBar()->maximum());
}

void ForgBaseLib::FrgBase_MainWindow::SetGeometry(int PercentageOfScreen)
{
	const QRect rect = QApplication::desktop()->screenGeometry();
	const int screen_width = rect.width();
	const int screen_height = rect.height();

	//Represent Percentage in decimals
	const float PercentageOfScreenFloat = static_cast<float>(PercentageOfScreen) / 100;

	//Calculate w and h
	int w = (PercentageOfScreenFloat * screen_width);
	int h = (PercentageOfScreenFloat * screen_height);

	//Check for max and min size hints
	const int minW = this->minimumWidth();
	const int minH = this->minimumHeight();

	const int maxW = this->maximumWidth();
	const int maxH = this->maximumHeight();

	if (w < minW || h < minH)
	{
		w = minW;
		h = minH;
	}
	else if (w > maxW || h > maxH)
	{
		w = maxW;
		h = maxH;
	}

	//Now Calculate x and y
	int x = screen_width / 2;
	x = x - w / 2;

	int y = screen_height / 2;
	y = y - h / 2;

	this->setGeometry(x, y, w, h);

	if (theFrameLessWindow_)
		theFrameLessWindow_->SetGeometry(PercentageOfScreen);
}

void ForgBaseLib::FrgBase_MainWindow::PrintInfoToConsole(const FrgString& info)
{
	LOG_INFO_E(theConsoleEngineName_, info);
	CorrectConsoleOutput();
}

void ForgBaseLib::FrgBase_MainWindow::PrintWarningToConsole(const FrgString& warning)
{
	LOG_WARNING_E(theConsoleEngineName_, warning);
	CorrectConsoleOutput();
}

void ForgBaseLib::FrgBase_MainWindow::PrintErrorToConsole(const FrgString& error)
{
	LOG_ERROR_E(theConsoleEngineName_, error);
	CorrectConsoleOutput();
}

void ForgBaseLib::FrgBase_MainWindow::SetPropertiesPanel(FrgBase_PropertiesPanel* propertiesPanel)
{
	thePropertiesPanel_ = propertiesPanel;

	thePropertiesPanelDockWidget_->setWidget(thePropertiesPanel_);
}

void ForgBaseLib::FrgBase_MainWindow::ShowTabWidget(QWidget* widget, const QString& title) const
{
	theTabWidget_->ShowTabWidget(widget, title);
}

void ForgBaseLib::FrgBase_MainWindow::SetTabText(QWidget* widget, const QString& title)
{
	int index = theTabWidget_->indexOf(widget);

	SetTabText(index, title);
}

void ForgBaseLib::FrgBase_MainWindow::SetTabText(int index, const QString& title) const
{
	theTabWidget_->setTabText(index, title);
}

void ForgBaseLib::FrgBase_MainWindow::FileLoadActionSlot()
{
	if (theProgramIsModified_)
	{
		const auto myMessageOutput = QMessageBox::information(this, "Save project?", "This project is not saved. Do you want to save your project?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

		if (myMessageOutput == QMessageBox::Yes)
		{
			FileSaveActionSlot();
			return;
		}
		else if (myMessageOutput == QMessageBox::Cancel)
			return;
	}

	QString* ext;
	const QString fileName = QFileDialog::getOpenFileName(this, "Load File", "", theProjectExtension_);

	if (fileName.isEmpty())
		return;


	std::ifstream myFile(fileName.toStdString());
	boost::archive::text_iarchive ia(myFile);

	FrgBase_Tree* myTree;

	try
	{
		ia >> myTree;
	}
	catch (const std::exception& myException)
	{
		this->PrintErrorToConsole("Cannot load because of \"" + QString(myException.what()) + "\"");
		myFile.close();
		return;
	}
	
	myFile.close();

	delete theTree_;
	theTree_ = myTree;
	theTree_->SetParentMainWindow(this);

	theTreeDockWidget_->setWidget(theTree_);

	ProgramModifiedSlot(false);

	PrintInfoToConsole("The project was successfully loaded from \"" + fileName + "\".");
}

void ForgBaseLib::FrgBase_MainWindow::FileSaveActionSlot()
{
	if (!theProgramIsModified_)
		return;

	QString* ext;
	const QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", theProjectExtension_);

	if (fileName.isEmpty())
		return;

	std::ofstream myFile(fileName.toStdString());
	boost::archive::polymorphic_text_oarchive oa(myFile);

	oa << theTree_;

	myFile.close();

	ProgramModifiedSlot(false);

	PrintInfoToConsole("The project was successfully saved in \"" + fileName + "\".");
}

void ForgBaseLib::FrgBase_MainWindow::ProgramModifiedSlot(bool condition)
{
	if (theProgramIsModified_ == condition)
		return;

	theProgramIsModified_ = condition;

	theMainWindowMenus_->theFileMenu_->GetItem("&Save")->setEnabled(condition);

	if (theProgramIsModified_)
		this->setWindowTitle(theWindowTitle_ + " *");
	else
		this->setWindowTitle(theWindowTitle_);
}

void ForgBaseLib::FrgBase_MainWindow::SetWindowTitle(QString title)
{
	this->setWindowTitle(title);
	theWindowTitle_ = title;

	if (theFrameLessWindow_)
		theFrameLessWindow_->setWindowTitle(title);
}

QString ForgBaseLib::FrgBase_MainWindow::GetWindowTitle() const
{
	return theWindowTitle_;
}

void ForgBaseLib::FrgBase_MainWindow::Show(bool darkTheme)
{
	SetThemeDark(darkTheme);
	
	if (!theFrameLessWindow_)
	{
		theFrameLessWindow_ = new FrgBase_FramelessWindow();
		theFrameLessWindow_->setWindowTitle(this->windowTitle());
	}
	theFrameLessWindow_->setContent(this);
	
	theFrameLessWindow_->show();
}

void ForgBaseLib::FrgBase_MainWindow::SetThemeDark(bool condition)
{
	theIsThemeDark_ = condition;
	if (theIsThemeDark_)
		QApplication::setStyle(new FrgBase_StylesDarkStyle);
	else
	{
		QApplication::setStyle(theDefaultStyle_);
		//QApplication::setStyle(QStyleFactory::create(QStringLiteral("Fusion")));

		QFile File(":/styles/Default/Default.qss");
		File.open(QFile::ReadOnly);
		const QString StyleSheet = QLatin1String(File.readAll());
		File.close();

		if (theQApplication_)
			theQApplication_->setStyleSheet(StyleSheet);
		else
			this->setStyleSheet(StyleSheet);
	}

	const auto& engine = dynamic_cast<WidgetLoggerEngine*>(Log->loggerEngineReference(theConsoleEngineName_));
	QPlainTextEdit* editor = nullptr;

	for (int i = 0; i < 3; i++)
	{
		if(i == 0)
			editor = engine->plainTextEdit(WidgetLoggerEngine::AllMessagesPlainTextEdit);
		else if (i == 1)
			editor = engine->plainTextEdit(WidgetLoggerEngine::WarningsPlainTextEdit);
		else
			editor = engine->plainTextEdit(WidgetLoggerEngine::ErrorsPlainTextEdit);
		
		if (theIsThemeDark_)
			editor->setStyleSheet("QPlainTextEdit {color : white;}");
		else
			editor->setStyleSheet("QPlainTextEdit {color : black;}");
	}
}