#pragma once
#ifndef _FrgBase_MainWindow_Header
#define _FrgBase_MainWindow_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Object.hxx>

#include <QtWidgets/QMainWindow>

class QDockWidget;
class QLabel;
class ContainerWidget;
class SectionWidget;

namespace chaiscript
{
	class ChaiScript;
}

BeginForgBaseLib

class FrgBase_Menu;
class FrgBase_Tree;
class FrgBase_ProgressBar;
class FrgBase_PropertiesPanel;
class FrgBase_TabWidget;
class FrgBase_FramelessWindow;
class FrgBase_MainStyle;

class FORGBASE_EXPORT FrgBase_MainWindow
	: public QMainWindow
	, public FrgBase_Object
{

	Q_OBJECT

protected:

	struct MainWindowMenus_Struct
	{
		FrgBase_Menu* theFileMenu_ = nullptr;
		FrgBase_Menu* theEditMenu_ = nullptr;
		FrgBase_Menu* theToolsMenu_ = nullptr;
		FrgBase_Menu* theWindowMenu_ = nullptr;
		FrgBase_Menu* theHelpMenu_ = nullptr;

		~MainWindowMenus_Struct();
	};

	MainWindowMenus_Struct* theMainWindowMenus_ = nullptr;
	FrgBase_Tree* theTree_ = nullptr;
	FrgBase_ProgressBar* theProgressBar_ = nullptr;
	FrgBase_PropertiesPanel* thePropertiesPanel_ = nullptr;

	QTabWidget* theTabWidgetForTrees_ = nullptr;

	QDockWidget* theTreeDockWidget_ = nullptr;
	QDockWidget* thePropertiesPanelDockWidget_ = nullptr;
	QDockWidget* theConsoleOutputDockWidget_ = nullptr;

	ContainerWidget* theCentralContainer_ = nullptr;
	mutable SectionWidget* theCentralSectionWidget_ = nullptr;

	std::map<QWidget*, FrgBase_TabWidget*> theMapWidgetToTabWidget_;

	FrgString theConsoleEngineName_;

	//FrgBase_TabWidget* theTabWidget_ = NullPtr;

	QString theWindowTitle_;
	//bool theProgramIsModified_ = false;

	QString theProjectExtension_;

	std::shared_ptr<chaiscript::ChaiScript> theChaiScript_;

	FrgBase_FramelessWindow* theFrameLessWindow_ = nullptr;
	bool theIsThemeDark_;

	QApplication* theQApplication_ = nullptr;

	QLabel* theCPUUsageLabel_ = nullptr;
	QLabel* theRAMUsageLabel_ = nullptr;

	FrgBase_MainStyle* theMainStyle_ = nullptr;

protected:

	virtual void InitMainWindow();
	virtual void InitTree();
	virtual void InitProgressBar();
	virtual void InitConsoleOutput();

	virtual void FormMenus();

	virtual void CorrectConsoleOutput();

public:

	FrgBase_MainWindow(QWidget* parent = nullptr);

	~FrgBase_MainWindow();

	FrgBase_ProgressBar* GetProgressBar() const { return theProgressBar_; }

	FrgBase_PropertiesPanel* GetPropertiesPanel() const { return thePropertiesPanel_; }
	void SetPropertiesPanel(FrgBase_PropertiesPanel* propertiesPanel);

	//FrgBase_TabWidget* GetTabWidget() const { return theTabWidget_; }

	auto GetMenus() const { return theMainWindowMenus_; }

	bool IsThemeDark() const { return theIsThemeDark_; }

	void ShowTabWidget(QWidget* widget, const QString& title);
	void RemoveTabWidget(QWidget* widget);

	bool IsTabWidgetVisible(QWidget* widget) const;

	void SetTabText(QWidget* widget, const QString& title);
	void SetTabText(int index, const QString& title) const;
	FrgBase_Tree* GetTree() const { return theTree_; }

	// Add tree to list of trees (if tree = nullptr) a new tree will be created and returned
	QWidget* AddTree(QWidget* tree, const QString& title);
	void RemoveTree(QWidget* tree);
	QTabWidget* GetTabWidgetForTrees() const { return theTabWidgetForTrees_; }

	void SetWindowTitle(QString title);
	QString GetWindowTitle() const;

	void SetGeometry(int PercentageOfScreen);

	auto& GetChaiScriptRef() { return theChaiScript_; }
	const auto& GetChaiScript() const { return theChaiScript_; }
	void SetChaiScript(const std::shared_ptr<chaiscript::ChaiScript>& chaiScript) { theChaiScript_ = chaiScript; }

	virtual void Show(bool darkTheme = false);

	virtual void SetThemeDark(bool condition = true);

	void SetQApplication(QApplication* qapplication) { theQApplication_ = qapplication; }
	QApplication* GetQApplication() const { return theQApplication_; }

	FrgBase_FramelessWindow* GetFramelessWindow() const { return theFrameLessWindow_; }

Q_SIGNALS:

	void PrintInfoToConsole(const QString& info);
	void PrintWarningToConsole(const QString& info);
	void PrintErrorToConsole(const QString& info);

	void ThemeModeChangedSignal(bool darkMode);

	void TabWidgetClosedSignal(QWidget*);

	void TabWidgetActivated(QWidget* w, bool isActive);

protected slots:

	/*=========================*/
	/* Menu File Actions Slots */
	/*=========================*/
	virtual void FileNewActionSlot() {}
	virtual void FileLoadActionSlot();
	virtual void FileSaveActionSlot();
	virtual void FileSaveAsActionSlot() {}
	virtual void FileImportActionSlot() {}
	virtual void FileExportActionSlot() {}
	virtual void FileExitActionSlot() {}

	void UpdateCPUUsageSlot();
	void UpdateRAMUsageSlot();

	void PrintInfoToConsoleSlot(const QString& info);
	void PrintWarningToConsoleSlot(const QString& info);
	void PrintErrorToConsoleSlot(const QString& info);

public slots:

	//void ProgramModifiedSlot(bool condition);
};

EndForgBaseLib

#endif // !_FrgBase_MainWindow_Header
