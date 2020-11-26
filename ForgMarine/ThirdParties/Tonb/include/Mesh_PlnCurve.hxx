#pragma once
#ifndef _Mesh_PlnCurve_Header
#define _Mesh_PlnCurve_Header

#include <Mesh_PlnCurve_Base.hxx>
#include <Mesh_PlnCurve_Traits.hxx>

namespace tnbLib
{

	template<class CurveType, class SizeFun, class MetricFun = void>
	class Mesh_PlnCurve
		: public CurveType
		, public Mesh_PlnCurve_Base
	{

		typedef Geo_MetricPrcsr<SizeFun, MetricFun> metricMap;

		/*Private Data*/

	public:

		typedef typename Mesh_PlnCurve_Traits<CurveType>::geomType geomType;
		typedef Mesh_PlnCurve_Base base;

		Mesh_PlnCurve(const CurveType& theCurve)
			: CurveType(theCurve)
		{}

		Mesh_PlnCurve
		(
			const Handle(geomType)& theCurve
		)
			: CurveType(theCurve)
		{}

		std::shared_ptr<Entity2d_Chain> Discrete
		(
			const std::shared_ptr<Geo_ApprxCurve_Info>& theInfo
		) const;

		virtual std::shared_ptr<Entity2d_Chain> Mesh
		(
			const std::shared_ptr<metricMap>& theMetricMap,
			const std::shared_ptr<Mesh_Curve_Info>& theInfo
		) const;


		template<class EdgeType, class PlnCurve>
		static std::vector<std::shared_ptr<EdgeType>> TopoMesh
		(
			const std::shared_ptr<PlnCurve>& theCurve,
			const std::shared_ptr<metricMap>& theMetricMap,
			const std::shared_ptr<Mesh_Curve_Info>& theInfo
		);

	};
}

#include <Mesh_PlnCurveI.hxx>

#endif // !_Mesh_PlnCurve_Header
