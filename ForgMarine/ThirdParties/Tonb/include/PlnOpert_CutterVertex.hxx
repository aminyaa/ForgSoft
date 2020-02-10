#pragma once
#ifndef _PlnOpert_CutterVertex_Header
#define _PlnOpert_CutterVertex_Header

#include <Pln_Vertex.hxx>

namespace tnbLib
{

	// Forward Declarations
	class PlnOpert_CutterEntity;

	class PlnOpert_CutterVertex
		: public Pln_Vertex
	{

		/*Private Data*/

		std::shared_ptr<PlnOpert_CutterEntity> theCutterEntity_;

	public:

		PlnOpert_CutterVertex()
		{}

		PlnOpert_CutterVertex
		(
			const Pnt2d& theCoord
		)
			: Pln_Vertex(theCoord)
		{}

		PlnOpert_CutterVertex
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Pnt2d& theCoord
		)
			: Pln_Vertex(theIndex, theName, theCoord)
		{}

		PlnOpert_CutterVertex(const Pln_Vertex& theVertex)
			: Pln_Vertex(theVertex)
		{}


		Standard_Boolean IsCutter() const override
		{
			return Standard_True;
		}

		//- Macros
		GLOBAL_ACCESS_SINGLE(std::shared_ptr<PlnOpert_CutterEntity>, CutterEntity)
	};
}

#endif // !_PlnOpert_CutterVertex_Header
