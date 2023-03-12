#include "FrgBase_MenuAction.hxx"

ForgBaseLib::FrgBase_MenuAction::FrgBase_MenuAction
(
	QObject* parent
)
	: QAction(parent)
{
	connect(this, &QAction::triggered, this, &FrgBase_MenuAction::ClickedSignal);
}

ForgBaseLib::FrgBase_MenuAction::FrgBase_MenuAction
(
	const QString& text,
	QObject* parent
)
	: QAction(text, parent)
{
	connect(this, &QAction::triggered, this, &FrgBase_MenuAction::ClickedSignal);
}

ForgBaseLib::FrgBase_MenuAction::FrgBase_MenuAction
(
	const QIcon& icon,
	const QString& text,
	QObject* parent
)
	: QAction(icon, text, parent)
{
	connect
	(
		this,
		&QAction::triggered,
		this,
		&FrgBase_MenuAction::ClickedSignal
	);
}

bool ForgBaseLib::FrgBase_MenuAction::IsHidden() const
{
	return !isVisible();
}

void ForgBaseLib::FrgBase_MenuAction::SetHidden(const bool c)
{
	setVisible(!c);
}

void ForgBaseLib::FrgBase_MenuAction::Click()
{
	emit triggered(this->isChecked());
}