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
	theToolBar_ = FrgNew QToolBar(menuTitle, parentMainWindow);
	
	theHasTitleAsAnAction_ = addTitleAsAnAction;

	if (theHasTitleAsAnAction_)
	{
		theTitleAsAnAction_ = AddItem(menuTitle, FrgFalse);
		theTitleAsAnAction_->setEnabled(FrgFalse);
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
	theToolBar_ = FrgNew QToolBar("", parentMainWindow);
	theHasTitleAsAnAction_ = false;
}

ForgBaseLib::FrgBase_Menu::~FrgBase_Menu()
{
	theParentMainWindow_ = NullPtr;
	FreePointer(theTitleAsAnAction_);
	FreePointer(theToolBar_);
}

ForgBaseLib::FrgBase_MenuAction* ForgBaseLib::FrgBase_Menu::AddItem
(
	const QString & itemTitle,
	const bool isInToolBar
)
{
	auto action = new FrgBase_MenuAction(QMainWindow::tr(itemTitle.toLocal8Bit().data()), this);

	action->SetIndex(actions().size());

	this->addAction(action);

	if (isInToolBar)
		theToolBar_->addAction(action);

	return action;
}

ForgBaseLib::FrgBase_MenuAction* ForgBaseLib::FrgBase_Menu::AddItem
(
	const QString & iconAddress,
	const QString & itemTitle,
	const bool isInToolBar
)
{
	QIcon icon(iconAddress);
	auto action = AddItem(itemTitle, isInToolBar);
	action->setIcon(icon);

	return action;
}

ForgBaseLib::FrgBase_MenuAction* ForgBaseLib::FrgBase_Menu::AddItem
(
	const QIcon& icon,
	const QString & itemTitle,
	const bool isInToolBar
)
{
	auto action = AddItem(itemTitle, isInToolBar);
	action->setIcon(icon);

	return action;
}

ForgBaseLib::FrgBase_MenuAction* ForgBaseLib::FrgBase_Menu::GetItem
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

void ForgBaseLib::FrgBase_Menu::MenuTitleChangedSlot(const QString& name)
{
	this->setTitle(name);

	if (theTitleAsAnAction_)
		theTitleAsAnAction_->setText(name);
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

std::vector<QAction*>
ForgBaseLib::FrgBase_Menu::GetListOfActions
(
	const bool containingHiddens
) const
{
	std::vector<QAction*> result;

	for (auto action : actions())
	{
		auto act = dynamic_cast<FrgBase_MenuAction*>(action);
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
		else
			result.push_back(act);
	}

	return result;
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
	auto items = GetListOfActions(false);

	int i = HasTitleAsAnAction() ? 2 : 0;

	if (items.size() > i)
		this->exec(pos);
}