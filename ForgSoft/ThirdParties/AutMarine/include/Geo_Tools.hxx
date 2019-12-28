#pragma once
#ifndef _Geo_Tools_Header
#define _Geo_Tools_Header

#include <Standard_TypeDef.hxx>
#include <Entity2d_BoxFwd.hxx>
#include <Entity2d_PolygonFwd.hxx>
#include <Entity2d_TriangulationFwd.hxx>

class gp_Pnt;
class Geom_Surface;

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Pnt2d;
	class Pnt3d;

	class Geo_Tools
	{

	public:

		static gp_Pnt CoordOnSurface
		(
			const Pnt2d& theCoord,
			const Geom_Surface& theSurface
		);

		static Standard_Real CalcSegmentLengthOnSurface
		(
			const Pnt2d& theP0, 
			const Pnt2d& theP1, 
			const Geom_Surface& theSurface
		);

		static Standard_Real CalcPolyLengthOnSurface
		(
			const Entity2d_Polygon& thePoly, 
			const Geom_Surface& theSurface
		);

		static std::shared_ptr<Entity2d_Triangulation> Triangulation
		(
			const Entity2d_Box& theBox
		);
	};
}

#endif // !_Geo_Tools_Header
