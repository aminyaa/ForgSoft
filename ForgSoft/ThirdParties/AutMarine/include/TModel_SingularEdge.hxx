#pragma once
#ifndef _TModel_SingularEdge_Header
#define _TModel_SingularEdge_Header

#include <TModel_Edge.hxx>

namespace AutLib
{

	class TModel_SingularEdge
		: public TModel_Edge
	{

		/*Private Data*/

	public:

		TModel_SingularEdge
		(
			const std::shared_ptr<TModel_Vertex>& theVtx,
			const std::shared_ptr<TModel_parCurve>& thePar
		)
			: TModel_Edge(theVtx, theVtx, nullptr, thePar, Standard_True)
		{}

		TModel_SingularEdge
		(
			const std::shared_ptr<TModel_parCurve>& thePar,
			const Standard_Boolean theSense = Standard_True
		)
			: TModel_Edge(nullptr, thePar, Standard_True)
		{}

		TModel_SingularEdge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<TModel_Vertex>& theVtx,
			const std::shared_ptr<TModel_parCurve>& thePar
		)
			: TModel_Edge(theIndex, theVtx, theVtx, nullptr, thePar, Standard_True)
		{}

		TModel_SingularEdge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<TModel_parCurve>& thePar
		)
			: TModel_Edge(theIndex, nullptr, thePar, Standard_True)
		{}

		TModel_SingularEdge
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<TModel_Vertex>& theVtx,
			const std::shared_ptr<TModel_parCurve>& thePar
		)
			: TModel_Edge(theIndex, theName, theVtx, theVtx, nullptr, thePar, Standard_True)
		{}

		TModel_SingularEdge
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<TModel_parCurve>& thePar
		)
			: TModel_Edge(theIndex, theName, nullptr, thePar, Standard_True)
		{}


		//- override functions and operators

		Standard_Boolean IsDegenerated() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_TModel_SingularEdge_Header
