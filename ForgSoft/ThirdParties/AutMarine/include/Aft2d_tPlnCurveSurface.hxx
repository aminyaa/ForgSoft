#pragma once
#ifndef _Aft2d_tPlnCurveSurface_Header
#define _Aft2d_tPlnCurveSurface_Header

#include <Aft2d_PlnCurveAnIso_Base.hxx>
#include <Aft2d_tSegmentEdgeFwd.hxx>
#include <TModel_parCurve.hxx>

namespace AutLib
{

	typedef Mesh_PlnCurve<TModel_parCurve, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_tPlnCurveSurface;

	template<>
	template<>
	static std::vector<std::shared_ptr<Aft2d_tSegmentEdge>>
		Aft2d_tPlnCurveSurface::TopoMesh<Aft2d_tSegmentEdge>
		(
			const std::shared_ptr<Aft2d_tPlnCurveSurface>& theCurve,
			const std::shared_ptr<Geo2d_MetricPrcsrAnIso>& theMap,
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
			);
}

#endif // !_Aft2d_tPlnCurveSurface_Header
