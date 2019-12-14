#pragma once
#ifndef _CadRepair_SingularPatch_Deep_Header
#define _CadRepair_SingularPatch_Deep_Header

#include <CadRepair_SingularPatch.hxx>

namespace AutLib
{

	template<class SurfType>
	class CadRepair_SingularPatch_Deep
		: public CadRepair_SingularPatch<SurfType>
	{

		typedef typename SurfType::surfPln surfPln;

		/*Private Data*/

	public:

		CadRepair_SingularPatch_Deep
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<SurfType>& theSurface, 
			const std::shared_ptr<CadSingularity_Detection<surfPln>>& theSingularity
		)
			: CadRepair_SingularPatch<SurfType>(theIndex, theSurface, theSingularity)
		{}
	};
}

#endif // !_CadRepair_SingularPatch_Deep_Header
