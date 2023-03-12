#include <FrgBase_Menu.hxx>
#include <FrgBase_MenuAction.hxx>
#include <FrgBase_MainWindow.hxx>

#include <QtWidgets/QToolBar>

ForgBaseLib::FrgBase_Menu::FrgBase_Menu
(
	const QString & menuTitle,
	FrgBase_MainWindow * parentMainWindow,
	const bool addTitleAsAnAction
)
	: QMenu(menuTitle, parentMainWindow)
	, theParentMainWindow_(parentMainWindow)
{
	theToolBar_ = new QToolBar(menuTitle, parentMainWindow);
	
	theHasTitleAsAnAction_ = addTitleAsAnAction;

	if (theHasTitleAsAnAction_)
	{
		theTitleAsAnAction_ = AddItem(menuTitle, false);
		theTitleAsAnAction_->setEnabled(false);
		QFont myFont;
		myFont.setBold(true);
		myFont.setItalic(true);
		myFont.setLetterSpacing(QFont::SpacingType::AbsoluteSpacing, 2);
		theTitleAsAnAction_->setFont(myFont);
		this->addSeparator();
	}

	SetToolBarHidden(true);
}

ForgBaseLib::FrgBase_Menu::FrgBase_Menu
(
	FrgBase_MainWindow * parentMainWindow
)
	: QMenu(parentMainWindow)
{
	theToolBar_ = new QToolBar("", parentMainWindow);
	theHasTitleAsAnAction_ = false;
}

ForgBaseLib::FrgBase_Menu::~FrgBase_Menu()
{
	theParentMainWindow_ = nullptr;
	FreePointer(theTitleAsAnAction_);
	FreePointer(theToolBar_);
}

ForgBaseLib::FrgBase_Menu*
ForgBaseLib::FrgBase_Menu::AddMenu
(
	const QString& menuTitle,
	const int addTitleAsAnAction,
	const int positionIndex
)
{
	auto menu =
		new FrgBase_Menu
		(
			menuTitle,
			theParentMainWindow_,
			addTitleAsAnAction
		);

	InsertMenu(positionIndex, menu);

	return menu;
}

ForgBaseLib::FrgBase_MenuAction*
ForgBaseLib::FrgBase_Menu::AddItem
(
	const QString & itemTitle,
	const int isInToolBar,
	const int positionIndex
)
{
	auto action =
		new FrgBase_MenuAction
		(
			QMainWindow::tr(itemTitle.toLocal8Bit().data()),
			this
		);

	InsertItem(positionIndex, action);

	if (isInToolBar)
		theToolBar_->addAction(action);

	return action;
}

ForgBaseLib::FrgBase_MenuAction*
ForgBaseLib::FrgBase_Menu::AddItem
(
	const QString & iconAddress,
	const QString & itemTitle,
	const int isInToolBar,
	const int positionIndex
)
{
	QIcon icon(iconAddress);
	auto action = AddItem(itemTitle, isInToolBar, positionIndex);
	action->setIcon(icon);

	return action;
}

ForgBaseLib::FrgBase_MenuAction*
ForgBaseLib::FrgBase_Menu::AddItem
(
	const QIcon& icon,
	const QString & itemTitle,
	const int isInToolBar,
	const int positionIndex
)
{
	auto action = AddItem(itemTitle, isInToolBar, positionIndex);
	action->setIcon(icon);

	return action;
}

ForgBaseLib::FrgBase_MenuAction*
ForgBaseLib::FrgBase_Menu::GetItem
(
	const QString & itemTitle
)
{
	auto listOfActions = this->actions();

	for (int iAction = 0; iAction < listOfActions.size(); iAction++)
	{
		auto action = listOfActions[iAction];

		if (action->text() == itemTitle)
			return dynamic_cast<FrgBase_MenuAction*>(action);
	}

	return nullptr;
}

int ForgBaseLib::FrgBase_Menu::GetIndexUsingItem
(
	FrgBase_MenuAction* action
)
{
	auto actions =
		GetListOfActions(true);

	int i = 0;
	for (auto act : actions)
	{
		if (act == action)
			return i;

		i++;
	}

	return -1;
}

void ForgBaseLib::FrgBase_Menu::MenuTitleChangedSlot(const QString& name)
{
	this->setTitle(name);

	if (theTitleAsAnAction_)
		theTitleAsAnAction_->setText(name);
}

void ForgBaseLib::FrgBase_Menu::InsertItem
(
	FrgBase_MenuAction* before,
	FrgBase_MenuAction* action
)
{
	if (ContainsItem(before))
		RemoveItem(before);

	if (!before)
		this->addAction(action);
	else
		this->insertAction(before, action);

	ReArrangeItems();
}

void ForgBaseLib::FrgBase_Menu::InsertItem
(
	const int positionIndex,
	FrgBase_MenuAction* action
)
{
	if (!action)
		return;

	auto actions =
		GetListOfActions(true);

	if (actions.empty() || positionIndex <= -1 || positionIndex >= (int)actions.size())
	{
		InsertItem
		(
			nullptr,
			action
		);
	}
	else
	{
		InsertItem
		(
			actions[positionIndex],
			action
		);
	}
}

void ForgBaseLib::FrgBase_Menu::RemoveItem
(
	FrgBase_MenuAction* action
)
{
	if (!action)
		return;

	auto actions =
		GetListOfActions(true);

	for (auto act : actions)
	{
		if (action == act)
		{
			this->removeAction(act);

			break;;
		}
	}

	ReArrangeItems();
}

void ForgBaseLib::FrgBase_Menu::InsertMenu
(
	FrgBase_MenuAction* before,
	FrgBase_Menu* menu
)
{
	if (!menu)
		return;

	if (before)
		this->addMenu(menu);
	else
		this->insertMenu(before, menu);
}

void ForgBaseLib::FrgBase_Menu::InsertMenu
(
	const int positionIndex,
	FrgBase_Menu* menu
)
{
	if (!menu)
		return;

	auto actions =
		GetListOfActions(true);

	if (positionIndex <= -1 || actions.empty() || positionIndex >= (int)actions.size())
		InsertMenu(nullptr, menu);
	else
		InsertMenu(actions[positionIndex], menu);
}

void ForgBaseLib::FrgBase_Menu::RemoveMenu
(
	FrgBase_Menu* menu
)
{
	if (!menu)
		return;

	auto menuToBeRemoved =
		menu->menuAction();

	this->removeAction(menuToBeRemoved);
}

void ForgBaseLib::FrgBase_Menu::SetToolBarHidden(const bool condition)
{
	if (!condition)
	{
		if (theToolBar_->actions().isEmpty())
			return;
	}

	theToolBar_->setHidden(condition);
}

std::vector<ForgBaseLib::FrgBase_MenuAction*>
ForgBaseLib::FrgBase_Menu::GetListOfActions
(
	const bool containingHiddens
) const
{
	std::vector<FrgBase_MenuAction*> result;

	for (auto action : actions())
	{
		auto act =
			dynamic_cast<FrgBase_MenuAction*>(action);

		if (act)
		{
			if (!containingHiddens)
			{
				if(!act->IsHidden())
					result.push_back(act);
			}
			else
				result.push_back(act);
		}
	}

	return result;
}

bool ForgBaseLib::FrgBase_Menu::ContainsItem
(
	FrgBase_MenuAction* action
) const
{
	if (!action)
		return false;

	auto actions =
		GetListOfActions(true);
	
	for (auto act : actions)
	{
		if (action == act)
			return true;
	}

	return false;
}

void ForgBaseLib::FrgBase_Menu::Execute()
{
	QPoint point;

	Execute(point);
}

void ForgBaseLib::FrgBase_Menu::Execute
(
	const QPoint& pos,
	QAction* at
)
{
	//auto items = GetListOfActions(false);
	std::vector<QAction*> items;
	for (auto action : actions())
	{
		const bool c1 = action->text().isEmpty();
		const bool c2 = action->isVisible();
		if (!c1 && c2)
			items.push_back(action);
	}

	int i = HasTitleAsAnAction() ? 2 : 0;

	if (items.size() > i)
		this->exec(pos);
}

void ForgBaseLib::FrgBase_Menu::ReArrangeItems()
{
	auto actions =
		GetListOfActions(true);

	int i = 0;
	for (auto action : actions)
		action->SetIndex(i++);
}