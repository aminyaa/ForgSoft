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

		Geo2d_Ellipse
		(
			const Pnt2d& theCentre, 
			const Standard_Real theMajorRadius,
			const Standard_Real theMinorRadius,
			const Standard_Boolean theSense = Standard_True
		);

		Geo2d_Ellipse
		(
			const Pnt2d& theCentre,
			const Standard_Real theMajorRadius,
			const Standard_Real theMinorRadius, 
			const Standard_Real theDeg,
			const Standard_Boolean theSense = Standard_True
		);

		Geo2d_Ellipse
		(
			const Pnt2d& theCentre,
			const Dir2d& theDir, 
			const Standard_Real theMajorRadius, 
			const Standard_Real theMinorRadius, 
			const Standard_Real theDeg, 
			const Standard_Boolean theSense = Standard_True
		);
	};
}

#endif // !_Geo2d_Ellipse_Header
