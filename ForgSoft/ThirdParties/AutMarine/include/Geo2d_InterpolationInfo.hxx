#pragma once
#ifndef _Geo2d_InterpolationInfo_Header
#define _Geo2d_InterpolationInfo_Header

#include <Global_AccessMethod.hxx>
#include <Standard_TypeDef.hxx>

namespace AutLib
{

	class Geo2d_InterpolationInfo
	{

		/*Private Data*/

		Standard_Real theTolerance_;

		Standard_Boolean thePeriodicFlag_;

	public:

		static const Standard_Real DEFAULT_TOLERANCE;

		Geo2d_InterpolationInfo()
			: theTolerance_(DEFAULT_TOLERANCE)
			, thePeriodicFlag_(Standard_False)
		{}

		//- Macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Tolerance)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Boolean, PeriodicFlag)
	};
}

#endif // !_Geo2d_InterpolationInfo_Header
