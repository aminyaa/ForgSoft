#pragma once
#ifndef _Geo_ApprxSurfMetric_Header
#define _Geo_ApprxSurfMetric_Header

#include <Standard_Handle.hxx>
#include <Global_Done.hxx>
#include <Entity2d_Box.hxx>
#include <GeoMesh2d_MetricBackgroundFwd.hxx>
#include <Geo_ApprxSurfMetricInfo.hxx>

#include <memory>

class Geom_Surface;

namespace AutLib
{
	class Geo_ApprxSurfMetric
		: public Global_Done
	{

		/*Private Data*/

		Handle(Geom_Surface) theSurface_;

		Entity2d_Box theDomain_;

		Standard_Real theMaxDet_;

		Standard_Boolean HasDegeneracy_;

		std::shared_ptr<GeoMesh2d_MetricBackground> theApprox_;
		std::shared_ptr<Geo_ApprxSurfMetricInfo> theInfo_;

	public:

		Geo_ApprxSurfMetric
		(
			const std::shared_ptr<Geo_ApprxSurfMetricInfo>& theInfo
		)
			: theInfo_(theInfo)
			, HasDegeneracy_(Standard_False)
		{}

		Geo_ApprxSurfMetric
		(
			const Handle(Geom_Surface)& theSurface,
			const Entity2d_Box& theDomain,
			const std::shared_ptr<Geo_ApprxSurfMetricInfo>& theInfo
		)
			: theInfo_(theInfo)
			, theSurface_(theSurface)
			, theDomain_(theDomain)
			, HasDegeneracy_(Standard_False)
		{}

		const Handle(Geom_Surface)& Surface() const
		{
			return theSurface_;
		}

		const Entity2d_Box& Domain() const
		{
			return theDomain_;
		}

		Standard_Real MaxDet() const
		{
			return theMaxDet_;
		}

		Standard_Boolean HasDegeneracy() const
		{
			return HasDegeneracy_;
		}

		const std::shared_ptr<GeoMesh2d_MetricBackground>& Approx() const
		{
			return theApprox_;
		}

		const std::shared_ptr<Geo_ApprxSurfMetricInfo>& Info() const
		{
			return theInfo_;
		}

		void LoadSurface
		(
			const Handle(Geom_Surface)& theSurface,
			const Entity2d_Box& theDomain
		)
		{
			theSurface_ = theSurface;
			theDomain_ = theDomain;
		}

		void Peform();


	};
}

#endif // !_Geo_ApprxSurfMetric_Header
