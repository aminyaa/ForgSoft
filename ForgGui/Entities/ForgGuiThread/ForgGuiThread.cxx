#include <ForgGuiThread.hxx>

ForgGuiLib::ForgGuiThread::ForgGuiThread(ForgGuiMainWindow* parent, void(*function)(), QMutex* mutex, void(*lockFunction)())
	: QThread(parent)
	, theParentMainWindow_(parent)
	, theFunction_(function)
	, theMutex_(mutex)
	, theLockFunction_(lockFunction)
{
}

void ForgGuiLib::ForgGuiThread::run()
{
	/*if (theMutex_)
	{
		theMutex_->lock();
		(*theLockFunction_)();
		theMutex_->unlock();
	}
	else
		theParentMainWindow_->ParseWarningToConsole("Running process in non mutex form!");*/

	(*theFunction_)();
}

void ForgGuiLib::ForgGuiThread::start()
{
	QThread::start();
}