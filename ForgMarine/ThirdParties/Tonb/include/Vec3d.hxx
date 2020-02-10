#pragma once
#ifndef _Vec3d_Header
#define _Vec3d_Header

#include <gp_Vec.hxx>
#include <Pnt3d.hxx>

namespace tnbLib
{

	class Dir3d;

	class Vec3d
		: public gp_Vec
	{

		/*Private Data*/

	public:

		static const Vec3d null;

		Vec3d()
		{}

		Vec3d(const Dir3d& V);

		Vec3d(const gp_XYZ& xyz)
			: gp_Vec(xyz)
		{}

		Vec3d(const Standard_Real x, const Standard_Real y, const Standard_Real z)
			: gp_Vec(x, y, z)
		{}

		Vec3d(const Pnt3d& theP0, const Pnt3d& theP1)
			: gp_Vec(theP0, theP1)
		{}
	};
}

#endif // !_Vec3d_Header
