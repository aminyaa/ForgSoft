#pragma once
#ifndef _FrgVisual_SerialSpec_vtkChartXY_Header
#define _FrgVisual_SerialSpec_vtkChartXY_Header

#include <FrgVisual_Serialization_Global.hxx>

#include <vtkChartXY.h>

BOOST_SERIALIZATION_SPLIT_FREE(vtkChartXY)

namespace boost
{
	namespace serialization
	{
		template<class Archive>
		void save(Archive& ar, const vtkChartXY& m, const unsigned int version)
		{
			
		}

		template<class Archive>
		void load(Archive& ar, vtkChartXY& m, const unsigned int version)
		{

		}
	}
}

SERIALIZE_VTKSMARTPOINTER(vtkChartXY)

#endif // !_FrgVisual_SerialSpec_vtkChartXY_Header
