#pragma once
#ifndef _SingularZone_Line_Header
#define _SingularZone_Line_Header

#include <Cad_SingularZone.hxx>

namespace AutLib
{

	template<class SurfPln>
	class SingularZone_Line
		: public Cad_SingularZone<SurfPln>
	{

		/*Private Data*/

	protected:

		SingularZone_Line()
		{}

		SingularZone_Line(const Standard_Integer theIndex)
			: Cad_SingularZone<SurfPln>(theIndex)
		{}

	public:

		typedef Cad_SingularZone<SurfPln> base;
	};
}

#endif // !_SingularZone_Line_Header
