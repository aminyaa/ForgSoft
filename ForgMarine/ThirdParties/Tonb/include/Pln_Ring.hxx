#pragma once
#ifndef _Pln_Ring_Header
#define _Pln_Ring_Header

#include <Pln_Edge.hxx>

namespace tnbLib
{

	class Pln_Ring
		: public Pln_Edge
	{

		/*Private Data*/

	public:

		Pln_Ring
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<Pln_Vertex>& theVrtx,
			const std::shared_ptr<Pln_Curve>& theCurve,
			const Standard_Boolean Sense = Standard_True
		)
			: Pln_Edge(theIndex, theName, theVrtx, theVrtx, theCurve, Sense)
		{}

		Pln_Ring
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<Pln_Vertex>& theVrtx
		)
			: Pln_Edge(theIndex, theVrtx, theVrtx)
		{}

		Pln_Ring
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<Pln_Vertex>& theVrtx
		)
			: Pln_Edge(theIndex, theName, theVrtx, theVrtx)
		{}

		Pln_Ring
		(
			const std::shared_ptr<Pln_Vertex>& theVrtx,
			const std::shared_ptr<Pln_Curve>& theCurve,
			const Standard_Boolean Sense = Standard_True
		)
			: Pln_Edge(theVrtx, theVrtx)
		{}


		//- override virtual functions

		Standard_Boolean IsRing() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_Pln_Ring_Header
