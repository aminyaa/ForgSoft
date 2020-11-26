#pragma once
#ifndef _FrgBase_SerialSpec_QStringList_Header
#define _FrgBase_SerialSpec_QStringList_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Serialization_Global.hxx>

#include <QtCore/QStringList>

BOOST_SERIALIZATION_SPLIT_FREE(QStringList)

DECLARE_SAVE_LOAD_HEADER_SPEC(QStringList)

BOOST_CLASS_EXPORT_KEY(QStringList)

#endif // !_FrgBase_SerialSpec_QStringList_Header
