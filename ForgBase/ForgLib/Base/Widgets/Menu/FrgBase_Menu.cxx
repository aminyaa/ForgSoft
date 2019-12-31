#include <FrgBase_Menu.hxx>
#include <FrgBase_MainWindow.hxx>

#include <QtWidgets/QToolBar>
#include <QtWidgets/QAction>

ForgBaseLib::FrgBase_Menu::FrgBase_Menu
(
	const FrgString & menuTitle,
	FrgBase_MainWindow * parentMainWindow,
	FrgBool addTitleAsAnAction
)
	: QMenu(menuTitle, parentMainWindow)
{
	theToolBar_ = FrgNew QToolBar(menuTitle, parentMainWindow);
	
	if (addTitleAsAnAction)
	{
		auto action = AddItem(menuTitle, FrgFalse);
		action->setEnabled(FrgFalse);
		action->font().setBold(true);
		action->font().setItalic(true);
		action->font().setUnderline(true);
		this->addSeparator();
	}
}

ForgBaseLib::FrgBase_Menu::FrgBase_Menu
(
	FrgBase_MainWindow * parentMainWindow
)
	: QMenu(parentMainWindow)
{
	theToolBar_ = FrgNew QToolBar("", parentMainWindow);
}

QAction* ForgBaseLib::FrgBase_Menu::AddItem
(
	const FrgString & itemTitle,
	FrgBool isInToolBar
)
{
	QAction* action = FrgNew QAction(QMainWindow::tr(itemTitle.toLocal8Bit().data()), this);
	this->addAction(action);

	if (isInToolBar)
		theToolBar_->addAction(action);

	return action;
}

QAction* ForgBaseLib::FrgBase_Menu::AddItem
(
	const FrgString & iconAddress,
	const FrgString & itemTitle,
	FrgBool isInToolBar
)
{
	QIcon icon(iconAddress);
	auto action = AddItem(itemTitle, isInToolBar);
	action->setIcon(icon);

	return action;
}

QAction* ForgBaseLib::FrgBase_Menu::AddItem
(
	QIcon icon,
	const FrgString & itemTitle,
	FrgBool isInToolBar
)
{
	auto action = AddItem(itemTitle, isInToolBar);
	action->setIcon(icon);

	return action;
}

QAction* ForgBaseLib::FrgBase_Menu::GetItem
(
	const FrgString & itemTitle
)
{
	auto listOfActions = this->actions();

	for (int iAction = 0; iAction < listOfActions.size(); iAction++)
	{
		if (listOfActions[iAction]->text() == itemTitle)
			return listOfActions[iAction];
	}
	return NullPtr;
}