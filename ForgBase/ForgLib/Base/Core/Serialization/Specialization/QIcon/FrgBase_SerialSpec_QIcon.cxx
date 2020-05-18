#include <FrgBase_SerialSpec_QIcon.hxx>
#include <FrgBase_SerialSpec_QString.hxx>

#include <QtCore/QString>

DECLARE_SAVE_IMP_SPEC(QIcon)
{
	ar & m.themeName();
}

DECLARE_LOAD_IMP_SPEC(QIcon)
{
	QString themeName;

	ar & themeName;

	m.setThemeName(themeName);
}

BOOST_CLASS_EXPORT_CXX_SPEC(QIcon)