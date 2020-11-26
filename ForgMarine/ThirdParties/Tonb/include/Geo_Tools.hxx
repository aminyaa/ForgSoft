#pragma once
#ifndef _Geo_Tools_Header
#define _Geo_Tools_Header

#include <Pnt2d.hxx>
#include <Pnt3d.hxx>
#include <Entity2d_PolygonFwd.hxx>
#include <Entity3d_PolygonFwd.hxx>
#include <Entity2d_ChainFwd.hxx>
#include <Entity3d_ChainFwd.hxx>
#include <Entity3d_TriangulationFwd.hxx>

#include <vector>
#include <memory>

namespace tnbLib
{

	class Geo_Tools
	{

	public:

		static Standard_Integer
			Round
			(
				const Standard_Real x
			);

		static Standard_Real
			DegToRadian
			(
				const Standard_Real Degree
			);

		static Standard_Real
			RadianToDegree
			(
				const Standard_Real Radian
			);

		static Standard_Real
			SquareDistance_cgal
			(
				const Pnt2d& theQ,
				const Pnt2d& theP0,
				const Pnt2d& theP1
			);

		static Standard_Real
			SquareDistance_cgal
			(
				const Pnt3d& theQ,
				const Pnt3d& theP0,
				const Pnt3d& theP1
			);

		static Standard_Real
			Distance_cgal
			(
				const Pnt2d& theQ,
				const Pnt2d& theP0,
				const Pnt2d& theP1
			);

		static Standard_Real
			Distance_cgal
			(
				const Pnt3d& theQ,
				const Pnt3d& theP0,
				const Pnt3d& theP1
			);

		static Standard_Real
			SquareDistance_cgal
			(
				const Pnt3d& theQ,
				const Pnt3d& theP0,
				const Pnt3d& theP1,
				const Pnt3d& theP2
			);

		static Standard_Real
			Distance_cgal
			(
				const Pnt3d& theQ,
				const Pnt3d& theP0,
				const Pnt3d& theP1,
				const Pnt3d& theP2
			);

		static Standard_Real
			SquareDistanceSegments_cgal
			(
				const Pnt3d& theQ0,
				const Pnt3d& theQ1,
				const Pnt3d& theP0,
				const Pnt3d& theP1
			);

		static Standard_Real
			DistanceSegments_cgal
			(
				const Pnt3d& theQ0,
				const Pnt3d& theQ1,
				const Pnt3d& theP0,
				const Pnt3d& theP1
			);

		static Standard_Real
			Oriented_cgal
			(
				const Pnt2d& theQ,
				const Pnt2d& theP0,
				const Pnt2d& theP1
			);

		static Standard_Real
			Oriented_cgal
			(
				const Pnt3d& theQ,
				const Pnt3d& theP0,
				const Pnt3d& theP1,
				const Pnt3d& theP2
			);

		static Standard_Real
			Area_cgal
			(
				const Pnt2d& theP0,
				const Pnt2d& theP1,
				const Pnt2d& theP2
			);

		static Standard_Boolean
			IsPointRightEdge_cgal
			(
				const Pnt2d& Point,
				const Pnt2d& P0,
				const Pnt2d& P1
			);

		static Standard_Boolean
			IsPointRightFacet_cgal
			(
				const Pnt3d& thePoint,
				const Pnt3d& theP0,
				const Pnt3d& theP1,
				const Pnt3d& theP2
			);

		static Standard_Boolean
			IsPointLeftEdge_cgal
			(
				const Pnt2d& Point,
				const Pnt2d& P0,
				const Pnt2d& P1
			);

		static Standard_Boolean
			IsPointLeftFacet_cgal
			(
				const Pnt3d& thePoint,
				const Pnt3d& theP0,
				const Pnt3d& theP1,
				const Pnt3d& theP2
			);

		static Standard_Boolean
			IsPointInsideTriangle_cgal
			(
				const Pnt2d& Point,
				const Pnt2d& P0,
				const Pnt2d& P1,
				const Pnt2d& P2
			);

		static Standard_Boolean
			IsPointInsideTriangleCW_cgal
			(
				const Pnt2d& Point,
				const Pnt2d& P0,
				const Pnt2d& P1,
				const Pnt2d& P2
			);

		static Standard_Boolean
			HasIntersection_cgal
			(
				const Pnt2d& theQ0,
				const Pnt2d& theQ1,
				const Pnt2d& theP0,
				const Pnt2d& theP1
			);

		static Standard_Boolean
			IsPairedTwoSegments
			(
				const Standard_Integer v1,
				const Standard_Integer v2,
				const Standard_Integer q1,
				const Standard_Integer q2
			);

		static Standard_Boolean
			IsIntersect
			(
				const Standard_Real U0,
				const Standard_Real U1,
				const Standard_Real V0,
				const Standard_Real V1
			);

		static Standard_Boolean
			IsOneCommonPointTwoSegments
			(
				const Standard_Integer v1,
				const Standard_Integer v2,
				const Standard_Integer q1,
				const Standard_Integer q2
			);

		static Standard_Boolean
			IsOneCommonPointTwoTriangles
			(
				const Standard_Integer v1,
				const Standard_Integer v2,
				const Standard_Integer v3,
				const Standard_Integer q1,
				const Standard_Integer q2,
				const Standard_Integer q3
			);

		static Standard_Boolean
			IsCcwOrder_cgal
			(
				const std::vector<Pnt2d>& thePts
			);

		static Standard_Boolean
			IsSimple_cgal
			(
				const std::vector<Pnt2d>& thePts
			);

		static Pnt2d 
			IntersectionTwoLines
			(
				const Pnt2d& P0,
				const Pnt2d& t0,
				const Pnt2d& P1,
				const Pnt2d& t1
			);

		static Pnt2d 
			ProjectPtAtSegment
			(
				const Pnt2d& thePt,
				const Pnt2d& theP0, 
				const Pnt2d& theP1
			);

		static std::shared_ptr<Entity2d_Chain>
			RetrieveChain
			(
				const Entity2d_Polygon& thePoly
			);

		static std::shared_ptr<Entity2d_Chain>
			RetrieveChain
			(
				const std::vector<std::shared_ptr<Entity2d_Polygon>>& thePoly
			);

		static std::shared_ptr<Entity3d_Chain>
			RetrieveChain
			(
				const std::vector<std::shared_ptr<Entity3d_Polygon>>& thePoly
			);

		static std::shared_ptr<Entity3d_Chain>
			RetrieveChain
			(
				const std::vector<std::shared_ptr<Entity3d_Chain>>& theChains
			);

		static std::shared_ptr<Entity3d_Triangulation>
			Triangulation
			(
				const Entity3d_Chain& theChain
			);


	};
}

#include <Geo_ToolsI.hxx>

#endif // !_Geo_Tools_Header
