#pragma once
#ifndef _Geo_CmptLib_Header
#define _Geo_CmptLib_Header

#include <Pnt2d.hxx>
#include <Entity2d_PolygonFwd.hxx>

#include <vector>

namespace tnbLib
{

	class Geo_CmptLib
	{

	public:

		static Standard_Real 
			Area
			(
				const Entity2d_Polygon& thePoly
			);

		static Standard_Real
			CxProductArea
			(
				const Entity2d_Polygon& thePoly
			);

		static Standard_Real 
			CyProductArea
			(
				const Entity2d_Polygon& thePoly
			);

		static Pnt2d 
			Centre
			(
				const Entity2d_Polygon& thePoly
			);

		static Standard_Real 
			Ix
			(
				const Entity2d_Polygon& thePoly,
				const Standard_Real y0
			);

		static Standard_Real 
			Iy
			(
				const Entity2d_Polygon& thePoly,
				const Standard_Real x0
			);

		static Standard_Real 
			Ixy
			(
				const Entity2d_Polygon& thePoly,
				const Pnt2d& theC
			);

		static Standard_Real 
			Ixi
			(
				const Standard_Real IxiBar, 
				const Standard_Real theArea, 
				const Standard_Real dxi
			);

		static Standard_Real
			Gyradius
			(
				const Standard_Real Ix,
				const Standard_Real theArea
			);

		static Standard_Real 
			Ixi
			(
				const std::vector<Standard_Real>& ix,
				const std::vector<Standard_Real>& Ax,
				const std::vector<Standard_Real>& dx
			);

		static Standard_Real 
			Ixy
			(
				const Standard_Real IxyBar,
				const Standard_Real dx,
				const Standard_Real dy, 
				const Standard_Real Area
			);

	};
}

#endif // !_Geo_CmptLib_Header
