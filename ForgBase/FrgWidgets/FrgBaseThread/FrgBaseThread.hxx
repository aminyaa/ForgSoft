#pragma once
#ifndef _FrgThread_Header
#define _FrgThread_Header

#include <FrgBaseGlobals.hxx>

#include <QtCore/QThread>
#include <QtCore/QMutex>

BeginFrgBaseLib

class FrgMainWindow;

class FORGBASE_EXPORT FrgThread : public QThread
{

private:

	QMutex* theMutex_ = FrgNullPtr;
	void(*theLockFunction_)() = FrgNullPtr;
	void(*theFunction_)() = FrgNullPtr;

	FrgMainWindow* theParentMainWindow_ = FrgNullPtr;

public:

	FrgThread(FrgMainWindow* parent, void(*function)() = FrgNullPtr, QMutex* mutex = FrgNullPtr, void (*lockFunction)() = FrgNullPtr);

	void run();
	void start();

	FrgGetMacro(QMutex*, Mutex, theMutex_);
};

EndFrgBaseLib

#endif // !_FrgThread_Header
