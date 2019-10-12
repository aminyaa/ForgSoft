#pragma once
#ifndef _Leg_DispNo1_Dim_Header
#define _Leg_DispNo1_Dim_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{

	namespace Leg_DispNo1
	{

		static const Standard_Integer LEVEL_OF_SMOOTHING(3);
		static const Standard_Real SMOOTHING_WEIGHT(0.25);

		static const Standard_Integer MIN_NB_SECTIONS(5);
		static const Standard_Integer MAX_NB_SECTIONS(100);

		static const Standard_Real MAX_FLARE(1.0);
		static const Standard_Real MIN_FLARE(1.0E-4);

		static const Standard_Real MAX_BOW_ROUNDING(1.0);
		static const Standard_Real MIN_BOW_ROUNDING(0.01);

		static const Standard_Real MAX_SIDESLOPE_COEFF(0.9);
		static const Standard_Real MAX_DEADRISE_COEFF(0.5);

		static const Standard_Real MIN_DIST_COEFF(0.05);
	}
}

#endif // !_Leg_DispNo1_Dim_Header
