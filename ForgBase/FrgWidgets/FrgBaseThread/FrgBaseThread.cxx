#include <FrgThread.hxx>
#include <FrgMainWindow.hxx>

ForgBaseLib::FrgThread::FrgThread(FrgMainWindow* parent, void(*function)(), QMutex* mutex, void(*lockFunction)())
	: QThread(parent)
	, theParentMainWindow_(parent)
	, theFunction_(function)
	, theMutex_(mutex)
	, theLockFunction_(lockFunction)
{
}

void ForgBaseLib::FrgThread::run()
{
	if (theMutex_)
	{
		theMutex_->lock();
		(*theLockFunction_)();
		theMutex_->unlock();
	}
	else
		theParentMainWindow_->ParseWarningToConsole("Running process in non mutex form!");

	(*theFunction_)();
}

void ForgBaseLib::FrgThread::start()
{
	QThread::start();
}