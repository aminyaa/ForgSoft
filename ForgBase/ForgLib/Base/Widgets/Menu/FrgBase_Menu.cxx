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
	, theParentMainWindow_(parentMainWindow)
{
	theToolBar_ = FrgNew QToolBar(menuTitle, parentMainWindow);
	
	if (addTitleAsAnAction)
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
}

ForgBaseLib::FrgBase_Menu::FrgBase_Menu
(
	FrgBase_MainWindow * parentMainWindow
)
	: QMenu(parentMainWindow)
{
	theToolBar_ = FrgNew QToolBar("", parentMainWindow);
}

ForgBaseLib::FrgBase_Menu::~FrgBase_Menu()
{
	theParentMainWindow_ = NullPtr;
	FreePointer(theTitleAsAnAction_);
	FreePointer(theToolBar_);
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

void ForgBaseLib::FrgBase_Menu::MenuTitleChangedSlot(const QString& name)
{
	this->setTitle(name);

	if (theTitleAsAnAction_)
		theTitleAsAnAction_->setText(name);
}

void ForgBaseLib::FrgBase_Menu::SetToolBarHidden(bool condition)
{
	theToolBar_->setHidden(condition);
}