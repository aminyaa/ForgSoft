#pragma once
inline Standard_Integer 
tnbLib::Geo_Tools::Round
(
	const Standard_Real x
)
{
	return (Standard_Integer)floor(x + 0.5);
}

inline Standard_Real 
tnbLib::Geo_Tools::DegToRadian
(
	const Standard_Real Degree
)
{
	return Degree * M_PI / 180.0;
}

inline Standard_Real 
tnbLib::Geo_Tools::RadianToDegree
(
	const Standard_Real Radian
)
{
	return Radian * 180.0 / M_PI;
}

inline Standard_Real 
tnbLib::Geo_Tools::Distance_cgal
(
	const Pnt2d & theQ, 
	const Pnt2d & theP0,
	const Pnt2d & theP1
)
{
	return sqrt(SquareDistance_cgal(theQ, theP0, theP1));
}

inline Standard_Real 
tnbLib::Geo_Tools::Distance_cgal
(
	const Pnt3d & theQ, 
	const Pnt3d & theP0, 
	const Pnt3d & theP1
)
{
	return sqrt(SquareDistance_cgal(theQ, theP0, theP1));
}

inline Standard_Real 
tnbLib::Geo_Tools::Distance_cgal
(
	const Pnt3d & theQ, 
	const Pnt3d & theP0, 
	const Pnt3d & theP1, 
	const Pnt3d & theP2
)
{
	return sqrt(SquareDistance_cgal(theQ, theP0, theP1, theP2));
}

inline Standard_Real 
tnbLib::Geo_Tools::DistanceSegments_cgal
(
	const Pnt3d & theQ0,
	const Pnt3d & theQ1, 
	const Pnt3d & theP0, 
	const Pnt3d & theP1
)
{
	return sqrt(SquareDistanceSegments_cgal(theQ0, theQ1, theP0, theP1));
}

inline Standard_Real 
tnbLib::Geo_Tools::Area_cgal
(
	const Pnt2d & theP0,
	const Pnt2d & theP1, 
	const Pnt2d & theP2
)
{
	return Oriented_cgal(theP0, theP1, theP2)*(Standard_Real)0.5;
}

inline Standard_Boolean 
tnbLib::Geo_Tools::IsPointRightEdge_cgal
(
	const Pnt2d & Point,
	const Pnt2d & P0, 
	const Pnt2d & P1
)
{
	return Oriented_cgal(Point, P0, P1) < 0.0;
}

inline Standard_Boolean 
tnbLib::Geo_Tools::IsPointRightFacet_cgal
(
	const Pnt3d & thePoint,
	const Pnt3d & theP0, 
	const Pnt3d & theP1, 
	const Pnt3d & theP2
)
{
	return Oriented_cgal(thePoint, theP0, theP1, theP2) < 0.0;
}

inline Standard_Boolean 
tnbLib::Geo_Tools::IsPointLeftEdge_cgal
(
	const Pnt2d & Point, 
	const Pnt2d & P0, 
	const Pnt2d & P1
)
{
	return Oriented_cgal(Point, P0, P1) > 0.0;
}

inline Standard_Boolean 
tnbLib::Geo_Tools::IsPointLeftFacet_cgal
(
	const Pnt3d & thePoint,
	const Pnt3d & theP0, 
	const Pnt3d & theP1, 
	const Pnt3d & theP2
)
{
	return Oriented_cgal(thePoint, theP0, theP1, theP2) > 0.0;
}

inline Standard_Boolean 
tnbLib::Geo_Tools::IsPointInsideTriangle_cgal
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

inline Standard_Boolean 
tnbLib::Geo_Tools::IsPairedTwoSegments
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

inline Standard_Boolean 
tnbLib::Geo_Tools::IsIntersect
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

inline Standard_Boolean 
tnbLib::Geo_Tools::IsOneCommonPointTwoSegments
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

inline Standard_Boolean 
tnbLib::Geo_Tools::IsOneCommonPointTwoTriangles
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