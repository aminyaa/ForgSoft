#pragma once
#ifndef _Pln_CurveTools_Header
#define _Pln_CurveTools_Header

#include <Standard_Handle.hxx>
#include <Entity2d_BoxFwd.hxx>
#include <Entity2d_TriangulationFwd.hxx>

class gp_Ax2d;
class gp_Ax22d;
class Bnd_Box2d;
class Geom2d_Curve;
class Geom2dAPI_InterCurveCurve;

namespace tnbLib
{

	class Pln_CurveTools
	{

	public:

		static Handle(Geom2d_Curve)
			MakeSegment
			(
				const Pnt2d& theP0,
				const Pnt2d& theP1
			);

		static Handle(Geom2d_Curve)
			MakeCircle
			(
				const gp_Ax22d& A,
				const Standard_Real Radius
			);

		static Handle(Geom2d_Curve)
			MakeCircle
			(
				const gp_Ax2d& A,
				const Standard_Real Radius,
				const Standard_Boolean Sense = Standard_True
			);

		
	};
}

#endif // !_Pln_CurveTools_Header
