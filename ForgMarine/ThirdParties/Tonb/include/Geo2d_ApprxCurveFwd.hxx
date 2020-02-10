#pragma once
#ifndef _Geo2d_ApprxCurveFwd_Header
#define _Geo2d_ApprxCurveFwd_Header

#include <Standard_Handle.hxx>

class Geom2d_Curve;

namespace tnbLib
{

	// Forward Declarations
	template<class CurveType, bool RandSamples>
	class Geo_ApprxCurve;

	typedef Geo_ApprxCurve<Handle(Geom2d_Curve), true>
		Geo2d_ApprxCurve;
}

#endif // !_Geo2d_ApprxCurveFwd_Header
