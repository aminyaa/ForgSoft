#pragma once
#ifndef _Aft2d_tBndNodeSurfaceTraits_Header
#define _Aft2d_tBndNodeSurfaceTraits_Header

#include <Aft2d_BndNodeSurfaceTraits.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>

namespace tnbLib
{
	// Forward Declarations
	class TModel_ParaCurve;

	template<class CrvEntity, class SizeFun, class MetricFun>
	class Mesh_PlnCurve;

	struct Aft2d_tBndNodeSurfaceTraits
	{

		typedef Aft2d_BndNodeSurfaceTraits bndNodeTraits;

		typedef Mesh_PlnCurve<TModel_ParaCurve, Geo2d_SizeFunction, Geo2d_MetricFunction> curveType;
		typedef void surfType;
	};
}

#endif // !_Aft2d_tBndNodeSurfaceTraits_Header