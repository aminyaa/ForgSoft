#pragma once
#ifndef _Aft2d_PlnCurveAnIso_Base_Header
#define _Aft2d_PlnCurveAnIso_Base_Header

#include <Mesh_PlnCurve.hxx>
#include <Geo2d_MetricPrcsrAnIso.hxx>

namespace AutLib
{
	template<>
	static std::shared_ptr<Entity2d_Chain>
		Mesh_PlnCurve_Base::Mesh<Geo2d_SizeFunction, Geo2d_MetricFunction>
		(
			const Handle(Geom2d_Curve)& theCurve,
			const Standard_Real theU0,
			const Standard_Real theU1,
			const std::shared_ptr<Geo2d_MetricPrcsrAnIso>& theMap,
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
			);
}

#endif // !_Aft2d_PlnCurveAnIso_Base_Header
