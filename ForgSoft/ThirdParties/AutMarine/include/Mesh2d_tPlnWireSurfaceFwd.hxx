#pragma once
#ifndef _Mesh2d_tPlnWireSurfaceFwd_Header
#define _Mesh2d_tPlnWireSurfaceFwd_Header

#include <Mesh2d_tPlnCurveSurfaceFwd.hxx>

namespace AutLib
{
	// Forward Declarations
	template<class PlnCurve>
	class Mesh_PlnWire;

	typedef Mesh_PlnWire<Mesh2d_tPlnCurveSurface>
		Mesh2d_tPlnWireSurface;
}

#endif // !_Mesh2d_tPlnWireSurfaceFwd_Header
