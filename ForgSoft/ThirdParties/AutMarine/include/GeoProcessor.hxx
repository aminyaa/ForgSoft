#pragma once
#ifndef _GeoProcessor_Header
#define _GeoProcessor_Header

#include <Pnt2d.hxx>
#include <Pnt3d.hxx>

#include <vector>

namespace AutLib
{

	namespace Processor
	{

		inline Standard_Integer Round(const Standard_Real x)
		{
			return (Standard_Integer)floor(x + 0.5);
		}

		inline Standard_Real DegToRadian(const Standard_Real Degree)
		{
			return Degree * M_PI / 180.0;
		}

		inline Standard_Real RadianToDegree(const Standard_Real Radian)
		{
			return Radian * 180.0 / M_PI;
		}

		Standard_Real Oriented(const Pnt2d& theQ, const Pnt2d& theP0, const Pnt2d& theP1);

		Standard_Real Oriented_fast(const Pnt2d& theQ, const Pnt2d& theP0, const Pnt2d& theP1);

		Standard_Real SquareDistance_cgal
		(
			const Pnt2d& theQ,
			const Pnt2d& theP0,
			const Pnt2d& theP1
		);

		Standard_Real SquareDistance_cgal
		(
			const Pnt3d& theQ,
			const Pnt3d& theP0,
			const Pnt3d& theP1
		);

		inline Standard_Real Distance_cgal
		(
			const Pnt2d& theQ,
			const Pnt2d& theP0,
			const Pnt2d& theP1
		)
		{
			return sqrt(SquareDistance_cgal(theQ, theP0, theP1));
		}

		inline Standard_Real Distance_cgal
		(
			const Pnt3d& theQ,
			const Pnt3d& theP0,
			const Pnt3d& theP1
		)
		{
			return sqrt(SquareDistance_cgal(theQ, theP0, theP1));
		}

		Standard_Real SquareDistance_cgal
		(
			const Pnt3d& theQ,
			const Pnt3d& theP0,
			const Pnt3d& theP1,
			const Pnt3d& theP2
		);

		inline Standard_Real Distance_cgal
		(
			const Pnt3d& theQ,
			const Pnt3d& theP0,
			const Pnt3d& theP1,
			const Pnt3d& theP2
		)
		{
			return sqrt(SquareDistance_cgal(theQ, theP0, theP1, theP2));
		}

		Standard_Real SquareDistanceSegments_cgal
		(
			const Pnt3d& theQ0,
			const Pnt3d& theQ1,
			const Pnt3d& theP0,
			const Pnt3d& theP1
		);

		inline Standard_Real DistanceSegments_cgal
		(
			const Pnt3d& theQ0,
			const Pnt3d& theQ1,
			const Pnt3d& theP0,
			const Pnt3d& theP1
		)
		{
			return sqrt(SquareDistanceSegments_cgal(theQ0, theQ1, theP0, theP1));
		}

		Standard_Real Oriented_cgal
		(
			const Pnt2d& theQ, 
			const Pnt2d& theP0,
			const Pnt2d& theP1
		);

		Standard_Real Oriented_cgal
		(
			const Pnt3d& theQ,
			const Pnt3d& theP0,
			const Pnt3d& theP1,
			const Pnt3d& theP2
		);

		inline Standard_Real Area_cgal
		(
			const Pnt2d& theP0,
			const Pnt2d& theP1, 
			const Pnt2d& theP2
		)
		{
			return Oriented_cgal(theP0, theP1, theP2)*(Standard_Real)0.5;
		}

		Standard_Real Oriented_predicate(const Pnt2d& theQ, const Pnt2d& theP0, const Pnt2d& theP1);

		inline Standard_Boolean IsPointRightEdge_cgal
		(
			const Pnt2d& Point,
			const Pnt2d& P0,
			const Pnt2d& P1
		)
		{
			return Oriented_cgal(Point, P0, P1) < 0.0;
		}

		inline Standard_Boolean IsPointLeftEdge_cgal
		(
			const Pnt2d& Point,
			const Pnt2d& P0,
			const Pnt2d& P1
		)
		{
			return Oriented_cgal(Point, P0, P1) > 0.0;
		}

		inline Standard_Boolean IsPointRightEdge_fast
		(
			const Pnt2d& Point,
			const Pnt2d& P0,
			const Pnt2d& P1
		)
		{
			return Oriented_fast(Point, P0, P1) < 1.0e-12;
		}

		inline Standard_Boolean IsPointLeftEdge_fast
		(
			const Pnt2d& Point,
			const Pnt2d& P0,
			const Pnt2d& P1
		)
		{
			return Oriented_fast(Point, P0, P1) > 1.0e-12;
		}

		Standard_Boolean IsPointInsideTriangle_cgal
		(
			const Pnt2d& Point,
			const Pnt2d& P0,
			const Pnt2d& P1,
			const Pnt2d& P2
		);

		Standard_Boolean IsPointInsideTriangle_fast
		(
			const Pnt2d& Point,
			const Pnt2d& P0,
			const Pnt2d& P1,
			const Pnt2d& P2
		);

		Standard_Boolean HasIntersection_cgal
		(
			const Pnt2d& theQ0,
			const Pnt2d& theQ1,
			const Pnt2d& theP0,
			const Pnt2d& theP1
		);

		Standard_Boolean IsPairedTwoSegments
		(
			const Standard_Integer v1, 
			const Standard_Integer v2, 
			const Standard_Integer q1,
			const Standard_Integer q2
		);

		inline
		Standard_Boolean IsIntersect
		(
			const Standard_Real U0,
			const Standard_Real U1,
			const Standard_Real V0,
			const Standard_Real V1
		)
		{
			if (U1 < V0)
				return Standard_False;
			else if (V1 < U0)
				return Standard_False;
			else
				return Standard_True;
		}

		inline 
			Standard_Boolean IsOneCommonPointTwoSegments
		(
			const Standard_Integer v1,
			const Standard_Integer v2,
			const Standard_Integer q1,
			const Standard_Integer q2
		)
		{
			if (v1 == q1)
			{
				return Standard_True;
			}
			else if (v1 == q2)
			{
				return Standard_True;
			}
			else if (v2 == q1)
			{
				return Standard_True;
			}
			else if (v2 == q2)
			{
				return Standard_True;
			}

			return Standard_False;
		}

		Standard_Boolean IsOneCommonPointTwoTriangles
		(
			const Standard_Integer v1,
			const Standard_Integer v2,
			const Standard_Integer v3,
			const Standard_Integer q1,
			const Standard_Integer q2, 
			const Standard_Integer q3
		);

		Standard_Boolean IsCcwOrder(const std::vector<Pnt2d>& thePts);

		Standard_Boolean IsCcwOrder_cgal(const std::vector<Pnt2d>& thePts);

		Standard_Boolean IsSimple_cgal(const std::vector<Pnt2d>& thePts);

		Pnt2d IntersectionTwoLines(const Pnt2d& P0, const Pnt2d& t0, const Pnt2d& P1, const Pnt2d& t1);
	}
}

#include <GeoProcessorI.hxx>

#endif // !_GeoProcessor_Header
