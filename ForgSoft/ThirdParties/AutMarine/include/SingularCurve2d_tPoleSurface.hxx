#pragma once
#ifndef _SingularCurve2d_tPoleSurface_Header
#define _SingularCurve2d_tPoleSurface_Header

#include <SingularCurve2d_PoleAnIso_Base.hxx>
#include <TModel_parCurve.hxx>
#include <Aft2d_BndEdgeSurfaceFwd.hxx>

namespace AutLib
{

	typedef SingularCurve_Pole<TModel_parCurve, Geo2d_SizeFunction, Geo2d_MetricFunction>
		SingularCurve2d_tPoleSurface;

	template<>
	template<>
	static std::vector<std::shared_ptr<Aft2d_BndEdgeSurface>>
		Mesh_PlnCurve<TModel_parCurve, Geo2d_SizeFunction, Geo2d_MetricFunction>::TopoMesh
		<
		Aft2d_BndEdgeSurface,
		SingularCurve2d_tPoleSurface
		>
		(
			const std::shared_ptr<SingularCurve2d_tPoleSurface>& theCurve,
			const std::shared_ptr<Geo2d_MetricPrcsrAnIso>& theMap,
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
			);
}

#endif // !_SingularCurve2d_tPoleSurface_Header
