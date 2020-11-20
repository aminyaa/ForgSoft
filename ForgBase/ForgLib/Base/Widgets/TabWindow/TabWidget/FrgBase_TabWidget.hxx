#pragma once
#ifndef _FrgBase_TabWidget_Header
#define _FrgBase_TabWidget_Header

#include <FrgBase_Global.hxx>
#include <QtWidgets/QTabWidget>

BeginForgBaseLib

class FrgBase_MainWindow;
class FrgBase_TabBar;

class FORGBASE_EXPORT FrgBase_TabWidget
	: public QTabWidget
{
	Q_OBJECT

public:

	FrgBase_TabWidget
	(
		FrgBase_MainWindow* parentMainWindow
	);

	~FrgBase_TabWidget();

	void ShowTabWidget(QWidget* widget, const QString& title);

protected:

	void keyPressEvent(QKeyEvent*) override;

private:

	FrgBase_TabBar* theTabBar_ = NullPtr;

private slots:

	void CloseMyTabSlot(int index);
	void closeAllActionClickedSlot();
	void closeOtherActionClickedSLot(int index);
};

EndForgBaseLib

#endif // !_FrgBase_TabWidget_Header
