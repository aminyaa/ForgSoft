#pragma once
#ifndef _Mesh2d_gPlnWireSurface_Header
#define _Mesh2d_gPlnWireSurface_Header

#include <Mesh2d_gPlnCurveSurfaceFwd.hxx>
#include <Mesh_PlnWire.hxx>

namespace AutLib
{
	typedef Mesh_PlnWire<Mesh2d_gPlnCurveSurface>
		Mesh2d_gPlnWireSurface;
}

#endif // !_Mesh2d_gPlnWireSurface_Header
