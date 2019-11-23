#pragma once
#ifndef _Leg_DuctNo1_Dim_Header
#define _Leg_DuctNo1_Dim_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{

	namespace Leg_DuctNo1
	{
		static const Standard_Integer LEVEL_OF_SMOOTHING(3);

		static const Standard_Real SMOOTH_WEIGHT(0.25);

		static const Standard_Integer MIN_NB_SECTIONS(5);
		static const Standard_Integer MAX_NB_SECTIONS(100);
	}
}

#endif // !_Leg_DuctNo1_Dim_Header
