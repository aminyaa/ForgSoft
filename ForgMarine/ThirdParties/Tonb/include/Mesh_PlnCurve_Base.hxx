#pragma once
#ifndef _Mesh_PlnCurve_Base_Header
#define _Mesh_PlnCurve_Base_Header

#include <Standard_Handle.hxx>
#include <Entity2d_Chain.hxx>

#include <memory>
#include <vector>

class Geom2d_Curve;

namespace tnbLib
{

	// Forward Declarations
	class Geo_ApprxCurve_Info;
	class Mesh_Curve_Info;

	template<class SizeFun, class MetricFun>
	class Geo_MetricPrcsr;

	class Mesh_PlnCurve_Base
	{

	protected:

		template<class SizeFun, class MetricFun = void>
		static std::shared_ptr<Entity2d_Chain> Mesh
		(
			const Handle(Geom2d_Curve)& theCurve,
			const Standard_Real theU0,
			const Standard_Real theU1,
			const std::shared_ptr<Geo_MetricPrcsr<SizeFun, MetricFun>>& theMap,
			const std::shared_ptr<Mesh_Curve_Info>& theInfo
		);

		static std::shared_ptr<Entity2d_Chain> Discrete
		(
			const Handle(Geom2d_Curve)& theCurve,
			const Standard_Real theU0,
			const Standard_Real theU1,
			const std::shared_ptr<Geo_ApprxCurve_Info>& theInfo
		);
	};
}

#endif // !_Mesh_PlnCurve_Base_Header
