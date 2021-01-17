#pragma once
#ifndef _FrgBase_Thread_Header
#define _FrgBase_Thread_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Object.hxx>

#include <QtCore/QThread>
#include <QtCore/QMutex>

BeginForgBaseLib

class FrgBase_MainWindow;

class FORGBASE_EXPORT FrgBase_Thread
	: public QThread
	, public ForgBaseLib::FrgBase_Object
{

	Q_OBJECT

private:

	QMutex* theMutex_ = nullptr;
	void(*theLockFunction_)() = nullptr;
	void(*theFunction_)() = nullptr;

	FrgBase_MainWindow* theParentMainWindow_ = nullptr;

public:

	FrgBase_Thread(FrgBase_MainWindow* parent = nullptr, void(*function)() = nullptr, QMutex* mutex = nullptr, void(*lockFunction)() = nullptr);

	void run();
	void start();

	FrgGetMacro(QMutex*, Mutex, theMutex_);

private slots:

	void ThreadFinishedSlot();
};

EndForgBaseLib

#endif // !_FrgBase_Thread_Header
