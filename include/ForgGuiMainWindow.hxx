#pragma once
#ifndef _ForgGuiMainWindow_Header
#define _ForgGuiMainWindow_Header

#include <ForgGuiGlobals.hxx>
#include <ForgGuiMenus.hxx>

#include <QtWidgets/QMainWindow>

BeginForgGuiLib

class FORGGUI_EXPORT ForgGuiMainWindow : public QMainWindow
{

	Q_OBJECT

private:

	ForgSharedPtr<ForgGuiMenus> theMenus_ = ForgNullPtr;

public:

	ForgGuiMainWindow(QWidget* parent = ForgNullPtr);

protected slots:

	/*=========================*/
	/* Menu File Actions Slots */
	/*=========================*/

	void FileNewAction();
	void FileLoadAction();
	void FileSaveAction();
	void FileSaveAsAction();
	void FileSaveAllAction();
	void FileImportAction();
	void FileExportAction();
	void FileExitAction();
};

EndForgGuiLib

#endif // !_ForgGuiMainWindow_Header
