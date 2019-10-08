#include <FrgMenu.hxx>
#include <FrgMainWindow.hxx>

#include <QtWidgets/QToolBar>

ForgBaseLib::FrgMenu::FrgMenu(const FrgString& title, FrgMainWindow* parentMainWindow)
	: QMenu(QMainWindow::tr(title.toLocal8Bit().data()), parentMainWindow)
	, theParentMainWindow_(parentMainWindow)
{
	FrgString str = title;
	str.remove('&');
	this->setObjectName(str);

	theToolBar_ = FrgNew QToolBar(str + " Toolbar", parentMainWindow);
}

ForgBaseLib::FrgMenu::FrgMenu(FrgMainWindow* parentMainWindow)
	: FrgMenu("", parentMainWindow)
{
}

void ForgBaseLib::FrgMenu::AddItem(const FrgString& title)
{
	FrgString str = title;
	str.remove('&');
	QAction* action = FrgNew QAction(QMainWindow::tr(title.toLocal8Bit().data()), this);
	action->setObjectName(this->objectName() + "_" + str);

	this->addAction(action);

	theItems_.push_back(action);

	if (theItemIsInToolBarCondition_)
		theToolBar_->addAction(action);
}

void ForgBaseLib::FrgMenu::AddItem(const FrgString& iconAddress, const FrgString& title)
{
	AddItem(title);

	theItems_.at(theItems_.size() - 1)->setIcon(QIcon(iconAddress));
}

void ForgBaseLib::FrgMenu::AddItem(const FrgString& iconAddress, const FrgString& title, const FrgString& shortcut, FrgBool isInToolbar)
{
	theItemIsInToolBarCondition_ = isInToolbar;

	AddItem(iconAddress, title);

	theItems_.at(theItems_.size() - 1)->setShortcut(QMainWindow::tr(shortcut.toLocal8Bit().data()));
}

void ForgBaseLib::FrgMenu::SetEnabledItem(const FrgString& title, FrgBool condition)
{
	for (FrgInt i = 0; i < theItems_.size(); i++)
	{
		if (theItems_.at(i)->objectName() == (this->objectName() + "_" + title))
		{
			theItems_.at(i)->setEnabled(condition);
			return;
		}
	}
}

QAction* ForgBaseLib::FrgMenu::GetItem(const FrgString& title)
{
	for (FrgInt i = 0; i < theItems_.size(); i++)
	{
		if (theItems_.at(i)->objectName() == (this->objectName() + "_" + title))
		{
			return theItems_.at(i);
		}
	}
}