#pragma once
#ifndef _CadRepair_DefectPatch_Geometry_Header
#define _CadRepair_DefectPatch_Geometry_Header

#include <CadRepair_DefectPatch.hxx>

namespace AutLib
{

	template<class SurfType>
	class CadRepair_DefectPatch_Geometry
		: public CadRepair_DefectPatch<SurfType>
	{

		/*Private Data*/

	protected:

		CadRepair_DefectPatch_Geometry
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

#endif // !_CadRepair_DefectPatch_Geometry_Header
