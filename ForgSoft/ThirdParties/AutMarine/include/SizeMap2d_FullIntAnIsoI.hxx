#pragma once
#include <GeoProcessor.hxx>
namespace AutLib
{

	inline Standard_Real
		SizeMap2d_FullIntAnIso::BaseElementSize() const
	{
		return theSizeMap_->BaseElementSize();
	}

	inline Standard_Real
		SizeMap2d_FullIntAnIso::CalcElementSize
		(
			const Pnt2d & P
		) const
	{
		return theSizeMap_->CalcElementSize(P);
	}

	inline Standard_Real
		SizeMap2d_FullIntAnIso::CalcElementSize
		(
			const front & theEdge
		) const
	{
		return theSizeMap_->CalcElementSize(theEdge);
	}

	inline Standard_Real
		SizeMap2d_FullIntAnIso::Oriented
		(
			const Pnt2d & P,
			const front & theEdge
		) const
	{
		const auto& n0 = theEdge.Node0();
		const auto& n1 = theEdge.Node1();

		return Processor::Oriented_cgal(P, n0->Coord(), n1->Coord());
	}

	inline Standard_Real
		SizeMap2d_FullIntAnIso::CalcSquareDistance
		(
			const Pnt2d & P0,
			const Pnt2d & P1
		) const
	{
		auto dis = CalcDistance(P0, P1);
		return dis * dis;
	}

	inline Standard_Real
		SizeMap2d_FullIntAnIso::CalcDistance
		(
			const Pnt2d & P,
			const front & theEdge
		) const
	{
		const auto& n0 = theEdge.Node0();
		const auto& n1 = theEdge.Node1();

		const auto& p0 = n0->Coord();
		const auto& p1 = n1->Coord();

		auto bot = SquareDistance(p0, p1);

		Pnt2d Pn;
		if (bot <= gp::Resolution()) Pn = p0;
		else
		{
			auto v1 = p1 - p0;
			auto v2 = P - p0;

			auto t = DotProduct(v1, v2) / bot;
			if (t > 1) t = 1;
			if (t < 0) t = 0;

			Pn = p0 + t * v1;
		}
		return CalcDistance(P, Pn);
	}

	inline Standard_Real
		SizeMap2d_FullIntAnIso::CalcSquareDistance
		(
			const Pnt2d & P,
			const front & theEdge
		) const
	{
		const auto& n0 = theEdge.Node0();
		const auto& n1 = theEdge.Node1();

		const auto& p0 = n0->Coord();
		const auto& p1 = n1->Coord();

		auto bot = SquareDistance(p0, p1);

		Pnt2d Pn;
		if (bot <= gp::Resolution()) Pn = p0;
		else
		{
			auto v1 = p1 - p0;
			auto v2 = P - p0;

			auto t = DotProduct(v1, v2) / bot;
			if (t > 1) t = 1;
			if (t < 0) t = 0;

			Pn = p0 + t * v1;
		}
		return CalcSquareDistance(P, Pn);
	}

	inline Pnt2d
		SizeMap2d_FullIntAnIso::CalcCentreOf
		(
			const Pnt2d & P0,
			const Pnt2d & P1
		) const
	{
		auto p = MEAN(P0, P1);
		return std::move(p);
	}

	inline Pnt2d
		SizeMap2d_FullIntAnIso::CalcCentreOf
		(
			const frontType & theFront
		) const
	{
		Debug_Null_Pointer(theFront.Node0());
		Debug_Null_Pointer(theFront.Node1());
		return CalcCentreOf(theFront.Node0()->Coord(), theFront.Node1()->Coord());
	}

	inline Standard_Real
		SizeMap2d_FullIntAnIso::Integrand
		(
			const Pnt2d & thePoint,
			const Pnt2d & theVector
		) const
	{
		return sqrt(DotProduct(theVector, MetricMap()->MetricAt(thePoint).Multiplied(theVector)));
	}

	inline Standard_Real
		SizeMap2d_FullIntAnIso::Integrand
		(
			const Pnt2d & thePoint,
			const gp_Vec2d & theVector
		) const
	{
		return sqrt(theVector.Dot(MetricMap()->MetricAt(thePoint).Multiplied(theVector)));
	}

	inline Standard_Real
		SizeMap2d_FullIntAnIso::IntegrandPerSize
		(
			const Pnt2d & thePoint,
			const Pnt2d & theVector
		) const
	{
		return sqrt(DotProduct(theVector, MetricMap()->MetricAt(thePoint).Multiplied(theVector)))
			/ CalcElementSize(thePoint);
	}

	inline Standard_Real
		SizeMap2d_FullIntAnIso::IntegrandPerSize
		(
			const Pnt2d & thePoint,
			const gp_Vec2d & theVector
		) const
	{
		return sqrt(theVector.Dot(MetricMap()->MetricAt(thePoint).Multiplied(theVector)))
			/ CalcElementSize(thePoint);
	}
}