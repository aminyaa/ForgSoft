#pragma once
#ifndef _CadRepair_ApproxSurfMetric_Header
#define _CadRepair_ApproxSurfMetric_Header

#include <Standard_Handle.hxx>
#include <Global_Done.hxx>
#include <Entity2d_Box.hxx>
#include <Geo2d_SizeFunctionFwd.hxx>
#include <GeoMesh2d_MetricBackgroundFwd.hxx>
#include <CadRepair_ApproxSurfMetric_Base.hxx>
#include <Pnt3d.hxx>

class Geom_Surface;

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class CadRepair_ApproxSurfMetric_Info;

	class CadRepair_ApproxSurfMetric
		: public Global_Done
		, public CadRepair_ApproxSurfMetric_Base
	{

		typedef CadRepair_ApproxSurfMetric_Info info;
		typedef Geo2d_SizeFunction sizeFun;

		/*Private Data*/

		Handle(Geom_Surface) theSurface_;

		Entity2d_Box theBoundingBox_;

		std::shared_ptr<GeoMesh2d_MetricBackground> theApprox_;
		std::shared_ptr<info> theInfo_;

		std::shared_ptr<sizeFun> theSizeFun_;

	public:

		CadRepair_ApproxSurfMetric(const std::shared_ptr<info>& theInfo)
			: theInfo_(theInfo)
		{}

		CadRepair_ApproxSurfMetric
		(
			const Handle(Geom_Surface)& theSurface,
			const Entity2d_Box& theDomain,
			const std::shared_ptr<info>& theInfo
		)
			: theInfo_(theInfo)
			, theSurface_(theSurface)
			, theBoundingBox_(theDomain)
		{}

		const std::shared_ptr<sizeFun>& SizeFunction() const
		{
			return theSizeFun_;
		}

		const Handle(Geom_Surface)& Surface() const
		{
			return theSurface_;
		}

		const Entity2d_Box& Domain() const
		{
			return theBoundingBox_;
		}

		const std::shared_ptr<GeoMesh2d_MetricBackground>& Approx() const
		{
			return theApprox_;
		}

		const std::shared_ptr<info>& Info() const
		{
			return theInfo_;
		}


		void OverrideInfo
		(
			const std::shared_ptr<info>& theInfo
		)
		{
			theInfo_ = theInfo;
		}

		void LoadSurface
		(
			const Handle(Geom_Surface)& theSurface,
			const Entity2d_Box& theBox
		)
		{
			theSurface_ = theSurface;
			theBoundingBox_ = theBox;
		}

		void LoadSizeFun
		(
			const std::shared_ptr<sizeFun>& theSize
		)
		{
			theSizeFun_ = theSize;
		}

		void Perform();
	};
}

#endif // !_CadRepair_ApproxSurfMetric_Header
