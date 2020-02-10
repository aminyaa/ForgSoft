#pragma once
#ifndef _Dir3d_Header
#define _Dir3d_Header

#include <gp_Dir.hxx>
#include <Vec3d.hxx>

namespace tnbLib
{

	class Pnt3d;

	class Dir3d
		: public gp_Dir
	{

		/*Private Data*/

	public:

		static const Dir3d null;

		Dir3d()
		{}

		Dir3d(const gp_XYZ& xyz)
			: gp_Dir(xyz)
		{}

		Dir3d(const Vec3d& v)
			: gp_Dir(v)
		{}

		Dir3d
		(
			const Standard_Real x, 
			const Standard_Real y, 
			const Standard_Real z
		)
			: gp_Dir(x, y, z)
		{}

		Dir3d(const Pnt3d& theP0, const Pnt3d& theP1);

	};
}

#endif // !_Dir3d_Header
