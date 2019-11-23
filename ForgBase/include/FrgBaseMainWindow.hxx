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
class FrgBaseMenuFile;
class FrgBaseTabWidget;

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
	FrgBaseMenuFile* theFileMenu_ = FrgNullPtr;

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
	FrgGetMacro(PropertiesWidgetStruct*, PropertyWidget, thePropertyWidget_);
	FrgGetMacro(FrgBaseTabWidget*, TabWidget, theTabWidget_);

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
