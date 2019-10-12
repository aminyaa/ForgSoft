#pragma once
#include <Entity_StaticData.hxx>
#include <GeoProcessor.hxx>
namespace AutLib
{
	inline
	Standard_Integer Geo2d_DelTri::Edge
	(
		const Standard_Integer L,
		const Standard_Integer K
	) const
	{
		const auto& E = Data()->Neighbors();
		forThose(Index, 0, 2)
		{
			if (E[Index_Of(L)].Value(Index) IS_EQUAL K) return Index;
		}
		return -1;
	}

	inline 
		Standard_Integer Geo2d_DelTri::TriLoc
		(
			const Pnt2d & theCoord, 
			const Standard_Integer i
		) const
	{
		if (i == 0) return 0;

		const auto& Vtx = Data()->Connectivity();

		auto v1 = Vtx[Index_Of(i)].Value(0) - 1;
		auto v2 = Vtx[Index_Of(i)].Value(1) - 1;
		auto v3 = Vtx[Index_Of(i)].Value(2) - 1;

		const auto& Pts = Data()->Points();
		const auto& Neighb = Data()->Neighbors();

		if (Processor::IsPointRightEdge_cgal(theCoord, Pts[v1], Pts[v2]))
			return TriLoc(theCoord, Neighb[Index_Of(i)].Value(0));
		else if (Processor::IsPointRightEdge_cgal(theCoord, Pts[v2], Pts[v3]))
			return TriLoc(theCoord, Neighb[Index_Of(i)].Value(1));
		else if (Processor::IsPointRightEdge_cgal(theCoord, Pts[v3], Pts[v1]))
			return TriLoc(theCoord, Neighb[Index_Of(i)].Value(2));
		return i;
	}
}