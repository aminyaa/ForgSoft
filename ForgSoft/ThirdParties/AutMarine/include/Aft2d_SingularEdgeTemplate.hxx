#pragma once
#ifndef _Aft2d_SingularEdgeTemplate_Header
#define _Aft2d_SingularEdgeTemplate_Header

#include <Standard_TypeDef.hxx>

#include <memory>

namespace AutLib
{

	template<class BndEdgeType>
	class Aft2d_SingularEdgeTemplate
		: public BndEdgeType
	{

		/*Private Data*/

	protected:

		typedef typename BndEdgeType::bndNodeType bndNodeType;
		typedef typename BndEdgeType::bndEdgeType bndEdgeType;

		Aft2d_SingularEdgeTemplate()
		{}

		Aft2d_SingularEdgeTemplate(const Standard_Integer theIndex)
			: BndEdgeType(theIndex)
		{}

		Aft2d_SingularEdgeTemplate
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<typename BndEdgeType::nodeType>& theNode0,
			const std::shared_ptr<typename BndEdgeType::nodeType>& theNode1
		)
			: BndEdgeType(theIndex, theNode0, theNode1)
		{}

	public:

		typedef BndEdgeType base;

		//- Static functions and operators
	};
}

#endif // !_Aft2d_SingularEdgeTemplate_Header
