#pragma once
#ifndef _FrgBase_Application_Header
#define _FrgBase_Application_Header

#include <FrgBase_Global.hxx>
#include <QtWidgets/QApplication>

namespace ForgBaseLib
{
	class FrgBase_MainWindow;
}

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_Application
	: public QApplication
{

	Q_OBJECT

public:

	FrgBase_Application
	(
		int& argc,
		char** argv,
		int af = ApplicationFlags
	);

	bool notify(QObject* receiver, QEvent* event) override;

	ForgBaseLib::FrgBase_MainWindow* GetParentMainWindow() const { return theParentMainWindow_; }
	void SetParentMainWindow(ForgBaseLib::FrgBase_MainWindow* parentMainWindow) { theParentMainWindow_ = parentMainWindow; }

protected:

	ForgBaseLib::FrgBase_MainWindow* theParentMainWindow_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_Application_Header
