#pragma once
#ifndef _Pln_TangEdge_Header
#define _Pln_TangEdge_Header

#include <Pln_Edge.hxx>

namespace tnbLib
{

	class Pln_TangEdge
		: public Pln_Edge
	{

		/*Private Data*/

		std::weak_ptr<Pln_TangEdge> thePair_;

	public:

		Pln_TangEdge
		(
			const std::shared_ptr<Pln_Vertex>& theVtx0,
			const std::shared_ptr<Pln_Vertex>& theVtx1
		);

		Pln_TangEdge
		(
			const std::shared_ptr<Pln_Vertex>& theVtx0,
			const std::shared_ptr<Pln_Vertex>& theVtx1,
			const std::shared_ptr<Pln_Curve>& theCurve,
			const Standard_Boolean Sense = Standard_True
		);

		Pln_TangEdge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<Pln_Vertex>& theVtx0,
			const std::shared_ptr<Pln_Vertex>& theVtx1
		);

		Pln_TangEdge
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<Pln_Vertex>& theVtx0,
			const std::shared_ptr<Pln_Vertex>& theVtx1
		);

		Pln_TangEdge
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<Pln_Vertex>& theVtx0,
			const std::shared_ptr<Pln_Vertex>& theVtx1,
			const std::shared_ptr<Pln_Curve>& theCurve,
			const Standard_Boolean Sense = Standard_True
		);


		Standard_Boolean IsTangential() const override
		{
			return Standard_True;
		}

		//- Macros
		GLOBAL_ACCESS_SINGLE(std::weak_ptr<Pln_TangEdge>, Pair)
	};
}

#endif // !_Pln_TangEdge_Header
