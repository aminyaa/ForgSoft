#pragma once
#ifndef _Vec2d_Header
#define _Vec2d_Header

#include <gp_Vec2d.hxx>
#include <Pnt2d.hxx>

namespace AutLib
{

	class Dir2d;

	class Vec2d
		: public gp_Vec2d
	{

		/*Private Data*/

	public:

		static const Vec2d null;

		Vec2d()
		{}

		Vec2d
		(
			const Dir2d& V
		);

		Vec2d
		(
			const gp_XY& Coord
		)
			: gp_Vec2d(Coord)
		{}

		Vec2d
		(
			const Standard_Real Xv,
			const Standard_Real Yv
		)
			: gp_Vec2d(Xv, Yv)
		{}

		Vec2d
		(
			const Pnt2d& theP0,
			const Pnt2d& theP1
		)
			: gp_Vec2d(theP0, theP1)
		{}
	};
}

#endif // !_Vec2d_Header
