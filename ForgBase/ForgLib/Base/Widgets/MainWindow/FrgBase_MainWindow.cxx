#include <FrgBase_MainWindow.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_MenuFile.hxx>
#include <FrgBase_MenuEdit.hxx>
#include <FrgBase_MenuWindow.hxx>
#include <FrgBase_MenuHelp.hxx>
#include <FrgBase_Tree.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_TabWidget.hxx>
#include <FrgBase_MainStyle.hxx>
#include <FrgBase_FramelessWindow.hxx>
#include <FrgBase_ProgressBar.hxx>
#include <FrgBase_Application.hxx>

#include <FrgBase_Serialization_Global.hxx>

#include <QtilitiesLogging/QtilitiesLogging>
#include <QtilitiesLogging/Qtilities>
#include <QtilitiesCore/QtilitiesCore>
#include <QtilitiesCoreGui/QtilitiesCoreGui>
#include <QtilitiesCoreGui/QtilitiesApplication>

#include <fstream>

#include <chaiscript.hpp>

#include "ads/API.h"
#include "ads/ContainerWidget.h"
#include "ads/SectionContent.h"
#include "ads/SectionWidget.h"
#include "ads/iconTitleWidget.h"

using namespace QtilitiesLogging;
using namespace Qtilities::CoreGui;

ForgBaseLib::FrgBase_MainWindow::FrgBase_MainWindow
(
	QWidget* parent
)
	: QMainWindow(parent)
{
	this->window()->setWindowIcon(QIcon(ICONLogo));

	//theTabWidget_ = new FrgBase_TabWidget(this);
	//this->setCentralWidget(theTabWidget_);

	SetWindowTitle("Forg Soft");

	theProjectExtension_ = "Forg (*.Forg)";

	theChaiScript_ = std::make_shared<chaiscript::ChaiScript>();

	connect(this, &FrgBase_MainWindow::PrintSuccessToConsole, this, &FrgBase_MainWindow::PrintSuccessToConsoleSlot, Qt::QueuedConnection);
	connect(this, &FrgBase_MainWindow::PrintInfoToConsole, this, &FrgBase_MainWindow::PrintInfoToConsoleSlot, Qt::QueuedConnection);
	connect(this, &FrgBase_MainWindow::PrintWarningToConsole, this, &FrgBase_MainWindow::PrintWarningToConsoleSlot, Qt::QueuedConnection);
	connect(this, &FrgBase_MainWindow::PrintErrorToConsole, this, &FrgBase_MainWindow::PrintErrorToConsoleSlot, Qt::QueuedConnection);

	if (!theFrameLessWindow_)
	{
		theFrameLessWindow_ = new FrgBase_FramelessWindow();
		theFrameLessWindow_->setWindowTitle(this->windowTitle());
		theFrameLessWindow_->window()->setWindowIcon(this->window()->windowIcon());
	}
	//theFrameLessWindow_->setContent(this);

	theIsThemeDark_ = true;
	theMainStyle_ = new FrgBase_MainStyle(theIsThemeDark_);

	QApplication::setStyle(theMainStyle_);
}

ForgBaseLib::FrgBase_MainWindow::~FrgBase_MainWindow()
{
	FreePointer(theTree_);
	FreePointer(theTreeDockWidget_);
	thePropertiesPanel_ = nullptr;
	FreePointer(thePropertiesPanelDockWidget_);
	//FreePointer(theTabWidget_);

	for (auto m : theMapWidgetToTabWidget_)
	{
		m.second->setParent(nullptr);
	}
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

	thePropertiesPanel_ = new FrgBase_PropertiesPanel(this, nullptr);

	theCentralContainer_= new ADS_NS::ContainerWidget();
	theCentralContainer_->layout()->setContentsMargins(0, 0, 0, 0);
	setCentralWidget(theCentralContainer_);

	QObject::connect(theCentralContainer_, &ContainerWidget::SectionContentClosed, [this](const SectionContent::RefPtr& sc)
		{
			auto func = [this, &sc]()
				{
					if (sc.isNull())
						return;

					QWidget* w = nullptr;

					for (const auto& m : theMapWidgetToTabWidget_)
					{

						if (m.second->GetSectionContent() == sc)
						{
							w = m.first;
							break;
						}
					}

					if (w)
					{
						RemoveTabWidget(w);
						emit TabWidgetClosedSignal(w);
					}
				};
			
			FrgBase_Application::CatchAndIgnore(func);
		}
	);

	QObject::connect(theCentralContainer_, &ContainerWidget::activeTabChanged, [this](const SectionContent::RefPtr& sc, bool isActive)
		{
			auto func = [this, &sc, &isActive]()
				{
					if (sc.isNull())
						return;

					QWidget* w = nullptr;

					for (const auto& m : theMapWidgetToTabWidget_)
					{

						if (m.second->GetSectionContent() == sc)
						{
							w = m.first;
							break;
						}
					}

					if (w)
						emit TabWidgetActivated(w, isActive);
				};

			FrgBase_Application::CatchAndIgnore(func);
		});

	thePropertiesPanelDockWidget_ = new QDockWidget("Properties", this);
	thePropertiesPanelDockWidget_->setWidget(thePropertiesPanel_);
	thePropertiesPanelDockWidget_->setTitleBarWidget(new QWidget);

	theTabWidgetForTrees_ = new QTabWidget();
	theTabWidgetForTrees_->setTabPosition(QTabWidget::South);
	theTabWidgetForTrees_->setTabsClosable(false);
	theTabWidgetForTrees_->tabBar()->hide();

	theTreeDockWidget_ = new QDockWidget("Trees", this);
	theTreeDockWidget_->setWidget(theTabWidgetForTrees_);
	theTreeDockWidget_->setTitleBarWidget(new QWidget);

	this->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, theTreeDockWidget_);
	this->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, thePropertiesPanelDockWidget_);

	InitTree();

	theTabWidgetForTrees_->addTab(theTree_, "Main Tree");

	InitProgressBar();

	InitConsoleOutput();
}

void ForgBaseLib::FrgBase_MainWindow::InitTree()
{
	theTree_ = new FrgBase_Tree(this);
	theTree_->FormTree();
}

static float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
	static unsigned long long _previousTotalTicks = 0;
	static unsigned long long _previousIdleTicks = 0;

	unsigned long long totalTicksSinceLastTime = totalTicks - _previousTotalTicks;
	unsigned long long idleTicksSinceLastTime = idleTicks - _previousIdleTicks;

	float ret = 1.0f - ((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime) / totalTicksSinceLastTime : 0);

	_previousTotalTicks = totalTicks;
	_previousIdleTicks = idleTicks;
	return ret;
}

static unsigned long long FileTimeToInt64(const FILETIME& ft) { return (((unsigned long long)(ft.dwHighDateTime)) << 32) | ((unsigned long long)ft.dwLowDateTime); }

// Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
// You'll need to call this at regular intervals, since it measures the load between
// the previous call and the current one.  Returns -1.0 on error.
float GetCPULoad()
{
	FILETIME idleTime, kernelTime, userTime;
	return GetSystemTimes(&idleTime, &kernelTime, &userTime) ? CalculateCPULoad(FileTimeToInt64(idleTime), FileTimeToInt64(kernelTime) + FileTimeToInt64(userTime)) : -1.0f;
}

#include "windows.h"
#include "psapi.h"

void ForgBaseLib::FrgBase_MainWindow::InitProgressBar()
{
	this->statusBar()->addWidget(new QWidget, 1);

	theCPUUsageLabel_ = new QLabel;
	theRAMUsageLabel_ = new QLabel;

	this->statusBar()->addWidget(theCPUUsageLabel_, 0);
	this->statusBar()->addWidget(theRAMUsageLabel_, 0);

	QTimer* timerForUpdatingCPUandRAMUsages = new QTimer;
	connect(timerForUpdatingCPUandRAMUsages, SIGNAL(timeout()), this, SLOT(UpdateCPUUsageSlot()));
	connect(timerForUpdatingCPUandRAMUsages, SIGNAL(timeout()), this, SLOT(UpdateRAMUsageSlot()));
	timerForUpdatingCPUandRAMUsages->start(1000);

	theProgressBar_ = new ForgBaseLib::FrgBase_ProgressBar(this);
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

	theMainWindowMenus_->theFileMenu_->SetToolBarHidden(false);
	theMainWindowMenus_->theEditMenu_->SetToolBarHidden(false);
	theMainWindowMenus_->theHelpMenu_->SetToolBarHidden(false);

	const auto newaction = theMainWindowMenus_->theFileMenu_->GetNewAction();
	const auto saveAction = theMainWindowMenus_->theFileMenu_->GetSaveAction();
	const auto loadAction = theMainWindowMenus_->theFileMenu_->GetLoadAction();
	const auto saveAsAction = theMainWindowMenus_->theFileMenu_->GetSaveAsAction();
	const auto importAction = theMainWindowMenus_->theFileMenu_->GetImportAction();
	const auto exportAction = theMainWindowMenus_->theFileMenu_->GetExportAction();
	const auto exitAction = theMainWindowMenus_->theFileMenu_->GetExitAction();

	saveAction->setEnabled(true);

	connect(newaction, SIGNAL(triggered()), this, SLOT(FileNewActionSlot()));
	connect(saveAction, SIGNAL(triggered()), this, SLOT(FileSaveActionSlot()));
	connect(loadAction, SIGNAL(triggered()), this, SLOT(FileLoadActionSlot()));
	connect(saveAsAction, SIGNAL(triggered()), this, SLOT(FileSaveAsActionSlot()));
	connect(importAction, SIGNAL(triggered()), this, SLOT(FileImportActionSlot()));
	connect(exportAction, SIGNAL(triggered()), this, SLOT(FileExportActionSlot()));
	connect(exitAction, SIGNAL(triggered()), this, SLOT(FileExitActionSlot()));
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

	const auto& engine = dynamic_cast<WidgetLoggerEngine*>(Log->loggerEngineReference(theConsoleEngineName_));
	const auto editor = engine->plainTextEdit(WidgetLoggerEngine::AllMessagesPlainTextEdit);
	editor->setMaximumBlockCount(0);
}

void ForgBaseLib::FrgBase_MainWindow::CorrectConsoleOutput()
{
	const auto& engine = dynamic_cast<WidgetLoggerEngine*>(Log->loggerEngineReference(theConsoleEngineName_));
	const auto editor = engine->plainTextEdit(WidgetLoggerEngine::AllMessagesPlainTextEdit);

	const auto text = editor->toPlainText();
	editor->setPlainText(text);
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

void ForgBaseLib::FrgBase_MainWindow::PrintSuccessToConsoleSlot
(
	const QString& success
)
{
	if (theConsoleSilent_)
		return;

	const auto& engine = dynamic_cast<WidgetLoggerEngine*>(Log->loggerEngineReference(theConsoleEngineName_));
	QPlainTextEdit* editor = engine->plainTextEdit(WidgetLoggerEngine::AllMessagesPlainTextEdit);

	QString message = "<a style=\"color:rgb(0, 153, 51);white-space:pre\">" + (QTime::currentTime().toString() + " [Success]  " + success).toHtmlEscaped() + "</a>";
	editor->appendHtml(message);
}

void ForgBaseLib::FrgBase_MainWindow::PrintInfoToConsoleSlot(const QString& info)
{
	if (theConsoleSilent_)
		return;

	const auto& engine = dynamic_cast<WidgetLoggerEngine*>(Log->loggerEngineReference(theConsoleEngineName_));
	QPlainTextEdit* editor = engine->plainTextEdit(WidgetLoggerEngine::AllMessagesPlainTextEdit);

	QString color = theIsThemeDark_ ? "white" : "black";
	QString message = "<a style=\"color:" + color + ";white-space:pre\">" + (QTime::currentTime().toString() + " [Info   ]  " + info).toHtmlEscaped() + "</a>";
	editor->appendHtml(message);
	
	//LOG_INFO_E(theConsoleEngineName_, info);
	//CorrectConsoleOutput();
}

void ForgBaseLib::FrgBase_MainWindow::PrintWarningToConsoleSlot(const QString& warning)
{
	if (theConsoleSilent_)
		return;

	const auto& engine = dynamic_cast<WidgetLoggerEngine*>(Log->loggerEngineReference(theConsoleEngineName_));
	QPlainTextEdit* editor = engine->plainTextEdit(WidgetLoggerEngine::AllMessagesPlainTextEdit);
	QPlainTextEdit* editor2 = engine->plainTextEdit(WidgetLoggerEngine::WarningsPlainTextEdit);

	QString message = "<a style=\"color:rgb(240, 137, 48);white-space:pre\">" + (QTime::currentTime().toString() + " [Warning]  " + warning).toHtmlEscaped() + "</a>";
	editor->appendHtml(message);
	editor2->appendHtml(message);

	/*LOG_WARNING_E(theConsoleEngineName_, warning);
	CorrectConsoleOutput();*/
}

void ForgBaseLib::FrgBase_MainWindow::PrintErrorToConsoleSlot(const QString& error)
{
	if (theConsoleSilent_)
		return;

	const auto& engine = dynamic_cast<WidgetLoggerEngine*>(Log->loggerEngineReference(theConsoleEngineName_));
	QPlainTextEdit* editor = engine->plainTextEdit(WidgetLoggerEngine::AllMessagesPlainTextEdit);
	QPlainTextEdit* editor2 = engine->plainTextEdit(WidgetLoggerEngine::ErrorsPlainTextEdit);

	QString message = "<a style=\"color:rgb(255, 0, 0);white-space:pre\">" + (QTime::currentTime().toString() + " [Error  ]  " + error).toHtmlEscaped() + "</a>";
	editor->appendHtml(message);
	editor2->appendHtml(message);

	/*LOG_ERROR_E(theConsoleEngineName_, error);
	CorrectConsoleOutput();*/
}

void ForgBaseLib::FrgBase_MainWindow::SetPropertiesPanel(FrgBase_PropertiesPanel* propertiesPanel)
{
	thePropertiesPanel_ = propertiesPanel;

	thePropertiesPanelDockWidget_->setWidget(thePropertiesPanel_);
}

void ForgBaseLib::FrgBase_MainWindow::ShowTabWidget(QWidget* widget, const QString& title)
{
	if (!theCentralContainer_)
		return;

	auto myContents = theCentralContainer_->contents();

	auto iter = theMapWidgetToTabWidget_.find(widget);
	if (iter != theMapWidgetToTabWidget_.end())
	{
		for (auto myContent : myContents)
		{
			if (myContent.data()->contentWidget() == theMapWidgetToTabWidget_.at(widget))
			{
				if (theCentralContainer_->isSectionContentVisible(myContent))
					theCentralContainer_->raiseSectionContent(myContent);
				else
					theCentralContainer_->showSectionContent(myContent);

				myContent.data()->setTitle(title);

				auto myTitleWidget = dynamic_cast<IconTitleWidget*>(myContent.data()->titleWidget());
				if (myTitleWidget)
					myTitleWidget->setTitle(title);

				auto tabWidget = theMapWidgetToTabWidget_[widget];
				tabWidget->setTabText(tabWidget->indexOf(widget), title);

				return;
			}
		}
	}

	auto tabWidget = new FrgBase_TabWidget(this);
	theMapWidgetToTabWidget_[widget] = tabWidget;
	tabWidget->ShowTabWidget(widget, title);

	auto _sc1 = ADS_NS::SectionContent::newSectionContent
	(
		title + " " + QString::number(myContents.size()),
		theCentralContainer_,
		new IconTitleWidget(QIcon(), title, tabWidget),
		tabWidget
	);

	tabWidget->SetSectionContent(_sc1);

	theCentralSectionWidget_ = theCentralContainer_->addSectionContent(_sc1, theCentralSectionWidget_, ADS_NS::CenterDropArea);
	theCentralContainer_->raiseSectionContent(_sc1);

	//_sc1->setFlags(SectionContent::Flag::None);

	//theTabWidget_->ShowTabWidget(widget, title);
}

void ForgBaseLib::FrgBase_MainWindow::RemoveTabWidget(QWidget* widget)
{
	if (!theCentralContainer_ || !theCentralSectionWidget_)
		return;

	bool shouldSetCentralSectionWidgetToNull = false;

	auto iter = theMapWidgetToTabWidget_.find(widget);
	if (iter != theMapWidgetToTabWidget_.end())
	{

		auto myContents = theCentralContainer_->contents();
		for (const auto& myContent : myContents)
		{
			if (myContent.data()->contentWidget() == theMapWidgetToTabWidget_.at(widget))
			{
				const auto& sc = iter->second->GetSectionContent();

				if (myContent.data()->containerWidget()->GetSectionWidgetBySectionContent(sc) == theCentralSectionWidget_)
				{
					if (theCentralSectionWidget_->contents().size() == 1)
						shouldSetCentralSectionWidgetToNull = true;
				}

				theCentralContainer_->hideSectionContent(myContent);
				delete myContent.data();
				//theCentralContainer_->removeSectionContent(myContent);
				break;
			}
		}

		theMapWidgetToTabWidget_.erase(widget);
	}

	if (shouldSetCentralSectionWidgetToNull)
		theCentralSectionWidget_ = nullptr;
}

bool ForgBaseLib::FrgBase_MainWindow::IsTabWidgetVisible(QWidget* widget) const
{
	if (!widget)
		return false;

	if (!theCentralContainer_)
		return false;

	auto iter = theMapWidgetToTabWidget_.find(widget);
	if (iter != theMapWidgetToTabWidget_.end())
	{
		auto myContents = theCentralContainer_->contents();
		for (const auto& myContent : myContents)
		{
			if (myContent.data()->contentWidget() == theMapWidgetToTabWidget_.at(widget))
			{
				return theCentralContainer_->isSectionContentVisible(myContent);
			}
		}
	}

	return false;
}

void ForgBaseLib::FrgBase_MainWindow::SetTabText(QWidget* widget, const QString& title)
{
	if (!theCentralContainer_)
		return;

	auto myContents = theCentralContainer_->contents();

	auto iter = theMapWidgetToTabWidget_.find(widget);
	if (iter != theMapWidgetToTabWidget_.end())
	{
		for (auto myContent : myContents)
		{
			if (myContent.data()->contentWidget() == theMapWidgetToTabWidget_.at(widget))
			{
				myContent.data()->setTitle(title);

				auto myTitleWidget = dynamic_cast<IconTitleWidget*>(myContent.data()->titleWidget());
				if (myTitleWidget)
					myTitleWidget->setTitle(title);

				auto tabWidget = theMapWidgetToTabWidget_[widget];
				tabWidget->setTabText(tabWidget->indexOf(widget), title);

				return;
			}
		}
	}

	/*auto myContents = theCentralContainer_->contents();
	for (auto myContent : myContents)
	{
		if (myContent.data()->contentWidget() == widget)
		{
			myContent.data()->setTitle(title);
			return;
		}
	}*/
	/*int index = theTabWidget_->indexOf(widget);

	SetTabText(index, title);*/
}

void ForgBaseLib::FrgBase_MainWindow::SetTabText(int index, const QString& title) const
{
	//theTabWidget_->setTabText(index, title);
}

void ForgBaseLib::FrgBase_MainWindow::SetTree(FrgBase_Tree* tree, const bool deleteTree)
{
	if (!tree || (tree == theTree_))
		return;

	while(theTabWidgetForTrees_->count() > 0)
		theTabWidgetForTrees_->removeTab(0);

	if (deleteTree)
	{
		auto func = [this]()
		{
			delete theTree_;
		};

		FrgBase_Application::CatchAndIgnore(func);
	}

	theTree_ = tree;
	theTree_->SetParentMainWindow(this);

	theTabWidgetForTrees_->addTab(theTree_, "Main Tree");
}

bool ForgBaseLib::FrgBase_MainWindow::FileNewActionSlot()
{
	const auto myMessageOutput =
		QMessageBox::information
		(
			this,
			"Save project?",
			"Before creating a new project, do you want to save your project?",
			QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel
		);

	if (myMessageOutput == QMessageBox::Yes)
	{
		if(!FileSaveActionSlot())
			return false;
	}
	else if (myMessageOutput == QMessageBox::Cancel)
		return false;

	auto myTree = new FrgBase_Tree;
	myTree->FormTree();

	// this method will set the new tree, delete the old one, update tab widget and set parent main window
	SetTree(myTree);

	return true;
}

bool ForgBaseLib::FrgBase_MainWindow::FileLoadActionSlot()
{
	//if (theProgramIsModified_)
	{
		const auto myMessageOutput =
			QMessageBox::information
			(
				this,
				"Save project?",
				"Before loading a new project, do you want to save your project?",
				QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel
			);

		if (myMessageOutput == QMessageBox::Yes)
		{
			if(!FileSaveActionSlot())
				return false;
		}
		else if (myMessageOutput == QMessageBox::Cancel)
			return false;
	}

	QString* ext;
	const QString fileName = QFileDialog::getOpenFileName(this, "Load File", "", theProjectExtension_);

	if (fileName.isEmpty())
		return false;


	std::ifstream myFile(fileName.toStdString());

	if (!myFile.is_open())
	{
		PrintErrorToConsole("Cannot open the file. Maybe it is in used by another application.");
		return false;
	}

	boost::archive::polymorphic_text_iarchive ia(myFile);

	FrgBase_Tree* myTree;

	try
	{
		ia >> myTree;
	}
	catch (const std::exception& myException)
	{
		this->PrintErrorToConsole("Cannot load because of \"" + QString(myException.what()) + "\"");
		myFile.close();
		return false;
	}

	myFile.close();

	// this method will set the new tree, delete the old one, update tab widget and set parent main window
	SetTree(myTree);

	//ProgramModifiedSlot(false);

	PrintSuccessToConsole("The project was successfully loaded from \"" + fileName + "\".");

	return true;
}

bool ForgBaseLib::FrgBase_MainWindow::FileSaveActionSlot()
{
	/*if (!theProgramIsModified_)
		return;*/

	QString* ext;
	const QString fileName = QFileDialog::getSaveFileName
	(
		this,
		"Save File",
		"",
		theProjectExtension_
	);

	if (fileName.isEmpty())
		return false;

	std::ofstream myFile(fileName.toStdString());

	if (!myFile.is_open())
	{
		PrintErrorToConsole("Cannot open the file. Maybe it is in used by another application.");
		return false;
	}

	boost::archive::polymorphic_text_oarchive oa(myFile);

	auto loadFunc = [this, &oa]()
	{
		oa << theTree_;
	};

	try
	{
		FrgBase_Application::CatchAndThrowStdException(loadFunc);
	}
	catch (const std::exception& ex)
	{
		myFile.close();
		throw ex;
	}

	myFile.close();

	//ProgramModifiedSlot(false);

	PrintSuccessToConsole("The project was successfully saved in \"" + fileName + "\".");

	return true;
}

//void ForgBaseLib::FrgBase_MainWindow::ProgramModifiedSlot(bool condition)
//{
//	if (theProgramIsModified_ == condition)
//		return;
//
//	theProgramIsModified_ = condition;
//
//	theMainWindowMenus_->theFileMenu_->GetItem("&Save")->setEnabled(condition);
//
//	if (theProgramIsModified_)
//		this->setWindowTitle(theWindowTitle_ + " *");
//	else
//		this->setWindowTitle(theWindowTitle_);
//}

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

	/*if (!theFrameLessWindow_)
	{
		theFrameLessWindow_ = new FrgBase_FramelessWindow();
		theFrameLessWindow_->setWindowTitle(this->windowTitle());
	}
	theFrameLessWindow_->setContent(this);*/

	//theFrameLessWindow_->show();
	this->show();
}

void ForgBaseLib::FrgBase_MainWindow::SetThemeDark(bool condition)
{
	if (theIsThemeDark_ == condition)
		return;

	theIsThemeDark_ = condition;
	theMainStyle_->SetThemeDark(theIsThemeDark_);

	const auto& engine = dynamic_cast<WidgetLoggerEngine*>(Log->loggerEngineReference(theConsoleEngineName_));
	QPlainTextEdit* editor = engine->plainTextEdit(WidgetLoggerEngine::AllMessagesPlainTextEdit);

	auto myText = editor->toPlainText();
	QTextStream ssIn(&myText);
	QString ssOut;
	QString line;
	QString color;

	while (ssIn.readLineInto(&line))
	{
		if (line.contains("[Success"))
			color = "rgb(0, 153, 51)";
		else if (line.contains("[Info"))
			color = theIsThemeDark_ ? "white" : "black";
		else if (line.contains("[Warning"))
			color = "rgb(240, 137, 48)";
		else if (line.contains("[Error"))
			color = "rgb(255, 0, 0)";
		else
			color = theIsThemeDark_ ? "white" : "black";
		ssOut += "<a style=\"color:" + color + ";white-space:pre\">" + line.toHtmlEscaped() + "</a><br>";
	}
	//Set the device to pos 0
	ssIn.seek(0);

	editor->clear();
	editor->appendHtml(ssOut);

	//emit ThemeModeChangedSignal(condition);

	if (theTree_)
		theTree_->SetThemeDark(theIsThemeDark_);
}

void ForgBaseLib::FrgBase_MainWindow::UpdateCPUUsageSlot()
{
	auto cpuUsage = GetCPULoad();
	theCPUUsageLabel_->setText("CPU Usage: " + QString::number(static_cast<int>(cpuUsage * 100)) + " %");
}

void ForgBaseLib::FrgBase_MainWindow::UpdateRAMUsageSlot()
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	float physMemUsedByMe = static_cast<float>(pmc.WorkingSetSize) / 1024.0 / 1024.0;
	bool isGB = false;
	if (physMemUsedByMe >= 1024)
	{
		physMemUsedByMe /= 1024;
		isGB = true;
	}
	theRAMUsageLabel_->setText("RAM Usage: " + QString::number(physMemUsedByMe, 'f', 2) + (isGB ? " GB" : " MB"));
}

QWidget* ForgBaseLib::FrgBase_MainWindow::AddTree(QWidget* tree, const QString& title)
{
	QWidget* myTree = tree;
	if (!myTree)
	{
		myTree = new FrgBase_Tree(this);
		dynamic_cast<FrgBase_Tree*>(myTree)->FormTree();
	}

	int index = theTabWidgetForTrees_->addTab(myTree, "Tree " + title);
	theTabWidgetForTrees_->setCurrentIndex(index);

	return myTree;
}

void ForgBaseLib::FrgBase_MainWindow::RemoveTree(QWidget* tree)
{
	if (!tree)
		return;

	if (tree == theTree_)
		return;

	theTabWidgetForTrees_->removeTab(theTabWidgetForTrees_->indexOf(tree));
}