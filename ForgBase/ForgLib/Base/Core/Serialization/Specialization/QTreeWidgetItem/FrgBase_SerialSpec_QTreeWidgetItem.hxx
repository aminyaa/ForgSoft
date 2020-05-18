#pragma once
#ifndef _FrgBase_SerialSpec_QTreeWidgetItem_Header
#define _FrgBase_SerialSpec_QTreeWidgetItem_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Serialization_Global.hxx>

#include <QtWidgets/QTreeWidgetItem>

BOOST_SERIALIZATION_SPLIT_FREE(QTreeWidgetItem)

class QTreeWidgetItem;

DECLARE_SAVE_LOAD_HEADER_SPEC(QTreeWidgetItem)

BOOST_CLASS_EXPORT_KEY(QTreeWidgetItem)

#endif // !_FrgBase_SerialSpec_QTreeWidgetItem_Header
