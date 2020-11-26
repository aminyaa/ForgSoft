#pragma once
#ifndef _Cad2d_GeoSketch_Circle_Header
#define _Cad2d_GeoSketch_Circle_Header

#include <Cad2d_GeoSketch.hxx>
#include <Pnt2d.hxx>
#include <Dir2d.hxx>

namespace tnbLib
{

	class Cad2d_GeoSketch_Circle
		: public Cad2d_GeoSketch
	{

		/*Private Data*/

	public:

		Cad2d_GeoSketch_Circle
		(
			const Pnt2d& theCentre,
			const Standard_Real theRadius
		);

		Cad2d_GeoSketch_Circle
		(
			const Pnt2d& theCentre,
			const Standard_Real theRadius,
			const Standard_Boolean theSense
		);

		Cad2d_GeoSketch_Circle
		(
			const Pnt2d& theCentre,
			const Standard_Real theRadius,
			const Dir2d& theDir,
			const Standard_Real theDeg,
			const Standard_Boolean Sense = Standard_True
		);

	};
}

#endif // !_Cad2d_GeoSketch_Circle_Header
