#pragma once
namespace AutLib
{
	namespace Processor
	{

		inline
		Standard_Real Oriented_fast
		(
			const Pnt2d & theQ, 
			const Pnt2d & theP0,
			const Pnt2d & theP1
		)
		{
			Pnt2d v1 = theP0 - theQ;
			Pnt2d v2 = theP1 - theQ;
			return CrossProduct(v1, v2);
		}

		inline
		Standard_Boolean IsPointInsideTriangle_cgal
		(
			const Pnt2d & Point,
			const Pnt2d & P0, 
			const Pnt2d & P1,
			const Pnt2d & P2
		)
		{
			if (IsPointRightEdge_cgal(Point, P0, P1))
			{
				return Standard_False;
			}
			else if (IsPointRightEdge_cgal(Point, P1, P2))
			{
				return Standard_False;
			}
			else if (IsPointRightEdge_cgal(Point, P2, P0))
			{
				return Standard_False;
			}

			return Standard_True;
		}

		inline
		Standard_Boolean IsPointInsideTriangle_fast
		(
			const Pnt2d & Point,
			const Pnt2d & P0, 
			const Pnt2d & P1,
			const Pnt2d & P2
		)
		{
			if (IsPointRightEdge_fast(Point, P0, P1))
			{
				return Standard_False;
			}
			else if (IsPointRightEdge_fast(Point, P1, P2))
			{
				return Standard_False;
			}
			else if (IsPointRightEdge_fast(Point, P2, P0))
			{
				return Standard_False;
			}

			return Standard_True;
		}

		inline
		Standard_Boolean AutLib::Processor::IsPairedTwoSegments
		(
			const Standard_Integer v1,
			const Standard_Integer v2,
			const Standard_Integer q1,
			const Standard_Integer q2
		)
		{
			if (v1 == q1)
			{
				if (v2 == q2)
					return Standard_True;
				else
					return Standard_False;
			}
			else if (v2 == q1)
			{
				if (v1 == q2)
					return Standard_True;
				else
					return Standard_False;
			}

			return Standard_False;
		}

		inline
			Standard_Boolean IsOneCommonPointTwoTriangles
			(
				const Standard_Integer v1,
				const Standard_Integer v2,
				const Standard_Integer v3,
				const Standard_Integer q1,
				const Standard_Integer q2,
				const Standard_Integer q3
			)
		{
			if (v1 == q1)
				return Standard_True;
			else
				if (v1 == q2)
					return Standard_True;
				else
					if (v1 == q3)
						return Standard_True;
					else
						if (v2 == q1)
							return Standard_True;
						else
							if (v2 == q2)
								return Standard_True;
							else
								if (v2 == q3)
									return Standard_True;
								else
									if (v3 == q1)
										return Standard_True;
									else
										if (v3 == q2)
											return Standard_True;
										else
											if (v3 == q3)
												return Standard_True;
											else
												return Standard_False;
		}

		inline
			Pnt2d ProjectPtAtSegment
			(
				const Pnt2d & thePt,
				const Pnt2d & theP0,
				const Pnt2d & theP1
			)
		{
			const auto bot = SquareDistance(theP0, theP1);

			Pnt2d Pn;
			if (bot == 0.0) Pn = theP1;
			else
			{
				const auto V1 = theP1 - theP0;
				const auto V2 = thePt - theP0;

				Standard_Real t = DotProduct(V1, V2) / bot;
				if (t > 1) t = 1;
				if (t < 0) t = 0;

				Pn = theP0 + t * V1;
			}
			return std::move(Pn);
		}
	}
}