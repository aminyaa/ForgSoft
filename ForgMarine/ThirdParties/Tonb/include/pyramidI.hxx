#pragma once
#include <IOstreams.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

	template<class Point, class PointRef, class polygonRef>
	pyramid<Point, PointRef, polygonRef>::pyramid
	(
		polygonRef base,
		const Point& apex
	)
		:
		base_(base),
		apex_(apex)
	{}


	template<class Point, class PointRef, class polygonRef>
	pyramid<Point, PointRef, polygonRef>::pyramid(Istream& is)
	{
		is >> base_ >> apex_;
		is.check("pyramid::pyramid(Istream& is)");
	}


	// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

	template<class Point, class PointRef, class polygonRef>
	const Point& pyramid<Point, PointRef, polygonRef>::apex() const
	{
		return apex_;
	}

	template<class Point, class PointRef, class polygonRef>
	polygonRef pyramid<Point, PointRef, polygonRef>::base() const
	{
		return base_;
	}


	template<class Point, class PointRef, class polygonRef>
	Point pyramid<Point, PointRef, polygonRef>::centre
	(
		const pointField& points
	) const
	{
		return (3.0 / 4.0)*base_.centre(points) + (1.0 / 4.0)*apex_;
	}


	template<class Point, class PointRef, class polygonRef>
	vector pyramid<Point, PointRef, polygonRef>::height
	(
		const pointField& points
	) const
	{
		// Height = apex - baseCentroid
		return (apex_ - base_.centre(points));
	}


	template<class Point, class PointRef, class polygonRef>
	scalar pyramid<Point, PointRef, polygonRef>::mag
	(
		const pointField& points
	) const
	{
		return (1.0 / 3.0)*(base_.normal(points)&(height(points)));
	}


	// * * * * * * * * * * * * * * IOstream Operators  * * * * * * * * * * * * * //

	template<class Point, class PointRef, class polygonRef>
	Istream& operator>>
		(
			Istream& is,
			pyramid<Point, PointRef, polygonRef>& p
			)
	{
		is >> p.base_ >> p.apex_;
		is.check("Istream& operator>>(Istream&, pyramid&)");
		return is;
	}


	template<class Point, class PointRef, class polygonRef>
	Ostream& operator<<
		(
			Ostream& os,
			const pyramid<Point, PointRef, polygonRef>& p
			)
	{
		os << p.base_ << tab << p.apex_ << nl;
		return os;
	}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// ************************************************************************* //