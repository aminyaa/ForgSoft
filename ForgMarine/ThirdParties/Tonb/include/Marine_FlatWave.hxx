#pragma once
#ifndef _Marine_FlatWave_Header
#define _Marine_FlatWave_Header

#include <Marine_Wave.hxx>

namespace tnbLib
{

	class Marine_FlatWave
		: public Marine_Wave
	{

		/*Private Data*/

		void MakeProfileCurve(const Pnt2d& x0, const Pnt2d& x1) override;

	protected:

		Dir3d SurfaceDirection() const override;

	public:

		Marine_FlatWave(const Entity3d_Box& theDomain)
			: Marine_Wave(theDomain)
		{}

	};
}

#endif // !_Marine_FlatWave_Header
