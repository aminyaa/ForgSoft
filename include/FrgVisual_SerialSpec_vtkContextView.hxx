#pragma once
#ifndef _FrgVisual_SerialSpec_vtkContextView_Header
#define _FrgVisual_SerialSpec_vtkContextView_Header

#include <FrgVisual_Serialization_Global.hxx>

#include <vtkContextView.h>

BOOST_SERIALIZATION_SPLIT_FREE(vtkContextView)

namespace boost
{
	namespace serialization
	{
		template<class Archive>
		void save(Archive& ar, const vtkContextView& m, const unsigned int version)
		{

		}

		template<class Archive>
		void load(Archive& ar, vtkContextView& m, const unsigned int version)
		{

		}
	}
}

SERIALIZE_VTKSMARTPOINTER(vtkContextView)

#endif // !_FrgVisual_SerialSpec_vtkContextView_Header
