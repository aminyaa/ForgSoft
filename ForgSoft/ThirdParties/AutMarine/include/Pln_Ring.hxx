#pragma once
#ifndef _Pln_Ring_Header
#define _Pln_Ring_Header

#include <Pln_Edge.hxx>

namespace AutLib
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
			const Standard_Boolean Sense = Standard_True,
			const Standard_Boolean Discrete = Standard_False
		)
			: Pln_Edge(theIndex, theName, theVrtx, theVrtx, theCurve, Sense, Discrete)
		{}

		Pln_Ring
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<Pln_Vertex>& theVrtx,
			const std::shared_ptr<Pln_Curve>& theCurve,
			const Standard_Boolean Sense = Standard_True,
			const Standard_Boolean Discrete = Standard_False
		)
			: Pln_Edge(theIndex, theVrtx, theVrtx, theCurve, Sense, Discrete)
		{}

		Pln_Ring
		(
			const std::shared_ptr<Pln_Vertex>& theVrtx,
			const std::shared_ptr<Pln_Curve>& theCurve,
			const Standard_Boolean Sense = Standard_True,
			const Standard_Boolean Discrete = Standard_False
		)
			: Pln_Edge(theVrtx, theVrtx, theCurve, Sense, Discrete)
		{}
	};
}

#endif // !_Pln_Ring_Header
