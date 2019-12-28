#pragma once
#ifndef _CadRepair_DefectPatch_Header
#define _CadRepair_DefectPatch_Header

#include <CadRepair_ImpPatch.hxx>

namespace AutLib
{

	template<class SurfType>
	class CadRepair_DefectPatch
		: public CadRepair_ImpPatch<SurfType>
	{

		/*Private Data*/

	protected:

		CadRepair_DefectPatch
		(
			const Standard_Integer theIndex, 
			const std::shared_ptr<SurfType>& theSurface
		)
			: CadRepair_ImpPatch<SurfType>(theIndex, theSurface)
		{}

	public:


	};
}

#endif // !_CadRepair_DefectPatch_Header
