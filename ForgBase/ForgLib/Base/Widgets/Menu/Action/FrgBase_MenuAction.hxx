#pragma once
#ifndef _FrgBase_MenuAction_Header
#define _FrgBase_MenuAction_Header

#include <FrgBase_Object.hxx>

#include <QAction>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_MenuAction
	: public QAction
	, public FrgBase_Object
{

	Q_OBJECT

public:

	explicit FrgBase_MenuAction
	(
		QObject* parent = nullptr
	);

	explicit FrgBase_MenuAction
	(
		const QString& text,
		QObject* parent = nullptr
	);

	explicit FrgBase_MenuAction
	(
		const QIcon& icon,
		const QString& text,
		QObject* parent = nullptr
	);

	bool IsHidden() const;
	void SetHidden(const bool c);

	// This signal will emit only when QAction::triggered calls
	Q_SIGNAL void ClickedSignal(bool checked = false);

	// This method will emit QAction::triggered signal, so ClickedSignal will be emitted after
	Q_SLOT void Click();
};

EndForgBaseLib

#endif // !_FrgBase_MenuAction_Header
