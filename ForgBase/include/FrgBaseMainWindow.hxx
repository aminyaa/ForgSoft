#pragma once
#ifndef _FrgBaseMainWindow_Header
#define _FrgBaseMainWindow_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QMainWindow>

class QDockWidget;
class QtAbstractPropertyBrowser;

BeginFrgBaseLib

//class FrgMenus;
class FrgBaseTree;
class FrgBaseTabWidget;

class FrgMenu_File;
class FrgMenu_Edit;
class FrgMenu_Models;
class FrgMenu_Mesh;
class FrgMenu_Solution;
//class FrgMenu_View;
class FrgMenu_Help;

class FORGBASE_EXPORT FrgBaseMainWindow : public QMainWindow
{
	Q_OBJECT

private:

	struct ConsoleWidgetStruct
	{
		QDockWidget* theDockWidget_ = FrgNullPtr;
		FrgString theEngineName_;

		~ConsoleWidgetStruct()
		{
			FreePointer(theDockWidget_);
		}
	};

	struct TreeWidgetStruct
	{
		QDockWidget* theDockWidget_ = FrgNullPtr;
		FrgBaseTree* theTree_;

		~TreeWidgetStruct()
		{
			FreePointer(theDockWidget_);
		}
	};

	struct PropertiesWidgetStruct
	{
		QDockWidget* theDockWidget_ = FrgNullPtr;
		QtAbstractPropertyBrowser* theProperty_ = FrgNullPtr;

		~PropertiesWidgetStruct()
		{
			FreePointer(theDockWidget_);
			FreePointer(theProperty_);
		}
	};

	TreeWidgetStruct* theTreeWidget_ = FrgNullPtr;

	//FrgSharedPtr<FrgMenus> theMenus_ = FrgNullPtr;
	FrgMenu_File* theFileMenu_ = FrgNullPtr;
	FrgMenu_Edit* theEditMenu_ = FrgNullPtr;
	FrgMenu_Models* theModelsMenu_ = FrgNullPtr;
	FrgMenu_Mesh* theMeshMenu_ = FrgNullPtr;
	FrgMenu_Solution* theSolutionMenu_ = FrgNullPtr;
	//FrgMenu_View* theViewMenu_ = FrgNullPtr;
	FrgMenu_Help* theHelpMenu_ = FrgNullPtr;




	ConsoleWidgetStruct* theConsoleWidget_ = FrgNullPtr;

	PropertiesWidgetStruct* thePropertyWidget_ = FrgNullPtr;

	FrgBaseTabWidget* theTabWidget_ = FrgNullPtr;

public:

	FrgBaseMainWindow(QWidget* parent = FrgNullPtr);

	~FrgBaseMainWindow();

	void ParseInfoToConsole(const FrgString& info);
	void ParseWarningToConsole(const FrgString& info);
	void ParseErrorToConsole(const FrgString& info);

	//FrgGetMacro(FrgSharedPtr<FrgMenus>, Menus, theMenus_);
	FrgGetMacro(FrgBaseTree*, Tree, theTreeWidget_->theTree_);
	FrgGetMacro(TreeWidgetStruct*, TreeWidget, theTreeWidget_);
	FrgGetMacro(PropertiesWidgetStruct*, PropertyWidget, thePropertyWidget_);
	FrgGetMacro(FrgBaseTabWidget*, TabWidget, theTabWidget_);

	FrgGetMacro(FrgMenu_File*, FileMenu, theFileMenu_);
	FrgGetMacro(FrgMenu_Edit*, EditMenu, theEditMenu_);
	FrgGetMacro(FrgMenu_Models*, ModelsMenu, theModelsMenu_);
	FrgGetMacro(FrgMenu_Mesh*, MeshMenu, theMeshMenu_);
	FrgGetMacro(FrgMenu_Solution*, SolutionMenu, theSolutionMenu_);
	//FrgGetMacro(FrgMenu_View*, ViewMenu, theViewMenu_);
	FrgGetMacro(FrgMenu_Help*, HelpMenu, theHelpMenu_);

protected slots:

	/*=========================*/
	/* Menu File Actions Slots */
	/*=========================*/
	void FileNewActionSlot();
	void FileLoadActionSlot();
	void FileSaveActionSlot();
	void FileSaveAsActionSlot();
	void FileSaveAllActionSlot();
	virtual void FileImportActionSlot();
	void FileExportActionSlot();
	void FileExitActionSlot();
	void AboutUsClickedSlot(bool);

private:

	/*friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) { ar& theDoubles_; }*/

	void CreateConsoleOutput();

	void SetMainWindowStyleSheet();

	void AddMainWindowStyleSheet(const FrgString& styleSheet);

	virtual void CreateTree();

	void CreateProperties();

	void InitFrgMainWindow();
};

EndFrgBaseLib

#endif // !_FrgBaseMainWindow_Header
