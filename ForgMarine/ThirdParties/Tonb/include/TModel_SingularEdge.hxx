#pragma once
#ifndef _TModel_SingularEdge_Header
#define _TModel_SingularEdge_Header

#include <TModel_Edge.hxx>

namespace tnbLib
{

	class TModel_SingularEdge
		: public TModel_Edge
	{

		/*Private Data*/

	public:

		TModel_SingularEdge
		(
			const std::shared_ptr<TModel_Vertex>& theVtx,
			const std::shared_ptr<TModel_ParaCurve>& theParaCurve
		);

		TModel_SingularEdge
		(
			const std::shared_ptr<TModel_ParaCurve>& theParaCurve
		);

		TModel_SingularEdge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<TModel_Vertex>& theVtx,
			const std::shared_ptr<TModel_ParaCurve>& theParaCurve
		);

		TModel_SingularEdge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<TModel_ParaCurve>& theParaCurve
		);

		TModel_SingularEdge
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<TModel_Vertex>& theVtx,
			const std::shared_ptr<TModel_ParaCurve>& theParaCurve
		);

		TModel_SingularEdge
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<TModel_ParaCurve>& theParaCurve
		);


		//- override functions and operators

		Standard_Boolean IsDegenerated() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_TModel_SingularEdge_Header
