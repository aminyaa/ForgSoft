#pragma once
#ifndef _FrgBase_SerialSpec_QTableWidget_Header
#define _FrgBase_SerialSpec_QTableWidget_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Serialization_Global.hxx>

#include <QtWidgets/QTableWidget>

BOOST_SERIALIZATION_SPLIT_FREE(QTableWidget)

DECLARE_SAVE_LOAD_HEADER_SPEC(QTableWidget)

BOOST_CLASS_EXPORT_KEY(QTableWidget)

#endif // !_FrgBase_SerialSpec_QTableWidget_Header
