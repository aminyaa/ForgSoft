#pragma once
#ifndef _GeoMesh_BackgroundInfo_Header
#define _GeoMesh_BackgroundInfo_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

namespace AutLib
{

	class GeoMesh_Background_SmoothingHvCorrectionInfo
	{

		/*Private Data*/

		Standard_Integer theNbIters_;
		Standard_Real theFactor_;

	public:

		static const Standard_Integer DEFAULT_MX_NB_ITERS;
		static const Standard_Real DEFAULT_FACTOR;

		GeoMesh_Background_SmoothingHvCorrectionInfo()
			: theNbIters_(DEFAULT_MX_NB_ITERS)
			, theFactor_(DEFAULT_FACTOR)
		{}

		
		//- Macros
		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbIters)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Factor)
	};

	class GeoMesh_Background_SmoothingLaplacianInfo
	{

		/*Private Data*/

		Standard_Integer theNbIters_;
		Standard_Real theFactor_;

	public:

		static const Standard_Integer DEFAULT_MX_NB_ITERS;
		static const Standard_Real DEFAULT_FACTOR;

		GeoMesh_Background_SmoothingLaplacianInfo()
			: theNbIters_(DEFAULT_MX_NB_ITERS)
			, theFactor_(DEFAULT_FACTOR)
		{}

		
		//- Macros
		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbIters)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Factor)
	};
}

#endif // !_GeoMesh_BackgroundInfo_Header