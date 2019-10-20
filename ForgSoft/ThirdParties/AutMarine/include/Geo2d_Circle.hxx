#pragma once
#ifndef _Geo2d_Circle_Header
#define _Geo2d_Circle_Header

#include <Geo2d_Sketch.hxx>
#include <Pnt2d.hxx>
#include <Dir2d.hxx>

namespace AutLib
{

	class Geo2d_Circle
		: public Geo2d_Sketch
	{

		/*Private Data*/

	public:

		Geo2d_Circle
		(
			const Pnt2d& theCentre,
			const Standard_Real theRadius
		);

		Geo2d_Circle
		(
			const Pnt2d& theCentre,
			const Standard_Real theRadius,
			const Standard_Boolean theSense
		);

		Geo2d_Circle
		(
			const Pnt2d& theCentre,
			const Standard_Real theRadius, 
			const Dir2d& theDir, 
			const Standard_Real theDeg, 
			const Standard_Boolean Sense = Standard_True
		);
	};
}

#endif // !_Geo2d_Circle_Header
