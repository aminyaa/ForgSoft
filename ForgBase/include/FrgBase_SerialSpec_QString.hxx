#pragma once
#ifndef _FrgBase_SerialSpec_QString_Header
#define _FrgBase_SerialSpec_QString_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Serialization_Global.hxx>

#include <QtCore/QString>

BOOST_SERIALIZATION_SPLIT_FREE(QString)

DECLARE_SAVE_LOAD_HEADER_SPEC(QString)

//namespace boost
//{
//	namespace serialization
//	{
//		template<class Archive>
//		void save(Archive& ar, const QString& m, const unsigned int version);
//		template<class Archive>
//		void load(Archive& ar, QString& m, const unsigned int version);
//	}
//}

BOOST_CLASS_EXPORT_KEY(QString)

#endif // !_FrgBase_SerialSpec_QString_Header
