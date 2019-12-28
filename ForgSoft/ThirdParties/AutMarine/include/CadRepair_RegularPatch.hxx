#pragma once
#ifndef _CadRepair_RegularPatch_Header
#define _CadRepair_RegularPatch_Header

#include <CadRepair_Patch.hxx>

namespace AutLib
{

	template<class SurfType>
	class CadRepair_RegularPatch
		: public CadRepair_Patch<SurfType>
	{

		/*Private Data*/

	public:

		typedef CadRepair_Patch<SurfType>
			base;

		CadRepair_RegularPatch
		(
			const Standard_Integer theIndex, 
			const std::shared_ptr<SurfType>& theSurface
		)
			: base(theIndex, theSurface)
		{}
	};
}

#endif // !_CadRepair_RegularPatch_Header
