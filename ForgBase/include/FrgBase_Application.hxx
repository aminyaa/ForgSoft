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
	
	static FrgBase_Application* Instance();

	FrgBase_Application
	(
		int& argc,
		char** argv,
		int af = ApplicationFlags
	);

	bool notify(QObject* receiver, QEvent* event) override;

	ForgBaseLib::FrgBase_MainWindow* GetParentMainWindow() const { return theParentMainWindow_; }
	void SetParentMainWindow(ForgBaseLib::FrgBase_MainWindow* parentMainWindow) { theParentMainWindow_ = parentMainWindow; }

	// Catch everything (including SEH) and throw std::exception
	static void CatchAndThrowStdException(const std::function<void()>& func);

	// Catch everything (including SEH) and do nothing
	static void CatchAndIgnore(const std::function<void()>& func);

protected:

	ForgBaseLib::FrgBase_MainWindow* theParentMainWindow_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_Application_Header
