#pragma once
#ifndef _FrgMainWindow_Header
#define _FrgMainWindow_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QMainWindow>

class QDockWidget;
class QtTreePropertyBrowser;

BeginFrgBaseLib

//class FrgMenus;
class FrgTree;
class FrgFileMenu;

class FORGBASE_EXPORT FrgMainWindow : public QMainWindow
{
	Q_OBJECT

private:

	struct ConsoleWidgetStruct
	{
		QDockWidget* theDockWidget_ = FrgNullPtr;
		FrgString theEngineName_;
	};

	struct TreeWidgetStruct
	{
		QDockWidget* theDockWidget_ = FrgNullPtr;
		FrgTree* theTree_;
	};

	struct PropertiesWidgetStruct
	{
		QDockWidget* theDockWidget_ = FrgNullPtr;
		QtTreePropertyBrowser* theProperty_ = FrgNullPtr;
	};

	FrgSharedPtr<TreeWidgetStruct> theTreeWidget_ = FrgNullPtr;

	//FrgSharedPtr<FrgMenus> theMenus_ = FrgNullPtr;
	FrgSharedPtr<FrgFileMenu> theFileMenu_ = FrgNullPtr;

	FrgSharedPtr<ConsoleWidgetStruct> theConsoleWidget_ = FrgNullPtr;

	FrgSharedPtr<PropertiesWidgetStruct> thePropertyWidget_ = FrgNullPtr;

	FrgVector<double> theDoubles_;

public:

	FrgMainWindow(QWidget* parent = FrgNullPtr);

	void ParseInfoToConsole(const FrgString& info);
	void ParseWarningToConsole(const FrgString& info);
	void ParseErrorToConsole(const FrgString& info);

	//FrgGetMacro(FrgSharedPtr<FrgMenus>, Menus, theMenus_);
	FrgGetMacro(FrgTree*, Tree, theTreeWidget_->theTree_);
	FrgGetMacro(FrgSharedPtr<PropertiesWidgetStruct>, PropertyWidget, thePropertyWidget_);

protected slots:

	/*=========================*/
	/* Menu File Actions Slots */
	/*=========================*/
	void FileNewActionSlot();
	void FileLoadActionSlot();
	void FileSaveActionSlot();
	void FileSaveAsActionSlot();
	void FileSaveAllActionSlot();
	void FileImportActionSlot();
	void FileExportActionSlot();
	void FileExitActionSlot();

private:

	/*friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) { ar& theDoubles_; }*/

	void CreateConsoleOutput();

	void SetMainWindowStyleSheet();

	void AddMainWindowStyleSheet(const FrgString& styleSheet);

	void CreateTree();

	void CreateProperties();

	void InitFrgMainWindow();
};

EndFrgBaseLib

#endif // !_FrgMainWindow_Header
