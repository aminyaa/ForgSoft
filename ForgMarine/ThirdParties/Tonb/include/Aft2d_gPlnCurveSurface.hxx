#pragma once
#ifndef _Aft2d_gPlnCurveSurface_Header
#define _Aft2d_gPlnCurveSurface_Header

#include <Aft2d_PlnCurveAnIso_Base.hxx>
#include <Aft2d_gSegmentEdgeFwd.hxx>
#include <GModel_ParaCurve.hxx>

namespace tnbLib
{

	// Forward Declarations
	class GModel_ParaCurve;

	typedef Mesh_PlnCurve<GModel_ParaCurve, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_gPlnCurveSurface;

	template<>
	template<>
	static std::vector<std::shared_ptr<Aft2d_gSegmentEdge>>
		Aft2d_gPlnCurveSurface::TopoMesh<Aft2d_gSegmentEdge>
		(
			const std::shared_ptr<Aft2d_gPlnCurveSurface>& theCurve,
			const std::shared_ptr<Geo2d_MetricPrcsrAnIso>& theMap,
			const std::shared_ptr<Mesh_Curve_Info>& theInfo
			);
}

#endif // !_Aft2d_PlnCurveSurface_Header