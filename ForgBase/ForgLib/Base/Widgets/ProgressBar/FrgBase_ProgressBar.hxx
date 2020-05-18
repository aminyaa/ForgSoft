#pragma once
#ifndef _FrgBase_ProgressBar_Header
#define _FrgBase_ProgressBar_Header

#include <FrgBase_Global.hxx>
#include <QtWidgets/QProgressBar>

BeginForgBaseLib

class FrgBase_MainWindow;

class FORGBASE_EXPORT FrgBase_ProgressBar
	: public QProgressBar
{
	Q_OBJECT

public:

	FrgBase_ProgressBar(FrgBase_MainWindow* parentMainWindow);

	void SetProgressBarBusy(bool condition);
};

EndForgBaseLib

#endif // !_FrgBase_ProgressBar_Header
