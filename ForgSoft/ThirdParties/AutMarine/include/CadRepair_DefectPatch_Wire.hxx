#pragma once
#ifndef _CadRepair_DefectPatch_Wire_Header
#define _CadRepair_DefectPatch_Wire_Header

#include <CadRepair_DefectPatch_Topology.hxx>

namespace AutLib
{

	template<class SurfType>
	class CadRepair_DefectPatch_Wire
		: public CadRepair_DefectPatch_Topology<SurfType>
	{

		/*Private Data*/

	protected:

		CadRepair_DefectPatch_Wire
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<SurfType>& theSurface
		)
			: CadRepair_DefectPatch_Topology<SurfType>(theIndex, theSurface)
		{}

	public:

		typedef CadRepair_DefectPatch_Topology<SurfType>
			base;
	};
}

#endif // !_CadRepair_DefectPatch_Wire_Header
