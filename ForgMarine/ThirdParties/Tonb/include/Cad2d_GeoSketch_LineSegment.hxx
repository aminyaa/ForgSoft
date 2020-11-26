#pragma once
#ifndef _Cad2d_GeoSketch_LineSegment_Header
#define _Cad2d_GeoSketch_LineSegment_Header

#include <Cad2d_GeoSketch.hxx>
#include <Pnt2d.hxx>
#include <Dir2d.hxx>

namespace tnbLib
{

	class Cad2d_GeoSketch_LineSegment
		: public Cad2d_GeoSketch
	{

		/*Private Data*/

	public:

		Cad2d_GeoSketch_LineSegment
		(
			const Pnt2d& theP0,
			const Pnt2d& theP1
		);

		Cad2d_GeoSketch_LineSegment
		(
			const Pnt2d& theP0,
			const Dir2d& theDir,
			const Standard_Real theLength
		);
	};
}

#endif // !_Cad2d_GeoSketch_LineSegment_Header
