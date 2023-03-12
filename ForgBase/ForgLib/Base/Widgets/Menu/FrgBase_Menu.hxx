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

	// positionIndex = -1 means: add menu at the last position
	FrgBase_Menu* AddMenu
	(
		const QString& menuTitle,
		const int addTitleAsAnAction = false,
		const int positionIndex = -1
	);

	// positionIndex = -1 means: add item at the last position
	FrgBase_MenuAction* AddItem
	(
		const QString& itemTitle,
		const int isInToolBar = true,
		const int positionIndex = -1
	);

	// positionIndex = -1 means: add item at the last position
	FrgBase_MenuAction* AddItem
	(
		const QString& iconAddress,
		const QString& itemTitle,
		const int isInToolBar = true,
		const int positionIndex = -1
	);

	// positionIndex = -1 means: add item at the last position
	FrgBase_MenuAction* AddItem
	(
		const QIcon& icon,
		const QString& itemTitle,
		const int isInToolBar = true,
		const int positionIndex = -1
	);

	FrgBase_MenuAction* GetItem
	(
		const QString& itemTitle
	);

	// returns -1 if not found
	int GetIndexUsingItem
	(
		FrgBase_MenuAction* action
	);

	void InsertItem
	(
		FrgBase_MenuAction* before,
		FrgBase_MenuAction* action
	);

	// positionIndex = -1 means: add item at the last position
	void InsertItem
	(
		const int positionIndex,
		FrgBase_MenuAction* action
	);

	void RemoveItem
	(
		FrgBase_MenuAction* action
	);

	void InsertMenu
	(
		FrgBase_MenuAction* before,
		FrgBase_Menu* menu
	);

	void InsertMenu
	(
		const int positionIndex,
		FrgBase_Menu* menu
	);

	void RemoveMenu
	(
		FrgBase_Menu* menu
	);

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

	std::vector<FrgBase_MenuAction*>
		GetListOfActions
		(
			const bool containingHiddens = true
		) const;

	bool ContainsItem
	(
		FrgBase_MenuAction* action
	) const;

public slots:

	void MenuTitleChangedSlot(const QString& name);

protected:

	void ReArrangeItems();

protected:

	bool theHasTitleAsAnAction_;
};

EndForgBaseLib

#endif // !_FrgBase_Menu_Header
