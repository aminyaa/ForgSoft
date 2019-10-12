#pragma once
#ifndef _Mesh_Conditions_Header
#define _Mesh_Conditions_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>
#include <Mesh_SurfaceCurvatureInfo.hxx>

namespace AutLib
{

	class Mesh_Conditions
	{

	private:

		Standard_Boolean theCustomBoundaryGrowthRate_;
		Standard_Boolean theCustomSurfaceSize_;

		Mesh_SurfaceCurvatureInfo theCustomSurfaceCurvature_;

	public:

		Mesh_Conditions()
		{}


		//- Macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Boolean, CustomBoundaryGrowthRate)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Boolean, CustomSurfaceSize)
			GLOBAL_ACCESS_PRIM_SINGLE(Mesh_SurfaceCurvatureInfo, CustomSurfaceCurvature)
	};
}

#endif // !_Mesh_Conditions_Header
