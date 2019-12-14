#pragma once
#ifndef _CadRepair_SingularPatch_Common_Header
#define _CadRepair_SingularPatch_Common_Header

#include <CadRepair_SingularPatch.hxx>

namespace AutLib
{

	template<class SurfType>
	class CadRepair_SingularPatch_Common
	{

		typedef typename SurfType::surfPln surfPln;

		/*Private Data*/

	public:

		CadRepair_SingularPatch_Common
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<SurfType>& theSurface,
			const std::shared_ptr<CadSingularity_Detection<surfPln>>& theSingularity
		)
			: CadRepair_SingularPatch<SurfType>(theIndex, theSurface, theSingularity)
		{}
	};
}

#endif // !_CadRepair_SingularPatch_Common_Header
