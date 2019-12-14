#pragma once
#ifndef _Aft_PlnBoundary_Header
#define _Aft_PlnBoundary_Header

#include <Geo_MetricPrcsr.hxx>
#include <Aft_PlnBoundary_Base.hxx>
#include <Aft_PlnBoundary_Traits.hxx>

#include <memory>
#include <vector>

//#include "Aft2d_gPlnRegionSurface.hxx"
//#include "Aft2d_gPlnCurveSurface.hxx"
//#include "Aft2d_gPlnWireSurface.hxx"
//#include "Aft2d_PlnBoundary_Info.hxx"
//#include "Aft2d_gSegmentEdge.hxx"

namespace AutLib
{

	

	template<class RegionType, class SizeFun, class MetricFun = void>
	class Aft_PlnBoundary
		: public Aft_PlnBoundary_Base<typename aft_pln_boundary_entity_type<RegionType>::type>
	{

		typedef Geo_MetricPrcsr<SizeFun, MetricFun>
			metricPrcsr;
		typedef typename aft_pln_boundary_info_type<RegionType>::type 
			info;
		typedef typename aft_pln_boundary_entity_type<RegionType>::type
			bndType;
		typedef Aft_PlnBoundary_Base<typename aft_pln_boundary_entity_type<RegionType>::type>
			base;
		typedef typename RegionType::plnCurveType curveType;

		/*Private Data*/

		std::shared_ptr<metricPrcsr> theMetricPrcsr_;
		std::shared_ptr<info> theInfo_;

		std::shared_ptr<RegionType> thePlane_;

		std::vector<std::shared_ptr<bndType>> theBoundaries_;


		//- private functions and operators

		std::vector<std::shared_ptr<bndType>>& ChangeBoundaries()
		{
			return theBoundaries_;
		}

		void RemoveDegeneracies();

		void UpdateFront();

	public:

		Aft_PlnBoundary()
		{}

		const std::shared_ptr<metricPrcsr>& MetricProcessor() const
		{
			return theMetricPrcsr_;
		}

		const std::shared_ptr<info>& Info() const
		{
			return theInfo_;
		}

		const std::shared_ptr<RegionType>& Plane() const
		{
			return thePlane_;
		}

		const std::vector<std::shared_ptr<bndType>>& Boundaries() const
		{
			return theBoundaries_;
		}

		void Perform();

		void LoadMetricProcessor(const std::shared_ptr<metricPrcsr>& thePrcsr)
		{
			theMetricPrcsr_ = thePrcsr;
		}

		void LoadPlane(const std::shared_ptr<RegionType>& thePlane)
		{
			thePlane_ = thePlane;
		}
	};

	template<class RegionType, class SizeFun>
	class Aft_PlnBoundary<RegionType, SizeFun, void>
		: public Aft_PlnBoundary_Base<typename aft_pln_boundary_entity_type<RegionType>::type>
	{

		typedef Geo_MetricPrcsr<SizeFun>
			metricPrcsr;
		typedef typename aft_pln_boundary_info_type<RegionType>::type
			info;
		typedef typename aft_pln_boundary_entity_type<RegionType>::type
			bndType;

		/*Private Data*/

		std::shared_ptr<metricPrcsr> theMetricPrcsr_;
		std::shared_ptr<info> theInfo_;

		std::shared_ptr<RegionType> thePlane_;


		std::vector<std::shared_ptr<bndType>> theBoundaries_;

		//- private functions and operators

		std::vector<std::shared_ptr<bndType>>& ChangeBoundaries()
		{
			return theBoundaries_;
		}

		void UpdateFront();

	public:

		Aft_PlnBoundary()
		{}

		const std::shared_ptr<metricPrcsr>& MetricProcessor() const
		{
			return theMetricPrcsr_;
		}

		const std::shared_ptr<info>& Info() const
		{
			return theInfo_;
		}

		const std::shared_ptr<RegionType>& Plane() const
		{
			return thePlane_;
		}

		const std::vector<std::shared_ptr<bndType>>& Boundaries() const
		{
			return theBoundaries_;
		}

		void Perform();

		void LoadMetricProcessor(const std::shared_ptr<metricPrcsr>& thePrcsr)
		{
			theMetricPrcsr_ = thePrcsr;
		}

		void LoadPlane(const std::shared_ptr<RegionType>& thePlane)
		{
			thePlane_ = thePlane;
		}
	};
}

#include <Aft_PlnBoundaryI.hxx>

#endif // !_Aft_PlnBoundary_Header
