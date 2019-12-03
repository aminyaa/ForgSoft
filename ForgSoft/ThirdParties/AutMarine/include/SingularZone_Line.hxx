#pragma once
#ifndef _SingularZone_Line_Header
#define _SingularZone_Line_Header

#include <Mesh_SingularZone.hxx>

namespace AutLib
{

	template<class SurfPln>
	class SingularZone_Line
		: public Mesh_SingularZone<SurfPln>
	{

		/*Private Data*/

	protected:

		SingularZone_Line()
		{}

		SingularZone_Line(const Standard_Integer theIndex)
			: Mesh_SingularZone<SurfPln>(theIndex)
		{}

	public:

		typedef Mesh_SingularZone<SurfPln> base;
	};
}

#endif // !_SingularZone_Line_Header
