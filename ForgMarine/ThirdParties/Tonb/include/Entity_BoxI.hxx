#pragma once
template<class Point>
tnbLib::Entity_Box<Point> 
tnbLib::Entity_Box<Point>::Expanded
(
	const Standard_Real theOffset
) const
{
	auto copy = *this;
	copy.Expand(theOffset);
	return std::move(copy);
}

template<class Point>
void tnbLib::Entity_Box<Point>::Expand
(
	const Standard_Real theOffset
)
{
	auto& p0 = P0();
	auto& p1 = P1();

	for (int i = 1; i <= Point::dim; i++)
	{
		auto x0 = p0.Coord(i);
		auto x1 = p1.Coord(i);

		x0 -= theOffset;
		x1 += theOffset;

		p0.SetCoord(i, x0);
		p1.SetCoord(i, x1);
	}
}

namespace tnbLib
{

	template<class Point>
	Entity_Box<Point> Entity_Box<Point>::Union
	(
		const Entity_Box & theBox0,
		const Entity_Box & theBox1
	)
	{
		std::vector<Point> list;
		list.push_back(theBox0.P0());
		list.push_back(theBox0.P1());

		list.push_back(theBox1.P0());
		list.push_back(theBox1.P1());

		auto box = BoundingBoxOf(list);
		return std::move(box);
	}

	template<class Point>
	Entity_Box<Point> Entity_Box<Point>::BoundingBoxOf(const std::vector<Point>& thePts)
	{
		Point Pmin, Pmax;
		Pmin = RealLast();
		Pmax = RealFirst();
		for (const auto& x : thePts)
		{
			for (int i = 1; i <= Point::dim; i++)
				Pmin.SetCoord(i, MIN(Pmin.Coord(i), x.Coord(i)));

			for (int i = 1; i <= Point::dim; i++)
				Pmax.SetCoord(i, MAX(Pmax.Coord(i), x.Coord(i)));
		}

		Entity_Box<Point> box(Pmin, Pmax);
		return std::move(box);
	}

	template<class Point>
	Entity_Box<Point> Entity_Box<Point>::BoundingBoxOf
	(
		const Point & P0,
		const Point & P1
	)
	{
		Point Pmin;
		for (int i = 1; i <= Point::dim; i++)
			Pmin.SetCoord(i, MIN(P0.Coord(i), P1.Coord(i)));

		Point Pmax;
		for (int i = 1; i <= Point::dim; i++)
			Pmax.SetCoord(i, MAX(P0.Coord(i), P1.Coord(i)));

		Entity_Box<Point> box(Pmin, Pmax);
		return std::move(box);
	}

	template<class Point>
	Standard_Boolean Entity_Box<Point>::IsInside
	(
		const Entity_Box & theInner,
		const Entity_Box & theBox
	)
	{
		const auto& Pmin = theBox.P0();
		const auto& Pmax = theBox.P1();

		const auto& P0 = theInner.P0();
		const auto& P1 = theInner.P1();

		for (int i = 1; i <= Point::dim; i++)
		{
			if (NOT INSIDE(P0.Coord(i), Pmin.Coord(i), Pmax.Coord(i))) return Standard_False;
			if (NOT INSIDE(P1.Coord(i), Pmin.Coord(i), Pmax.Coord(i))) return Standard_False;
		}
		return Standard_True;
	}

	template<class Point>
	std::ostream& operator<<(std::ostream& os, const Entity_Box<Point>& b)
	{
		os
			<< " P0 = ("
			<< b.P0()
			<< "),  P1 = ("
			<< b.P1()
			<< ")";
		return os;
	}

	template<class Point>
	Ostream & operator<<(Ostream & os, const Entity_Box<Point>& b)
	{
		os << " P0 = " << b.P0() << ", P1 = " << b.P1();
		os.check("Ostream & operator<<(Ostream & os, const Entity_Box<Point>& b)");
		return os;
	}
}