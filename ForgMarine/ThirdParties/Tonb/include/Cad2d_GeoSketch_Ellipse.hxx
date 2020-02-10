#pragma once
#ifndef _Cad2d_GeoSketch_Ellipse_Header
#define _Cad2d_GeoSketch_Ellipse_Header

#include <Cad2d_GeoSketch.hxx>
#include <Pnt2d.hxx>
#include <Dir2d.hxx>

namespace tnbLib
{

	class Cad2d_GeoSketch_Ellipse
		: public Cad2d_GeoSketch
	{

		/*Private Data*/

	public:

		Cad2d_GeoSketch_Ellipse
		(
			const Pnt2d& theCentre,
			const Standard_Real theMajorRadius,
			const Standard_Real theMinorRadius,
			const Standard_Boolean theSense = Standard_True
		);

		Cad2d_GeoSketch_Ellipse
		(
			const Pnt2d& theCentre,
			const Standard_Real theMajorRadius,
			const Standard_Real theMinorRadius,
			const Standard_Real theDeg,
			const Standard_Boolean theSense = Standard_True
		);

		Cad2d_GeoSketch_Ellipse
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

#endif // !_Cad2d_GeoSketch_Ellipse_Header
