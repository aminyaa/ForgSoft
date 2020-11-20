#pragma once
#ifndef _FrgBase_SerialSpec_QColor_Header
#define _FrgBase_SerialSpec_QColor_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Serialization_Global.hxx>

#include <QtGui/QColor>

BOOST_SERIALIZATION_SPLIT_FREE(QColor)

DECLARE_SAVE_LOAD_HEADER_SPEC(QColor)

BOOST_CLASS_EXPORT_KEY(QColor)

#endif // !_FrgBase_SerialSpec_QColor_Header
