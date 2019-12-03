#pragma once
#ifndef _Mesh2d_gPlnWireSurfaceFwd_Header
#define _Mesh2d_gPlnWireSurfaceFwd_Header

#include <Mesh2d_gPlnCurveSurfaceFwd.hxx>

namespace AutLib
{
	// Forward Declarations
	template<class PlnCurve>
	class Mesh_PlnWire;

	typedef Mesh_PlnWire<Mesh2d_gPlnCurveSurface>
		Mesh2d_gPlnWireSurface;
}

#endif // !_Mesh2d_gPlnWireSurfaceFwd_Header
