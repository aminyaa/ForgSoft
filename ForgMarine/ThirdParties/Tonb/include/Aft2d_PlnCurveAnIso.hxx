#pragma once
#ifndef _Aft2d_PlnCurveAnIso_Header
#define _Aft2d_PlnCurveAnIso_Header

#include <Aft2d_PlnCurveAnIso_Base.hxx>
#include <Aft2d_SegmentEdgeAnIso.hxx>
#include <Pln_Curve.hxx>

namespace tnbLib
{

	// Forward Declarations
	class Pln_Curve;


	typedef Mesh_PlnCurve<Pln_Curve, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_PlnCurveAnIso;

	template<>
	template<>
	static std::vector<std::shared_ptr<Aft2d_SegmentEdgeAnIso>>
		Aft2d_PlnCurveAnIso::TopoMesh<Aft2d_SegmentEdgeAnIso>
		(
			const std::shared_ptr<Aft2d_PlnCurveAnIso>& theCurve,
			const std::shared_ptr<Geo2d_MetricPrcsrAnIso>& theMap,
			const std::shared_ptr<Mesh_Curve_Info>& theInfo
			);
}

#endif // !_Aft2d_PlnCurveAnIso_Header