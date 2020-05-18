#include <FrgBase_Thread.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgBase_ProgressBar.hxx>

ForgBaseLib::FrgBase_Thread::FrgBase_Thread(FrgBase_MainWindow* parent, void(*function)(), QMutex* mutex, void(*lockFunction)())
	: QThread(parent)
	, theParentMainWindow_(parent)
	, theFunction_(function)
	, theMutex_(mutex)
	, theLockFunction_(lockFunction)
{
	connect(this, SIGNAL(finished()), this, SLOT(ThreadFinishedSlot()));
}

void ForgBaseLib::FrgBase_Thread::run()
{
	if (theMutex_)
	{
		theMutex_->lock();
		if (theLockFunction_)
			(*theLockFunction_)();
		theMutex_->unlock();
	}
	else
		if (theParentMainWindow_)
			theParentMainWindow_->PrintWarningToConsole("Running process in non mutex form!");
	if (theFunction_)
		(*theFunction_)();
}

void ForgBaseLib::FrgBase_Thread::start()
{
	if (theParentMainWindow_)
	{
		auto progressBar = theParentMainWindow_->GetProgressBar();
		if (progressBar)
		{
			progressBar->SetProgressBarBusy(true);
		}
	}

	QThread::start();
}

void ForgBaseLib::FrgBase_Thread::ThreadFinishedSlot()
{
	if (theParentMainWindow_)
	{
		auto progressBar = theParentMainWindow_->GetProgressBar();
		if (progressBar)
		{
			progressBar->SetProgressBarBusy(false);
		}
	}
}