#include <FrgBaseThread.hxx>
#include <FrgBaseMainWindow.hxx>

ForgBaseLib::FrgBaseThread::FrgBaseThread(FrgBaseMainWindow* parent, void(*function)(), QMutex* mutex, void(*lockFunction)())
	: QThread(parent)
	, theParentMainWindow_(parent)
	, theFunction_(function)
	, theMutex_(mutex)
	, theLockFunction_(lockFunction)
{
}

void ForgBaseLib::FrgBaseThread::run()
{
	if (theMutex_)
	{
		theMutex_->lock();
		(*theLockFunction_)();
		theMutex_->unlock();
	}
	else
		if (theParentMainWindow_)
			theParentMainWindow_->ParseWarningToConsole("Running process in non mutex form!");

	(*theFunction_)();
}

void ForgBaseLib::FrgBaseThread::start()
{
	QThread::start();
}