#pragma once
#ifndef _FrgVisual_SerialSpec_vtkProperty_Header
#define _FrgVisual_SerialSpec_vtkProperty_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Serialization_Global.hxx>

#include <vtkProperty.h>

BOOST_SERIALIZATION_SPLIT_FREE(vtkProperty)

DECLARE_SAVE_LOAD_HEADER_SPEC(vtkProperty)

SERIALIZE_VTKSMARTPOINTER(vtkProperty)

BOOST_CLASS_EXPORT_KEY(vtkProperty)

#endif // !_FrgVisual_SerialSpec_vtkProperty_Header
