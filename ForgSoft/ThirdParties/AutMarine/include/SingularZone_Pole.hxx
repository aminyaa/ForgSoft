#pragma once
#ifndef _SingularZone_Pole_Header
#define _SingularZone_Pole_Header

#include <Cad_SingularZone.hxx>

namespace AutLib
{

	template<class SurfPln>
	class SingularZone_Pole
		: public Cad_SingularZone<SurfPln>
	{

		/*Private Data*/

		Pnt2d thePole_;

	protected:

		SingularZone_Pole()
		{}

		SingularZone_Pole(const Standard_Integer theIndex)
			: Cad_SingularZone<SurfPln>(theIndex)
		{}

	public:

		typedef Cad_SingularZone<SurfPln> base;

		const Pnt2d& Pole() const
		{
			return thePole_;
		}

		void SetPole(const Pnt2d& thePole)
		{
			thePole_ = thePole;
		}
	};
}

#endif // !_SingularZone_Pole_Header
