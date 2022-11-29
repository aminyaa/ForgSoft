#pragma once
#ifndef _FrgBase_Menu_Header
#define _FrgBase_Menu_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Object.hxx>
#include <FrgBase_MenuAction.hxx>

#include <QtWidgets/QMenu>

class QToolBar;

BeginForgBaseLib

class FrgBase_MainWindow;

class FORGBASE_EXPORT FrgBase_Menu
	: public QMenu
	, public FrgBase_Object
{
	Q_OBJECT

private:

	FrgBase_MainWindow* theParentMainWindow_ = nullptr;
	QToolBar* theToolBar_ = nullptr;

	FrgBase_MenuAction* theTitleAsAnAction_ = nullptr;

public:

	FrgBase_Menu
	(
		const QString& menuTitle,
		FrgBase_MainWindow* parentMainWindow,
		const bool addTitleAsAnAction = false
	);

	FrgBase_Menu
	(
		FrgBase_MainWindow* parentMainWindow
	);

	~FrgBase_Menu();

	FrgBase_MenuAction* AddItem
	(
		const QString& itemTitle,
		const bool isInToolBar = true
	);

	FrgBase_MenuAction* AddItem
	(
		const QString& iconAddress,
		const QString& itemTitle,
		const bool isInToolBar = true
	);

	FrgBase_MenuAction* AddItem
	(
		const QIcon& icon,
		const QString& itemTitle,
		const bool isInToolBar = true
	);

	FrgBase_MenuAction* GetItem(const QString& itemTitle);

	void SetToolBarHidden(const bool condition);

	FrgGetMacro(QToolBar*, ToolBar, theToolBar_);
	FrgGetMacro(FrgBase_MainWindow*, ParentMainWindow, theParentMainWindow_);

	bool HasTitleAsAnAction() const { return theHasTitleAsAnAction_; }

	void Execute();

	void Execute
	(
		const QPoint& pos,
		QAction* at = nullptr
	);

	std::vector<QAction*>
		GetListOfActions
		(
			const bool containingHiddens = true
		) const;

public slots:

	void MenuTitleChangedSlot(const QString& name);

private:

	bool theHasTitleAsAnAction_;
};

EndForgBaseLib

#endif // !_FrgBase_Menu_Header
