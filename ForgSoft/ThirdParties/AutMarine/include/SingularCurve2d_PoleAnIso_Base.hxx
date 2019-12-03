#pragma once
#ifndef _SingularCurve2d_PoleAnIso_Base_Header
#define _SingularCurve2d_PoleAnIso_Base_Header

#include <SingularCurve_Pole.hxx>
#include <Geo2d_MetricPrcsrAnIso.hxx>

namespace AutLib
{
	template<>
	static std::shared_ptr<Entity2d_Chain>
		SingularCurve_Pole_Base::Mesh<Geo2d_SizeFunction, Geo2d_MetricFunction>
		(
			const Handle(Geom2d_Curve)& theCurve, 
			const Standard_Real theU0, 
			const Standard_Real theU1, 
			const std::shared_ptr<Geo2d_MetricPrcsrAnIso>& theMap,
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
			);
}

#endif // !_SingularCurve2d_PoleAnIso_Base_Header
