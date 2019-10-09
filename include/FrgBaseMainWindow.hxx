#pragma once
#ifndef _FrgBaseMainWindow_Header
#define _FrgBaseMainWindow_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QMainWindow>

class QDockWidget;
class QtTreePropertyBrowser;

BeginFrgBaseLib

//class FrgMenus;
class FrgBaseTree;
class FrgBaseMenuFile;

class FORGBASE_EXPORT FrgBaseMainWindow : public QMainWindow
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
		FrgBaseTree* theTree_;
	};

	struct PropertiesWidgetStruct
	{
		QDockWidget* theDockWidget_ = FrgNullPtr;
		QtTreePropertyBrowser* theProperty_ = FrgNullPtr;
	};

	FrgSharedPtr<TreeWidgetStruct> theTreeWidget_ = FrgNullPtr;

	//FrgSharedPtr<FrgMenus> theMenus_ = FrgNullPtr;
	FrgSharedPtr<FrgBaseMenuFile> theFileMenu_ = FrgNullPtr;

	FrgSharedPtr<ConsoleWidgetStruct> theConsoleWidget_ = FrgNullPtr;

	FrgSharedPtr<PropertiesWidgetStruct> thePropertyWidget_ = FrgNullPtr;

	FrgVector<double> theDoubles_;

public:

	FrgBaseMainWindow(QWidget* parent = FrgNullPtr);

	void ParseInfoToConsole(const FrgString& info);
	void ParseWarningToConsole(const FrgString& info);
	void ParseErrorToConsole(const FrgString& info);

	//FrgGetMacro(FrgSharedPtr<FrgMenus>, Menus, theMenus_);
	FrgGetMacro(FrgBaseTree*, Tree, theTreeWidget_->theTree_);
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

#endif // !_FrgBaseMainWindow_Header
