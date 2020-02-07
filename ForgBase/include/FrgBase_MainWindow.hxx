#pragma once
#ifndef _FrgBase_MainWindow_Header
#define _FrgBase_MainWindow_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Object.hxx>

#include <QtWidgets/QMainWindow>

class QDockWidget;

BeginForgBaseLib

class FrgBase_Menu;
class FrgBase_Tree;
class FrgBase_PropertiesPanel;

class FORGBASE_EXPORT FrgBase_MainWindow
	: public QMainWindow
	, public FrgBase_Object
{

	Q_OBJECT

private:

	struct MainWindowMenus_Struct
	{
		FrgBase_Menu* theFileMenu_ = NullPtr;
		FrgBase_Menu* theEditMenu_ = NullPtr;
		FrgBase_Menu* theToolsMenu_ = NullPtr;
		FrgBase_Menu* theWindowMenu_ = NullPtr;
		FrgBase_Menu* theHelpMenu_ = NullPtr;
	};

	MainWindowMenus_Struct* theMainWindowMenus_ = NullPtr;
	FrgBase_Tree* theTree_ = NullPtr;
	FrgBase_PropertiesPanel* thePropertiesPanel_ = NullPtr;

	QDockWidget* theTreeDockWidget_ = NullPtr;
	QDockWidget* thePropertiesPanelDockWidget_ = NullPtr;

	FrgString theConsoleEngineName_;

private:

	void InitMainWindow();
	void FormMenus();
	void SetMainWindowStyleSheet();
	void AddMainWindowStyleSheet(const QString& styleSheet);
	void CreateConsoleOutput();

public:

	FrgBase_MainWindow(QWidget* parent = NullPtr);

	void PrintInfoToConsole(const FrgString& info);
	void PrintWarningToConsole(const FrgString& info);
	void PrintErrorToConsole(const FrgString& info);

	FrgBase_PropertiesPanel* GetPropertiesPanel() const { return thePropertiesPanel_; }
	void SetPropertiesPanel(FrgBase_PropertiesPanel* propertiesPanel);

protected slots:

	/*=========================*/
	/* Menu File Actions Slots */
	/*=========================*/
	virtual void FileNewActionSlot() {}
	virtual void FileLoadActionSlot() {}
	virtual void FileSaveActionSlot() {}
	virtual void FileSaveAsActionSlot() {}
	virtual void FileImportActionSlot() {}
	virtual void FileExportActionSlot() {}
	virtual void FileExitActionSlot() {}
};

EndForgBaseLib

#endif // !_FrgBase_MainWindow_Header
