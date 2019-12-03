#pragma once
#ifndef _SingularCurve2d_gPoleSurface_Header
#define _SingularCurve2d_gPoleSurface_Header

#include <SingularCurve2d_PoleAnIso_Base.hxx>
#include <GModel_parCurve.hxx>
#include <Aft2d_BndEdgeSurfaceFwd.hxx>

namespace AutLib
{

	typedef SingularCurve_Pole<GModel_parCurve, Geo2d_SizeFunction, Geo2d_MetricFunction>
		SingularCurve2d_gPoleSurface;

	template<>
	template<>
	static std::vector<std::shared_ptr<Aft2d_BndEdgeSurface>>
		Mesh_PlnCurve<GModel_parCurve, Geo2d_SizeFunction, Geo2d_MetricFunction>::TopoMesh
		<
		Aft2d_BndEdgeSurface, 
		SingularCurve2d_gPoleSurface
		>
		(
			const std::shared_ptr<SingularCurve2d_gPoleSurface>& theCurve,
			const std::shared_ptr<Geo2d_MetricPrcsrAnIso>& theMap,
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
			);
}


#endif // !_SingularCurve2d_gPoleSurface_Header
