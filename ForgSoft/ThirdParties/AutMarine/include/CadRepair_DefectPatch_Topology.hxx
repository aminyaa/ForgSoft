#pragma once
#ifndef _CadRepair_DefectPatch_Topology_Header
#define _CadRepair_DefectPatch_Topology_Header

#include <CadRepair_DefectPatch.hxx>

namespace AutLib
{

	template<class SurfType>
	class CadRepair_DefectPatch_Topology
		: public CadRepair_DefectPatch<SurfType>
	{

		/*Private Data*/

	protected:

		CadRepair_DefectPatch_Topology
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<SurfType>& theSurface
		)
			: CadRepair_DefectPatch<SurfType>(theIndex, theSurface)
		{}

	public:

		typedef CadRepair_DefectPatch<SurfType>
			base;
	};
}

#endif // !_CadRepair_DefectPatch_Topology_Header
