#pragma once
#ifndef _CadRepair_ApproxSurfMetric_Info_Header
#define _CadRepair_ApproxSurfMetric_Info_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

namespace AutLib
{

	class CadRepair_ApproxSurfMetric_Info
	{

		/*Private Data*/

		Standard_Integer theMinLevel_;
		Standard_Integer theMaxLevel_;

		Standard_Real theTolerance_;
		Standard_Real theDegeneracy_;

	public:

		//- Static parameters

		static const Standard_Integer MIN_LEVEL;
		static const Standard_Integer MAX_LEVEL;

		static const Standard_Real DEFAULT_TOLERANCE;
		static const Standard_Real DEFAULT_DEGENERACY;


		//- constructors

		CadRepair_ApproxSurfMetric_Info();

		//- Macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, MinLevel)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, MaxLevel)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Tolerance)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Degeneracy)
	};
}

#endif // !_CadRepair_ApproxSurfMetric_Info_Header
