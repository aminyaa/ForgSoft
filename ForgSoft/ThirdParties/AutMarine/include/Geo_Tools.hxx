#pragma once
#ifndef _Geo_Tools_Header
#define _Geo_Tools_Header

#include <Standard_TypeDef.hxx>
#include <Entity2d_PolygonFwd.hxx>

class gp_Pnt;
class Geom_Surface;

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
	};
}

#endif // !_Geo_Tools_Header
