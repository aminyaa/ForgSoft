#pragma once
#ifndef _PlnOpert_IntsctVertex_Header
#define _PlnOpert_IntsctVertex_Header

#include <Pln_Vertex.hxx>

namespace tnbLib
{

	// Forward Declarations
	class PlnOpert_IntsctPoint;

	class PlnOpert_IntsctVertex
		: public Pln_Vertex
	{

		/*Private Data*/

		std::shared_ptr<PlnOpert_IntsctPoint> theIntsctEntity_;

	public:

		PlnOpert_IntsctVertex()
		{}

		PlnOpert_IntsctVertex(const Pnt2d& theCoord)
			: Pln_Vertex(theCoord)
		{}

		PlnOpert_IntsctVertex
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Pnt2d& theCoord
		)
			: Pln_Vertex(theIndex, theName, theCoord)
		{}

		PlnOpert_IntsctVertex(const Pln_Vertex& theVertex)
			: Pln_Vertex(theVertex)
		{}


		Standard_Boolean IsIntersect() const override
		{
			return Standard_True;
		}

		//- Macros
		GLOBAL_ACCESS_SINGLE(std::shared_ptr<PlnOpert_IntsctPoint>, IntsctEntity)
	};
}

#endif // !_PlnOpert_IntsctVertex_Header
