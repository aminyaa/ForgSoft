#pragma once
#ifndef _Aft2d_LineNodeTemplate_Header
#define _Aft2d_LineNodeTemplate_Header

#include <Aft2d_SingularNodeTemplate.hxx>

namespace AutLib
{

	template<class BndNodeType>
	class Aft2d_LineNodeTemplate
		: public Aft2d_SingularNodeTemplate<BndNodeType>
	{

		/*Private Data*/

	public:

		typedef Aft2d_SingularNodeTemplate<BndNodeType>
			base;

		Aft2d_LineNodeTemplate()
		{}

		Aft2d_LineNodeTemplate
		(
			const Standard_Integer theIndex
		)
			: Aft2d_SingularNodeTemplate<BndNodeType>(theIndex)
		{}

		Aft2d_LineNodeTemplate
		(
			const Standard_Integer theIndex, 
			const Pnt2d& theCoord
		)
			: Aft2d_SingularNodeTemplate<BndNodeType>(theIndex, theCoord)
		{}


		//- Static functions and operators

		static std::shared_ptr<BndNodeType> MergeNodes
		(
			const std::shared_ptr<BndNodeType>& theNode0,
			const std::shared_ptr<BndNodeType>& theNode1,
			const typename base::Merge_Alg Alg = base::Merge_Alg::New
		);
	};
}

#include <Aft2d_LineNodeTemplateI.hxx>

#endif // !_Aft2d_LineNodeTemplate_Header
