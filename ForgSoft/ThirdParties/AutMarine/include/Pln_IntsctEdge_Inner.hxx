#pragma once
#ifndef _Pln_IntsctEdge_Inner_Header
#define _Pln_IntsctEdge_Inner_Header

#include <Pln_IntsctEdge.hxx>

namespace AutLib
{

	class Pln_IntsctEdge_Inner
		: public Pln_IntsctEdge
	{

		/*Private Data*/

	public:

		Pln_IntsctEdge_Inner
		(
			const std::shared_ptr<Pln_Vertex>& theV0,
			const std::shared_ptr<Pln_Vertex>& theV1,
			const std::shared_ptr<Pln_Curve>& theCurve,
			const Standard_Boolean Sense = Standard_True,
			const Standard_Boolean Discrete = Standard_False
		)
			: Pln_IntsctEdge(theV0, theV1, theCurve, Sense, Discrete)
		{}

		Pln_IntsctEdge_Inner
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<Pln_Vertex>& theV0,
			const std::shared_ptr<Pln_Vertex>& theV1,
			const std::shared_ptr<Pln_Curve>& theCurve,
			const Standard_Boolean Sense = Standard_True,
			const Standard_Boolean Discrete = Standard_False
		)
			: Pln_IntsctEdge(theIndex, theV0, theV1, theCurve, Sense, Discrete)
		{}

		Pln_IntsctEdge_Inner
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<Pln_Vertex>& theV0,
			const std::shared_ptr<Pln_Vertex>& theV1,
			const std::shared_ptr<Pln_Curve>& theCurve,
			const Standard_Boolean Sense = Standard_True,
			const Standard_Boolean Discrete = Standard_False
		)
			: Pln_IntsctEdge(theIndex, theName, theV0, theV1, theCurve, Sense, Discrete)
		{}
	};
}

#endif // !_Pln_IntsctEdge_Inner_Header
