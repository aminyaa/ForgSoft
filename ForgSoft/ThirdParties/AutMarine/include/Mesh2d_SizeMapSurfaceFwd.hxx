#pragma once
#ifndef _Mesh2d_SizeMapSurfaceFwd_Header
#define _Mesh2d_SizeMapSurfaceFwd_Header

#include <Aft2d_EdgeSurfaceFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class FrontType>
	class Mesh_SizeMap;

	typedef Mesh_SizeMap<Aft2d_EdgeSurface> Mesh2d_SizeMapSurface;
}

#endif // !_Mesh2d_SizeMapSurfaceFwd_Header