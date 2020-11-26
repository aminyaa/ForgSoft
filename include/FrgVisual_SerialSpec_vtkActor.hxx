#pragma once
#ifndef _FrgVisual_SerialSpec_vtkActor_Header
#define _FrgVisual_SerialSpec_vtkActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Serialization_Global.hxx>

#include <vtkActor.h>

BOOST_SERIALIZATION_SPLIT_FREE(vtkActor)

DECLARE_SAVE_LOAD_HEADER_SPEC(vtkActor)

SERIALIZE_VTKSMARTPOINTER(vtkActor)

BOOST_CLASS_EXPORT_KEY(vtkActor)

#endif // !_FrgVisual_SerialSpec_vtkActor_Header
