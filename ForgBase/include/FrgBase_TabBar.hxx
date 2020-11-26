#pragma once
#ifndef _FrgBase_TabBar_Header
#define _FrgBase_TabBar_Header

#include <FrgBase_Global.hxx>
#include <QtWidgets/QTabBar>

BeginForgBaseLib

class FrgBase_MainWindow;
class FrgBase_Menu;

class FORGBASE_EXPORT FrgBase_TabBar
	: public QTabBar
{
	Q_OBJECT

public:

	FrgBase_TabBar
	(
		FrgBase_MainWindow* parentMainWindow
	);

Q_SIGNALS:

	void closeAllActionClickedSignal();
	void closeOtherActionClickedSignal(int);

protected:

	void mouseReleaseEvent(QMouseEvent*) override;

public Q_SLOTS:

	virtual void ShowContextMenu(const QPoint& globalPos);

	void closeActionClickedSlot(bool);
	void closeAllActionClickedSlot(bool);
	void closeOtherActionClickedSLot(bool);
	void shiftLeftActionClickedSlot(bool);
	void shiftRightActionClickedSlot(bool);

private:

	FrgBase_Menu* theContextMenu_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_TabBar_Header
