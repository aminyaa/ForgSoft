#include "ads/icontitlewidget.h"

#include <QIcon>
#include <QString>
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStyle>
#include <QMainWindow>
#include <QtGui/QKeyEvent>
#include <QtGui/QMouseEvent>

#include <FrgBase_Menu.hxx>

IconTitleWidget::IconTitleWidget(const QIcon& icon, const QString& title, QWidget *parent) :
	QFrame(parent)
{
	QBoxLayout* l = new QBoxLayout(QBoxLayout::LeftToRight);
	l->setContentsMargins(0, 0, 0, 0);
	setLayout(l);

	_iconLabel = new QLabel();
	l->addWidget(_iconLabel);

	_titleLabel = new QLabel();
	l->addWidget(_titleLabel, 1);

	_closeButton = new QPushButton();
	_closeButton->setToolTip("Close Tab");
	l->addWidget(_closeButton);

	auto buttonIcon = QIcon(":/styles/DarkStyle/icon_close.png");
	_closeButton->setIcon(buttonIcon);
	_closeButton->setMaximumSize(16, 16);

	setIcon(icon);
	setTitle(title);

	QObject::connect(_closeButton, &QPushButton::clicked, this, &IconTitleWidget::CloseButtonClicked);

	theContextMenu_ = new ForgBaseLib::FrgBase_Menu("Tabs Manager", nullptr, true);
	theContextMenu_->SetToolBarHidden(true);

	auto closeAction = theContextMenu_->AddItem("Close", false);
	closeAction->setShortcutVisibleInContextMenu(true);
	auto closeAllAction = theContextMenu_->AddItem("Close All", false);
	auto closeOtherAction = theContextMenu_->AddItem("Close Other", false);

	theContextMenu_->addSeparator();

	auto shiftLeftAction = theContextMenu_->AddItem("Shift Left", false);
	auto shiftRightAction = theContextMenu_->AddItem("Shift Right", false);

	connect(closeAction, &QAction::triggered, [this]() {emit CloseButtonClicked(); });
	connect(closeAllAction, &QAction::triggered, [this]() {emit CloseAllButtonClicked(); });
	connect(closeOtherAction, &QAction::triggered, [this]() {emit CloseOtherButtonClicked(); });
	connect(shiftLeftAction, &QAction::triggered, [this]() {emit TabShifted(-1); });
	connect(shiftRightAction, &QAction::triggered, [this]() {emit TabShifted(1); });
}

void IconTitleWidget::setIcon(const QIcon& icon)
{
	if (icon.isNull())
	{
		_iconLabel->setPixmap(QPixmap());
		_iconLabel->setVisible(false);
	}
	else
	{
		_iconLabel->setPixmap(icon.pixmap(16, 16));
		_iconLabel->setVisible(true);
	}
}

void IconTitleWidget::setTitle(const QString& title)
{
	if (title.isEmpty())
	{
		_titleLabel->setText(QString());
		_titleLabel->setVisible(false);
	}
	else
	{
		_titleLabel->setText(title);
		_titleLabel->setVisible(true);
	}
}

void IconTitleWidget::polishUpdate()
{
	QList<QWidget*> widgets;
	widgets.append(_iconLabel);
	widgets.append(_titleLabel);
	foreach (QWidget* w, widgets)
	{
		w->style()->unpolish(w);
		w->style()->polish(w);
		w->update();
	}
}

void IconTitleWidget::keyPressEvent(QKeyEvent* event)
{
	QFrame::keyPressEvent(event);
}

void IconTitleWidget::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::MouseButton::MiddleButton)
	{
		emit CloseButtonClicked();
	}
	if (event->button() == Qt::MouseButton::RightButton)
	{
		emit TabClicked();
		ShowContextMenu(this->mapToGlobal(event->pos()));
	}

	QFrame::mouseReleaseEvent(event);
}

void IconTitleWidget::wheelEvent(QWheelEvent* event)
{
	if (event->delta() < 0)
		emit TabScrolled(1);
	else
		emit TabScrolled(-1);

	QFrame::wheelEvent(event);
}

void IconTitleWidget::ShowContextMenu(const QPoint& globalPos)
{
	theContextMenu_->exec(globalPos);
}