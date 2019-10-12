#pragma once
#ifndef _FrgBaseThread_Header
#define _FrgBaseThread_Header

#include <FrgBaseGlobals.hxx>

#include <QtCore/QThread>
#include <QtCore/QMutex>

BeginFrgBaseLib

class FrgBaseMainWindow;

class FORGBASE_EXPORT FrgBaseThread : public QThread
{

private:

	QMutex* theMutex_ = FrgNullPtr;
	void(*theLockFunction_)() = FrgNullPtr;
	void(*theFunction_)() = FrgNullPtr;

	FrgBaseMainWindow* theParentMainWindow_ = FrgNullPtr;

public:

	FrgBaseThread(FrgBaseMainWindow* parent, void(*function)() = FrgNullPtr, QMutex* mutex = FrgNullPtr, void (*lockFunction)() = FrgNullPtr);

	void run();
	void start();

	FrgGetMacro(QMutex*, Mutex, theMutex_);
};

EndFrgBaseLib

#endif // !_FrgThread_Header
