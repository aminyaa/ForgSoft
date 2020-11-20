#include <FrgBase_TabBar.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgBase_Menu.hxx>

#include <QtGui/QMouseEvent>

ForgBaseLib::FrgBase_TabBar::FrgBase_TabBar
(
	FrgBase_MainWindow* parentMainWindow
)
	: QTabBar(parentMainWindow)
{
	FrgString style = "QTabBar {"
		"qproperty-drawBase: 0;"
		"border-radius: 4px;"
		"margin: 0px;"
		"padding: 2px;"
		"border : 0;"
		"}";


	//this->setStyleSheet(style);

	this->setMovable(FrgTrue);
	this->setTabsClosable(FrgTrue);
	//this->setShape(QTabBar::TriangularNorth);
	this->setUsesScrollButtons(FrgTrue);

	theContextMenu_ = new FrgBase_Menu("Tabs Manager", parentMainWindow, true);
	theContextMenu_->SetToolBarHidden(true);

	auto closeAction = theContextMenu_->AddItem("Close", false);
	closeAction->setShortcutVisibleInContextMenu(true);
	closeAction->setShortcutContext(Qt::ShortcutContext::WidgetShortcut);
	closeAction->setShortcut(QKeySequence(QMainWindow::tr("Ctrl+W")));
	auto closeAllAction = theContextMenu_->AddItem("Close All", false);
	auto closeOtherAction = theContextMenu_->AddItem("Close Other", false);

	theContextMenu_->addSeparator();

	auto shiftLeftAction = theContextMenu_->AddItem("Shift Left", false);
	auto shiftRightAction = theContextMenu_->AddItem("Shift Right", false);

	connect(closeAction, SIGNAL(triggered(bool)), this, SLOT(closeActionClickedSlot(bool)));
	connect(closeAllAction, SIGNAL(triggered(bool)), this, SLOT(closeAllActionClickedSlot(bool)));
	connect(closeOtherAction, SIGNAL(triggered(bool)), this, SLOT(closeOtherActionClickedSLot(bool)));
	connect(shiftLeftAction, SIGNAL(triggered(bool)), this, SLOT(shiftLeftActionClickedSlot(bool)));
	connect(shiftRightAction, SIGNAL(triggered(bool)), this, SLOT(shiftRightActionClickedSlot(bool)));
}

void ForgBaseLib::FrgBase_TabBar::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::MouseButton::MiddleButton)
	{
		emit this->tabCloseRequested(this->currentIndex());
	}
	if (event->button() == Qt::MouseButton::RightButton)
	{
		setCurrentIndex(tabAt(event->pos()));
		ShowContextMenu(this->mapToGlobal(event->pos()));
	}
}

void ForgBaseLib::FrgBase_TabBar::ShowContextMenu(const QPoint& globalPos)
{
	int myCurrentIndex = this->currentIndex();
	auto shiftLeftAction = theContextMenu_->GetItem("Shift Left");
	auto shiftRightAction = theContextMenu_->GetItem("Shift Right");

	if (this->count() == 1)
	{
		shiftLeftAction->setEnabled(false);
		shiftRightAction->setEnabled(false);
	}
	else if (myCurrentIndex == 0)
	{
		shiftLeftAction->setEnabled(false);
		shiftRightAction->setEnabled(true);
	}
	else if (myCurrentIndex == this->count() - 1)
	{
		shiftLeftAction->setEnabled(true);
		shiftRightAction->setEnabled(false);
	}
	else
	{
		shiftLeftAction->setEnabled(true);
		shiftRightAction->setEnabled(true);
	}

	theContextMenu_->exec(globalPos);
}

void ForgBaseLib::FrgBase_TabBar::closeActionClickedSlot(bool)
{
	emit this->tabCloseRequested(this->currentIndex());
}

void ForgBaseLib::FrgBase_TabBar::closeAllActionClickedSlot(bool)
{
	emit closeAllActionClickedSignal();
}

void ForgBaseLib::FrgBase_TabBar::closeOtherActionClickedSLot(bool)
{
	emit closeOtherActionClickedSignal(this->currentIndex());
}

void ForgBaseLib::FrgBase_TabBar::shiftLeftActionClickedSlot(bool)
{
	this->moveTab(this->currentIndex(), this->currentIndex() - 1);
}

void ForgBaseLib::FrgBase_TabBar::shiftRightActionClickedSlot(bool)
{
	this->moveTab(this->currentIndex(), this->currentIndex() + 1);
}