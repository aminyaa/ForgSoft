#include <FrgBase_TabWidget.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgBase_TabBar.hxx>

#include <QtGui/QKeyEvent>

ForgBaseLib::FrgBase_TabWidget::FrgBase_TabWidget
(
	FrgBase_MainWindow* parentMainWindow
)
	: QTabWidget(parentMainWindow)
{
	FrgString style = "QTabWidget {"
		"padding: 2px;"
		"selection-background-color: #32414B;"
		"}"
		"QTabWidget QWidget{"
		" border: 1px solid #32414B;"
		"}"
		"QTabWidget::pane{"
		"  border: 1px solid #32414B;"
		"  border-radius: 4px;"
		"  margin: 0px;"
		"  padding: 0px;"
		"}"
		"QTabWidget::pane:selected{"
		"  background-color: #32414B;"
		"  border: 1px solid #1464A0;"
		"}";

	//this->setStyleSheet(style);
	theTabBar_ = FrgNew FrgBase_TabBar(parentMainWindow);
	this->setTabBar(theTabBar_);

	connect(this, SIGNAL(tabCloseRequested(int)), this, SLOT(CloseMyTabSlot(int)));

	connect(theTabBar_, SIGNAL(closeAllActionClickedSignal()), this, SLOT(closeAllActionClickedSlot()));
	connect(theTabBar_, SIGNAL(closeOtherActionClickedSignal(int)), this, SLOT(closeOtherActionClickedSLot(int)));
}

ForgBaseLib::FrgBase_TabWidget::~FrgBase_TabWidget()
{
	FreePointer(theTabBar_);
}

void ForgBaseLib::FrgBase_TabWidget::ShowTabWidget(QWidget * widget, const QString& title)
{
	if (currentWidget() == widget)
		return;

	if(this->indexOf(widget) < 0)
		this->addTab(widget, title);

	this->setCurrentWidget(widget);
}

void ForgBaseLib::FrgBase_TabWidget::keyPressEvent(QKeyEvent* event)
{
	if (event->modifiers() == Qt::KeyboardModifier::ControlModifier && event->key() == Qt::Key::Key_W)
	{
		emit this->tabCloseRequested(this->currentIndex());
	}
}

void ForgBaseLib::FrgBase_TabWidget::CloseMyTabSlot(int index)
{
	this->removeTab(index);
}

void ForgBaseLib::FrgBase_TabWidget::closeAllActionClickedSlot()
{
	while (this->count() > 0)
		this->removeTab(0);
}

void ForgBaseLib::FrgBase_TabWidget::closeOtherActionClickedSLot(int index)
{
	auto myWidget = widget(index);

	int i = 0;
	while(this->count() > 1)
	{
		if (this->widget(i) != myWidget)
		{
			this->removeTab(i);
			continue;
		}
		i++;
	}
}