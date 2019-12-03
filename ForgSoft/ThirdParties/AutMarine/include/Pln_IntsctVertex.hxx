#pragma once
#ifndef _Pln_IntsctVertex_Header
#define _Pln_IntsctVertex_Header

#include <Pln_Vertex.hxx>

namespace AutLib
{

	// Forward Declarations


	class Pln_IntsctVertex
		: public Pln_Vertex
	{

		/*Private Data*/

	public:

		Pln_IntsctVertex()
		{}

		Pln_IntsctVertex(const Standard_Integer theIndex)
			: Pln_Vertex(theIndex)
		{}

		Pln_IntsctVertex
		(
			const Standard_Integer theIndex,
			const Pnt2d& theCoord
		)
			: Pln_Vertex(theIndex, theCoord)
		{}

		Pln_IntsctVertex
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Pnt2d& theCoord
		)
			: Pln_Vertex(theIndex, theName, theCoord)
		{}
	};
}

#endif // !_Pln_IntsctVertex_Header
