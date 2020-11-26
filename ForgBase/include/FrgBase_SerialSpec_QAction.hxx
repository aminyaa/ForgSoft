#pragma once
#ifndef _FrgBase_SerialSpec_QAction_Header
#define _FrgBase_SerialSpec_QAction_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Serialization_Global.hxx>

#include <QtWidgets/QAction>

BOOST_SERIALIZATION_SPLIT_FREE(QAction)

#define FRG_ACTION_SEPERATOR "FRG_ACTION_SEPERATOR"
#define FRG_ACTION_ACTION "FRG_ACTION_ACTION"

DECLARE_SAVE_LOAD_HEADER_SPEC(QAction)

BOOST_CLASS_EXPORT_KEY(QAction)

#endif // !_FrgBase_SerialSpec_QAction_Header
