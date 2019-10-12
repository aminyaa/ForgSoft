#pragma once
#ifndef _Mesh_Values_Header
#define _Mesh_Values_Header

#include <Mesh_SurfaceCurvatureValues.hxx>
#include <Mesh_SurfaceSizeValues.hxx>
#include <Mesh_VariationRateInfo.hxx>

namespace AutLib
{

	class Mesh_Values
	{

		/*Private Data*/

		Mesh_VariationRateInfo theBoundaryGrowthRate_;

		Mesh_SurfaceSizeValues theSurfaceSize_;

		Mesh_SurfaceCurvatureValues theCurvature_;

	public:

		Mesh_Values()
		{}


		//- Macros

		GLOBAL_ACCESS_SINGLE(Mesh_SurfaceSizeValues, SurfaceSize)
			GLOBAL_ACCESS_SINGLE(Mesh_SurfaceCurvatureValues, Curvature)

			GLOBAL_ACCESS_PRIM_SINGLE(Mesh_VariationRateInfo, BoundaryGrowthRate)
	};
}

#endif // !_Mesh_Values_Header
