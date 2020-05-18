#include <FrgBase_SerialSpec_QString.hxx>

#include <boost/serialization/string.hpp>

#include <string>

DECLARE_SAVE_IMP_SPEC(QString)
{
	std::string data;
	if (!m.isNull())
		data = m.toStdString();

	ar & data;
}

DECLARE_LOAD_IMP_SPEC(QString)
{
	std::string data;
	ar & data;
	if (!data.empty())
		m = data.c_str();
}

BOOST_CLASS_EXPORT_CXX_SPEC(QString)