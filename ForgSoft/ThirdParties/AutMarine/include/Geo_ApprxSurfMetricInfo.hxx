#pragma once
#ifndef _Geo_ApprxSurfMetricInfo_Header
#define _Geo_ApprxSurfMetricInfo_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

namespace AutLib
{

	class Geo_ApprxSurfMetricInfo
	{

		/*Private Data*/

		Standard_Integer theMinLevel_;
		Standard_Integer theMaxLevel_;

		Standard_Real theTolerance_;
		Standard_Real theDegeneracy_;

	public:

		static const Standard_Integer MIN_LEVEL;
		static const Standard_Integer MAX_LEVEL;

		static const Standard_Real DEFAULT_TOLERANCE;
		static const Standard_Real DEFAULT_DEGENERACY;

		Geo_ApprxSurfMetricInfo()
			: theMinLevel_(MIN_LEVEL)
			, theMaxLevel_(MAX_LEVEL)
			, theTolerance_(DEFAULT_TOLERANCE)
			, theDegeneracy_(DEFAULT_DEGENERACY)
		{}

		//- Macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, MinLevel)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, MaxLevel)

			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Tolerance)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Degeneracy)
	};
}

#endif // !_Geo_ApprxSurfMetricInfo_Header
