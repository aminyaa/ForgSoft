#pragma once
#ifndef _CadRepair_DefectPatch_AR_Header
#define _CadRepair_DefectPatch_AR_Header

#include <CadRepair_DefectPatch_Geometry.hxx>

namespace AutLib
{

	template<class SurfType>
	class CadRepair_DefectPatch_AR
		: public CadRepair_DefectPatch_Geometry<SurfType>
	{

		/*Private Data*/

	public:

		CadRepair_DefectPatch_AR
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<SurfType>& theSurface
		)
			: CadRepair_DefectPatch_Geometry<SurfType>(theIndex, theSurface)
		{}

		static std::pair<Standard_Integer, Standard_Real> CalcMaxAR(const SurfType& theSurface);
	};
}

#include <CadRepair_DefectPatch_ARI.hxx>

#endif // !_CadRepair_DefectPatch_AR_Header
