#include <FrgBase_SerialSpec_QTreeWidgetItem.hxx>
#include <FrgBase_SerialSpec_QIcon.hxx>
#include <FrgBase_SerialSpec_QString.hxx>

DECLARE_SAVE_IMP_SPEC(QTreeWidgetItem)
{
	int nbColumns = m.columnCount();
	ar & nbColumns;

	for (int iColumn = 0; iColumn < nbColumns; iColumn++)
	{
		ar & m.icon(iColumn);
		ar & m.text(iColumn);
	}
}

DECLARE_LOAD_IMP_SPEC(QTreeWidgetItem)
{
	int nbColumns;
	ar & nbColumns;

	for (int iColumn = 0; iColumn < nbColumns; iColumn++)
	{
		QIcon icon;
		QString text;

		ar & icon;
		ar & text;

		m.setIcon(iColumn, icon);
		m.setText(iColumn, text);
	}
}

BOOST_CLASS_EXPORT_CXX_SPEC(QTreeWidgetItem)