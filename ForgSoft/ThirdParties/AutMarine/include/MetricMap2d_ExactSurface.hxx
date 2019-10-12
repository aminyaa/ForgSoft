#pragma once
#ifndef _MetricMap2d_ExactSurface_Header
#define _MetricMap2d_ExactSurface_Header

#include <MetricMap2d_Surface.hxx>
#include <Entity2d_Metric1.hxx>

#include <Geom_Surface.hxx>

namespace AutLib
{

	class MetricMap2d_ExactSurface
		: public MetricMap2d_Surface
	{

		typedef Entity2d_Metric1 metric;

		/*Private Data*/

		Handle(Geom_Surface) thePatch_;

	public:

		MetricMap2d_ExactSurface()
		{}

		MetricMap2d_ExactSurface
		(
			const Handle(Geom_Surface)& thePatch,
			const Entity2d_Box& theBox
		);

		Standard_Real MaxDim() const override;

		const Handle(Geom_Surface)& Patch() const override
		{
			return thePatch_;
		}

		metric MetricAt
		(
			const Pnt2d& theP
		) const override
		{
			Debug_Null_Pointer(thePatch_);

			auto m = CorrectMetric(theP, BoundingBox(), *Patch());
			return std::move(m);
		}

		void LoadGeometry(const Handle(Geom_Surface)& geom)
		{
			thePatch_ = geom;
		}

		void Reset() override
		{
			thePatch_ = 0;
		}

		//- Use this if the point is inside the bounding box of the surface
		static metric CalcMetric
		(
			const Pnt2d& theCoord,
			const Geom_Surface& theSurface
		);

		//- Calculate metric even if the point is outside the bounding box of the surface
		static metric CorrectMetric
		(
			const Pnt2d& theCoord,
			const Entity2d_Box& theDomain,
			const Geom_Surface& theSurface
		);
	};
}

#endif // !_MetricMap2d_ExactSurface_Header