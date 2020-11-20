#pragma once
#ifndef _FrgBase_SerialSpec_QIcon_Header
#define _FrgBase_SerialSpec_QIcon_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Serialization_Global.hxx>

#include <QtGui/QIcon>

BOOST_SERIALIZATION_SPLIT_FREE(QIcon)

DECLARE_SAVE_LOAD_HEADER_SPEC(QIcon)

BOOST_CLASS_EXPORT_KEY(QIcon)

#endif // !_FrgBase_SerialSpec_QIcon_Header
