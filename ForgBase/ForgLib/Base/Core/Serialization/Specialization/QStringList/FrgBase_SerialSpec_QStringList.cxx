#include <FrgBase_SerialSpec_QStringList.hxx>

#include <FrgBase_SerialSpec_QString.hxx>

#include <QtCore/QVector>

DECLARE_SAVE_IMP_SPEC(QStringList)
{
	std::vector<QString> myDataList = m.toVector().toStdVector();

	ar& myDataList;
}

DECLARE_LOAD_IMP_SPEC(QStringList)
{
	std::vector<QString> myDataList;

	ar& myDataList;

	for (int i = 0; i < myDataList.size(); i++)
	{
		m << myDataList[i];
	}
}

BOOST_CLASS_EXPORT_CXX_SPEC(QStringList)