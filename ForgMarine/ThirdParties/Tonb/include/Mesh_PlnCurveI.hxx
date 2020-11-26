#pragma once
namespace tnbLib
{

	template<class CurveType, class SizeFun, class MetricFun>
	std::shared_ptr<Entity2d_Chain>
		Mesh_PlnCurve<CurveType, SizeFun, MetricFun>::Discrete
		(
			const std::shared_ptr<Geo_ApprxCurve_Info>& theInfo
		) const
	{
		auto mesh =
			base::Discrete
			(
				CurveType::Geometry(),
				CurveType::FirstParameter(), CurveType::LastParameter(),
				theInfo);
		return std::move(mesh);
	}

	template<class CurveType, class SizeFun, class MetricFun>
	std::shared_ptr<Entity2d_Chain>
		Mesh_PlnCurve<CurveType, SizeFun, MetricFun>::Mesh
		(
			const std::shared_ptr<metricMap>& theMetricMap,
			const std::shared_ptr<Mesh_Curve_Info>& theInfo
		) const
	{
		auto mesh =
			base::Mesh<SizeFun, MetricFun>
			(
				CurveType::Geometry(),
				CurveType::FirstParameter(),
				CurveType::LastParameter(), theMetricMap, theInfo
				);
		return std::move(mesh);
	}
}