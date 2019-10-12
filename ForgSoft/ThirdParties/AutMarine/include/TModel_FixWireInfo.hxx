#pragma once
#ifndef _TModel_FixWireInfo_Header
#define _TModel_FixWireInfo_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

namespace AutLib
{

	class TModel_FixWireInfo
	{

		/*Private Data*/

		Standard_Real thePrecision_;
		Standard_Real theMaxTolerance_;
		Standard_Real theMinTolerance_;

		Standard_Real theTolerance_;

	public:

		static const Standard_Real DEFAULT_PRECISION;
		static const Standard_Real DEFAULT_MAX_TOLERANCE;
		static const Standard_Real DEFAULT_MIN_TOLERANCE;
		static const Standard_Real DEFAULT_TOLERANCE;

		TModel_FixWireInfo()
			: thePrecision_(DEFAULT_PRECISION)
			, theMinTolerance_(DEFAULT_MIN_TOLERANCE)
			, theMaxTolerance_(DEFAULT_MAX_TOLERANCE)
			, theTolerance_(DEFAULT_TOLERANCE)
		{}

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Precision)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, MaxTolerance)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, MinTolerance)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Tolerance)
	};
}

#endif // !_TModel_FixWireInfo_Header
