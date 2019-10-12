#pragma once
#ifndef _Mesh_SurfaceSizeValues_Header
#define _Mesh_SurfaceSizeValues_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>
#include <Mesh_SizeMethodInfo.hxx>
#include <Mesh_RelativeAbsoluteInfo.hxx>

namespace AutLib
{

	class Mesh_SurfaceSizeValues
	{

		/*Private Data*/

		Mesh_SizeMethodInfo theSizeMethod_;

		Mesh_RelativeAbsoluteInfo theRelativeAbsolute_;

		Standard_Real theMinSize_;
		Standard_Real theTargetSize_;

	public:

		Mesh_SurfaceSizeValues()
		{}

		GLOBAL_ACCESS_PRIM_SINGLE(Mesh_SizeMethodInfo, SizeMethod)
			GLOBAL_ACCESS_PRIM_SINGLE(Mesh_RelativeAbsoluteInfo, RelativeAbsolute)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, MinSize)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, TargetSize)

	};
}

#endif // !_Mesh_SurfaceSizeValues_Header
