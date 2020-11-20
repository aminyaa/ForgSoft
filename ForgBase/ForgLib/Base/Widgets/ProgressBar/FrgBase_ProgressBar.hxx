#pragma once
#ifndef _FrgBase_ProgressBar_Header
#define _FrgBase_ProgressBar_Header

#include <FrgBase_Global.hxx>
#include <QtWidgets/QWidget>

class QProgressBar;
class QLabel;

BeginForgBaseLib

class FrgBase_MainWindow;

class FORGBASE_EXPORT FrgBase_ProgressBar
	: public QWidget
{
	Q_OBJECT

public:

	FrgBase_ProgressBar(FrgBase_MainWindow* parentMainWindow);

	void SetProgressBarBusy(bool condition = true);

	auto GetLabel() const -> const QString&;
	void SetLabel(const QString& label) const;

	void SetLabelHidden(bool condition = true) const;

private:

	QProgressBar* theProgressBar_ = nullptr;
	QLabel* theLabel_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_ProgressBar_Header
