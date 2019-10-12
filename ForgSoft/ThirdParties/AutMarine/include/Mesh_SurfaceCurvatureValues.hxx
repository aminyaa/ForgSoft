#pragma once
#ifndef _Mesh_SurfaceCurvatureValues_Header
#define _Mesh_SurfaceCurvatureValues_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>
#include <Mesh_SurfaceCurvatureInfo.hxx>

namespace AutLib
{

	class Mesh_SurfaceCurvatureValues
	{

	private:

		Standard_Real theSpanAngle_;

		Mesh_SurfaceCurvatureInfo theCurvatureInfo_;

	public:

		Mesh_SurfaceCurvatureValues()
		{}

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, SpanAngle)
			GLOBAL_ACCESS_PRIM_SINGLE(Mesh_SurfaceCurvatureInfo, CurvatureInfo)
	};
}

#endif // !_Mesh_SurfaceCurvatureValues_Header
