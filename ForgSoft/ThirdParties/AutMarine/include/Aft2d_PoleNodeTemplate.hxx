#pragma once
#ifndef _Aft2d_PoleNodeTemplate_Header
#define _Aft2d_PoleNodeTemplate_Header

#include <Aft2d_SingularNodeTemplate.hxx>

namespace AutLib
{

	template<class BndNodeType>
	class Aft2d_PoleNodeTemplate
		: public Aft2d_SingularNodeTemplate<BndNodeType>
	{

		/*Private Data*/

		Standard_Boolean IsFixed_;

	public:

		typedef Aft2d_SingularNodeTemplate<BndNodeType>
			base;

		Aft2d_PoleNodeTemplate()
			: IsFixed_(Standard_False)
		{}

		Aft2d_PoleNodeTemplate
		(
			const Standard_Integer theIndex
		)
			: Aft2d_SingularNodeTemplate<BndNodeType>(theIndex)
			, IsFixed_(Standard_False)
		{}

		Aft2d_PoleNodeTemplate
		(
			const Standard_Integer theIndex,
			const Pnt2d& theCoord
		)
			: Aft2d_SingularNodeTemplate<BndNodeType>(theIndex, theCoord)
			, IsFixed_(Standard_False)
		{}

		Standard_Boolean IsFixed() const
		{
			return IsFixed_;
		}

		void SetFixed(const Standard_Boolean IsFixed)
		{
			IsFixed_ = IsFixed;
		}


		//- Static functions and operators

		static std::shared_ptr<BndNodeType> MergeNodes
		(
			const std::shared_ptr<BndNodeType>& theNode0,
			const std::shared_ptr<BndNodeType>& theNode1,
			const typename base::Merge_Alg Alg = base::Merge_Alg::New
		);
	};
}

#include <Aft2d_PoleNodeTemplateI.hxx>

#endif // !_Aft2d_PoleNodeTemplate_Header
