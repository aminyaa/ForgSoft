#pragma once
#ifndef _Cad_Curve_Header
#define _Cad_Curve_Header

#include <Standard_Handle.hxx>
#include <Global_AccessMethod.hxx>
#include <Entity2d_BoxFwd.hxx>

namespace AutLib
{

	template<class gCurveType>
	class Cad_Curve
	{

		/*Private Data*/

		Handle(gCurveType) theCurve_;

		Standard_Real theFirstParam_;
		Standard_Real theLastParam_;

	public:

		Cad_Curve()
		{}

		Cad_Curve
		(
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const Handle(gCurveType)& theCurve
		)
			: theFirstParam_(theFirst)
			, theLastParam_(theLast)
			, theCurve_(theCurve)
		{}

		GLOBAL_ACCESS_SINGLE(Handle(gCurveType), Curve)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, FirstParam)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, LastParam)
	};
}

#endif // !_Cad_Curve_Header
