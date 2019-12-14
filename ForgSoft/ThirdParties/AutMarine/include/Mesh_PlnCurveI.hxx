#pragma once
namespace AutLib
{

	template<class CurveType, class SizeFun, class MetricFun>
	std::shared_ptr<Entity2d_Chain>
		Mesh_PlnCurve<CurveType, SizeFun, MetricFun>::Discrete
		(
			const std::shared_ptr<Geo_ApprxCurveInfo>& theInfo
		) const
	{
		auto mesh =
			base::Discrete
			(
				CurveType::Curve(),
				CurveType::FirstParam(), CurveType::LastParam(),
				theInfo);
		return std::move(mesh);
	}

	template<class CurveType, class SizeFun, class MetricFun>
	std::shared_ptr<Entity2d_Chain>
		Mesh_PlnCurve<CurveType, SizeFun, MetricFun>::Mesh
		(
			const std::shared_ptr<metricMap>& theMetricMap,
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
		) const
	{
		auto mesh =
			base::Mesh<SizeFun, MetricFun>
			(
				CurveType::Curve(),
				CurveType::FirstParam(),
				CurveType::LastParam(), theMetricMap, theInfo
				);
		return std::move(mesh);
	}
}