#include <FrgBase_WindowDragger.hxx>

#include <QPainter>
#include <QStyleOption>
#include <QMouseEvent>

ForgBaseLib::FrgBase_WindowDragger::FrgBase_WindowDragger(QWidget* parent)
	: QWidget(parent)
{
	mousePressed = false;
}

void ForgBaseLib::FrgBase_WindowDragger::mousePressEvent(QMouseEvent* event)
{
	mousePressed = true;
	mousePos = event->globalPos();

	QWidget* parent = parentWidget();
	if (parent) parent = parent->parentWidget();

	if (parent) wndPos = parent->pos();
}

void ForgBaseLib::FrgBase_WindowDragger::mouseMoveEvent(QMouseEvent* event)
{
	QWidget* parent = parentWidget();
	if (parent) parent = parent->parentWidget();

	if (parent && mousePressed)
		parent->move(wndPos + (event->globalPos() - mousePos));
}

void ForgBaseLib::FrgBase_WindowDragger::mouseReleaseEvent(QMouseEvent* event)
{
	Q_UNUSED(event);
	mousePressed = false;
}

void ForgBaseLib::FrgBase_WindowDragger::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event);
	QStyleOption styleOption;
	styleOption.init(this);
	QPainter painter(this);
	style()->drawPrimitive(QStyle::PE_Widget, &styleOption, &painter, this);
}

void ForgBaseLib::FrgBase_WindowDragger::mouseDoubleClickEvent(QMouseEvent* event)
{
	Q_UNUSED(event);
	emit doubleClicked();
}