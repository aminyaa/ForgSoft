#pragma once
#ifndef _Aft2d_SingularNodeTemplate_Header
#define _Aft2d_SingularNodeTemplate_Header

#include <Pnt2d.hxx>

namespace AutLib
{

	template<class BndNodeType>
	class Aft2d_SingularNodeTemplate
		: public BndNodeType
	{

		/*Private Data*/

	protected:

		Aft2d_SingularNodeTemplate()
		{}

		Aft2d_SingularNodeTemplate
		(
			const Standard_Integer theIndex
		)
			: BndNodeType(theIndex)
		{}

		Aft2d_SingularNodeTemplate
		(
			const Standard_Integer theIndex,
			const Pnt2d& theCoord
		)
			: BndNodeType(theIndex, theCoord)
		{}

	public:


	};
}

#endif // !_Aft2d_SingularNodeTemplate_Header
