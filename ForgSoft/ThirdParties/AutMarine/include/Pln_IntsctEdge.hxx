#pragma once
#ifndef _Pln_IntsctEdge_Header
#define _Pln_IntsctEdge_Header

#include <Pln_Edge.hxx>

namespace AutLib
{

	class Pln_IntsctEdge
		: public Pln_Edge
	{

		/*Private Data*/

	protected:

		Pln_IntsctEdge
		(
			const std::shared_ptr<Pln_Vertex>& theV0,
			const std::shared_ptr<Pln_Vertex>& theV1,
			const std::shared_ptr<Pln_Curve>& theCurve,
			const Standard_Boolean Sense = Standard_True,
			const Standard_Boolean Discrete = Standard_False
		)
			: Pln_Edge(theV0, theV1, theCurve, Sense, Discrete)
		{}

		Pln_IntsctEdge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<Pln_Vertex>& theV0,
			const std::shared_ptr<Pln_Vertex>& theV1,
			const std::shared_ptr<Pln_Curve>& theCurve,
			const Standard_Boolean Sense = Standard_True,
			const Standard_Boolean Discrete = Standard_False
		)
			: Pln_Edge(theIndex, theV0, theV1, theCurve, Sense, Discrete)
		{}

		Pln_IntsctEdge
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<Pln_Vertex>& theV0,
			const std::shared_ptr<Pln_Vertex>& theV1,
			const std::shared_ptr<Pln_Curve>& theCurve,
			const Standard_Boolean Sense = Standard_True,
			const Standard_Boolean Discrete = Standard_False
		)
			: Pln_Edge(theIndex, theName, theV0, theV1, theCurve, Sense, Discrete)
		{}

	public:


	};
}

#endif // !_Pln_IntsctEdge_Header
