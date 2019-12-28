#pragma once
#ifndef _Geo2d_LineSegment_Header
#define _Geo2d_LineSegment_Header

#include <Geo2d_Sketch.hxx>
#include <Pnt2d.hxx>
#include <Dir2d.hxx>

namespace AutLib
{

	class Geo2d_LineSegment
		: public Geo2d_Sketch
	{

		/*Private Data*/

	public:

		Geo2d_LineSegment
		(
			const Pnt2d& theP0,
			const Pnt2d& theP1
		);

		Geo2d_LineSegment
		(
			const Pnt2d& theP0,
			const Dir2d& theDir, 
			const Standard_Real theLength
		);

	};
}

#endif // !_Geo2d_LineSegment_Header
