#pragma once
#ifndef _Mesh_PlnCurve_Header
#define _Mesh_PlnCurve_Header

#include <Standard_Handle.hxx>
#include <Entity2d_Chain.hxx>
//#include <Geo_MetricPrcsr.hxx>

#include <memory>
#include <vector>

class Geom2d_Curve;

namespace AutLib
{

	// Forward Declarations
	class Geo_ApprxCurveInfo;
	class Mesh_CurveInfo;

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
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
		);

		static std::shared_ptr<Entity2d_Chain> Discrete
		(
			const Handle(Geom2d_Curve)& theCurve, 
			const Standard_Real theU0,
			const Standard_Real theU1, 
			const std::shared_ptr<Geo_ApprxCurveInfo>& theInfo
		);
	};
	

	template<class CurveType, class SizeFun, class MetricFun = void>
	class Mesh_PlnCurve
		: public CurveType
		, public Mesh_PlnCurve_Base
	{

		typedef Geo_MetricPrcsr<SizeFun, MetricFun> metricMap;

		/*Private Data*/

	public:

		typedef typename CurveType::geomType geomType;
		typedef typename CurveType::infoType info;
		typedef info infoType;

		typedef Mesh_PlnCurve_Base base;

		Mesh_PlnCurve(const CurveType& theCurve)
			: CurveType(theCurve)
		{}

		Mesh_PlnCurve
		(
			const Handle(geomType)& theCurve,
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const std::shared_ptr<info>& theInfo
		)
			: CurveType(theFirst, theLast, theCurve, theInfo)
		{}

		std::shared_ptr<Entity2d_Chain> Discrete
		(
			const std::shared_ptr<Geo_ApprxCurveInfo>& theInfo
		) const;

		virtual std::shared_ptr<Entity2d_Chain> Mesh
		(
			const std::shared_ptr<metricMap>& theMetricMap, 
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
		) const;

		
		template<class EdgeType, class PlnCurve>
		static std::vector<std::shared_ptr<EdgeType>> TopoMesh
		(
			const std::shared_ptr<PlnCurve>& theCurve,
			const std::shared_ptr<metricMap>& theMetricMap, 
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
		);

	};
}

#include <Mesh_PlnCurveI.hxx>

#endif // !_Mesh_PlnCurve_Header
