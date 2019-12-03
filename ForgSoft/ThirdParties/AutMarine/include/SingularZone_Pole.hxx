#pragma once
#ifndef _SingularZone_Pole_Header
#define _SingularZone_Pole_Header

#include <Mesh_SingularZone.hxx>

namespace AutLib
{

	template<class SurfPln>
	class SingularZone_Pole
		: public Mesh_SingularZone<SurfPln>
	{

		/*Private Data*/

		Pnt2d thePole_;

	protected:

		SingularZone_Pole()
		{}

		SingularZone_Pole(const Standard_Integer theIndex)
			: Mesh_SingularZone<SurfPln>(theIndex)
		{}

		Pnt2d& ChangePole()
		{
			return thePole_;
		}

	public:

		typedef Mesh_SingularZone<SurfPln> base;

		const Pnt2d& Pole() const
		{
			return thePole_;
		}
	};
}

#endif // !_SingularZone_Pole_Header
