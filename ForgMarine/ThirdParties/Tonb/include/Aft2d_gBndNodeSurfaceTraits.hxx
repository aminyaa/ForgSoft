#pragma once
#ifndef _Aft2d_gBndNodeSurfaceTraits_Header
#define _Aft2d_gBndNodeSurfaceTraits_Header

#include <Aft2d_BndNodeSurfaceTraits.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>

namespace tnbLib
{
	// Forward Declarations
	class GModel_ParaCurve;

	template<class CrvEntity, class SizeFun, class MetricFun>
	class Mesh_PlnCurve;

	struct Aft2d_gBndNodeSurfaceTraits
	{

		typedef Aft2d_BndNodeSurfaceTraits bndNodeTraits;

		typedef Mesh_PlnCurve<GModel_ParaCurve, Geo2d_SizeFunction, Geo2d_MetricFunction> curveType;
		typedef void surfType;
	};
}

#endif // !_Aft2d_gBndNodeSurfaceTraits_Header