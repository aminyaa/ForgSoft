#pragma once
#ifndef _TModel_Ring_Header
#define _TModel_Ring_Header

#include <TModel_Edge.hxx>

namespace AutLib
{

	class TModel_Ring
		: public TModel_Edge
	{

		/*Private Data*/

	public:

		TModel_Ring
		(
			const std::shared_ptr<TModel_Vertex>& theVtx, 
			const std::shared_ptr<TModel_Curve>& theCurve,
			const std::shared_ptr<TModel_parCurve>& thePar,
			const Standard_Boolean theSense = Standard_True
		)
			: TModel_Edge(theVtx, theVtx, theCurve, thePar, theSense)
		{}

		TModel_Ring
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<TModel_Vertex>& theVtx,
			const std::shared_ptr<TModel_Curve>& theCurve,
			const std::shared_ptr<TModel_parCurve>& thePar,
			const Standard_Boolean theSense = Standard_True
		)
			: TModel_Edge(theIndex, theVtx, theVtx, theCurve, thePar, theSense)
		{}

		TModel_Ring
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<TModel_Vertex>& theVtx,
			const std::shared_ptr<TModel_Curve>& theCurve,
			const std::shared_ptr<TModel_parCurve>& thePar,
			const Standard_Boolean theSense = Standard_True
		)
			: TModel_Edge(theIndex, theName, theVtx, theVtx, theCurve, thePar, theSense)
		{}

		TModel_Ring
		(
			const std::shared_ptr<TModel_Curve>& theCurve,
			const std::shared_ptr<TModel_parCurve>& thePar,
			const Standard_Boolean theSense = Standard_True
		)
			: TModel_Edge(theCurve, thePar, theSense)
		{}

		TModel_Ring
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<TModel_Curve>& theCurve,
			const std::shared_ptr<TModel_parCurve>& thePar,
			const Standard_Boolean theSense = Standard_True
		)
			: TModel_Edge(theIndex, theCurve, thePar, theSense)
		{}

		TModel_Ring
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<TModel_Curve>& theCurve,
			const std::shared_ptr<TModel_parCurve>& thePar,
			const Standard_Boolean theSense = Standard_True
		)
			: TModel_Edge(theIndex, theName, theCurve, thePar, theSense)
		{}


		//- override functions and operators

		Standard_Boolean IsRing() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_TModel_Ring_Header
