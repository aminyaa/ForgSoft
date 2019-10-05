#pragma once
#ifndef _ForgThread_Header
#define _ForgThread_Header

#include <ForgGuiGlobals.hxx>
#include <QtCore/QThread>
#include <QtCore/QMutex>

#include <ForgGuiMainWindow.hxx>

BeginForgGuiLib

class ForgGuiThread : public QThread
{

private:

	QMutex* theMutex_ = ForgNullPtr;
	void(*theLockFunction_)() = ForgNullPtr;
	void(*theFunction_)() = ForgNullPtr;

	ForgGuiMainWindow* theParentMainWindow_ = ForgNullPtr;

public:

	ForgGuiThread(ForgGuiMainWindow* parent, void(*function)() = ForgNullPtr, QMutex* mutex = ForgNullPtr, void (*lockFunction)() = ForgNullPtr);

	void run();
	void start();

	ForgGetMacro(QMutex*, Mutex, theMutex_);
};

EndForgGuiLib

#endif // !_ForgThread_Header
