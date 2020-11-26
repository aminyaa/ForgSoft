#pragma once
#ifndef _Aft2d_TBndNodeAnIsoTraits_Header
#define _Aft2d_TBndNodeAnIsoTraits_Header

#include <Aft2d_BndNodeAnIsoTraits.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>

namespace tnbLib
{

	// Forward Declarations
	class Pln_Curve;

	template<class CrvEntity, class SizeFun, class MetricFun>
	class Mesh_PlnCurve;

	struct Aft2d_TBndNodeAnIsoTraits
	{

		typedef Aft2d_BndNodeAnIsoTraits bndNodeTraits;

		typedef Mesh_PlnCurve<Pln_Curve, Geo2d_SizeFunction, Geo2d_MetricFunction> curveType;
		typedef void surfType;
	};
}

#endif // !_Aft2d_TBndNodeAnIsoTraits_Header