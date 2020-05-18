#include <FrgBase_SerialSpec_QMenu.hxx>
#include <FrgBase_SerialSpec_QAction.hxx>
#include <FrgBase_SerialSpec_QIcon.hxx>
#include <FrgBase_SerialSpec_QString.hxx>

DECLARE_SAVE_IMP_SPEC(QMenu)
{
	ar & m.icon();
	ar & m.title();

	int nbActions = m.actions().size();
	ar & nbActions;

	for (int iAction = 0; iAction < nbActions; iAction++)
	{
		QString myActionType = "";

		if (m.actions()[iAction]->menu())
		{
			myActionType = FRG_ACTION_MENU;
			ar & myActionType;

			QMenu* myMenu = m.actions()[iAction]->menu();
			ar & myMenu;
		}
		else
		{
			myActionType = FRG_ACTION_ACTION;
			ar & myActionType;

			ar & (m.actions()[iAction]);
		}
	}
}

DECLARE_LOAD_IMP_SPEC(QMenu)
{
	QIcon icon;
	QString text;

	ar & icon;
	ar & text;

	m.setTitle(text);
	m.setIcon(icon);

	int nbActions;
	ar & nbActions;

	for (int iAction = 0; iAction < nbActions; iAction++)
	{
		QString myActionType = "";
		ar & myActionType;

		if (myActionType == FRG_ACTION_MENU)
		{
			QMenu* mySubMenu;
			ar & mySubMenu;

			m.addMenu(mySubMenu);
		}
		else if (myActionType == FRG_ACTION_ACTION)
		{
			QAction* myAction;
			ar & myAction;

			m.addAction(myAction->icon(), myAction->text());

			delete myAction;
		}
	}
}

BOOST_CLASS_EXPORT_CXX_SPEC(QMenu)