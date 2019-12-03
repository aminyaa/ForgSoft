#pragma once
namespace AutLib
{

	template<class CurveType, class SizeFun, class MetricFun>
	std::shared_ptr<Entity2d_Chain> SingularCurve_Pole<CurveType, SizeFun, MetricFun>::Mesh
	(
		const std::shared_ptr<metricMap>& theMetricMap, 
		const std::shared_ptr<Mesh_CurveInfo>& theInfo
	) const
	{
		auto mesh = 
			SingularCurve_Pole_Base::Mesh<SizeFun, MetricFun>
			(
				CurveType::Curve(), 
				CurveType::FirstParam(), 
				CurveType::LastParam(), theMetricMap, theInfo
				);
		return std::move(mesh);
	}
}