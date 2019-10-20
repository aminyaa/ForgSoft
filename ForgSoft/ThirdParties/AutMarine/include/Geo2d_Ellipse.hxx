#pragma once
#ifndef _Geo2d_Ellipse_Header
#define _Geo2d_Ellipse_Header

#include <Geo2d_Sketch.hxx>
#include <Pnt2d.hxx>
#include <Dir2d.hxx>

namespace AutLib
{

	class Geo2d_Ellipse
		: public Geo2d_Sketch
	{

		/*Private Data*/

	public:

		Geo2d_Ellipse(const Pnt2d& theCentre, const Standard_Real theMajorRadius, const Standard_Real theMinorRadius);

		Geo2d_Ellipse(const Pnt2d& theCentre, const Standard_Real theMajorRadius, const Standard_Real theMinorRadius, const Standard_Real theDeg0, const Standard_Real theDeg1);

		Geo2d_Ellipse(const Pnt2d& theCentre, const Dir2d& theDir, const Standard_Real theMajorRadius, const Standard_Real theMinorRadius, const Standard_Real theDeg0, const Standard_Real theDeg1);
	};
}

#endif // !_Geo2d_Ellipse_Header
