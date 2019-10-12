#pragma once
#ifndef _MetricMap2d_ExactSurfaceLowerBounded_Header
#define _MetricMap2d_ExactSurfaceLowerBounded_Header

#include <MetricMap2d_ExactSurface.hxx>
#include <MetricMap2d_ExactSurfaceLowerBoundedInfo.hxx>

#include <memory>

namespace AutLib
{

	class MetricMap2d_ExactSurfaceLowerBounded
		: public MetricMap2d_ExactSurface
	{

		typedef Entity2d_Metric1 metric;
		typedef MetricMap2d_ExactSurface exact;

		typedef MetricMap2d_ExactSurfaceLowerBoundedInfo info;

		/*Private Data*/

		std::shared_ptr<info> theInfo_;

	public:

		MetricMap2d_ExactSurfaceLowerBounded
		(
			const std::shared_ptr<info>& theInfo
		)
			: theInfo_(theInfo)
		{}

		MetricMap2d_ExactSurfaceLowerBounded
		(
			const Handle(Geom_Surface)& thePatch,
			const Entity2d_Box& theBox,
			const std::shared_ptr<info>& theInfo
		)
			: exact(thePatch, theBox)
			, theInfo_(theInfo)
		{}

		const std::shared_ptr<info>& Info() const
		{
			return theInfo_;
		}

		metric MetricAt
		(
			const Pnt2d& theP
		) const override
		{
			const auto eps = Info()->Epsilon();
			auto m = exact::MetricAt(theP);
			if (m.A() <= eps) m.A() = eps;
			if (m.C() <= eps) m.B() = eps;
			return std::move(m);
		}
	};

}

#endif // !_MetricMap2d_ExactSurfaceLowerBounded_Header