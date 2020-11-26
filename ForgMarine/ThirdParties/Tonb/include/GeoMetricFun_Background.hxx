#pragma once
#ifndef _GeoMetricFun_Background_Header
#define _GeoMetricFun_Background_Header

#include <GeoMetricFun_nonUniform.hxx>

#include <memory>

namespace tnbLib
{

	template<class BackMeshData>
	class GeoMetricFun_Background
		: public GeoMetricFun_nonUniform<typename BackMeshData::ptType>
	{

		typedef typename BackMeshData::ptType Point;

		/*Private Data*/

		std::shared_ptr<BackMeshData> theBackMesh_;

	public:

		typedef Point ptType;
		typedef typename metric_type_from_point<Point>::metricType metricType;

		GeoMetricFun_Background
		(
			const std::shared_ptr<BackMeshData>& theBackMesh
		)
			: theBackMesh_(theBackMesh)
		{}

		GeoMetricFun_Background
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<BackMeshData>& theBackMesh
		);


		const std::shared_ptr<BackMeshData>& BackMesh() const
		{
			return theBackMesh_;
		}


		//- override functions and operators

		metricType Value(const Point& theCoord) const override;
	};
}

#include <GeoMetricFun_BackgroundI.hxx>

#endif // !_GeoMetricFun_Background_Header