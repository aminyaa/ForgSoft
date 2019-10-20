#pragma once
#include <error.hxx>
#include <OSstream.hxx>
namespace AutLib
{

	template<class BackMeshData>
	GeoMetricFun_Background<BackMeshData>::GeoMetricFun_Background
	(
		const Standard_Integer theIndex, 
		const word & theName,
		const std::shared_ptr<BackMeshData>& theBackMesh
	)
		: GeoMetricFun_nonUniform<typename BackMeshData::ptType>(theIndex, theName)
		, theBackMesh_(theBackMesh)
	{
	}

	template<class BackMeshData>
	typename AutLib::GeoMetricFun_Background<BackMeshData>::metricType 
		AutLib::GeoMetricFun_Background<BackMeshData>::Value
		(
			const Point & theCoord
		) const
	{
		Debug_Null_Pointer(theBackMesh_);

		auto metric = theBackMesh_->InterpolateAt(theCoord);
		return std::move(metric);
	}
}