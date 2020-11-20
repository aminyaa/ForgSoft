#pragma once
#ifndef _FrgBase_SerialSpec_QMenu_Header
#define _FrgBase_SerialSpec_QMenu_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Serialization_Global.hxx>

#include <QtWidgets/QMenu>

BOOST_SERIALIZATION_SPLIT_FREE(QMenu)

#define FRG_ACTION_MENU "FRG_ACTION_MENU"

DECLARE_SAVE_LOAD_HEADER_SPEC(QMenu)

BOOST_CLASS_EXPORT_KEY(QMenu)

#endif // !_FrgBase_SerialSpec_QMenu_Header
