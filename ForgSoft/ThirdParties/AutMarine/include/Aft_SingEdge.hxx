#pragma once
#ifndef _Aft_SingEdge_Header
#define _Aft_SingEdge_Header

#include <Standard_TypeDef.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	template<class SurfPln>
	class Mesh_SingularZone;

	template<class BndEdgeType, class SurfPln>
	class Aft_SingEdge
		: public BndEdgeType
	{

	public:

		typedef BndEdgeType base;
		typedef Mesh_SingularZone<SurfPln> singularZone;

	private:

		/*Private Data*/

		std::shared_ptr<singularZone> theZone_;

	public:

		Aft_SingEdge()
		{}

		Aft_SingEdge
		(
			const Standard_Integer theIndex
		)
			: base(theIndex)
		{}

		Aft_SingEdge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<typename base::nodeType>& theNode0,
			const std::shared_ptr<typename base::nodeType>& theNode1
		)
			: base(theIndex, theNode0, theNode1)
		{}


		//- static functions and operators

		static Standard_Boolean IsSingular(const std::shared_ptr<BndEdgeType>& theEdge);

		// Macros

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<singularZone>, Zone)
	};
}

#include <Aft_SingEdgeI.hxx>

#endif // !_Aft_SingEdge_Header
