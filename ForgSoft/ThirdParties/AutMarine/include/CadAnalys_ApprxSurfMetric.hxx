#pragma once
#ifndef _CadAnalys_ApprxSurfMetric_Header
#define _CadAnalys_ApprxSurfMetric_Header

#include <Global_Done.hxx>
#include <Standard_Handle.hxx>
#include <Entity2d_Box.hxx>
#include <GeoMesh2d_MetricBackgroundFwd.hxx>
#include <Pnt3d.hxx>

class Geom_Surface;

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class CadAnalys_ApprxSurfMetricInfo;

	template<class Point>
	class Geo_SizeFunction;

	class CadAnalys_ApprxSurfMetricBase
	{

		/*Private Data*/

		Standard_Real theMaxDet_;
		Standard_Real theMinDet_;

		Standard_Boolean HasDegeneracy_;

	protected:

		CadAnalys_ApprxSurfMetricBase();


		Standard_Real& ChangeMaxDet()
		{
			return theMaxDet_;
		}

		Standard_Real& ChangeMinDet()
		{
			return theMinDet_;
		}

		Standard_Boolean& Change_HasDegeneracy()
		{
			return HasDegeneracy_;
		}

	public:

		Standard_Real MaxDet() const
		{
			return theMaxDet_;
		}

		Standard_Real MinDet() const
		{
			return theMinDet_;
		}

		Standard_Boolean HasDegeneracy() const
		{
			return HasDegeneracy_;
		}
	};

	class CadAnalys_ApprxSurfMetric
		: public Global_Done
		, public CadAnalys_ApprxSurfMetricBase
	{

		typedef CadAnalys_ApprxSurfMetricInfo info;
		typedef Geo_SizeFunction<Pnt3d> sizeFun;

		/*Private Data*/

		Handle(Geom_Surface) theSurface_;

		Entity2d_Box theBoundingBox_;

		std::shared_ptr<GeoMesh2d_MetricBackground> theApprox_;
		std::shared_ptr<info> theInfo_;

		std::shared_ptr<sizeFun> theSizeFun_;

	public:


		CadAnalys_ApprxSurfMetric
		(
			const std::shared_ptr<info>& theInfo
		)
			: theInfo_(theInfo)
		{}

		CadAnalys_ApprxSurfMetric
		(
			const Handle(Geom_Surface)& theSurface,
			const Entity2d_Box& theDomain,
			const std::shared_ptr<info>& theInfo
		)
			: theInfo_(theInfo)
			, theSurface_(theSurface)
			, theBoundingBox_(theDomain)
		{}



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

#endif // !_CadAnalys_ApprxSurfMetric_Header
