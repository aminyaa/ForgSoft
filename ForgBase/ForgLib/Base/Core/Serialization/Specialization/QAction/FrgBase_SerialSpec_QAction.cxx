#include <FrgBase_SerialSpec_QAction.hxx>
#include <FrgBase_SerialSpec_QIcon.hxx>
#include <FrgBase_SerialSpec_QString.hxx>

DECLARE_SAVE_IMP_SPEC(QAction)
{
	QString myActionType = "";

	if (m.isSeparator())
	{
		myActionType = FRG_ACTION_SEPERATOR;
		ar & myActionType;
	}
	else
	{
		myActionType = FRG_ACTION_ACTION;
		ar & myActionType;

		ar & m.icon();
		ar & m.text();
	}
}

DECLARE_LOAD_IMP_SPEC(QAction)
{
	QString myActionType = "";

	ar & myActionType;

	if (myActionType == FRG_ACTION_SEPERATOR)
	{
		m.setSeparator(true);
	}
	else if (myActionType == FRG_ACTION_ACTION)
	{
		QIcon icon;
		QString text;

		ar & icon;
		ar & text;

		m.setText(text);
		m.setIcon(icon);
	}
}

BOOST_CLASS_EXPORT_CXX_SPEC(QAction)