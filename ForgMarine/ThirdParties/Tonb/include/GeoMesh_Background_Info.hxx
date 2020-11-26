#pragma once
#ifndef _GeoMesh_Background_Info_Header
#define _GeoMesh_Background_Info_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

namespace tnbLib
{

	class GeoMesh_Background_SmoothingHvCorrection_Info
	{

		/*Private Data*/

		Standard_Integer theMaxNbIters_;
		Standard_Real theFactor_;

	public:

		static const Standard_Integer DEFAULT_MX_NB_ITERS;
		static const Standard_Real DEFAULT_FACTOR;

		GeoMesh_Background_SmoothingHvCorrection_Info()
			: theMaxNbIters_(DEFAULT_MX_NB_ITERS)
			, theFactor_(DEFAULT_FACTOR)
		{}


		//- Macros
		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, MaxNbIters)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Factor)
	};

	class GeoMesh_Background_SmoothingLaplacian_Info
	{

		/*Private Data*/

		Standard_Integer theMaxNbIters_;
		Standard_Real theFactor_;

	public:

		static const Standard_Integer DEFAULT_MX_NB_ITERS;
		static const Standard_Real DEFAULT_FACTOR;

		GeoMesh_Background_SmoothingLaplacian_Info()
			: theMaxNbIters_(DEFAULT_MX_NB_ITERS)
			, theFactor_(DEFAULT_FACTOR)
		{}


		//- Macros
		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, MaxNbIters)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Factor)
	};
}

#endif // !_GeoMesh_Background_Info_Header
