#pragma once
#ifndef _SingularCurve2d_tLineSurface_Header
#define _SingularCurve2d_tLineSurface_Header

#include <SingularCurve2d_LineAnIso_Base.hxx>
#include <TModel_parCurve.hxx>
#include <Aft2d_BndEdgeSurfaceFwd.hxx>

namespace AutLib
{

	typedef SingularCurve_Line<TModel_parCurve, Geo2d_SizeFunction, Geo2d_MetricFunction>
		SingularCurve2d_tLineSurface;

	template<>
	template<>
	static std::vector<std::shared_ptr<Aft2d_BndEdgeSurface>>
		Mesh_PlnCurve<TModel_parCurve, Geo2d_SizeFunction, Geo2d_MetricFunction>::TopoMesh
		<
		Aft2d_BndEdgeSurface,
		SingularCurve2d_tLineSurface
		>
		(
			const std::shared_ptr<SingularCurve2d_tLineSurface>& theCurve,
			const std::shared_ptr<Geo2d_MetricPrcsrAnIso>& theMap,
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
			);
}

#endif // !_SingularCurve2d_tLineSurface_Header
