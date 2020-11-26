#pragma once
#ifndef _Geo3d_ApprxCurveFwd_Header
#define _Geo3d_ApprxCurveFwd_Header

#include <Standard_Handle.hxx>

class Geom_Curve;

namespace tnbLib
{

	// Forward Declarations
	template<class CurveType, bool RandSamples>
	class Geo_ApprxCurve;

	typedef Geo_ApprxCurve<Handle(Geom_Curve), true>
		Geo3d_ApprxCurve;
}

#endif // !_Geo3d_ApprxCurveFwd_Header