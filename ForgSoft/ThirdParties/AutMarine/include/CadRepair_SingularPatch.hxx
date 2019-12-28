#pragma once
#ifndef _CadRepair_SingularPatch_Header
#define _CadRepair_SingularPatch_Header

#include <CadRepair_ImpPatch.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	template<class SurfPln>
	class CadSingularity_Detection;

	template<class SurfType>
	class CadRepair_SingularPatch
		: public CadRepair_ImpPatch<SurfType>
	{

		typedef typename SurfType::planeType surfPln;

		/*private Data*/

		std::shared_ptr<CadSingularity_Detection<surfPln>> theSingularity_;

	protected:

		CadRepair_SingularPatch
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<SurfType>& theSurface,
			const std::shared_ptr<CadSingularity_Detection<surfPln>>& theSingularity
		)
			: CadRepair_ImpPatch<SurfType>(theIndex, theSurface)
			, theSingularity_(theSingularity)
		{}

	public:

		typedef CadRepair_ImpPatch<SurfType>
			base;

		const std::shared_ptr<CadSingularity_Detection<surfPln>>& Singularity() const
		{
			return theSingularity_;
		}
	};
}

#endif // !_CadRepair_SingularPatch_Header
