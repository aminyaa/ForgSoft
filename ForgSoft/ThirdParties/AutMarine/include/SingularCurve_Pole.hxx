#pragma once
#ifndef _SingularCurve_Pole_Header
#define _SingularCurve_Pole_Header

#include <Global_AccessMethod.hxx>
#include <Mesh_SingularCurve.hxx>
#include <Entity2d_Chain.hxx>

namespace AutLib
{

	class SingularCurve_Pole_Base
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


	};

	template<class CurveType, class SizeFun, class MetricFun = void>
	class SingularCurve_Pole
		: public Mesh_SingularCurve<CurveType, SizeFun, MetricFun>
		, public SingularCurve_Pole_Base
	{

		typedef Geo_MetricPrcsr<SizeFun, MetricFun> metricMap;

		/*Private Data*/

		Pnt2d theMid_;

	public:

		typedef Mesh_SingularCurve<CurveType, SizeFun, MetricFun> base;
		typedef typename base::infoType info;
		typedef typename base::geomType geomType;


		SingularCurve_Pole
		(
			const Handle(geomType)& theCurve,
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const std::shared_ptr<info>& theInfo
		)
			: base(theCurve, theFirst, theLast, theInfo)
		{}

		std::shared_ptr<Entity2d_Chain> Mesh
		(
			const std::shared_ptr<metricMap>& theMetricMap,
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
		) const override;

		// macros

		GLOBAL_ACCESS_SINGLE(Pnt2d, Mid)
	};
}

#include <SingularCurve_PoleI.hxx>

#endif // !_SingularCurve_Pole_Header
