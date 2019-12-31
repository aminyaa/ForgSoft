#pragma once
#ifndef _FrgBase_MainWindow_Header
#define _FrgBase_MainWindow_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Object.hxx>

#include <QtWidgets/QMainWindow>

BeginForgBaseLib

class FrgBase_Menu;

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

	void FormMenus();
	void SetMainWindowStyleSheet();
	void AddMainWindowStyleSheet(const QString& styleSheet);

public:

	FrgBase_MainWindow(QWidget* parent = NullPtr);

protected slots:

	/*=========================*/
	/* Menu File Actions Slots */
	/*=========================*/
	virtual void FileNewActionSlot() {}
	virtual void FileLoadActionSlot() {}
	virtual void FileSaveActionSlot() {}
	virtual void FileSaveAsActionSlot() {}
	virtual void FileImportActionSlot();
	virtual void FileExportActionSlot() {}
	virtual void FileExitActionSlot() {}
};

EndForgBaseLib

#endif // !_FrgBase_MainWindow_Header
