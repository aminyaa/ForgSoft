#pragma once
#ifndef _Mesh2d_PlnCurve_Header
#define _Mesh2d_PlnCurve_Header

#include <Mesh_PlnCurve.hxx>
#include <Geo2d_MetricPrcsr.hxx>
#include <Aft2d_BndEdgeFwd.hxx>
#include <Pln_Curve.hxx>

namespace AutLib
{

	template<>
	static std::shared_ptr<Entity2d_Chain> 
		Mesh_PlnCurve_Base::Mesh<Geo2d_SizeFunction>
		(
			const Handle(Geom2d_Curve)& theCurve,
			const Standard_Real theU0,
			const Standard_Real theU1, 
			const std::shared_ptr<Geo2d_MetricPrcsr>& theMap, 
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
			);

	
	// Forward Declarations
	class Pln_Curve;


	typedef Mesh_PlnCurve<Pln_Curve, Geo2d_SizeFunction>
		Mesh2d_PlnCurve;

	template<>
	template<>
	static std::vector<std::shared_ptr<Aft2d_BndEdge>> 
		Mesh2d_PlnCurve::TopoMesh<Aft2d_BndEdge>
		(
			const std::shared_ptr<Mesh2d_PlnCurve>& theCurve,
			const std::shared_ptr<Geo2d_MetricPrcsr>& theMap,
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
			);
}

#endif // !_Mesh2d_PlnCurve_Header
